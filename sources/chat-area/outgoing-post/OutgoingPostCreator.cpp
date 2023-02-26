/**
 * @file OutgoingPostCreator.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Feb 20, 2022
 *
 * Copyright 2021, 2022 Lyubomir Filipov
 *
 * This file is part of Mattermost-QT.
 *
 * Mattermost-QT is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Mattermost-QT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Mattermost-QT. if not, see https://www.gnu.org/licenses/.
 */

#include <QDragMoveEvent>
#include <QMimeData>
#include <QDebug>
#include <QFileDialog>
#include <QVBoxLayout>
#include "chat-area/ChatArea.h"
#include "backend/Backend.h"
#include "backend/types/BackendPost.h"
#include "MessageTextEditWidget.h"
#include "OutgoingPostCreator.h"
#include "OutgoingAttachmentList.h"
#include "choose-emoji-dialog/ChooseEmojiDialogWrapper.h"
#include "../ui_ChatArea.h"

namespace Mattermost {

struct OutgoingPostData {
	const BackendPost*	postToEdit;			//!< Post to be edited. If nullptr - start a new post
	QString 			message;			//!< Message text
	QList<QString>		attachmentPaths;	//!< List of file paths waiting to be attached
	QList<QString>		attachmentIds;		//!< List of file paths already uploaded to the Mattermost server
};

OutgoingPostCreator::OutgoingPostCreator (ChatArea& chatArea)
:chatArea (chatArea)
,postToEdit (nullptr)
,attachmentList (nullptr)
,isConnected (true)
{
	QTimer::singleShot (0, [this, chatAreaUi = chatArea.getUi()] {

		/**
		 * the escape key erases currently entered text or cancels a message edit
		 */
		connect (chatAreaUi->textEdit, &MessageTextEditWidget::escapePressed, [this] {
			auto* textEdit = this->chatArea.getUi()->textEdit;
			textEdit->clear();
			postToEdit = nullptr;
			postEditFinished ();
		});

		connect (chatAreaUi->textEdit, &MessageTextEditWidget::textChanged, [this, chatAreaUi] {
			updateSendButtonState ();
		});

		/*
		 * Send new post after pressing enter or clicking the 'Send' button
		 */
		connect (chatAreaUi->sendButton, &QPushButton::clicked, this, &OutgoingPostCreator::sendPostButtonAction);
		connect (chatAreaUi->textEdit, &MessageTextEditWidget::enterPressed, this, &OutgoingPostCreator::sendPostButtonAction);

		connect (chatAreaUi->attachButton, &QPushButton::clicked, this, &OutgoingPostCreator::onAttachButtonClick);

		connect (chatAreaUi->addEmojiButton, &QPushButton::clicked, [this] {
			showEmojiDialog ([this] (Emoji emoji){

				auto* textEdit = this->chatArea.getUi()->textEdit;
				textEdit->insertPlainText (" :" + emoji.name + ": ");
				textEdit->setFocus ();
			});
		});

		updateSendButtonState();
	});

	auto& backend = chatArea.getBackend();

	connect (&backend, &Backend::onWebSocketConnect, [this] {
		isConnected = true;
		updateSendButtonState();
	});

	connect (&backend, &Backend::onWebSocketDisconnect, [this] {
		isConnected = false;
		updateSendButtonState();
	});

	connect (&sendRetryTimer, &QTimer::timeout, [this] {
		qDebug () << "Post send retry";
		prepareAndSendPost ();
	});
}

OutgoingPostCreator::~OutgoingPostCreator () = default;

void OutgoingPostCreator::onAttachButtonClick ()
{
	QStringList files = QFileDialog::getOpenFileNames (&chatArea, "Select File(s) to attach");

	if (files.empty()) {
		return;
	}

	createAttachmentList ();

	for (auto& filename: files) {
		qDebug() << filename;
		attachmentList->addFile (filename);
	}
}

void OutgoingPostCreator::postEditInitiated (BackendPost& post)
{
	if (isCreatingPost()) {
		qDebug () << "Post edit requested while creating post";
		emit postEditFinished();
		return;
	}

	auto* textEdit = chatArea.getUi()->textEdit;

	textEdit->setText (post.message);
	textEdit->setFocus ();
	textEdit->moveCursor (QTextCursor::End);
	postToEdit = &post;
}

void OutgoingPostCreator::sendPostButtonAction ()
{
	auto* textEdit = chatArea.getUi()->textEdit;
	QString message = textEdit->toPlainText ();

	//do not send empty messages
	if (message.isEmpty() && !attachmentList) {
		return;
	}

	outgoingPostData = std::make_unique<OutgoingPostData>();

	outgoingPostData->message = message;
	outgoingPostData->postToEdit = postToEdit;
	postToEdit = nullptr;

	sendRetryTimer.start (10000);

	if (attachmentList) {
		outgoingPostData->attachmentPaths = attachmentList->getAllFiles();
		attachmentList->setDisableInput (true);
	}

	textEdit->setReadOnly (true);
	updateSendButtonState ();
	prepareAndSendPost ();
	chatArea.setStatusLabelText ("Sending message...");
}

void OutgoingPostCreator::prepareAndSendPost ()
{
	auto& backend = chatArea.getBackend();
	auto& channel = chatArea.getChannel();

	if (outgoingPostData->attachmentPaths.isEmpty()) {
		sendPost ();
		return;
	}

	for (auto it = outgoingPostData->attachmentPaths.begin(); it != outgoingPostData->attachmentPaths.end(); ++it) {
		auto& file = *it;
		backend.uploadFile (channel, file, [this, &backend, &channel, it] (QString fileId) {

			outgoingPostData->attachmentIds.push_back (fileId);
			outgoingPostData->attachmentPaths.erase (it);
			size_t uploadedFilesCount = outgoingPostData->attachmentIds.size();
			size_t remainingFileCount = outgoingPostData->attachmentPaths.size();

			chatArea.setStatusLabelText ("Attached file " + QString::number (uploadedFilesCount)
					+ " of " + QString::number (uploadedFilesCount + remainingFileCount));

			qDebug () << "Remaining file count: " << remainingFileCount;

			if (remainingFileCount == 0) {
				sendPost ();
			}
		});
	}
}

void OutgoingPostCreator::sendPost ()
{
	auto& backend = chatArea.getBackend();
	auto& channel = chatArea.getChannel();

	QString attachmentsLogStr (outgoingPostData->attachmentIds.isEmpty() ? "" : " (+attachments)");

	if (outgoingPostData->postToEdit) {
		qDebug () << "Send post edit" << attachmentsLogStr;
		backend.editPost (outgoingPostData->postToEdit->id, outgoingPostData->message, outgoingPostData->attachmentIds);
	} else {
		qDebug () << "Send post" << attachmentsLogStr;
		backend.addPost (channel, outgoingPostData->message, outgoingPostData->attachmentIds);
	}
}

void OutgoingPostCreator::onDragEnterEvent (QDragEnterEvent* event)
{
	if (event->mimeData()->hasUrls()) {
		event->acceptProposedAction();
	}
}

void OutgoingPostCreator::onDragMoveEvent (QDragMoveEvent* event)
{
	if (event->mimeData()->hasUrls()) {
		event->acceptProposedAction();
	}
}

void OutgoingPostCreator::onDropEvent (QDropEvent* event)
{
	if (isWaitingForPostServerResponse ()) {
		qDebug() << "Cannot attach files while sending a post";
		return;
	}

	createAttachmentList ();

	for (auto& url: event->mimeData ()->urls()) {
		qDebug() << "Drop" << url;
		attachmentList->addFile (url.toLocalFile());
	}
}

void OutgoingPostCreator::onPostReceived (BackendPost& post)
{
	if (outgoingPostData && post.isOwnPost()) {

		sendRetryTimer.stop ();

		chatArea.setStatusLabelText ("");

		//reset the 'editing post' state
		if (outgoingPostData->postToEdit) {
			emit postEditFinished();
		}

		outgoingPostData.reset();

		if (attachmentList) {
			delete (attachmentList);
			attachmentList = nullptr;
		}

		auto* textEdit = chatArea.getUi()->textEdit;
		textEdit->clear();
		textEdit->setReadOnly (false);
		updateSendButtonState ();
	}
}

void OutgoingPostCreator::createAttachmentList ()
{
	if (!attachmentList) {
		attachmentList = new OutgoingAttachmentList (&chatArea);
		chatArea.getAttachmentListParentWidget().insertWidget(2, attachmentList);
		updateSendButtonState ();

		connect (attachmentList, &OutgoingAttachmentList::deleted, [this] {
			delete (attachmentList);
			attachmentList = nullptr;
			updateSendButtonState ();
		});
	}
}

void OutgoingPostCreator::updateSendButtonState ()
{
	bool sendButtonEnabled = true;
	QString tooltipText;

	if (!isConnected) { //no connection
		tooltipText = "Server connection lost";

		if (outgoingPostData) {
			tooltipText += ", sending message";
		}

		sendButtonEnabled = false;
	} else if (outgoingPostData) { //sending message in progress
		sendButtonEnabled = false;
		tooltipText = "Waiting for server response";
	}

	bool attachButtonEnabled = sendButtonEnabled;

	chatArea.getUi()->attachButton->setDisabled (!attachButtonEnabled);
	chatArea.getUi()->attachButton->setToolTip (tooltipText);

	/**
	 * Send button is disabled if the post text area is empty
	 */
	if (sendButtonEnabled && !isCreatingPost()) {
		sendButtonEnabled = false;
		tooltipText = "Cannot send empty message";
	}

	chatArea.getUi()->sendButton->setDisabled (!sendButtonEnabled);
	chatArea.getUi()->sendButton->setToolTip (tooltipText);
}

/**
 * returns true if the client is waiting for server response after sending or editing a post,
 * or if the user is in the process of creating or editing a post (if there is typed text or attached files)
 */
bool OutgoingPostCreator::isCreatingPost ()
{
	if (isWaitingForPostServerResponse ()) {
		return true;
	}

	auto* textEdit = chatArea.getUi()->textEdit;
	QString message = textEdit->toPlainText ();

	if (message.isEmpty() && !attachmentList) {
		return false;
	}

	return true;
}

/**
 * returns true if the client is waiting for server response after sending or editing a post
 */
bool OutgoingPostCreator::isWaitingForPostServerResponse ()
{
	return outgoingPostData ? true : false;
}

} /* namespace Mattermost */

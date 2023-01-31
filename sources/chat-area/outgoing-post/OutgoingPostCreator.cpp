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

OutgoingPostCreator::OutgoingPostCreator (ChatArea& chatArea)
:chatArea (chatArea)
,postToEdit (nullptr)
,attachmentList (nullptr)
,waitingForNewPostToAppear (false)
{
	QTimer::singleShot (0, [this, chatAreaUi = chatArea.getUi()] {
		connect (chatAreaUi->textEdit, &MessageTextEditWidget::enterPressed, this, &OutgoingPostCreator::sendPost);

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
		connect (chatAreaUi->sendButton, &QPushButton::clicked, this, &OutgoingPostCreator::sendPost);

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

void OutgoingPostCreator::sendPost ()
{
	auto& backend = chatArea.getBackend();
	auto& channel = chatArea.getChannel();

	auto* textEdit = chatArea.getUi()->textEdit;
	QString message = textEdit->toPlainText ();

	//do not send empty messages
	if (!attachmentList && message.isEmpty()) {
		return;
	}

	if (!attachmentList) {
		waitingForNewPostToAppear = true;
		updateSendButtonState ();
		if (postToEdit) {
			backend.editPost (postToEdit->id, message, nullptr);
			postToEdit = nullptr;
			qDebug () << "Send post edit";
			emit postEditFinished();
		} else {
			qDebug () << "Send post";
			backend.addPost (channel, message);
		}
		return;
	}

	QList<QString> files = attachmentList->getAllFiles();

	static QList<QString> fileIds;
	static uint32_t filesCount;
	filesCount = files.size();

	fileIds.clear ();

	for (auto& file: files) {
		backend.uploadFile (channel, file, [this, &backend, &channel, message, textEdit] (QString fileId ){
			--filesCount;
			qDebug () << "Remaining file count: " << filesCount;
			fileIds.push_back (fileId);

			if (filesCount == 0) {
				waitingForNewPostToAppear = true;
				updateSendButtonState ();

				if (postToEdit) {
					backend.editPost (postToEdit->id, message, &fileIds);
					postToEdit = nullptr;
					qDebug () << "Send post edit (+attachments)";
					emit postEditFinished();
				} else {
					qDebug () << "Send post";
					backend.addPost (channel, message, fileIds);
				}
				delete (attachmentList);
				attachmentList = nullptr;
			}

		});
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
	createAttachmentList ();

	for (auto& url: event->mimeData ()->urls()) {
		qDebug() << "Drop" << url;
		attachmentList->addFile (url.toLocalFile());
	}
}

void OutgoingPostCreator::onPostReceived (BackendPost& post)
{
	if (waitingForNewPostToAppear && post.isOwnPost()) {
		waitingForNewPostToAppear = false;
		auto* textEdit = chatArea.getUi()->textEdit;
		textEdit->clear();
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
	bool buttonDisabled = false;

	if (waitingForNewPostToAppear) {
		buttonDisabled = true;
	} else {
		if (!isCreatingPost()) {
			buttonDisabled = true;
		}
	}

	chatArea.getUi()->sendButton->setDisabled (buttonDisabled);
}

bool OutgoingPostCreator::isCreatingPost ()
{
	if (waitingForNewPostToAppear) {
		return true;
	}

	auto* textEdit = chatArea.getUi()->textEdit;
	QString message = textEdit->toPlainText ();

	if (message.isEmpty() && !attachmentList) {
		return false;
	}

	return true;
}

} /* namespace Mattermost */

/**
 * @file OutgoingPostCreator.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Feb 20, 2022
 */

#include <QDragMoveEvent>
#include <QMimeData>
#include <QDebug>
#include <QFileDialog>
#include <QVBoxLayout>
#include "ChatArea.h"
#include "backend/Backend.h"
#include "MessageTextEditWidget.h"
#include "OutgoingPostCreator.h"
#include "OutgoingAttachmentList.h"
#include "ui_ChatArea.h"

namespace Mattermost {

OutgoingPostCreator::OutgoingPostCreator (ChatArea& pchatArea)
:chatArea (pchatArea)
,attachmentList (nullptr)
{
	QTimer::singleShot (0, [this, chatAreaUi = chatArea.getUi()] {
		connect (chatAreaUi->textEdit, &MessageTextEditWidget::enterPressed, this, &OutgoingPostCreator::sendPost);

		connect (chatAreaUi->textEdit, &MessageTextEditWidget::upArrowPressed, [chatAreaUi] {
			if (!chatAreaUi->textEdit->hasNonEmptyText ()) {
				qDebug () << "Up Arrow pressed. Ready to implement message editing";
			}
		});

		connect (chatAreaUi->textEdit, &MessageTextEditWidget::textChanged, [chatAreaUi] {
				if (!chatAreaUi->textEdit->hasNonEmptyText ()) {
					chatAreaUi->sendButton->setDisabled (true);
				} else {
					chatAreaUi->sendButton->setDisabled (false);
				}
		});

		/*
		 * Send new post after pressing enter or clicking the 'Send' button
		 */
		connect (chatAreaUi->sendButton, &QPushButton::clicked, this, &OutgoingPostCreator::sendPost);

		connect (chatAreaUi->attachButton, &QPushButton::clicked, this, &OutgoingPostCreator::onAttachButtonClick);

		chatAreaUi->sendButton->setDisabled (true);
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
		textEdit->clear();
		backend.addPost (channel, message);
		return;
	}

	QList<QString> files = attachmentList->getAllFiles();

	static QList<QString> fileIds;
	static uint32_t filesCount = files.size();

	fileIds.clear ();

	for (auto& file: files) {
		backend.uploadFile (channel, file, [this, &backend, &channel, message, textEdit] (QString fileId ){
			--filesCount;
			qDebug () << "Remaining file count: " << filesCount;
			fileIds.push_back (fileId);

			if (filesCount == 0) {
				textEdit->clear();
				backend.addPost (channel, message, fileIds);
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

void OutgoingPostCreator::createAttachmentList ()
{
	if (!attachmentList) {
		attachmentList = new OutgoingAttachmentList (&chatArea);
		chatArea.getAttachmentListParentWidget().insertWidget(2, attachmentList);

		connect (attachmentList, &OutgoingAttachmentList::deleted, [this] {
			delete (attachmentList);
			attachmentList = nullptr;
		});
	}
}

} /* namespace Mattermost */

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

namespace Mattermost {

OutgoingPostCreator::OutgoingPostCreator (ChatArea& chatArea, MessageTextEditWidget*& textEdit)
:chatArea (chatArea)
,textEdit (textEdit)
,attachmentList (nullptr)
{
}

OutgoingPostCreator::~OutgoingPostCreator () = default;

void OutgoingPostCreator::onAttachButtonClick ()
{
	createAttachmentList ();

	for (auto& filename: QFileDialog::getOpenFileNames (&chatArea, "Select File(s) to attach")) {
		qDebug() << filename;
		attachmentList->addFile (filename);
#if 0
		this->backend.uploadFile (this->channel, filename, [] (QString fileID) {

		});
#endif
	}
}

void OutgoingPostCreator::sendPost (Backend& backend, BackendChannel& channel)
{
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
		backend.uploadFile (channel, file, [this, &backend, &channel, message] (QString fileId ){
			--filesCount;
			qDebug () << "Remaining file count: " << filesCount;
			fileIds.push_back (fileId);

			if (filesCount == 0) {
				backend.addPost (channel, message, fileIds);
			}

			delete (attachmentList);
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
	}
}

} /* namespace Mattermost */

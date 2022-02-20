/**
 * @file OutgoingPostCreator.h
 * @brief
 * @author Lyubomir Filipov
 * @date Feb 20, 2022
 */

#pragma once

#include "fwd.h"

class QDragEnterEvent;
class QDragMoveEvent;
class QDropEvent;

namespace Mattermost {

class OutgoingPostCreator: public QObject {
	Q_OBJECT
public:
	OutgoingPostCreator (ChatArea& chatArea, MessageTextEditWidget*& textEdit);
	virtual ~OutgoingPostCreator ();
public:

	void onAttachButtonClick ();
	void sendPost (Backend& backend, BackendChannel& channel);

	void onDragEnterEvent (QDragEnterEvent* event);
	void onDragMoveEvent (QDragMoveEvent* event);
	void onDropEvent (QDropEvent* event);
private:
	void createAttachmentList ();
private:
	ChatArea& 				chatArea;
	MessageTextEditWidget*&	textEdit;
	OutgoingAttachmentList*	attachmentList;

};

} /* namespace Mattermost */

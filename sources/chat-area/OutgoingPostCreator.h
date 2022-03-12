/**
 * @file OutgoingPostCreator.h
 * @brief
 * @author Lyubomir Filipov
 * @date Feb 20, 2022
 */

#pragma once

#include <QObject>
#include "fwd.h"

class QDragEnterEvent;
class QDragMoveEvent;
class QDropEvent;

namespace Mattermost {

class OutgoingPostCreator: public QObject {
	Q_OBJECT
public:
	OutgoingPostCreator (ChatArea& chatArea);
	virtual ~OutgoingPostCreator ();

public slots:
	void onAttachButtonClick ();
	void sendPost ();

public:
	void onDragEnterEvent (QDragEnterEvent* event);
	void onDragMoveEvent (QDragMoveEvent* event);
	void onDropEvent (QDropEvent* event);

private:
	void createAttachmentList ();

private:
	ChatArea& 				chatArea;
	OutgoingAttachmentList*	attachmentList;

};

} /* namespace Mattermost */

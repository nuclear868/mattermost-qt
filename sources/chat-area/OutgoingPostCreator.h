/**
 * @file OutgoingPostCreator.h
 * @brief
 * @author Lyubomir Filipov
 * @date Feb 20, 2022
 *
 * Copyright 2021, 2022 Lyubomir Filipov
 *
 * This file is part of Mattermost-QT.
 *
 * Mattermost-QT is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Mattermost-QT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Mattermost-QT; if not, see https://www.gnu.org/licenses/.
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
	void onPostReceived (BackendPost& post);
	void sendPost ();
	void postEditInitiated (BackendPost& post);

signals:
	void postEditFinished ();

public:
	void onDragEnterEvent (QDragEnterEvent* event);
	void onDragMoveEvent (QDragMoveEvent* event);
	void onDropEvent (QDropEvent* event);

private:
	void createAttachmentList ();
	void updateSendButtonState ();
	bool isCreatingPost ();

private:
	ChatArea& 				chatArea;
	const BackendPost*		postToEdit;
	OutgoingAttachmentList*	attachmentList;
	bool					waitingForNewPostToAppear;
};

} /* namespace Mattermost */

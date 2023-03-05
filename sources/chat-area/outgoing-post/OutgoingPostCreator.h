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

#pragma once

#include <QTimer>
#include <QWidget>
#include "fwd.h"

class QDragEnterEvent;
class QDragMoveEvent;
class QDropEvent;
class QBoxLayout;

namespace Ui {
class OutgoingPostCreator;
}

namespace Mattermost {

struct OutgoingPostData;
class PostsListWidget;
class OutgoingPostPanel;

class OutgoingPostCreator: public QWidget {
	Q_OBJECT
public:
	explicit OutgoingPostCreator (QWidget *parent = nullptr);
	~OutgoingPostCreator();
public:
	void init (Backend& backend, BackendChannel& channel, OutgoingPostPanel& panel, PostsListWidget& postsListWidget, QBoxLayout* attachmentParent);
	void onDragEnterEvent (QDragEnterEvent* event);
	void onDragMoveEvent (QDragMoveEvent* event);
	void onDropEvent (QDropEvent* event);
	void setStatusLabelText (const QString& string);

public slots:
	void onAttachButtonClick ();
	void onPostReceived (BackendPost& post);
	void sendPostButtonAction ();
	void postEditInitiated (BackendPost& post);

signals:
	void postEditFinished ();
	void heightChanged (int height);


private:
	void createAttachmentList (QStringList& files);
	void updateSendButtonState ();
	bool isCreatingPost ();
	bool isWaitingForPostServerResponse ();

	void prepareAndSendPost ();
	void sendPost ();

private:
    Ui::OutgoingPostCreator*			ui;
	Backend*							backend;
	BackendChannel*						channel;
	OutgoingPostPanel*					panel;
	QTimer								sendRetryTimer;
	const BackendPost*					postToEdit;
	OutgoingAttachmentList*				attachmentList;
	std::unique_ptr<OutgoingPostData> 	outgoingPostData;
	bool								isConnected;
	QBoxLayout* 						attachmentParent;
};

} /* namespace Mattermost */

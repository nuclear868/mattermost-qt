/**
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

#include <QWidget>
#include <memory>

namespace Ui {
class PostWidget;
}

namespace Mattermost {

class Backend;
class BackendPost;
class PostAttachmentList;
class PostReactionList;
class PostPoll;
class ChatArea;

class PostWidget: public QWidget
{
    Q_OBJECT

public:
    explicit PostWidget (Backend& backend, BackendPost &post, QWidget *parent, ChatArea* chatArea);
    ~PostWidget();
public:

    enum FormatType {
		messageOnly,
		entirePost
    };

    void setEdited (const QString& message);
    void updateReactions ();

    void markAsDeleted ();


    QString getMessageTimeString (uint64_t timestamp);
    QString formatMessageText (const QString& str);
    QString formatForClipboardSelection (FormatType formatType) const;

    BackendPost&						post;
    QString								hoveredLink;
signals:
	void dimensionsChanged ();
private:
    Ui::PostWidget*						ui;
    std::unique_ptr<PostAttachmentList>	attachments;
    std::unique_ptr<PostPoll>			poll;
    std::unique_ptr<PostReactionList>	reactions;
};

} /* namespace Mattermost */


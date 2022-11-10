/**
 * @file PostReactionAddedEvent.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Nov 9, 2022
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

#include "PostReactionAddedEvent.h"

#include <QJsonDocument>

namespace Mattermost {

//the post object is a JSON string inside the data object, with escaped json elements
//,postObject (QJsonDocument::fromJson (data.value ("post").toString().toUtf8()).object())

PostReactionAddedEvent::PostReactionAddedEvent (const QJsonObject& data, const QJsonObject& broadcast)
:channelId (broadcast.value ("channel_id").toString())
{
	QJsonDocument innerJson (QJsonDocument::fromJson (data.value ("reaction").toString().toUtf8()));

	userId = innerJson.object().value ("user_id").toString ();
	postId = innerJson.object().value ("post_id").toString ();
	emojiName = innerJson.object().value ("emoji_name").toString ();
}

PostReactionAddedEvent::~PostReactionAddedEvent () = default;

} /* namespace Mattermost */

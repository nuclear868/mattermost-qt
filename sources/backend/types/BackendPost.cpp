/**
 * @file BackendPost.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 4, 2021
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

#include "BackendPost.h"

#include <QJsonArray>
#include "backend/EmojiMap.h"

namespace Mattermost {

BackendPost::BackendPost (const QJsonObject& jsonObject)
:author (nullptr)
,isDeleted (false)
{
	id = jsonObject.value("id").toString();
	create_at = jsonObject.value("create_at").toVariant().toULongLong();
	update_at = jsonObject.value("update_at").toVariant().toULongLong();
	edit_at = jsonObject.value("edit_at").toVariant().toULongLong();
	delete_at = jsonObject.value("delete_at").toVariant().toULongLong();
	is_pinned = jsonObject.value("is_pinned").toBool();
	user_id = jsonObject.value("user_id").toString();
	channel_id = jsonObject.value("channel_id").toString();
	root_id = jsonObject.value("root_id").toString();
	parent_id = jsonObject.value("parent_id").toString();
	original_id = jsonObject.value("original_id").toString();
	message = jsonObject.value("message").toString();
	type = jsonObject.value("type").toString();
	props = jsonObject.value("props").toVariant();
	hashtags = jsonObject.value("hashtags").toString();
	pending_post_id = jsonObject.value("pending_post_id").toString();

	QJsonObject metadata = jsonObject.value("metadata").toObject();

	for (const auto &fileElement: metadata.value("files").toArray()) {
		files.emplace_back (fileElement.toObject());
	}

	for (const auto &reactionElement: metadata.value("reactions").toArray()) {
		QString emoji = reactionElement.toObject().value ("emoji_name").toString();
		reactions.emplace_back (EmojiMap::nameToId (emoji));
	}
}

BackendPost::~BackendPost () = default;

bool BackendPost::isOwnPost () const
{
	if (!author) {
		return false;
	}

	return author->isLoginUser;
}

QString BackendPost::getDisplayAuthorName () const
{
	if (author) {
		return author->getDisplayName ();
	}

	return user_id;
}

QDateTime BackendPost::getCreationTime () const
{
	return QDateTime::fromMSecsSinceEpoch (create_at);
}

} /* namespace Mattermost */

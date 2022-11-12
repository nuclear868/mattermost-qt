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
#include "BackendPoll.h"
#include "backend/Storage.h"
#include "log.h"

namespace Mattermost {

BackendPost::BackendPost (const QJsonObject& jsonObject, const Storage& storage)
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
	props = jsonObject.value("props");
	hashtags = jsonObject.value("hashtags").toString();
	pending_post_id = jsonObject.value("pending_post_id").toString();

	QJsonObject metadata = jsonObject.value("metadata").toObject();

	for (const auto &fileElement: metadata.value("files").toArray()) {
		files.emplace_back (fileElement.toObject());
	}

	for (const auto &reactionElement: metadata.value("reactions").toArray()) {

		QString userName = storage.getUserDisplayNameByUserId (reactionElement.toObject().value ("user_id").toString(), true);
		addReaction (userName, reactionElement.toObject().value ("emoji_name").toString());
	}

	/**
	 * If there are attachments to the post, it is either a poll or a call
	 */
	QJsonValue attachments (props.toObject().value("attachments"));
	if (attachments.isArray()) {
		auto pollObject = attachments.toArray()[0].toObject();

		/**
		 * If there is no actions array and no fields array, this is not a poll
		 */
		if (pollObject.value("actions").toArray().isEmpty() && pollObject.value("fields").toArray().isEmpty()) {
			return;
		}

		poll = std::make_unique<BackendPoll> (props.toObject().value("poll_id").toString(), pollObject);
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

/**
 * Get the author name to be displayed in chat windows, dialogs, etc.
 * This differs from author name, in cases like polls - where the post author is a bot
 * @return
 */
QString BackendPost::getDisplayAuthorName () const
{
	if (poll) {
		return poll->authorName + " (" + getAuthorName() + ")";
	}

	return getAuthorName();
}

void BackendPost::addReaction (QString userName, QString emojiName)
{
	auto iterator = EmojiMap::findByName(emojiName);

	if (iterator == EmojiMap::missing()) {
		LOG_DEBUG ("Missing emoji: " << emojiName);
		return;
	}

	reactions[iterator].push_back (userName);
}

void BackendPost::removeReaction (QString userName, QString emojiName)
{
	auto iterator = EmojiMap::findByName(emojiName);

	if (iterator == EmojiMap::missing()) {
		LOG_DEBUG ("Missing emoji: " << emojiName);
		return;
	}

	auto& vec = reactions[iterator];

	vec.erase(std::remove(vec.begin(), vec.end(), userName), vec.end());

	//if this was the only user used this reaction, remove the reaction
	if (vec.isEmpty()) {
		reactions.erase (iterator);
	}
}

/**
 * Get the author name. This is the name of the user, set as a post author
 * @return
 */
QString BackendPost::getAuthorName () const
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

void BackendPost::updatePostEdits (BackendPost& editedPost)
{
	message = editedPost.message;

	if (poll && editedPost.poll) {

		editedPost.poll->metadata = poll->metadata;
		poll = std::move (editedPost.poll);
	}

}


} /* namespace Mattermost */

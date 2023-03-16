/**
 * @file BackendPost.h
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 4, 2021
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

#include <QJsonObject>
#include <QVariant>
#include <QDateTime>
#include <list>
#include <memory>
#include "BackendUser.h"
#include "BackendFile.h"
#include "backend/emoji/EmojiDefs.h"

namespace Mattermost {

class BackendPoll;
class Storage;

using BackendPostReaction = QVector<QString>;

class BackendPost {
public:
	BackendPost (const QJsonObject& jsonObject, const Storage& storage);
	BackendPost (BackendPost&& other) = default;
	~BackendPost ();
public:

	/**
	 * Returns whether a post was posted by the logged-in user.
	 * Poll posts are never considered as own posts, because they appear as posted by Matterpoll bot
	 * @return bool
	 */
	bool isOwnPost () 		const;

	/**
	 * Returns whether a post was created as a result of creating a poll from the logged-in user.
	 * Even if it returned true, the post is not considered as an own post (because it appears as
	 * posted by the Matterpoll bot and), in the sense, that it cannot be edited or deleted like other posts.
	 * The function is used to check whether a poll create request has succeeded
	 * @return bool
	 */
	bool isOwnPollPost () 	const;
	QString getDisplayAuthorName () const;
	QDateTime getCreationTime () const;
	void updatePostEdits (BackendPost& editedPost);
	void addReaction (QString userName, QString emojiName);
	void removeReaction (QString userName, QString emojiName);
private:
	QString getAuthorName () const;
public:
	QString						id;
	uint64_t					create_at;
	uint64_t					update_at;
	uint64_t					edit_at;
	uint64_t					delete_at;
	bool						is_pinned;
	QString						user_id;
	QString						channel_id;
#if 1
	QString						root_id;
	QString						parent_id;
	QString						original_id;
#endif
	BackendPost*				rootPost;
	QString						message;
	QString						type;
	QJsonValue					props;
	QString						hashtags;
	QString						pending_post_id;
	std::list<BackendFile>		files;
	std::map<EmojiID, BackendPostReaction> reactions;


	std::unique_ptr<BackendPoll> poll;
	const BackendUser*			author;
	bool						isDeleted;
};

} /* namespace Mattermost */

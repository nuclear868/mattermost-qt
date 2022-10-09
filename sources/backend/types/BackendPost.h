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

#include <QJsonObject>
#include <QVariant>
#include <QDateTime>
#include <list>
#include <memory>
#include "BackendUser.h"
#include "BackendFile.h"

namespace Mattermost {

class BackendPoll;

class BackendPost {
public:
	BackendPost (const QJsonObject& jsonObject);
	BackendPost (BackendPost&& other) = default;
	~BackendPost ();
public:
	bool isOwnPost () const;
	QString getDisplayAuthorName () const;
	QDateTime getCreationTime () const;
	void updatePostEdits (BackendPost& editedPost);
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
	QString						root_id;
	QString						parent_id;
	QString						original_id;
	QString						message;
	QString						type;
	QJsonValue					props;
	QString						hashtags;
	QString						pending_post_id;
	std::list<BackendFile>		files;
	std::vector<int>			reactions;


	std::unique_ptr<BackendPoll> poll;
	const BackendUser*			author;
	bool						isDeleted;
};

} /* namespace Mattermost */

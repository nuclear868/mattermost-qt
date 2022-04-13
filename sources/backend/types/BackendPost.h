/**
 * @file BackendPost.h
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 4, 2021
 */

#pragma once

#include <QJsonObject>
#include <QVariant>
#include <list>
#include "BackendUser.h"
#include "BackendFile.h"

namespace Mattermost {

class BackendPost {
public:
	BackendPost (const QJsonObject& jsonObject);
	BackendPost (BackendPost&& other) = default;
	~BackendPost ();
public:
	bool isOwnPost () const;
	QString getDisplayAuthorName () const;
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
	QVariant					props;
	QString						hashtags;
	QString						pending_post_id;
	std::list<BackendFile>		files;

	bool						isDeleted;

	const BackendUser*			author;
};

} /* namespace Mattermost */

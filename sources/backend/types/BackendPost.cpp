/**
 * @file BackendPost.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 4, 2021
 */

#include "BackendPost.h"

#include <QJsonArray>

namespace Mattermost {

BackendPost::BackendPost (const QJsonObject& jsonObject)
:author (nullptr)
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

} /* namespace Mattermost */

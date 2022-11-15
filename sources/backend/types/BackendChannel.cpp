/**
 * @file BackendChannel.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 1, 2021
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

#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>
#include "BackendChannel.h"
#include "BackendPoll.h"
#include "backend/Storage.h"
#include "log.h"

namespace Mattermost {

uint32_t BackendChannel::getChannelType (const QJsonObject& jsonObject)
{
	switch (jsonObject.value("type").toString()[0].unicode()) {
	case 'O':
		return publicChannel;
		break;
	case 'P':
		return privateChannel;
		break;
	case 'D':
		return directChannel;
	case 'G':
		return groupChannel;
		break;
	default:
		return unknown;
		break;
	}
}

QString BackendChannel::getChannelDescription () const
{
	return !header.isEmpty() ? header : purpose;
}

void ChannelNewPosts::addChunk (ChannelNewPostsChunk&& chunk)
{
	//do not add empty chunk
	if (chunk.postsToAdd.empty()) {
		return;
	}

	postsToAdd.emplace (postsToAdd.begin(), std::move (chunk));
}

BackendChannel::BackendChannel (Storage& storage, const QJsonObject& jsonObject)
:storage (storage)
{
	id = jsonObject.value("id").toString();
	create_at = jsonObject.value("create_at").toVariant().toULongLong();
	update_at = jsonObject.value("update_at").toVariant().toULongLong();
	delete_at = jsonObject.value("delete_at").toVariant().toULongLong();
	team = storage.getTeamById (jsonObject.value("team_id").toString());
	display_name = jsonObject.value("display_name").toString();
	name = jsonObject.value("name").toString();
	header = jsonObject.value("header").toString();
	purpose = jsonObject.value("purpose").toString();

	type = getChannelType (jsonObject);

	last_post_at = jsonObject.value("last_post_at").toVariant().toULongLong();

	total_msg_count = jsonObject.value("total_msg_count").toInt();
	extra_update_at = jsonObject.value("extra_update_at").toInt();
	creator = storage.getUserById (jsonObject.value("creator_id").toString());
	scheme_id = jsonObject.value("scheme_id").toVariant();
	props = jsonObject.value("props").toVariant();
	referenceCount = 1;
}

BackendChannel::~BackendChannel () = default;

BackendPost* BackendChannel::addPost (const QJsonObject& postObject)
{
	posts.emplace_back (postObject, storage);

	BackendPost* newPost = &posts.back ();
	newPost->author = storage.getUserById (newPost->user_id);
	return newPost;
}

void BackendChannel::addPost (const QJsonObject& postObject, std::list<BackendPost>::iterator position, ChannelNewPostsChunk& currentChunk, bool initialLoad)
{
	/*
	 * Add a post.
	 * And add added post to the list of new posts
	 */
	BackendPost* newPost = &*posts.emplace(position, postObject, storage);
	newPost->author = storage.getUserById (newPost->user_id);

	currentChunk.postsToAdd.emplace_front (newPost);

	if (!initialLoad) {
		qDebug() << newPost->create_at << " " << newPost->id << " " << newPost->getDisplayAuthorName() << " " << newPost->message;
	}
}


void BackendChannel::prependPosts (const QJsonArray& orderArray, const QJsonObject& postsObject)
{
	/*
	 * A list of (sequential) groups of new posts
	 */
	ChannelNewPosts allNewPosts;

	/*
	 * A sequential group of new posts
	 */
	ChannelNewPostsChunk currentNewPostsChunk;

	bool initialLoad = true;

	//add all posts to the beginning of the posts list
	for (const auto& newPostEl: orderArray) {
		QString newPostId = newPostEl.toString();
		addPost (postsObject.find (newPostId).value().toObject(), posts.begin (), currentNewPostsChunk, initialLoad);
	}

	//if there are new posts left, add them to allMissingPosts
	if (!currentNewPostsChunk.postsToAdd.empty()) {
		allNewPosts.addChunk (std::move (currentNewPostsChunk));
	}

	emit onNewPosts (allNewPosts);
}

void BackendChannel::addPosts (const QJsonArray& orderArray, const QJsonObject& postsObject)
{
	/*
	 * A list of (sequential) groups of new posts
	 */
	ChannelNewPosts allNewPosts;

	/*
	 * A sequential group of new posts
	 */
	ChannelNewPostsChunk currentNewPostsChunk;

	//search local posts from newest to oldest
	std::list<BackendPost>::reverse_iterator currentLocalPost = posts.rbegin();

#warning "Handle case of deleted post, that is not deleted locally"

	bool initialLoad = (posts.empty());
	bool lastPostWasSkipped = false;

	int i = 0;

	for (const auto& newPostEl: orderArray) {

		++i;

		QString newPostId = newPostEl.toString();

		//if a post is deleted, it will exist locally, but will not exist in the list of received post
		while (currentLocalPost != posts.rend() && currentLocalPost->isDeleted) {
			++currentLocalPost;
		}

		//end of local posts list. Save the current missing post sequence and add all missing posts
		if (currentLocalPost == posts.rend()) {
			addPost (postsObject.find (newPostId).value().toObject(), posts.begin (), currentNewPostsChunk, initialLoad);
			++currentLocalPost;
			continue;
		}

		//post already exists. No need to be added. Save the current missing posts chunk and start a new one
		if (currentLocalPost->id == newPostId) {
			++currentLocalPost;

			if (lastPostWasSkipped) {
				currentNewPostsChunk.previousPostId = newPostId;
				allNewPosts.addChunk (std::move (currentNewPostsChunk));
				lastPostWasSkipped = false;
			}
			continue;
		}

		//post not found. Add it to the list of new posts
		qDebug () << "Add after currentLocalPost";
		addPost (postsObject.find (newPostId).value().toObject(), currentLocalPost.base(), currentNewPostsChunk, initialLoad);
		++currentLocalPost;
		lastPostWasSkipped = true;
	}

	//if there are new posts left, add them to allMissingPosts
	if (!currentNewPostsChunk.postsToAdd.empty()) {
		if (currentLocalPost != posts.rend()) {
			currentNewPostsChunk.previousPostId = currentLocalPost->id;
		}
		allNewPosts.addChunk (std::move (currentNewPostsChunk));
	}

	emit onNewPosts (allNewPosts);
}

void BackendChannel::editPost (BackendPost& newPost)
{
	for (auto& post: posts) {
		if (post.id == newPost.id) {
			post.updatePostEdits (newPost);
			emit onPostEdited (post);
			break;
		}
	}
}

void BackendChannel::addPostReaction (QString postId, QString userId, QString emojiName)
{
	for (auto& post: posts) {
		if (post.id == postId) {

			post.addReaction (storage.getUserDisplayNameByUserId (userId, true), emojiName);
			emit onPostReactionUpdated (post);
			break;
		}
	}
}

void BackendChannel::removePostReaction (QString postId, QString userId, QString emojiName)
{
	for (auto& post: posts) {
		if (post.id == postId) {

			post.removeReaction (storage.getUserDisplayNameByUserId (userId, true), emojiName);
			emit onPostReactionUpdated (post);
			break;
		}
	}
}

QSet<const BackendUser*> BackendChannel::getAllMembers () const
{
	QSet<const BackendUser*> ret;

	for (auto& member: members) {
		ret.insert (member.user);
	}

	return ret;
}

} /* namespace Mattermost */


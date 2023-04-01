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
	postIdToPost[newPost->id] = newPost;
	return newPost;
}

void BackendChannel::addPost (const QJsonObject& postObject, std::list<BackendPost>::iterator position, ChannelNewPostsChunk& currentChunk, QVector<QPair<QString, QString>>& rootIdAndPostList, bool initialLoad)
{
	/*
	 * Add a post.
	 * And add added post to the list of new posts
	 */
	BackendPost* newPost = &*posts.emplace (position, postObject, storage);
	postIdToPost[newPost->id] = newPost;

	currentChunk.postsToAdd.emplace_front (newPost);

	QString rootId = postObject.value("root_id").toString();

	if (!rootId.isEmpty()) {
		rootIdAndPostList.push_back(QPair<QString,QString> (rootId, newPost->id));
	}

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

	QVector<QPair<QString, QString>> rootIdAndPostList;

	bool initialLoad = true;

	//add all posts to the beginning of the posts list
	for (const auto& newPostEl: orderArray) {
		QString newPostId = newPostEl.toString();
		addPost (postsObject.find (newPostId).value().toObject(), posts.begin (), currentNewPostsChunk, rootIdAndPostList, initialLoad);
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

	QVector<QPair<QString, QString>> rootIdAndPostList;

	/* Position to add new posts (if any)
	 * local posts are searched from newest to oldest
	 */
	std::list<BackendPost>::reverse_iterator currentLocalPost = posts.rbegin();

#warning "Handle case of deleted post, that is not deleted locally"

	bool initialLoad = (posts.empty());
	bool lastPostWasSkipped = false;

	for (const auto& newPostEl: orderArray) {

		/*
		 * Skip deleted posts.
		 * if a post is deleted, it will exist locally (with 'message deleted' text), but will not exist in the list of received posts.
		 * Deleted posts are not affected. They will not be present after client restart
		 */
		while (currentLocalPost != posts.rend() && currentLocalPost->isDeleted) {
			++currentLocalPost;
		}

		QString newPostId = newPostEl.toString();

		/*
		 * end of local posts list. Save the current missing post sequence and add all missing posts.
		 * This is the case when scrolling up and getting older posts.
		 */
		if (currentLocalPost == posts.rend()) {
			addPost (postsObject.find (newPostId).value().toObject(), posts.begin (), currentNewPostsChunk, rootIdAndPostList, initialLoad);
			++currentLocalPost;
			continue;
		}

		/*
		 * Compare new posts with existing ones. If there is a new post, mark it for adding.
		 */

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
		addPost (postsObject.find (newPostId).value().toObject(), currentLocalPost.base(), currentNewPostsChunk, rootIdAndPostList, initialLoad);
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

	/**
	 * Associate post with a root ID (if exists)
	 */
	for (auto& it: rootIdAndPostList) {
		QString& rootID = it.first;
		QString& postID = it.second;

		BackendPost* rootPost = findPostById (rootID);
		BackendPost* post = findPostById (postID);

		if (!rootPost) {
			LOG_DEBUG("root post " << rootID << " not found  (to be associated with post " << postID << ")");
			continue;
		}

		if (!post) {
			LOG_DEBUG("post " << postID << " not found (to be associated with root " << rootID << ")");
			continue;
		}

		LOG_DEBUG("post " << postID << " add root " << rootID << ")");
		post->rootPost = rootPost;
	}

	emit onNewPosts (allNewPosts);
}

void BackendChannel::addPinnedPosts (const QJsonArray& orderArray, const QJsonObject& postsObject)
{
	for (const auto& newPostEl: orderArray) {
		QString newPostId = newPostEl.toString();

		pinnedPosts.emplace_back (postsObject.find (newPostId).value().toObject(), storage);
	}

	if (!pinnedPosts.empty()) {
		emit onPinnedPostsReceived ();
	}
}

void BackendChannel::editPost (BackendPost& newPost)
{
	BackendPost* existingPost = findPostById (newPost.id);

	if (!existingPost) {
		LOG_DEBUG ("BackendChannel::editPost: post with ID " << newPost.id << " not found");
		return;
	}

	existingPost->updatePostEdits (newPost);
	emit onPostEdited (*existingPost);
}

void BackendChannel::addPostReaction (QString postId, QString userId, QString emojiName)
{
	BackendPost* existingPost = findPostById (postId);

	if (!existingPost) {
		LOG_DEBUG ("BackendChannel::addPostReaction: post with ID " << postId << " not found");
		return;
	}

	existingPost->addReaction (storage.getUserDisplayNameByUserId (userId, true), emojiName);
	emit onPostReactionUpdated (*existingPost);
}

void BackendChannel::removePostReaction (QString postId, QString userId, QString emojiName)
{
	BackendPost* existingPost = findPostById (postId);

	if (!existingPost) {
		LOG_DEBUG ("BackendChannel::addPostReaction: post with ID " << postId << " not found");
		return;
	}

	existingPost->removeReaction (storage.getUserDisplayNameByUserId (userId, true), emojiName);
	emit onPostReactionUpdated (*existingPost);
}

QSet<const BackendUser*> BackendChannel::getAllMembers () const
{
	QSet<const BackendUser*> ret;

	for (auto& member: members) {
		ret.insert (member.user);
	}

	return ret;
}

BackendPost* BackendChannel::findPostById (QString postID)
{
	auto it = postIdToPost.find (postID);

	if (it == postIdToPost.end()) {
		return nullptr;
	}

	return it.value();
}

} /* namespace Mattermost */


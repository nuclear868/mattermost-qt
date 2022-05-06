/**
 * @file BackendChannel.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 1, 2021
 */

#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>
#include "BackendChannel.h"
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

	last_post_at = jsonObject.value("last_post_at").toInt();
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
	posts.emplace_back (postObject);

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
	BackendPost* newPost = &*posts.emplace(position, postObject);
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
		while (currentLocalPost->isDeleted && currentLocalPost != posts.rend()) {
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

void BackendChannel::editPost (const QString& postID, const QString& postMessage)
{
	for (auto& post: posts) {
		if (post.id == postID) {
			post.message = postMessage;
			emit onPostEdited (post);
		}
	}
}

} /* namespace Mattermost */


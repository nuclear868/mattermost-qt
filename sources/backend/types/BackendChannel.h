/**
 * @file BackendChannel.h
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 1, 2021
 */

#pragma once

#include <QVariant>
#include <list>
#include "BackendPost.h"
#include "fwd.h"

class QJsonObject;

namespace Mattermost {

class Storage;

/**
 * A sequence of missing posts
 */
struct ChannelMissingPostsSequence {
	QString 									previousPostId;
	std::list<BackendPost*>						postsToAdd;
};

/**
 * Collections of missing posts for a channel.
 * Missing posts can happen if a webSocket disconnect occurs and new posts arrive before reconnect
 */
struct ChannelMissingPosts {

	void addSequence (ChannelMissingPostsSequence&& seq);

	std::vector<ChannelMissingPostsSequence>		postsToAdd;
};


class BackendChannel: public QObject {
	Q_OBJECT
public:
	enum type {
		unknown,
		publicChannel,
		privateChannel,
		directChannel,
	};
	BackendChannel (Storage& storage, const QJsonObject& jsonObject);
	virtual ~BackendChannel ();
public:
	static uint32_t getChannelType (const QJsonObject& jsonObject);

	BackendPost* addPost (const QJsonObject& postObject);

	void addPost (const QJsonObject& postObject, std::list<BackendPost>::iterator position, ChannelMissingPostsSequence& currentSequence, bool initialLoad);

	void addPosts (const QJsonArray& orderArray, const QJsonObject& postsObject);

	void editPost (const QString& postID, const QString& postMessage);
signals:

	/**
	 * Called when a channel is being viewed, either from this or from another Mattermost instance.
	 * Same notification as Backend::onChannelViewed()
	 */
	void onViewed ();

	/**
	 * Called when new posts are received.
	 * Either after init or after WebSocket disconnect.
	 *
	 * @param posts Collection of the missing posts only
	 */
	void onNewPosts (const ChannelMissingPosts& collection);

	/**
	 * Called when a new post has arrived in the channel
	 * Same notification as Backend::onNewPost()
	 * @param post post
	 */
	void onNewPost (BackendPost& post);

	/**
	 * Called when a post is being edited
	 * @param postId postId
	 */
	void onPostEdited (BackendPost& post);

	/**
	 * Called when a post is being deleted
	 * @param postId postId
	 */
	void onPostDeleted (const QString& postId);

	/**
	 * Called when someone is typing in the channel.
	 * Typing notifications are sent ~every 5 seconds, while the user is typing
	 * @param user user, who is typing
	 */
	void onUserTyping (const BackendUser& user);

	/**
	 * Called when there were missed posts - for example, because of a disconnect
	 */
	void onMissedPosts ();

	/**
	 * Called when the user is removed from the channel, or has left the channel
	 */
	void onLeave ();
public:
	const Storage&		storage;
    QString				id;
    uint64_t			create_at;
    uint64_t			update_at;
    uint64_t			delete_at;
    BackendTeam*		team;
    QString				display_name;
    QString				name;
    QString				header;
    QString				purpose;
    int					type;
    int					last_post_at;
    int					total_msg_count;
    int					extra_update_at;
    const BackendUser*	creator;
    QVariant			scheme_id;
    QVariant			props;
    uint32_t			referenceCount;

    std::list<BackendPost>	posts;
};

} /* namespace Mattermost */


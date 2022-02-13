/**
 * @file BackendChannel.h
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 1, 2021
 */

#pragma once

#include <QJsonObject>
#include <QVariant>
#include <list>
#include "BackendPost.h"

namespace Mattermost {

class BackendChannel: public QObject {
	Q_OBJECT
public:
	enum type {
		unknown,
		publicChannel,
		privateChannel,
		directChannel,
	};
	BackendChannel (const QJsonObject& jsonObject);
	virtual ~BackendChannel ();
signals:

	/**
	 * Called when a channel is being viewed, either from this or from another Mattermost instance.
	 * Same notification as Backend::onChannelViewed()
	 */
	void onViewed ();

	/**
	 * Called when a new post has arrived in the channel
	 * Same notification as Backend::onNewPost()
	 * @param post post
	 */
	void onNewPost (BackendPost& post);

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
public:
    QString			id;
    uint64_t		create_at;
    uint64_t		update_at;
    uint64_t		delete_at;
    QString			team_id;
    QString			display_name;
    QString			name;
    QString			header;
    QString			purpose;
    int				type;
    int				last_post_at;
    int				total_msg_count;
    int				extra_update_at;
    QString			creator_id;
    QVariant		scheme_id;
    QVariant		props;
    uint32_t		referenceCount;

    std::list<BackendPost>	posts;
};

} /* namespace Mattermost */


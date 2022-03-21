/**
 * @file Backend.h
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 11, 2021
 */

#pragma once

#include <QNetworkCookie>
#include <QObject>
#include <QList>

#include "backend/types/BackendLoginData.h"
#include "backend/HTTPConnector.h"
#include "backend/WebSocketConnector.h"
#include "backend/WebSocketEventHandler.h"
#include "backend/Storage.h"

namespace Mattermost {

class Backend: public QObject
{
    Q_OBJECT
public:
	explicit Backend (QObject *parent = nullptr);

	void reset ();

	//login to server (/users/login)
	void login (const BackendLoginData& loginData, std::function<void(const QString&)> callback);

	//login retry - after a HTTP error
	void loginRetry ();

	//logout (/users/logout)
	void logout (std::function<void ()> callback);

	//get specific user (/users/userID);
	void retrieveUser (QString userID, std::function<void(BackendUser&)> callback);

	//get count of all users in the system (users/stats)
	void retrieveTotalUsersCount (std::function<void(uint32_t)> callback);

	//get all users (/users?per_page=200&page=pageIdx);
	void retrieveAllUsers ();

	//get user's avatar image (/users/userID/image). Emits BackendUser::onAvatarChanged
	void retrieveUserAvatar (QString userID);

	//get file (files/fileID)
	void retrieveFile (QString fileID, std::function<void(const QByteArray&)> callback);

	//get own teams (/users/me/teams)
	void retrieveOwnTeams (std::function<void(BackendTeam&)> callback);

	//get a team (/teams/teamID)
	void retrieveTeam (QString teamID);

	//get own channel memberships (/users/me/teams/teamID/channels)
	void retrieveOwnChannelMemberships (BackendTeam& team, std::function<void(BackendChannel&)> callback);

	//get own channel memberships from all teams (/users/me/channel_members)
	//void retrieveOwnAllChannelMemberships (std::function<void()> callback);

	//get team members (/teams/teamID/members)
	void retrieveTeamMembers (BackendTeam& team);

	//get a channel (/channels/channelID)
	void retrieveChannel (BackendTeam& team, QString channelID);

	//get posts in a channel (/channels/ID/posts)
	void retrieveChannelPosts (BackendChannel& channel, int page, int perPage);

	//get first unread post in a channel (/users/{user_id}/channels/{channel_id}/posts/unread)
	void retrieveChannelUnreadPost (BackendChannel& channel, std::function<void(const QString&)> responseHandler);

	//mark the channel as viewed (/channels/members/me/view), so that the server knows that the channel is viewed
	void markChannelAsViewed (BackendChannel& channel);

	//add new post in a channel (/posts)
	void addPost (BackendChannel& channel, const QString& message, const QList<QString>& attachments = QList<QString> (), const QString& rootID = "");

	//delete a post (/posts/{post_id})
	void deletePost (const QString postID);

	//pin a post (/posts/{post_id}/pin)
	void pinPost (const QString postID);

	//upload a file, to be added to a post (/files)
	void uploadFile (BackendChannel& channel, const QString& filePath, std::function<void(QString)> responseHandler);

	const BackendUser& getLoginUser () const;

	Storage& getStorage ();
signals:

	/**
	 * Called when unread posts for a channel are received at startup
	 * @param channel
	 */
	void onUnreadPostsAtStartup (const BackendChannel&);


	/**
	 * Called when a channel is being viewed, either from this or from another Mattermost instance
	 * @param channel channel
	 */
	void onChannelViewed (const BackendChannel& channel);

	/**
	 * Called when new post arrives. Same notification as Channel::onNewPost
	 * @param channel channel, in which the post was added
	 * @param post post
	 */
	void onNewPost (BackendChannel& channel, const BackendPost& post);
    void onAllUsers ();

    /**
     * Called when all public and direct channels for all teams are received and filled in storage
     */
    void onAllTeamChannelsPopulated (BackendTeam& directChannels);

    /**
     * Called when the logged-in user was added to a team.
     * In most cases this is a new team
     * @param team
     */
	void onAddedToTeam (BackendTeam&);

    void onNetworkError (uint32_t errorNumber, const QString& errorText);
    void onHttpError (uint32_t errorNumber, const QString& errorText);
private:
    void loginSuccess (const QByteArray& data, const QNetworkReply& reply, std::function<void(const QString&)> callback);
private:
    Storage							storage;

    HTTPConnector 					httpConnector;
    WebSocketEventHandler			webSocketEventHandler;
    WebSocketConnector				webSocketConnector;
    BackendLoginData				loginData;
    bool							isLoggedIn;
    uint32_t						nonFilledTeams;
};

} /* namespace Mattermost */


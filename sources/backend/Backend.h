/**
 * @file Backend.h
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 11, 2021
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

#include <QNetworkCookie>
#include <QObject>
#include <QList>
#include <QNetworkDiskCache>

#include "backend/types/BackendLoginData.h"
#include "backend/HTTPConnector.h"
#include "backend/WebSocketConnector.h"
#include "backend/WebSocketEventHandler.h"
#include "backend/Storage.h"
#include "backend/ServerDialogsMap.h"

namespace Mattermost {

class BackendNewPollData;

class Backend: public QObject
{
    Q_OBJECT
public:
	explicit Backend (QObject *parent = nullptr);

	bool autoLoginEnabled ();

	void reset ();

	//login to server (/users/login)
	void login (const BackendLoginData& loginData, std::function<void(const QString&)> callback);

	//login retry - after a HTTP error
	void loginRetry ();

	//logout (/users/logout)
	void logout (std::function<void ()> callback);

	//get specific user (/users/userID)
	void retrieveUser (QString userID, std::function<void(const BackendUser&)> callback);

	//get user's preferences (/users/{user_id}/preferences)
	void retrieveUserPreferences ();

	void updateUserPreferences (const BackendUserPreferences& preferences);

	//get user's status (/users/status/ids)
	void retrieveMultipleUsersStatus (QVector<QString> userIDs, std::function<void()> callback);

	//get count of all users in the system (users/stats)
	void retrieveTotalUsersCount (std::function<void(uint32_t)> callback);

	//get all users (/users?per_page=200&page=pageIdx);
	void retrieveAllUsers ();

	//get user's avatar image (/users/userID/image). Emits BackendUser::onAvatarChanged
	void retrieveUserAvatar (QString userID, uint64_t lastUpdateTime = 0);

	//get file (files/fileID)
	void retrieveFile (QString fileID, std::function<void(const QByteArray&)> callback);

	//get own teams (/users/me/teams)
	void retrieveOwnTeams (std::function<void(BackendTeam&)> callback);

	//get a team (/teams/teamID)
	void retrieveTeam (QString teamID);

	//get all public channels for a team (/teams/teamID/channels)
	void retrieveTeamPublicChannels (QString teamID, std::function<void(std::list<BackendChannel>&)> callback);

	//get own channel memberships (/users/me/teams/teamID/channels)
	void retrieveOwnChannelMembershipsForTeam (BackendTeam& team, std::function<void(BackendChannel&)> callback);

	//get own channel memberships from all teams (/users/me/channel_members)
	//void retrieveOwnAllChannelMemberships (std::function<void()> callback);

	//get team members (/teams/teamID/members)
	void retrieveTeamMembers (BackendTeam& team, int page = 0);

	//get a channel (/channels/channelID)
	void retrieveChannel (BackendTeam& team, QString channelID);
	void retrieveDirectChannel (QString channelID);

	//get posts in a channel (/channels/{channel_id}/posts)
	void retrieveChannelPosts (BackendChannel& channel, int page, int perPage);

	//get channel's pinned posts (/channels/{channel_id}/pinned)
	void retrieveChannelPinnedPosts (BackendChannel& channel);

	//get older posts in a channel (before the first one) (/channels/ID/posts)
	void retrieveChannelOlderPosts (BackendChannel& channel, int perPage);

	//get first unread post in a channel (/users/{user_id}/channels/{channel_id}/posts/unread)
	void retrieveChannelUnreadPost (BackendChannel& channel, std::function<void(const QString&)> responseHandler);

	//get all channel members (/channels/{channel_id}/members)
	void retrieveChannelMembers (BackendChannel& channel, std::function<void ()> callback);

	//get a single channel member (/channels/{channel_id}/members/{user_id})
	void retrieveChannelMember (BackendChannel& channel, const BackendUser& user, std::function<void ()> callback);

	//get poll metadata (/plugins/com.github.matterpoll.matterpoll/api/v1/polls/{poll_id}/metadata)
	void retrievePollMetadata (BackendPoll& poll);

	//mark the channel as viewed (/channels/members/me/view), so that the server knows that the channel is viewed
	void markChannelAsViewed (BackendChannel& channel);

	//edit channel properties (PUT /channels/{channel_id})
	void editChannelProperties (BackendChannel& channel, const BackendChannelProperties& newProperties);

	//add new post in a channel (/posts)
	void addPost (BackendChannel& channel, const QString& message, const QList<QString>& attachments, const QString& rootID = "");

	//edit post (/posts/{post_id}/patch)
	void editPost (const QString& postID, const QString& message, const QList<QString>& attachments);

	//delete a post (/posts/{post_id})
	void deletePost (const QString postID);

	//pin a post (/posts/{post_id}/pin)
	void pinPost (const QString postID);

	//add a poll (/actions/dialogs/submit /plugins/com.github.matterpoll.matterpoll/api/v1/polls/create)
	void addPoll (BackendChannel& channel, const BackendNewPollData& pollData);

	//add a reaction to a post (/reactions)
	void addPostReaction (const QString& postID, const QString& emojiName);

	//send a post action (/posts/{post_id}/actions/{action})
	void sendPostAction (const BackendPost& post, const QString& action);

	//upload a file, to be added to a post (/files)
	void uploadFile (BackendChannel& channel, const QString& filePath, std::function<void(QString)> responseHandler);

	//create a direct channel with given user (/channels/direct)
	void createDirectChannel (const BackendUser& user);

	//add a user to a channel (/channels/{channel_id}/members)
	void addUserToChannel (const BackendChannel& channel, const QString& userID);

	//remove a user from a channel (/channels/{channel_id}/members/{user_id})
	void removeUserFromChannel (const BackendChannel& channel, const QString& userID);

	//join a channel (addUserToChannel for loginUser)
	void joinChannel (const BackendChannel& channel);

	//leave a channel (/channels/{channel_id}/members/{user_id})
	void leaveChannel (const BackendChannel& channel);

	//add a user to a team (/teams/{team_id}/members)
	void addUserToTeam (const BackendTeam& team, const QString& userID);

	//remove a user from a team (/teams/{team_id}/members/{user_id})
	void removeUserFromTeam (const BackendTeam& team, const QString& userID);

	//send a submit dialog response. In most cases, dialogs are handled by the UI
	void sendSubmitDialog (const QJsonDocument& json);

	//retrieve custom emojis (/emoji)
	void retrieveCustomEmojis ();

	//retrieve custom emojis (/emoji/{emoji_id}/image)
	void retrieveCustomEmojiImage (const QString& emojiID, std::function <void(QByteArray)> callback);

	const BackendUser& getLoginUser () const;

	void setCurrentChannel (BackendChannel& channel);

	BackendChannel* getCurrentChannel () const;

	Storage& getStorage ();

	ServerDialogsMap& getServerDialogsMap ();
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
    void onAllTeamChannelsPopulated ();

    /**
     * Called when the logged-in user was added to a team.
     * In most cases this is a new team
     * @param team
     */
	void onAddedToTeam (BackendTeam&);

    void onNetworkError (uint32_t errorNumber, const QString& errorText);
    void onHttpError (uint32_t errorNumber, const QString& errorText);

    void onWebSocketConnect ();
    void onWebSocketDisconnect ();
private:
    void loginSuccess (const QJsonDocument& data, const QNetworkReply& reply, std::function<void(const QString&)> callback);
private:
    Storage							storage;
    ServerDialogsMap				serverDialogsMap;

    HTTPConnector 					httpConnector;
    WebSocketEventHandler			webSocketEventHandler;
    WebSocketConnector				webSocketConnector;
    BackendLoginData				loginData;
    QNetworkDiskCache				attachmentsCache;
    BackendChannel*					currentChannel;
    QTimer 							timeoutTimer;
    bool							isLoggedIn;
    bool							autoLoginEnabledFlag;
    uint32_t						nonFilledTeams;
    uint64_t						lastStartTime;
};

} /* namespace Mattermost */


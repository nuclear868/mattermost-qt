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
#include "backend/Storage.h"

namespace Mattermost {

class Backend: public QObject
{
    Q_OBJECT
public:
    explicit Backend (QObject *parent = nullptr);

    //login to server (/users/login)
    void login (const BackendLoginData& loginData, std::function<void()> callback);

    //get specific user (/users/userID);
    void getUser (QString userID, std::function<void(BackendUser&)> callback);

    //get count of all users in the system (users/stats)
    void getTotalUsersCount (std::function<void(uint32_t)> callback);

    //get all users (/users?per_page=200&page=pageIdx);
    void getAllUsers ();

    //get user's image (/users/userID/image)
    void getUserImage (QString userID, std::function<void(QByteArray&)> callback);

    //get file (files/fileID)
    void getFile (QString fileID, std::function<void(QByteArray&)> callback);

    //get own teams (/users/me/teams)
    void getOwnTeams (std::function<void(QMap<QString, BackendTeam>&)> callback);

    //get a team (/teams/teamID)
    void getTeam (QString teamID);

    //get own channel memberships (/users/me/teams/teamID/channels)
    void getOwnChannelMemberships (BackendTeam& team, std::function<void(QList<BackendChannel*>&)> callback);

    QList<BackendChannel*>& getDirectChannels ();

    //get own channel memberships from all teams (/users/me/channel_members)
    //void getOwnAllChannelMemberships (std::function<void()> callback);

    //get team members (/teams/teamID/members)
    void getTeamMembers (BackendTeam& team);

    //get posts in a channel (/channels/ID/posts)
    void getChannelPosts (BackendChannel& channel, int page, int perPage, std::function<void()> responseHandler);

    //get first unread post in a channel (/users/{user_id}/channels/{channel_id}/posts/unread)
    void getChannelUnreadPost (BackendChannel& channel, std::function<void(const QString&)> responseHandler);

    //add new post in a channel (/posts)
    void addPost (BackendChannel& channel, const QString& message, const QString& rootID = "");

    //upload a file, to be added to a post (/files)
    void uploadFile (BackendChannel& channel, const QString& filePath, std::function<void(QString)> responseHandler);

	const BackendUser& getLoginUser () const;

    Storage& getStorage ();
signals:
	void onNewTeam (BackendTeam&);

	/**
	 * Called when unread posts for a channel are received at startup
	 * @param channel
	 */
	void onUnreadPostsAtStartup (const BackendChannel&);

	/**
	 * Called when the logged-in user has left a team
	 * @param team
	 */
	void onLeaveTeam (BackendTeam&);
    void onAllUsers ();

    /**
     * Called when all public and direct channels for all teams are received and filled in storage
     */
    void onAllTeamChannelsPopulated ();
    void onHttpError (uint32_t errorNumber, const QString& errorText);
    void onNetworkError (uint32_t errorNumber, const QString& errorText);
private:
    Storage							storage;

    HTTPConnector 					httpConnector;
    WebSocketConnector				webSocketConnector;
};

} /* namespace Mattermost */

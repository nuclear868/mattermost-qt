/**
 * @file Backend.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 11, 2021
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

#include "Backend.h"

#include <iostream>
#include <QtWebSockets/QWebSocket>
#include <QNetworkCookie>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "QByteArrayCreator.h"
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QSettings>
#include <QDebug>
#include <QList>

#include "NetworkRequest.h"
#include "types/BackendPoll.h"
#include "log.h"

/**
 * Get number of 'containers' needed for 'total' items, if each container
 * can hold 'capacity' items. For example, getting page count
 */
#define CONTAINER_COUNT(total,capacity) (!(total)?0:((total)-1)/(capacity)+1)

namespace Mattermost {

Backend::Backend(QObject *parent)
:QObject (parent)
,serverDialogsMap (*this)
,webSocketEventHandler (*this)
,webSocketConnector (webSocketEventHandler)
,currentChannel (nullptr)
,isLoggedIn (false)
,autoLoginEnabledFlag (true)
,nonFilledTeams (0)
{
	connect (&webSocketConnector, &WebSocketConnector::onReconnect, [this] {
		LOG_DEBUG ("Reconnect - check for missed posts");
		for (auto& it: storage.channels) {
			retrieveChannelPosts (*it, 0, 25);
		}
	});

	connect (&httpConnector, &HTTPConnector::onNetworkError, this, &Backend::onNetworkError);

	connect (&httpConnector, &HTTPConnector::onHttpError, [this] (uint32_t errorNumber, const QString& errorText) {

		emit onHttpError (errorNumber, errorText);

		if (errorNumber == 401) {
			if (isLoggedIn) { //invalid session, login again
				QTimer::singleShot (1000, [this] {
					httpConnector.reset ();
					webSocketConnector.reset ();
					loginRetry ();
					exit (1);
				});
			} else {
				NetworkRequest::clearToken ();
			}
		}
	});
}

void debugRequest (const QNetworkRequest& request, QByteArray data = QByteArray())
{
  qDebug() << request.url().toString();
  const QList<QByteArray>& rawHeaderList(request.rawHeaderList());
  foreach (QByteArray rawHeader, rawHeaderList) {
    qDebug() << rawHeader << ":"  << request.rawHeader(rawHeader);
  }
  qDebug() << data;
}

void Backend::login (const BackendLoginData& loginData, std::function<void(const QString&)> callback)
{
	this->loginData = loginData;
	NetworkRequest::setHost (loginData.domain);

	if (!loginData.token.isEmpty()) {

		NetworkRequest::setToken (loginData.token);
		NetworkRequest request ("users/me");

		httpConnector.get (request, HttpResponseCallback ([this, callback](const QJsonDocument& data, const QNetworkReply& reply) {
			loginSuccess (data, reply, callback);
		}));


#if 0
		NetworkRequest request1 ("users/me/preferences");

		httpConnector.get (request1, [this, callback](QVariant, QByteArray data, const QNetworkReply& reply) {
			QJsonDocument doc = QJsonDocument::fromJson(data);

			QString jsonString = doc.toJson(QJsonDocument::Indented);
			LOG_DEBUG (jsonString);
		});
#endif

		return;
	}

	QJsonDocument  json;
	QJsonObject  jsonRoot;

	jsonRoot.insert("login_id", loginData.username);
	jsonRoot.insert("password", loginData.password);
	//jsonRoot.insert("device_id", "QT Client");
#if 0
	if (!token.isEmpty())
		jsonRoot.insert("token", token);
#endif
	json.setObject(jsonRoot);

	NetworkRequest request ("users/login");

	//debugRequest (request, data);

	httpConnector.post (request, json, HttpResponseCallback ([this, callback](const QJsonDocument& data, const QNetworkReply& reply) {
		loginSuccess (data, reply, callback);
	}));
}

void Backend::loginRetry ()
{
	if (!loginData.token.isEmpty()) {

		NetworkRequest::setToken (loginData.token);
		NetworkRequest request ("users/me");

		debugRequest (request);

		httpConnector.get (request, HttpResponseCallback ([this](QVariant, QByteArray, const QNetworkReply&) {
			webSocketConnector.open (NetworkRequest::host() + "api/v4/", loginData.token);
			isLoggedIn = true;
			//loginSuccess (data, reply, [this] (const QString& token) {
		//	});
		}));

		return;
	}

	LOG_DEBUG ("Login retry - no token");
}

void Backend::setCurrentChannel (BackendChannel& channel)
{
	currentChannel = &channel;
}

BackendChannel* Backend::getCurrentChannel () const
{
	return currentChannel;
}

bool Backend::autoLoginEnabled ()
{
	return autoLoginEnabledFlag;
}

void Backend::loginSuccess (const QJsonDocument& doc, const QNetworkReply& reply, std::function<void (const QString&)> callback)
{
#if 1
	QString jsonString = doc.toJson(QJsonDocument::Indented);
	std::cout << "loginUser: " << jsonString.toStdString() << std::endl;
#endif
	BackendUser* loginUser = storage.addUser (doc.object(), true);
	loginUser->isLoginUser = true;

	if (NetworkRequest::getToken().isEmpty()) {
		NetworkRequest::setToken (reply.rawHeader ("Token"));
	}

	if (NetworkRequest::getToken().isEmpty()) {
		qCritical() << "Login Token is empty. WebSocket communication may not work";
	}

	webSocketConnector.open (NetworkRequest::host() + "api/v4/", NetworkRequest::getToken());
	isLoggedIn = true;
	retrieveUserPreferences ();
	retrieveCustomEmojis ();
	callback (NetworkRequest::getToken());
}

void Backend::reset ()
{
	isLoggedIn = false;

	/*
	 * This is important. Disconnect all signals. Added lambda functions are not removed when
	 * objects are destroyed
	 */
	disconnect ();
	NetworkRequest::clearToken ();

	//reinit all network connectors
	timeoutTimer.disconnect ();
	httpConnector.reset ();
	webSocketConnector.close ();
	storage.reset ();
	nonFilledTeams = 0;
}

void Backend::logout (std::function<void ()> callback)
{
	NetworkRequest request ("users/logout");
	isLoggedIn = false;

	//when logging out manually, disable the autologin
	autoLoginEnabledFlag = false;

	timeoutTimer.setSingleShot (true);
	connect (&timeoutTimer, &QTimer::timeout, [this, callback] {
		LOG_DEBUG ("Logout timeout");
		reset ();
		callback ();
	});

	timeoutTimer.start (1000);

	httpConnector.post (request, QByteArray(), HttpResponseCallback ([this, callback] (const QJsonDocument& doc) {
		LOG_DEBUG ("Logout done");

		timeoutTimer.stop();
		reset ();

		QString jsonString = doc.toJson(QJsonDocument::Indented);
		qDebug () << jsonString;
		callback ();
	}));
}

void Backend::retrieveUser (QString userID, std::function<void (BackendUser&)> callback)
{
	NetworkRequest request ("users/" + userID);

	httpConnector.get (request, HttpResponseCallback ([this, callback](const QJsonDocument& doc) {

		LOG_DEBUG ("getUser reply");

		QString jsonString = doc.toJson(QJsonDocument::Indented);
		//std::cout << "get users reply: " << statusCode.toInt() << std::endl;

		BackendUser *user = storage.addUser (doc.object());
		retrieveUserAvatar (user->id);
		callback (*user);
	}));
}

void Backend::retrieveUserPreferences ()
{
	NetworkRequest request ("users/" + getLoginUser().id + "/preferences");

	httpConnector.get (request, HttpResponseCallback ([this](const QJsonDocument& doc) {

		LOG_DEBUG ("retrieveUserPreferences reply");

		QString jsonString = doc.toJson(QJsonDocument::Indented);
		//LOG_DEBUG ("retrieveUserPreferences reply: " << jsonString);
	}));
}

void Backend::updateUserPreferences (const BackendUserPreferences& preferences)
{
	NetworkRequest request ("users/" + getLoginUser().id + "/preferences");

	QJsonArray jsonArr;
	jsonArr.push_back (QJsonObject {
		{"user_id", getLoginUser().id},
		{"category", preferences.category},
		{"name", preferences.name},
		{"value", preferences.value},
	});

	httpConnector.put (request, jsonArr, HttpResponseCallback ([this](const QJsonDocument& doc) {

		QString jsonString = doc.toJson(QJsonDocument::Indented);
	}));
}

void Backend::retrieveMultipleUsersStatus (QVector<QString> userIDs, std::function<void ()> callback)
{
	QJsonArray userIDsJson;

	for (auto& id: userIDs) {
		userIDsJson.push_back (id);
	}

	NetworkRequest request ("users/status/ids");

	httpConnector.post (request, userIDsJson, HttpResponseCallback ([this, callback] (const QJsonDocument& doc) {

		LOG_DEBUG ("getStatus reply");

		for (const auto& element: doc.array()) {

			const QJsonObject& jsonObject = element.toObject();

			QString userId = jsonObject.value("user_id").toString();;

			BackendUser* user = storage.getUserById (userId);

			if (!user) {
				LOG_DEBUG ("retrieveMultipleUsersStatus: used with id '" << userId << "not found");
				continue;
			}

			user->status = jsonObject.value("status").toString();
			user->lastActivity = jsonObject.value("last_activity_at").toVariant().toULongLong();
		}

#if 0
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		qDebug() << "get user status reply: " << jsonString;
#endif
		callback ();
	}));
}


void Backend::retrieveTotalUsersCount (std::function<void(uint32_t)> callback)
{
	NetworkRequest request ("users/stats");

	httpConnector.get (request, HttpResponseCallback ([this, callback] (const QJsonDocument& doc) {

		LOG_DEBUG ("getTotalUsersCount reply");

		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << jsonString.toStdString() << std::endl;

		storage.totalUsersCount = doc.object().value("total_users_count").toInt();
		callback (storage.totalUsersCount);
	}));
}

void Backend::retrieveAllUsers ()
{
	uint32_t usersPerPage = 200;
	uint32_t totalPages = CONTAINER_COUNT (storage.totalUsersCount, usersPerPage);
	static uint32_t obtainedPages;

	for (uint32_t page = 0; page < totalPages; ++page) {
		NetworkRequest request ("users?per_page=" + QString::number(usersPerPage) + "&page=" + QString::number(page));

		httpConnector.get (request, HttpResponseCallback ([this, page, totalPages] (const QJsonDocument& doc) {

			LOG_DEBUG ("getAllUsers reply");

			QString jsonString = doc.toJson(QJsonDocument::Indented);
			//std::cout << "get users reply: " << statusCode.toInt() << std::endl;
			//std::cout << jsonString.toStdString() << std::endl;

			QVector<QString> userIds;
			userIds.reserve (200);

			for (const auto &itemRef: doc.array()) {
				BackendUser *user = storage.addUser (itemRef.toObject());
				retrieveUserAvatar (user->id);
				userIds.push_back (user->id);
			}

			retrieveMultipleUsersStatus (userIds, [] {
			});

			LOG_DEBUG ("Page " << page << " (" << obtainedPages << " of " << totalPages << "): users count " << storage.users.size());
		#if 0
			for (auto& user: users) {
				std::cout << user.id.toStdString() << " "
						<< user.first_name.toStdString() <<	" "
						<< user.last_name.toStdString() <<	" "
						<< user.username.toStdString() <<	" "
						<< std::endl;
			}
		#endif

			++obtainedPages;
			if (obtainedPages == totalPages) {
				emit onAllUsers ();
				LOG_DEBUG ("Get Users: Done ");
				obtainedPages = 0;
			}
		}));

	}
}

void Backend::retrieveUserAvatar (QString userID)
{
	NetworkRequest request ("users/" + userID + "/image", true);

	httpConnector.get (request, HttpResponseCallback ([this, userID] (QVariant, QByteArray data) {

		//LOG_DEBUG ("getUserImage reply");

		BackendUser* user = storage.getUserById (userID);

		if (!user) {
			qCritical() << "Get Image: user " << userID << " not found";
			return;
		}

		user->avatar = data;

		emit user->onAvatarChanged();
	}));
}

void Backend::retrieveFile (QString fileID, std::function<void (const QByteArray&)> callback)
{
	NetworkRequest request ("files/" + fileID, true);
	//request.setRawHeader("X-Requested-With", "XMLHttpRequest");

	httpConnector.get (request, HttpResponseCallback ([this, fileID, callback](QVariant, QByteArray data) {
		callback (data);
	}));
}

/**
 * Get a list of teams that a user is on.
 */
void Backend::retrieveOwnTeams (std::function<void(BackendTeam&)> callback)
{
    NetworkRequest request ("users/me/teams");
    //request.setRawHeader("X-Requested-With", "XMLHttpRequest");

    LOG_DEBUG ("retrieveOwnTeams request");

    httpConnector.get (request, HttpResponseCallback ([this, callback] (const QJsonDocument& doc) {
    	LOG_DEBUG ("retrieveOwnTeams reply");
		storage.teams.clear ();

#if 0
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << "get teams reply: "  << std::endl;
		std::cout << jsonString.toStdString() << std::endl;
#endif

		auto root = doc.array();
		for (const auto &itemRef: qAsConst(root)) {
			storage.addTeam (itemRef.toObject());
			++nonFilledTeams;
		}

		for (auto& team: storage.teams) {
			callback (team.second);
		}
    }));
}

void Backend::retrieveTeam (QString teamID)
{
	NetworkRequest request ("teams/" + teamID);

    std::cout << "get team " << teamID.toStdString() << std::endl;


    httpConnector.get (request, HttpResponseCallback ([this] (const QJsonDocument& doc) {
    	LOG_DEBUG ("getTeam reply");

#if 1
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << "get team reply: " <<  jsonString.toStdString() << std::endl;
#endif

		auto object = doc.object();
		BackendTeam *team = storage.addTeam (doc.object());

		if (team) {
			emit onAddedToTeam (*team);
		}
    }));
}


void Backend::retrieveTeamPublicChannels (QString teamID, std::function<void(std::list<BackendChannel>&)> callback)
{
	NetworkRequest request ("teams/" + teamID + "/channels");

    std::cout << "get team channels " << teamID.toStdString() << std::endl;

    httpConnector.get (request, HttpResponseCallback ([this, callback, teamID](QVariant, const QJsonDocument& doc) {
    	LOG_DEBUG ("getTeamChannels reply");

		BackendTeam* team = storage.getTeamById (teamID);

		if (!team) {
			return;
		}

		team->allPublicChannels.clear();

		for (const auto &item: doc.array()) {
			team->allPublicChannels.emplace_back (storage, item.toObject());
		}

#if 0
		QString jsonString = QJsonDocument::fromJson(data).toJson(QJsonDocument::Indented);
		std::cout << "get team channels reply: " <<  jsonString.toStdString() << std::endl;
#endif
		callback (team->allPublicChannels);
    }));
}

void Backend::retrieveOwnChannelMembershipsForTeam (BackendTeam& team, std::function<void(BackendChannel&)> callback)
{
    NetworkRequest request ("users/me/teams/" + team.id + "/channels");

    httpConnector.get (request, HttpResponseCallback ([this, &team, callback] (const QJsonDocument& doc) {
    	team.channels.clear ();

#if 0
    	QString jsonString = doc.toJson(QJsonDocument::Indented);
    	std::cout << "retrieveOwnChannelMembershipsForTeam reply: " <<  jsonString.toStdString() << std::endl;
#endif

    	LOG_DEBUG ("Team " << team.display_name << ":");
		for (const auto &itemRef: doc.array()) {

			const QJsonObject& channelObject = itemRef.toObject();
			uint32_t channelType = BackendChannel::getChannelType (channelObject);

			switch (channelType) {
			case BackendChannel::directChannel:
				storage.addDirectChannel (channelObject);
				break;
			case BackendChannel::groupChannel:
				storage.addGroupChannel (channelObject);
				break;
			default:
				storage.addTeamScopeChannel (team, channelObject);
				break;
			}
		}

		for (auto& channel: team.channels) {
			callback (*channel.get());
			LOG_DEBUG ("\tChannel added: " << channel->id << " " << channel->display_name);
		}

		--nonFilledTeams;

		if (nonFilledTeams == 0) {
			emit onAllTeamChannelsPopulated ();
		}
    }));
}

#if 0 //supported in Mattermost server 6.2
void Backend::retrieveOwnAllChannelMemberships (std::function<void ()> callback)
{
    QNetworkRequest request;

    request.setUrl(QUrl(httpHost + "users/me/channel_members?page=0&per_page=2"));
    request.setRawHeader("X-Requested-With", "XMLHttpRequest");

    httpConnector.get(request, [this, callback](QVariant, QByteArray data) {

    	QJsonDocument doc = QJsonDocument::fromJson(data);

    	QString jsonString = doc.toJson(QJsonDocument::Indented);
    	std::cout << "getOwnAllChannelMemberships reply: " <<  jsonString.toStdString() << std::endl;


		callback ();
    });
}
#endif

void Backend::retrieveTeamMembers (BackendTeam& team)
{
	NetworkRequest request ("teams/" + team.id + "/members");

	httpConnector.get(request, HttpResponseCallback ([this, &team] (const QJsonDocument& doc) {

		auto root = doc.array();
		for(const auto &itemRef: qAsConst(root)) {
			BackendTeamMember member (itemRef.toObject());
			member.user = storage.getUserById(member.user_id);
			team.members.append (std::move (member));
		}

		//LOG_DEBUG ("Team Members Count: " << team.members.size());
#if 0
		for (auto& it: team.members) {
			if (!it.user) {
				std::cout << "\t" << it.user_id.toStdString() << " (no user) " << std::endl;
			} else {
				std::cout << "\t" << it.user_id.toStdString() << " " << it.user->username.toStdString() << std::endl;
			}
		}
#endif
	}));
}

void Backend::retrieveChannel (BackendTeam& team, QString channelID)
{
	NetworkRequest request ("channels/" + channelID);

	LOG_DEBUG ("retrieveChannel " << channelID);

	httpConnector.get (request, HttpResponseCallback ([this, &team] (const QJsonDocument& doc) {
		LOG_DEBUG ("retrieveChannel reply");

#if 0
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << "retrieveChannel reply: " <<  jsonString.toStdString() << std::endl;
#endif

		BackendChannel* channel =  storage.addTeamScopeChannel (team, doc.object());
		LOG_DEBUG ("\tNew Channel added: " << channel->id << " " << channel->display_name);

		emit team.onNewChannel (*channel);
    }));
}

void Backend::retrieveDirectChannel (QString channelID)
{
	NetworkRequest request ("channels/" + channelID);

	LOG_DEBUG ("retrieveChannel " << channelID);

	httpConnector.get (request, HttpResponseCallback ([this] (const QJsonDocument& doc) {
		LOG_DEBUG ("retrieveChannel reply");

#if 0
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << "retrieveChannel reply: " <<  jsonString.toStdString() << std::endl;
#endif

		BackendChannel* channel =  storage.addDirectChannel (doc.object());
		LOG_DEBUG ("\tNew Channel added: " << channel->id << " " << channel->display_name);

		emit storage.directChannels.onNewChannel (*channel);

		/*
		 * The channel is created, but the official Mattermost client requires
		 * that the 'direct_channel_show' property is set for this channel,
		 * in order for the channel to be visible there
		 */
		updateUserPreferences(BackendUserPreferences {"direct_channel_show", channel->name, "true"});
    }));
}

void Backend::retrieveChannelPosts (BackendChannel& channel, int page, int perPage)
{
    NetworkRequest request ("channels/" + channel.id + "/posts?page=" + QString::number(page) + "&per_page=" + QString::number(perPage));

    httpConnector.get (request, HttpResponseCallback ([this, &channel](const QJsonDocument& doc) {

		LOG_DEBUG ("retrieveChannelPosts reply for " << channel.display_name << " (" << channel.id << ")");

#if 0
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << jsonString.toStdString() << std::endl;
#endif

		QJsonObject root = doc.object();
		channel.addPosts (root.value("order").toArray(), root.value("posts").toObject());
    }));
}

void Backend::retrieveChannelOlderPosts (BackendChannel& channel, int perPage)
{
    NetworkRequest request ("channels/" + channel.id + "/posts?page=" + QString::number(0) + "&per_page=" + QString::number(perPage) + "&before=" + channel.posts.front().id);

    httpConnector.get (request, HttpResponseCallback ([this, &channel](const QJsonDocument& doc) {

		LOG_DEBUG ("retrieveChannelOlderPosts reply for " << channel.display_name << " (" << channel.id << ") - since " << channel.posts.front().id);

#if 0
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << jsonString.toStdString() << std::endl;
#endif

		QJsonObject root = doc.object();
		channel.prependPosts (root.value("order").toArray(), root.value("posts").toObject());
    }));
}

void Backend::retrieveChannelUnreadPost (BackendChannel& channel, std::function<void (const QString&)> responseHandler)
{
	NetworkRequest request ("users/me/channels/" + channel.id + "/posts/unread?limit_before=0&limit_after=1");

    httpConnector.get (request, HttpResponseCallback ([this, &channel, responseHandler](const QJsonDocument& doc) {

    	//LOG_DEBUG ("getChannelUnreadPost reply for " << channel.display_name << " (" << channel.id << ")");

#if 0
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << jsonString.toStdString() << std::endl;
#endif

		QJsonObject root = doc.object();
		QString lastReadPost (root.value("prev_post_id").toString());

		if (!lastReadPost.isEmpty()) {
			responseHandler (lastReadPost);
			emit onUnreadPostsAtStartup (channel);
		} else {
			static QString emptyString ("");
			responseHandler (emptyString);
		}
    }));
}

void Backend::retrieveChannelMembers (BackendChannel& channel)
{
	NetworkRequest request ("channels/" + channel.id + "/members");

	httpConnector.get (request, HttpResponseCallback ([this, &channel](const QJsonDocument& doc) {

		//LOG_DEBUG ("retrieveChannelMembers reply");

		auto root = doc.array();
		for(const auto &itemRef: qAsConst(root)) {
			BackendChannelMember member (itemRef.toObject());
			member.user = storage.getUserById(member.user_id);
			channel.members.append (std::move (member));
		}

		//LOG_DEBUG ("Channel Members Count: " << channel.members.size());
#if 0
		for (auto& it: team.members) {
			if (!it.user) {
				std::cout << "\t" << it.user_id.toStdString() << " (no user) " << std::endl;
			} else {
				std::cout << "\t" << it.user_id.toStdString() << " " << it.user->username.toStdString() << std::endl;
			}
		}
#endif
	}));
}

void Backend::retrievePollMetadata (BackendPoll& poll)
{
	NetworkRequest request (NetworkRequest::matterpoll, "polls/" + poll.id + "/metadata");

	LOG_DEBUG ("retrievePollMetadata request");

	httpConnector.get (request, HttpResponseCallback ([this, &poll](const QJsonDocument& doc) {

		LOG_DEBUG ("retrievePollMetadata reply");

		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << jsonString.toStdString() << std::endl;

		poll.fillMetadata (doc.object());
	}));
}

void Backend::markChannelAsViewed (BackendChannel& channel)
{
	QJsonObject  json;

	json.insert ("channel_id", channel.id);

	//maybe add prev_channel_id, the Mattermost API supports it
	//json.insert ("prev_channel_id", channel.id);

	NetworkRequest request ("channels/members/me/view");

	httpConnector.post (request, json, HttpResponseCallback ([this](QVariant, QByteArray) {

		//no callbacks are required. the server will send a WebSocket packet 'channel_viewed'

#if 0
		QJsonDocument doc = QJsonDocument::fromJson(data);
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << jsonString.toStdString() << std::endl;
#endif

	}));
}

void Backend::editChannelProperties (BackendChannel& channel, const BackendChannelProperties& newProperties)
{
	QJsonObject  json {
		{"id", channel.id},
		{"name", channel.name},
		{"display_name", newProperties.displayName},
		{"purpose", newProperties.purpose},
		{"header", newProperties.header},
	};


	QString jsonString = QJsonDocument(json).toJson(QJsonDocument::Indented);
	std::cout << jsonString.toStdString() << std::endl;

	QByteArray data (QJsonDocument (json).toJson(QJsonDocument::Compact));

	NetworkRequest request ("channels/" + channel.id);
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

	httpConnector.put (request, data, HttpResponseCallback ([this](QVariant, QByteArray) {
#if 0
	QJsonDocument doc = QJsonDocument::fromJson(data);
	QString jsonString = doc.toJson(QJsonDocument::Indented);
	std::cout << "editChannelProperties" << jsonString.toStdString() << std::endl;
#endif

	}));
}

void Backend::addPost (BackendChannel& channel, const QString& message, const QList<QString>& attachments, const QString& rootID)
{
	QJsonArray files;

	for (auto& id: attachments) {
		files.push_back (id);
	}

	QJsonObject  json;

	json.insert ("channel_id", channel.id);
	json.insert ("message", message);

	if (!files.isEmpty()) {
		json.insert ("file_ids", files);
	}

	if (!rootID.isEmpty()) {
		json.insert ("root_id", rootID);
	}


	NetworkRequest request ("posts");

	httpConnector.post (request, json, HttpResponseCallback ([this](QVariant, QByteArray) {
#if 0
		QJsonDocument doc = QJsonDocument::fromJson(data);
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << jsonString.toStdString() << std::endl;
#endif
	}));
}

void Backend::editPost (const QString& postID, const QString& message, const QList<QString>* attachments)
{
	QJsonArray files;

	if (attachments) {
		for (auto& id: *attachments) {
			files.push_back (id);
		}
	}

	QJsonObject  json;

	json.insert ("message", message);

	if (!files.isEmpty()) {
		json.insert ("file_ids", files);
	}

	QString jsonString = QJsonDocument(json).toJson(QJsonDocument::Indented);
	std::cout << jsonString.toStdString() << std::endl;

    QByteArray data (QJsonDocument (json).toJson(QJsonDocument::Compact));

	NetworkRequest request ("posts/" + postID + "/patch");
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

	httpConnector.put (request, data, HttpResponseCallback ([this](const QJsonDocument& doc) {

#if 1
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << jsonString.toStdString() << std::endl;
#endif

	}));
}

void Backend::deletePost (const QString postID)
{
	NetworkRequest request ("posts/" + postID);

	httpConnector.del (request);
}

void Backend::pinPost (const QString postID)
{
}

void Backend::sendPostAction (const BackendPost& post, const QString& action)
{
	NetworkRequest request  ("posts/" + post.id + "/actions/" + action);

	httpConnector.post (request, QByteArray(), HttpResponseCallback ([this](const QJsonDocument& doc) {

#if 1
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << "sendPostAction reply: " << jsonString.toStdString() << std::endl;

		const QJsonObject& obj = doc.object();
		if (obj.value("status").toString() == "OK") {
			serverDialogsMap.addEvent (obj.value ("trigger_id").toString());
		}
#endif

	}));
}

void Backend::uploadFile (BackendChannel& channel, const QString& filePath, std::function<void (QString)> responseHandler)
{
	QFileInfo fileInfo (filePath);

	NetworkRequest request ("files?channel_id=" + channel.id + "&filename=" + fileInfo.fileName());
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/octet-stream");

	QFile file (filePath);

	if (!file.open(QIODevice::ReadOnly)) {
		qDebug() << "Cannot open file " << filePath;
		return;
	}

	QByteArray data = file.readAll();
	qDebug() << data.size();

	httpConnector.post (request, data, HttpResponseCallback ([this, responseHandler](QVariant, const QJsonDocument& doc) {

#if 1
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << jsonString.toStdString() << std::endl;
#endif

		QJsonObject root = doc.object();
		QJsonArray arr = root.value ("file_infos").toArray();

		if (arr.size() < 1) {
			return responseHandler ("");
		}

		responseHandler (arr.at(0).toObject().value("id").toString());
	}));
}

void Backend::createDirectChannel (const BackendUser& user)
{
	QJsonArray json {getLoginUser().id, user.id};

	NetworkRequest request ("channels/direct");

	httpConnector.post (request, json, HttpResponseCallback ([this, &user](QVariant, QByteArray) {
#if 0
		QJsonDocument doc = QJsonDocument::fromJson(data);

		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << jsonString.toStdString() << std::endl;
#endif
	}));
}

void Backend::addUserToChannel (const BackendChannel& channel, const QString& userID)
{
	QJsonObject json {
		{"user_id", userID}
	};

	NetworkRequest request ("channels/" + channel.id + "/members");

	httpConnector.post (request, json, HttpResponseCallback ([this](QVariant, QByteArray) {
#if 0
		QJsonDocument doc = QJsonDocument::fromJson(data);

		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << jsonString.toStdString() << std::endl;
#endif

	}));
}

void Backend::joinChannel (const BackendChannel& channel)
{
	return addUserToChannel (channel, getLoginUser().id);
}

void Backend::leaveChannel (const BackendChannel& channel)
{
	NetworkRequest request ("channels/" + channel.id + "/members/" + getLoginUser().id);

	httpConnector.del (request);
}

void Backend::addUserToTeam (const BackendTeam& team, const QString& userID)
{
	QJsonObject json {
		{"user_id", userID},
		{"team_id", team.id}
	};

	NetworkRequest request ("teams/" + team.id + "/members");

	httpConnector.post (request, json, HttpResponseCallback ([this](QVariant, QByteArray) {
#if 0
		QJsonDocument doc = QJsonDocument::fromJson(data);

		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << jsonString.toStdString() << std::endl;
#endif

	}));
}

void Backend::sendSubmitDialog (const QJsonDocument& json)
{
	QString jsonString = json.toJson(QJsonDocument::Indented);
	qDebug() << "SendSubmitDialog request: " << jsonString.toStdString().c_str();


	NetworkRequest request ("actions/dialogs/submit");
	httpConnector.post (request, json, HttpResponseCallback ([] (QVariant, QByteArray) {
#if 0
		QJsonDocument doc2 = QJsonDocument::fromJson(data);
		QString jsonString = doc2.toJson(QJsonDocument::Indented);
		qDebug() << "SendSubmitDialog reply: " << jsonString.toStdString().c_str();
#endif
	}));
}

void Backend::retrieveCustomEmojis ()
{
	NetworkRequest request ("emoji");
	httpConnector.get (request, HttpResponseCallback ([this] (QVariant, QJsonDocument data) {

#if 0
		QString jsonString = data.toJson(QJsonDocument::Indented);
		qDebug() << "retrieveCustomEmojis reply: " << jsonString.toStdString().c_str();
#endif

		for (const auto& it: data.array()) {
			QString emojiID = it.toObject().value("id").toString();
			QString emojiName = it.toObject().value("name").toString();
			retrieveCustomEmojiImage (emojiID, [emojiID, emojiName] (QByteArray data) {
				QString filename ("cache/custom-emoji/" + emojiID + ".png");

				QDir dir("cache/custom-emoji/");
				if (!dir.exists()) {
					dir.mkpath(".");
				}

				QFile file (filename);

				if (!file.open (QIODevice::WriteOnly)) {
					qDebug() << "retrieveCustomEmojiImage: Cannot open " << filename << ":" << file.errorString();
					return;
				}

				file.write (data);
				file.close ();
				EmojiMap::addCustomEmoji (emojiName, emojiID);
			});
		}
	}));
}

void Mattermost::Backend::retrieveCustomEmojiImage (const QString& emojiID, std::function <void (QByteArray)> callback)
{
	NetworkRequest request ("emoji/" + emojiID + "/image");
	httpConnector.get (request, HttpResponseCallback (callback));
}

const BackendUser& Backend::getLoginUser () const
{
	return *storage.loginUser;
}

Storage& Backend::getStorage ()
{
	return storage;
}

ServerDialogsMap& Backend::getServerDialogsMap ()
{
	return serverDialogsMap;
}

} /* namespace Mattermost */


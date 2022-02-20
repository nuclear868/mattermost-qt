/**
 * @file Backend.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 11, 2021
 */

#include "Backend.h"

#include <iostream>
#include <QtWebSockets/QWebSocket>
#include <QNetworkCookie>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QFileInfo>
#include <QSettings>
#include <QDebug>
#include <QList>

#include "NetworkRequest.h"
#include "log.h"

/**
 * Get number of 'containers' needed for 'total' items, if each container
 * can hold 'capacity' items. For example, getting page count
 */
#define CONTAINER_COUNT(total,capacity) (!(total)?0:((total)-1)/(capacity)+1)

namespace Mattermost {

Backend::Backend(QObject *parent)
:QObject (parent)
,webSocketEventHandler (*this)
,webSocketConnector (webSocketEventHandler)
,isLoggedIn (false)
,nonFilledTeams (0)
{
	connect (&webSocketConnector, &WebSocketConnector::onReconnect, [this] {
		LOG_DEBUG ("Reconnect - check for missed posts");
		for (auto& it: storage.channels) {
			retrieveChannelPosts (*it, 0, 200);
		}
	});

	connect (&httpConnector, &HTTPConnector::onNetworkError, this, &Backend::onNetworkError);

	connect (&httpConnector, &HTTPConnector::onHttpError, [this] (uint32_t errorNumber, const QString& errorText) {

		emit onHttpError (errorNumber, errorText);

		if (errorNumber == 401 && isLoggedIn) { //invalid session, login again
			QTimer::singleShot (1000, [this] {
				httpConnector.reset ();
				webSocketConnector.close();
				loginRetry ();
			});
		}
	});
}

void Backend::reset ()
{
	/*
	 * This is important. Disconnect all signals. Added lambda functions are not removed when
	 * objects are destroyed
	 */
	disconnect ();

	//reinit all network connectors
	httpConnector.reset ();
	webSocketConnector.close ();
	storage.reset ();
	nonFilledTeams = 0;
}

void debugRequest (const QNetworkRequest& request, QByteArray data = QByteArray())
{
  qDebug() << request.url().toString();
  const QList<QByteArray>& rawHeaderList(request.rawHeaderList());
  foreach (QByteArray rawHeader, rawHeaderList) {
    qDebug() << request.rawHeader(rawHeader);
  }
  qDebug() << data;
}

void Backend::login (const BackendLoginData& loginData, std::function<void()> callback)
{
	this->loginData = loginData;
	NetworkRequest::setHost (loginData.domain);

	QJsonDocument  json;
	QJsonObject  jsonRoot;

	jsonRoot.insert("login_id", loginData.username);
	jsonRoot.insert("password", loginData.password);
	jsonRoot.insert("device_id", "QT Client");
#if 0
	if (!token.isEmpty())
		jsonRoot.insert("token", token);
#endif
	json.setObject(jsonRoot);
	QByteArray data = json.toJson(QJsonDocument::Compact);

	NetworkRequest request ("users/login");
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
	//request.setRawHeader("X-Requested-With", "XMLHttpRequest");

	//debugRequest (request, data);

	httpConnector.post(request, data, [this, callback](QVariant, QByteArray data, const QNetworkReply& reply) {
		QJsonDocument doc = QJsonDocument::fromJson(data);

#if 0
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << "loginUser: " << jsonString.toStdString() << std::endl;
#endif
		BackendUser* loginUser = storage.addUser (doc.object(), true);
		loginUser->isLoginUser = true;

		QString loginToken = reply.rawHeader ("Token");
		NetworkRequest::setToken (loginToken);

		if (loginToken.isEmpty()) {
			qCritical() << "Login Token is empty. WebSocket communication may not work";
		}

		webSocketConnector.open (NetworkRequest::host(), loginToken);
		isLoggedIn = true;
		callback ();
	});
}

void Backend::loginRetry ()
{
	NetworkRequest::clearToken ();

	QJsonDocument  json;
	QJsonObject  jsonRoot;

	LOG_DEBUG ("Login retry");

	jsonRoot.insert("login_id", loginData.username);
	jsonRoot.insert("password", loginData.password);
	jsonRoot.insert("device_id", "QT Client");
#if 0
	if (!token.isEmpty())
		jsonRoot.insert("token", token);
#endif
	json.setObject(jsonRoot);
	QByteArray data = json.toJson(QJsonDocument::Compact);

	NetworkRequest request ("users/login");
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

	//debugRequest (request, data);

	httpConnector.post(request, data, [this](QVariant, QByteArray data, const QNetworkReply& reply) {
		QJsonDocument doc = QJsonDocument::fromJson(data);

		LOG_DEBUG ("Login retry successful");

#if 0
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << "loginUser: " << jsonString.toStdString() << std::endl;
#endif
		//storage.loginUser = BackendUser (doc.object());

		//callback ();

		QString loginToken = reply.rawHeader ("Token");
		NetworkRequest::setToken (loginToken);

		if (loginToken.isEmpty()) {
			qCritical() << "Login Token is empty. WebSocket communication may not work";
		}

		webSocketConnector.open (NetworkRequest::host(), loginToken);
		isLoggedIn = true;
	});
}

void Backend::logout (std::function<void ()> callback)
{
	NetworkRequest request ("users/logout");
	isLoggedIn = false;

	httpConnector.post (request, QByteArray(), [callback] (QVariant, QByteArray data) {
		LOG_DEBUG ("Logout done");

		QJsonDocument doc = QJsonDocument::fromJson(data);
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		qDebug () << jsonString;
		callback ();
	});
}

void Backend::retrieveUser (QString userID, std::function<void (BackendUser&)> callback)
{
	NetworkRequest request ("users/" + userID);

	httpConnector.get(request, [this, callback](QVariant, QByteArray data) {

		LOG_DEBUG ("getUser reply");

		QJsonDocument doc = QJsonDocument::fromJson(data);

		QString jsonString = doc.toJson(QJsonDocument::Indented);
		//std::cout << "get users reply: " << statusCode.toInt() << std::endl;

		BackendUser *user = storage.addUser (doc.object());
		callback (*user);
	});
}

void Backend::retrieveTotalUsersCount (std::function<void(uint32_t)> callback)
{
	NetworkRequest request ("users/stats");

	httpConnector.get(request, [this, callback](QVariant, QByteArray data) {

		LOG_DEBUG ("getTotalUsersCount reply");

		QJsonDocument doc = QJsonDocument::fromJson(data);

		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << jsonString.toStdString() << std::endl;

		storage.totalUsersCount = doc.object().value("total_users_count").toInt();
		callback (storage.totalUsersCount);
	});
}

void Backend::retrieveAllUsers ()
{
	uint32_t usersPerPage = 200;
	uint32_t totalPages = CONTAINER_COUNT (storage.totalUsersCount, usersPerPage);
	static uint32_t obtainedPages;

	for (uint32_t page = 0; page < totalPages; ++page) {
		NetworkRequest request ("users?per_page=" + QString::number(usersPerPage) + "&page=" + QString::number(page));

		httpConnector.get(request, [this, page, totalPages](QVariant, QByteArray data) {

			LOG_DEBUG ("getAllUsers reply");

			QJsonDocument doc = QJsonDocument::fromJson(data);

			QString jsonString = doc.toJson(QJsonDocument::Indented);
			//std::cout << "get users reply: " << statusCode.toInt() << std::endl;
			//std::cout << jsonString.toStdString() << std::endl;

			for (const auto &itemRef: doc.array()) {
				BackendUser *user = storage.addUser (itemRef.toObject());
				retrieveUserAvatar (user->id);
			}

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
		});

	}
}

void Backend::retrieveUserAvatar (QString userID)
{
	NetworkRequest request ("users/" + userID + "/image", true);

	httpConnector.get(request, [this, userID] (QVariant, QByteArray data) {

		//LOG_DEBUG ("getUserImage reply");

		BackendUser* user = storage.getUserById (userID);

		if (!user) {
			qCritical() << "Get Image: user " << userID << " not found";
			return;
		}

		user->avatar = data;

		emit user->onAvatarChanged();
	});
}

void Backend::retrieveFile (QString fileID, std::function<void (const QByteArray&)> callback)
{
	NetworkRequest request ("files/" + fileID, true);
	//request.setRawHeader("X-Requested-With", "XMLHttpRequest");

	httpConnector.get(request, [this, fileID, callback](QVariant, QByteArray data) {
		callback (data);
	});
}

/**
 * Get a list of teams that a user is on.
 */
void Backend::retrieveOwnTeams (std::function<void(BackendTeam&)> callback)
{
    NetworkRequest request ("users/me/teams");
    //request.setRawHeader("X-Requested-With", "XMLHttpRequest");

    std::cout << "get teams" << std::endl;

    httpConnector.get(request, [this, callback](QVariant, QByteArray data) {
    	LOG_DEBUG ("getOwnTeams reply");
		storage.teams.clear ();

		QJsonDocument doc = QJsonDocument::fromJson(data);

#if 0
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << "get teams reply: " << statusCode.toInt() << std::endl;
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
    });
}

void Backend::retrieveTeam (QString teamID)
{
	NetworkRequest request ("teams/" + teamID);

    std::cout << "get team " << teamID.toStdString() << std::endl;

    httpConnector.get(request, [this](QVariant, QByteArray data) {
    	LOG_DEBUG ("getTeam reply");

		QJsonDocument doc = QJsonDocument::fromJson(data);

#if 1
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << "get team reply: " <<  jsonString.toStdString() << std::endl;
#endif

		auto object = doc.object();
		BackendTeam *team = storage.addTeam (doc.object());

		emit onAddedToTeam (*team);
    });
}

void Backend::retrieveOwnChannelMemberships (BackendTeam& team, std::function<void(BackendChannel&)> callback)
{
    NetworkRequest request ("users/me/teams/" + team.id + "/channels");

    httpConnector.get(request, [this, &team, callback](QVariant, QByteArray data) {
    	team.channels.clear ();

    	QJsonDocument doc = QJsonDocument::fromJson(data);

#if 0
    	QString jsonString = doc.toJson(QJsonDocument::Indented);
    	std::cout << "getOwnChannelMemberships reply: " <<  jsonString.toStdString() << std::endl;
#endif

    	LOG_DEBUG ("Team " << team.display_name << ":");
		for (const auto &itemRef: doc.array()) {
			BackendChannel* channel =  storage.addChannel (team, itemRef.toObject());
			LOG_DEBUG ("\tChannel added: " << channel->id << " " << channel->display_name);
		}

		for (auto& channel: team.channels) {
			callback (*channel.get());
		}

		--nonFilledTeams;

		if (nonFilledTeams == 0) {
			emit onAllTeamChannelsPopulated (storage.directChannels);
		}
    });
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

	httpConnector.get(request, [this, &team](QVariant, QByteArray data) {

		LOG_DEBUG ("getTeamMembers reply");

		QJsonDocument doc = QJsonDocument::fromJson(data);

		auto root = doc.array();
		for(const auto &itemRef: qAsConst(root)) {
			BackendTeamMember member;
			member.deserialize (itemRef.toObject());
			member.user = storage.getUserById(member.user_id);
			team.members.append (std::move (member));
		}

		LOG_DEBUG ("Team Members Count: " << team.members.size());
#if 0
		for (auto& it: team.members) {
			if (!it.user) {
				std::cout << "\t" << it.user_id.toStdString() << " (no user) " << std::endl;
			} else {
				std::cout << "\t" << it.user_id.toStdString() << " " << it.user->username.toStdString() << std::endl;
			}
		}
#endif
	});
}

void Backend::retrieveChannel (BackendTeam& team, QString channelID)
{
	NetworkRequest request ("channels/" + channelID);

	LOG_DEBUG ("retrieveChannel " << channelID);

	httpConnector.get(request, [this, &team](QVariant, QByteArray data) {
		LOG_DEBUG ("retrieveChannel reply");

		QJsonDocument doc = QJsonDocument::fromJson(data);

#if 1
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << "retrieveChannel reply: " <<  jsonString.toStdString() << std::endl;
#endif

		BackendChannel* channel =  storage.addChannel (team, doc.object());
		LOG_DEBUG ("\tChannel added: " << channel->id << " " << channel->display_name);

		emit team.onNewChannel (*channel);
#if 0
		auto object = doc.object();
		BackendTeam *team = storage.addTeam (doc.object());

		emit onAddedToTeam (*team);
#endif
    });
}

void Backend::retrieveChannelPosts (BackendChannel& channel, int page, int perPage)
{
    NetworkRequest request ("channels/" + channel.id + "/posts?page=" + QString::number(page) + "&per_page=" + QString::number(perPage));

    httpConnector.get(request, [this, &channel](QVariant, QByteArray data) {

    	LOG_DEBUG ("getChannelPosts reply for " << channel.display_name << " (" << channel.id << ")");

		QJsonDocument doc = QJsonDocument::fromJson(data);

#if 0
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << jsonString.toStdString() << std::endl;
#endif

		QJsonObject root = doc.object();
		channel.addPosts (root.value("order").toArray(), root.value("posts").toObject());
    });
}

void Backend::retrieveChannelUnreadPost (BackendChannel& channel, std::function<void (const QString&)> responseHandler)
{
	NetworkRequest request ("users/me/channels/" + channel.id + "/posts/unread?limit_before=0&limit_after=1");

    httpConnector.get(request, [this, &channel, responseHandler](QVariant, QByteArray data) {

    	//LOG_DEBUG ("getChannelUnreadPost reply for " << channel.display_name << " (" << channel.id << ")");

		QJsonDocument doc = QJsonDocument::fromJson(data);

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
    });
}

void Backend::markChannelAsViewed (BackendChannel& channel)
{
	QJsonObject  json;

	json.insert ("channel_id", channel.id);

	//maybe add prev_channel_id, the Mattermost API supports it
	//json.insert ("prev_channel_id", channel.id);

	QByteArray data (QJsonDocument (json).toJson(QJsonDocument::Compact));

	NetworkRequest request ("channels/members/me/view");
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

	httpConnector.post(request, data, [this](QVariant, QByteArray data) {
		QJsonDocument doc = QJsonDocument::fromJson(data);

		//no callbacks are required. the server will send a WebSocket packet 'channel_viewed'

#if 0
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << jsonString.toStdString() << std::endl;
#endif

	});
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

    QByteArray data (QJsonDocument (json).toJson(QJsonDocument::Compact));

	NetworkRequest request ("posts");
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

	httpConnector.post(request, data, [this](QVariant, QByteArray data) {
		QJsonDocument doc = QJsonDocument::fromJson(data);

#if 0
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << jsonString.toStdString() << std::endl;
#endif

	});
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

	httpConnector.post(request, data, [this, responseHandler](QVariant, QByteArray data) {
		QJsonDocument doc = QJsonDocument::fromJson(data);

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
	});
}

const BackendUser& Backend::getLoginUser () const
{
	return *storage.loginUser;
}

Storage& Backend::getStorage ()
{
	return storage;
}

} /* namespace Mattermost */


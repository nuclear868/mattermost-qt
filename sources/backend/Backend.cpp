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
:QObject(parent)
{
	connect (&httpConnector, &HTTPConnector::onNetworkError, this, &Backend::onNetworkError);
	connect (&httpConnector, &HTTPConnector::onHttpError, this, &Backend::onHttpError);

	connect (&webSocketConnector, &WebSocketConnector::onChannelViewed, [this](const ChannelViewedEvent& event) {
		BackendChannel* channel = storage.getChannelById (event.channel_id);
		QString channelName = channel ? channel->name : event.channel_id;
		LOG_DEBUG ("Channel viewed: " << channelName);
	});

	connect (&webSocketConnector, &WebSocketConnector::onAddedToTeam, [this](const UserTeamEvent& event) {
		BackendTeam* team = storage.getTeamById (event.team_id);
		QString teamName = team ? team->name : event.team_id;
		LOG_DEBUG ("User " << event.user_id << " added to team: " << teamName);

		//Adds the new team. It's channels and messages in channels will be obtained too
		if (!team) {
			getTeam (event.team_id);
		}
	});

	connect (&webSocketConnector, &WebSocketConnector::onUserAdded, [this](const UserTeamEvent& event) {
		BackendTeam* team = storage.getTeamById (event.team_id);
		QString teamName = team ? team->name : event.team_id;
		LOG_DEBUG ("User " << event.user_id << " added: " << teamName);
	});

	connect (&webSocketConnector, &WebSocketConnector::onLeaveTeam, [this](const UserTeamEvent& event) {
		BackendTeam* team = storage.getTeamById (event.team_id);
		QString teamName = team ? team->name : event.team_id;

		LOG_DEBUG ("User " << event.user_id << " left team: " << teamName);
		emit (onLeaveTeam (*team));

		storage.eraseTeam (team->id);
		//printTeams ();
	});

	connect (&webSocketConnector, &WebSocketConnector::onPost, [this](PostEvent& event) {
		BackendTeam* team = storage.getTeamById (event.team_id);
		QString teamName = team ? team->name : event.team_id;

		auto& post = event.post;

		BackendChannel* channel = storage.getChannelById (event.post.channel_id);

		if (!channel) {
			return;
		}

		QString channelName = channel ? channel->name : event.post.channel_id;

		for (auto& file: post.files) {
			getFile (file->id, [&file] (QByteArray& data) {
				file->contents = data;
				emit file->onContentsAvailable();
			});
		}

		post.author = storage.getUserById (post.user_id);

		LOG_DEBUG ("Post in  '" << teamName << "' : '" << channelName << "' by " << event.post.user_id << ": " << event.post.message);
		if (channel) {
			emit channel->onNewPost (post);
			//emit onNewPost (*channel, event.post);
		}

		channel->posts.append (std::move (post));
	});

	connect (&webSocketConnector, &WebSocketConnector::onTyping, [this](const TypingEvent& event) {
		BackendChannel* channel = storage.getChannelById(event.channel_id);

		BackendUser* user = storage.getUserById (event.user_id);

		if (!user || !channel) {
			//return;
		}
		//LOG_DEBUG ("User " << event.user_id << " left team: " << teamName);
		emit (channel->onUserTyping(*user));
	});
}

void Backend::login (const BackendLoginData& loginData, std::function<void()> callback)
{
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

	httpConnector.post(request, data, [this, callback](QVariant, QByteArray data, const QNetworkReply& reply) {
		QJsonDocument doc = QJsonDocument::fromJson(data);

#if 0
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << "loginUser: " << jsonString.toStdString() << std::endl;
#endif
		storage.loginUser = BackendUser (doc.object());

		callback ();

		QString loginToken = reply.rawHeader ("Token");
		NetworkRequest::setToken (loginToken);

		if (loginToken.isEmpty()) {
			qCritical() << "Login Token is empty. WebSocket communication may not work";
		}

		webSocketConnector.open (NetworkRequest::host(), loginToken);
	});
}

void Backend::getUser (QString userID, std::function<void (BackendUser&)> callback)
{
	NetworkRequest request ("users/" + userID);

	httpConnector.get(request, [this, callback](QVariant, QByteArray data) {

		LOG_DEBUG ("getUser reply");

		QJsonDocument doc = QJsonDocument::fromJson(data);

		QString jsonString = doc.toJson(QJsonDocument::Indented);
		//std::cout << "get users reply: " << statusCode.toInt() << std::endl;
		//std::cout << jsonString.toStdString() << std::endl;

		BackendUser user (doc.object());
		QString newUserId (user.id);

		if (newUserId == getLoginUser ().id) {
			user.isLoginUser = true;
		}

		LOG_DEBUG ("got user " << user.id);
		storage.users[user.id] = std::move (user);

		callback (*storage.getUserById(newUserId));
	});
}

void Backend::getTotalUsersCount (std::function<void(uint32_t)> callback)
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

void Backend::getAllUsers ()
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
				BackendUser user (itemRef.toObject());
				getUserImage (user.id, [](QByteArray&){});

				if (user.id == getLoginUser().id) {
					user.isLoginUser = true;

		#if 0
					QJsonDocument doc1 (itemRef.toObject());
					QString jsonString = doc1.toJson(QJsonDocument::Indented);
					std::cout << "me: " << jsonString.toStdString() << std::endl;
		#endif
				}

				storage.users[user.id] = std::move (user);
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
			}
		});

	}

}

void Backend::getUserImage (QString userID, std::function<void(QByteArray&)> callback)
{
	NetworkRequest request ("users/" + userID + "/image");

	httpConnector.get(request, [this, userID, callback](QVariant, QByteArray data) {

		//LOG_DEBUG ("getUserImage reply");

		BackendUser* user = storage.getUserById (userID);

		if (!user) {
			qCritical() << "Get Image: user " << userID << " not found";
			return;
		}

		user->avatar = data;
		callback (user->avatar);
	});
}

void Backend::getFile (QString fileID, std::function<void (QByteArray&)> callback)
{
	NetworkRequest request ("files/" + fileID);
	//request.setRawHeader("X-Requested-With", "XMLHttpRequest");

	httpConnector.get(request, [this, fileID, callback](QVariant, QByteArray data) {
		callback (data);
	});
}

/**
 * Get a list of teams that a user is on.
 */
void Backend::getOwnTeams (std::function<void(QMap<QString, BackendTeam>&)> callback)
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
			BackendTeam team;
			team.deserialize (itemRef.toObject());
			storage.teams[team.id] = team;
		}

		callback (storage.teams);
    });
}

void Backend::getTeam (QString teamID)
{
    QNetworkRequest request ("teams/" + teamID);

    std::cout << "get team " << teamID.toStdString() << std::endl;

    httpConnector.get(request, [this](QVariant, QByteArray data) {
    	LOG_DEBUG ("getTeam reply");

		QJsonDocument doc = QJsonDocument::fromJson(data);

#if 1
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << "get team reply: " <<  jsonString.toStdString() << std::endl;
#endif

		auto object = doc.object();
		BackendTeam team;
		team.deserialize (object);
		storage.teams[team.id] = team;

		emit onNewTeam (storage.teams[team.id]);
    });
}

void Backend::getOwnChannelMemberships (BackendTeam& team, std::function<void(QList<BackendChannel*>&)> callback)
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
			BackendChannel* channel = new BackendChannel (itemRef.toObject());
			LOG_DEBUG ("\tChannel added: " << channel->id << " " << channel->display_name);
			storage.addChannel (team, channel);
		}

		callback (team.channels);
    });
}

#if 0 //supported in Mattermost server 6.2
void Backend::getOwnAllChannelMemberships (std::function<void ()> callback)
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

void Backend::getTeamMembers (BackendTeam& team)
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

void Backend::getChannelPosts (BackendChannel& channel, int page, int perPage, std::function<void()> responseHandler)
{
    NetworkRequest request ("channels/" + channel.id + "/posts?page=" + QString::number(page) + "&per_page=" + QString::number(perPage));

    //LOG_DEBUG ("getChannelPosts request for " << channel.display_name << " (" << channel.id << ")");

    httpConnector.get(request, [this, &channel, responseHandler](QVariant, QByteArray data) {

    	LOG_DEBUG ("getChannelPosts reply for " << channel.display_name << " (" << channel.id << ")");

		QJsonDocument doc = QJsonDocument::fromJson(data);

#if 0
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << jsonString.toStdString() << std::endl;
#endif

		QJsonObject root = doc.object();
		QJsonObject posts_item = root.value("posts").toObject();

		for (const auto &orderItemRef: root.value("order").toArray()) {
			auto order_id = orderItemRef.toString();
			auto item = posts_item.find(order_id).value().toObject();

			BackendPost post;
			post.deserialize (item);

			for (auto& file: post.files) {
				getFile (file->id, [&file] (QByteArray& data) {
					file->contents = data;
					emit file->onContentsAvailable();
				});
			}

			post.author = storage.getUserById (post.user_id);
			channel.posts.prepend (std::move (post));
			//qDebug() << post.create_at << post.author->username << " " << post.message;
		}

		responseHandler ();
    });
}

void Backend::getChannelUnreadPost (BackendChannel& channel, std::function<void (const QString&)> responseHandler)
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
		}
 //
//		for (const auto &orderItemRef: root.value("order").toArray()) {
//			auto order_id = orderItemRef.toString();
//			auto item = posts_item.find(order_id).value().toObject();
//
//			BackendPost post;
//			post.deserialize (item);
//
//			for (auto& file: post.files) {
//				getFile (file->id, [&file] (QByteArray& data) {
//					file->contents = data;
//					emit file->onContentsAvailable();
//				});
//			}
//
//			post.author = storage.getUserById (post.user_id);
//			channel.posts.prepend (std::move (post));
//			//qDebug() << post.create_at << post.author->username << " " << post.message;
//		}
//
//		responseHandler ();
    });
}

void Backend::addPost (BackendChannel& channel, const QString& message, const QString& rootID)
{
#if 0
	QJsonArray files;
	files.push_back ("jbyk3u3zp3ggumk8m3je48ad6w");
#endif

	QJsonObject  json;

	json.insert ("channel_id", channel.id);
	json.insert ("message", message);
	//json.insert ("file_ids", files);

	if (!rootID.isEmpty()) {
		json.insert ("root_id", rootID);
	}

    QByteArray data (QJsonDocument (json).toJson(QJsonDocument::Compact));

	NetworkRequest request ("posts");
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

	httpConnector.post(request, data, [this](QVariant, QByteArray data, const QNetworkReply& reply) {
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

	httpConnector.post(request, data, [this](QVariant, QByteArray data, const QNetworkReply& reply) {
		QJsonDocument doc = QJsonDocument::fromJson(data);

#if 1
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << jsonString.toStdString() << std::endl;
#endif

	});
}

const BackendUser& Backend::getLoginUser () const
{
	return storage.loginUser;
}

QList<BackendChannel*>& Backend::getDirectChannels ()
{
	return storage.directChannels;
}

Storage& Backend::getStorage ()
{
	return storage;
}

} /* namespace Mattermost */


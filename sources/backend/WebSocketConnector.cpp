/**
 * @file WebSocketConnector.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 28, 2021
 */

#include "WebSocketConnector.h"

#include <iostream>
#include <QJsonDocument>
#include <QJsonObject>

#include "backend/WebSocketEventHandler.h"
#include "log.h"

namespace Mattermost {

static const QMap<QString, std::function<void(WebSocketConnector&, const QJsonObject&, const QJsonObject&)>> eventHandlers {
	{"hello", [] (WebSocketConnector& conn, const QJsonObject&, const QJsonObject&) {
		std::cout << "Hello" << std::endl;
	}},
	{"channel_viewed", [] (WebSocketConnector& conn, const QJsonObject& data, const QJsonObject& broadcast) {
		conn.eventHandler.handleEvent (ChannelViewedEvent (data));
	}},

	{"posted", [] (WebSocketConnector& conn, const QJsonObject& data, const QJsonObject& broadcast) {
		conn.eventHandler.handleEvent (PostEvent (data, broadcast));
	}},

	{"typing", [] (WebSocketConnector& conn, const QJsonObject& data, const QJsonObject& broadcast) {
		conn.eventHandler.handleEvent (TypingEvent (data, broadcast));
	}},

	//post deleted
	{"post_deleted", [] (WebSocketConnector& conn, const QJsonObject& data, const QJsonObject& broadcast) {
		conn.eventHandler.handleEvent (PostDeletedEvent (data, broadcast));
	}},

	//user added to channel
	{"user_added", [] (WebSocketConnector& conn, const QJsonObject& data, const QJsonObject&) {
		conn.eventHandler.handleEvent (UserAddedEvent (data));
	}},

	//user added to team
	{"added_to_team", [] (WebSocketConnector& conn, const QJsonObject& data, const QJsonObject&) {
		conn.eventHandler.handleEvent (UserAddedToTeamEvent (data));
	}},

	//a user has left a team
	{"leave_team", [] (WebSocketConnector& conn, const QJsonObject& data, const QJsonObject&) {
		conn.eventHandler.handleEvent (UserLeaveTeamEvent (data));
	}},

	//a user (the logged-in user, or someone else) was removed from a channel
	{"user_removed", [] (WebSocketConnector& conn, const QJsonObject& data, const QJsonObject& broadcast) {
		conn.eventHandler.handleEvent (UserRemovedFromChannelEvent (data, broadcast));
	}},

	//a new channel was created
	{"channel_created", [] (WebSocketConnector& conn, const QJsonObject& data, const QJsonObject&) {
		conn.eventHandler.handleEvent (ChannelCreatedEvent (data));
	}},
};

WebSocketConnector::WebSocketConnector (WebSocketEventHandler& eventHandler)
:eventHandler (eventHandler)
,hasReconnect (false)
{
	connect (&webSocket, qOverload<QAbstractSocket::SocketError>(&QWebSocket::error), [this] (QAbstractSocket::SocketError error){
		qDebug() << "WebSocket error " << error << " " << webSocket.errorString();

	});

	connect(&webSocket, &QWebSocket::connected, [this] {
		LOG_DEBUG ("WebSocket connected");
		doHandshake ();

		if (hasReconnect) {
			emit onReconnect ();
		}

		hasReconnect = false;
		pingTimer.start (5000);
	});

	connect(&webSocket, &QWebSocket::pong, [this]{
		//LOG_DEBUG ("WebSocket pong");
		pongTimer.stop();
	});

	connect(&webSocket, &QWebSocket::disconnected, [this]{
		LOG_DEBUG ("WebSocket disconnected: " << webSocket.closeCode() << " " << webSocket.closeReason());
		pingTimer.stop();
		pongTimer.stop();
		QTimer::singleShot (2000, [this] {
			LOG_DEBUG ("WebSocket Reconnecting");
			hasReconnect = true;
			webSocket.open (webSocket.requestUrl());
		});
	});

    connect(&webSocket, &QWebSocket::textMessageReceived, this, &WebSocketConnector::onNewPacket);

    connect (&pingTimer, &QTimer::timeout, [this] {
		//LOG_DEBUG ("WebSocket send ping");
		webSocket.ping ("ping");
		pongTimer.start (4000);
	});

    pongTimer.setSingleShot (true);
    connect (&pongTimer, &QTimer::timeout, [this] {
		LOG_DEBUG ("WebSocket ping timeout. Reconnecting");
		webSocket.close();
	});
}

WebSocketConnector::~WebSocketConnector ()
{
	// TODO Auto-generated destructor stub
}

void WebSocketConnector::open (const QString& urlString, const QString& token)
{
	QUrl url (urlString + "websocket");
	url.setScheme("wss");

	//qDebug() << "WebSocket open: " << url;

	this->token = token;
	webSocket.open (url);
}

void WebSocketConnector::doHandshake ()
{
	QJsonObject  jsonData {
		{"token",token},
	};

	QJsonDocument json (QJsonObject {
		{"seq", 1},
		{"action", "authentication_challenge"},
		{"data", jsonData},
	});

	QByteArray data = json.toJson(QJsonDocument::Compact);
	webSocket.sendBinaryMessage(data);
}

void WebSocketConnector::close ()
{
	webSocket.close(QWebSocketProtocol::CloseCodeNormal, "Client Close");
}

void WebSocketConnector::onNewPacket (const QString& string)
{
	QJsonDocument doc = QJsonDocument::fromJson(string.toUtf8());


	const QJsonObject& jsonObject = doc.object();

	//reply of sent packet
	QJsonValue seqReply = jsonObject.value("seq_reply");

	if (!seqReply.isUndefined()) {
		std::cout << "got seqReply " << seqReply.toInt() << std::endl;
		return;
	}

	//event from server
	QJsonValue event = jsonObject.value("event");

	auto it = eventHandlers.find(event.toString());

	QString jsonString = doc.toJson(QJsonDocument::Indented);
	std::cout << jsonString.toStdString();
	if (it == eventHandlers.end()) {
		LOG_DEBUG ("Unhandled WebSocket event '" << event.toString() << "'\n");
		qDebug() << "========" << '\n';
		return;
	}

	it.value() (*this, 	jsonObject.value ("data").toObject(),
						jsonObject.value ("broadcast").toObject());

	qDebug() << "========" << '\n';

//	if (obj.value("seq_reply")) {
//
//	}
}

} /* namespace Mattermost */


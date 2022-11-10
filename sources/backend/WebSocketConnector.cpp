/**
 * @file WebSocketConnector.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 28, 2021
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

#include "WebSocketConnector.h"

#include <iostream>
#include <QJsonDocument>
#include <QJsonObject>

#include "backend/WebSocketEventHandler.h"
#include "log.h"

namespace Mattermost {

static const QMap<QString, std::function<void(WebSocketConnector&, const QJsonObject&, const QJsonObject&)>> eventHandlers {
	{"hello", [] (WebSocketConnector&, const QJsonObject&, const QJsonObject&) {
		std::cout << "Hello" << std::endl;
	}},
	{"channel_viewed", [] (WebSocketConnector& conn, const QJsonObject& data, const QJsonObject&) {
		conn.eventHandler.handleEvent (ChannelViewedEvent (data));
	}},

	{"posted", [] (WebSocketConnector& conn, const QJsonObject& data, const QJsonObject& broadcast) {
		conn.eventHandler.handleEvent (PostEvent (data, broadcast));
	}},

	//post edited
	{"post_edited", [] (WebSocketConnector& conn, const QJsonObject& data, const QJsonObject& broadcast) {
		conn.eventHandler.handleEvent (PostEditedEvent (data, broadcast));
	}},

	//post deleted
	{"post_deleted", [] (WebSocketConnector& conn, const QJsonObject& data, const QJsonObject& broadcast) {
		conn.eventHandler.handleEvent (PostDeletedEvent (data, broadcast));
	}},

	//post reaction added
	{"reaction_added", [] (WebSocketConnector& conn, const QJsonObject& data, const QJsonObject& broadcast) {
		conn.eventHandler.handleEvent (PostReactionAddedEvent (data, broadcast));
	}},

	{"typing", [] (WebSocketConnector& conn, const QJsonObject& data, const QJsonObject& broadcast) {
		conn.eventHandler.handleEvent (TypingEvent (data, broadcast));
	}},

	//new direct channel created
	{"direct_added", [] (WebSocketConnector& conn, const QJsonObject& data, const QJsonObject& broadcast) {
		conn.eventHandler.handleEvent (NewDirectChannelEvent (data, broadcast));
	}},

	//user added to channel
	{"user_added", [] (WebSocketConnector& conn, const QJsonObject& data, const QJsonObject& broadcast) {
		conn.eventHandler.handleEvent (UserAddedToChannelEvent (data, broadcast));
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

	//a channel was updated
	{"channel_updated", [] (WebSocketConnector& conn, const QJsonObject& data, const QJsonObject&) {
		conn.eventHandler.handleEvent (ChannelUpdatedEvent (data));
	}},

	//a server-side dialog
	{"open_dialog", [] (WebSocketConnector& conn, const QJsonObject& data, const QJsonObject&) {
		conn.eventHandler.handleEvent (OpenDialogEvent (data));
	}},
};

WebSocketConnector::WebSocketConnector (WebSocketEventHandler& eventHandler)
:eventHandler (eventHandler)
,hasReconnect (false)
{
	connect (&webSocket, qOverload<QAbstractSocket::SocketError>(&QWebSocket::error), [this] (QAbstractSocket::SocketError error){
		qDebug() << "WebSocket error " << error << " " << webSocket.errorString();
		doReconnect ();
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
		doReconnect ();
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

WebSocketConnector::~WebSocketConnector () = default;

void WebSocketConnector::open (const QString& urlString, const QString& token)
{
	QUrl url (urlString + "websocket");
	url.setScheme("wss");

	//qDebug() << "WebSocket open: " << url << " " << token;

	this->token = token;
	webSocket.open (url);
}

void WebSocketConnector::close ()
{
	token = "";
	reset ();
}

void WebSocketConnector::doReconnect ()
{
	pingTimer.stop();
	pongTimer.stop();
	QTimer::singleShot (2000, [this] {

		if (token.isEmpty()) {
			return;
		}

		LOG_DEBUG ("WebSocket Reconnecting");
		hasReconnect = true;
		webSocket.open (webSocket.requestUrl());
	});
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
	webSocket.sendTextMessage (data);
}

void WebSocketConnector::reset ()
{
	webSocket.close(QWebSocketProtocol::CloseCodeNormal, "Client Close");
}

static bool printEvent (const QString& name)
{
	if (name == "channel_viewed" || name == "channel_updated") {
		return false;
	}

	return true;
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


	if (it == eventHandlers.end()) {
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << jsonString.toStdString();

		LOG_DEBUG ("Unhandled WebSocket event '" << event.toString() << "'\n");
		qDebug() << "========" << '\n';
		return;
	}

	if (printEvent (it.key())) {
	qDebug() << "========" << '\n';
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << jsonString.toStdString();
	}

	it.value() (*this, 	jsonObject.value ("data").toObject(),
						jsonObject.value ("broadcast").toObject());


//	if (obj.value("seq_reply")) {
//
//	}
}

} /* namespace Mattermost */


/**
 * @file WebSocketConnector.h
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 28, 2021
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

#include <QObject>
#include <QTimer>
#include <QtWebSockets/QWebSocket>

namespace Mattermost {

class WebSocketEventHandler;

class WebSocketConnector: public QObject {
	Q_OBJECT
public:
	WebSocketConnector (WebSocketEventHandler& eventHandler);
	virtual ~WebSocketConnector ();
public:
	void open (const QString& urlString, const QString& token);
	void close ();
	void reset ();
	void doHandshake ();
signals:
	void onConnect (bool isReconnect);
	void onDisconnect ();
private:
	void onNewPacket (const QString& string);
	void doReconnect ();
public:
	WebSocketEventHandler	&eventHandler;
private:
	QWebSocket 				webSocket;
	QString					token;
	QTimer					pingTimer;
	QTimer					pongTimer;
	bool					hasReconnect;
};

} /* namespace Mattermost */


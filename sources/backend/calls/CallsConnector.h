/**
 * @file CallsConnector.h
 * @brief Manages Mattermost calls
 * @author Lyubomir Filipov
 * @date Aug 3, 2022
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

#pragma once

#include <QObject>
#include <QString>
#include <QTimer>
#include <QtWebSockets/QWebSocket>

namespace rtc {
	class PeerConnection;
};

namespace Mattermost {

class CallsConnector: public QObject {
	Q_OBJECT
public:
	CallsConnector (QString ICEServer, const QString& urlString, const QString& token);
	virtual ~CallsConnector ();
public:
	void openWebSocket (const QString& channelID);
	int64_t sendTextMessage(const QString& message);
	int64_t sendBinaryMessage(const QByteArray& message);
	std::shared_ptr<rtc::PeerConnection> createPeerConnection ();

	void onRemoteCandidate (const QString& candidateString);
	void onRemoteAnswer (const QString& answerSdp);
signals:
	void onReconnect ();
private:
	void doHandshake ();
	void onNewPacket (const QString& string);
	void doReconnect ();
public:
	QString 		ICEServer;
	QString			channelID;
	uint32_t		seq;
	const QString&	urlString;
	const QString&	token;
	QWebSocket 		webSocket;
	QTimer			pingTimer;
	QTimer			pongTimer;
	QTimer			bindTimer;
	bool			hasReconnect;
};

} /* namespace Mattermost */

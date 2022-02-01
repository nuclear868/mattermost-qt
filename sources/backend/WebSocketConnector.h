/**
 * @file WebSocketConnector.h
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 28, 2021
 */

#pragma once

#include <QObject>
#include <QTimer>
#include <QtWebSockets/QWebSocket>
#include "events/ChannelViewedEvent.h"
#include "events/PostEvent.h"
#include "events/UserTeamEvent.h"
#include "events/TypingEvent.h"

namespace Mattermost {

class WebSocketConnector: public QObject {
	Q_OBJECT
public:
	WebSocketConnector ();
	virtual ~WebSocketConnector ();
public:
	void open (const QString& urlString, const QString& token);
	void close ();
	void doHandshake ();
signals:
	void onChannelViewed (const ChannelViewedEvent& event);
	void onAddedToTeam (const UserTeamEvent& event);
	void onUserAdded (const UserTeamEvent& event);
	void onLeaveTeam (const UserTeamEvent& event);
	void onPost (PostEvent& event);
	void onTyping (const TypingEvent& event);
private:
	void onNewPacket (const QString& string);
private:
	QWebSocket 	webSocket;
	QString		token;
	QTimer		pingTimer;
	QTimer		pongTimer;
};

} /* namespace Mattermost */


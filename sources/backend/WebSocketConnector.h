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
	void onReconnect ();
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


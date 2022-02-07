/**
 * @file NetworkRequest.h
 * @brief
 * @author Lyubomir Filipov
 * @date Jan 23, 2022
 */

#pragma once

#include <QNetworkRequest>
#include <QString>

namespace Mattermost {

class NetworkRequest: public QNetworkRequest {
public:
	NetworkRequest ();
	NetworkRequest (const QString& url, bool useCache = false);
	virtual ~NetworkRequest ();
public:
	static void setHost (const QString& host);
	static void clearToken ();
	static void setToken (const QString& token);
	static const QString& host ();
private:
	static QString		httpHost;
	static QString		httpToken;
};

} /* namespace Mattermost */

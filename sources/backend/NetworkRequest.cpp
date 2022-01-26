/**
 * @file NetworkRequest.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Jan 23, 2022
 */

#include "NetworkRequest.h"

namespace Mattermost {

#define API_V4 "api/v4/"

QString NetworkRequest::httpHost;
QString NetworkRequest::httpToken;

NetworkRequest::NetworkRequest () = default;

NetworkRequest::NetworkRequest (const QString& url)
{
	setUrl (httpHost + url);

	if (!httpToken.isEmpty()) {
		setRawHeader("Authorization", httpToken.toUtf8());
	}
}

NetworkRequest::~NetworkRequest () = default;

void NetworkRequest::setHost (const QString& host)
{
	httpHost = host;

	if (!httpHost.endsWith('/')) {
		httpHost.append('/');
	}

	httpHost += API_V4;
}

void NetworkRequest::setToken (const QString& token)
{
	NetworkRequest::httpToken = "Bearer " + token;
}

const QString& NetworkRequest::host ()
{
	return httpHost;
}

} /* namespace Mattermost */

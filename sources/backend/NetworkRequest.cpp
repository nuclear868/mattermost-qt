/**
 * @file NetworkRequest.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Jan 23, 2022
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

#include "NetworkRequest.h"

namespace Mattermost {

QString NetworkRequest::httpHost;
QString NetworkRequest::httpToken;

const QString NetworkRequest::mattermostMain = "api/v4/";
const QString NetworkRequest::matterpoll = "plugins/com.github.matterpoll.matterpoll/api/v1/";

NetworkRequest::NetworkRequest () = default;

NetworkRequest::NetworkRequest (const QString& url, bool useCache)
:NetworkRequest (mattermostMain, url, useCache)
{
}

NetworkRequest::NetworkRequest (const QString& urlRoot, const QString& url, bool useCache)
{
	setUrl (httpHost + urlRoot + url);

	setRawHeader("User-Agent", "QT");
	setRawHeader("X-Requested-With", "XMLHttpRequest");

	if (!httpToken.isEmpty()) {
		setRawHeader("Cookie", "MMAUTHTOKEN=" + httpToken.toUtf8());
	}

	setAttribute (QNetworkRequest::CacheSaveControlAttribute, useCache);
}

NetworkRequest::~NetworkRequest () = default;

void NetworkRequest::setHost (const QString& host)
{
	httpHost = host;

	if (!httpHost.endsWith('/')) {
		httpHost.append('/');
	}
}

void NetworkRequest::clearToken ()
{
	httpToken = "";
}

void NetworkRequest::setToken (const QString& token)
{
	httpToken = token;
}

const QString& NetworkRequest::getToken ()
{
	return httpToken;
}

const QString& NetworkRequest::host ()
{
	return httpHost;
}

} /* namespace Mattermost */

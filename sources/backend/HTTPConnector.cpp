/**
 * @file HTTPConnector.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Nov 29, 2021
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

#include "HTTPConnector.h"

#include <QAbstractNetworkCache>
#include <QNetworkAccessManager>
#include <QNetworkDiskCache>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include "QByteArrayCreator.h"
#include <QNetworkReply>

namespace Mattermost {

HTTPConnector::HTTPConnector ()
:qnetworkManager (std::make_unique <QNetworkAccessManager> ())
,diskCache (new QNetworkDiskCache)
{
	diskCache->setCacheDirectory ("cache");
	qnetworkManager->setCache (diskCache);
}

HTTPConnector::~HTTPConnector () = default;

void HTTPConnector::reset ()
{
	qnetworkManager.reset(new QNetworkAccessManager());
	diskCache = new QNetworkDiskCache ();
	diskCache->setCacheDirectory ("cache");
	qnetworkManager->setCache (diskCache);
}

void HTTPConnector::get (const QNetworkRequest& request, HttpResponseCallback responseHandler)
{
	QNetworkReply* reply = qnetworkManager->get (request);
	setProcessReply (reply, std::move (responseHandler));
}

void HTTPConnector::post (QNetworkRequest& request, const QByteArrayCreator& data, HttpResponseCallback responseHandler)
{
	if (data.isJson()) {
		request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
	}

	QNetworkReply* reply = qnetworkManager->post (request, data);
	setProcessReply (reply, std::move (responseHandler));
}

void HTTPConnector::put (const QNetworkRequest& request, const QByteArrayCreator& data, HttpResponseCallback responseHandler)
{
	QNetworkReply* reply = qnetworkManager->put (request, data);
	setProcessReply (reply, std::move (responseHandler));
}

void HTTPConnector::del (const QNetworkRequest& request)
{
	QNetworkReply* reply = qnetworkManager->deleteResource (request);
	setProcessReply (reply, [](QVariant, QByteArray, const QNetworkReply&){});
}

void HTTPConnector::setProcessReply (QNetworkReply* reply, std::function<void (QVariant, QByteArray, const QNetworkReply&)> responseHandler)
{
	connect(reply, &QNetworkReply::finished, [this, reply, responseHandler]() {

		QVariant statusCode = reply->attribute( QNetworkRequest::HttpStatusCodeAttribute );
		auto data = reply->readAll();
		reply->deleteLater();

		QAbstractNetworkCache* cache = qnetworkManager->cache();

		if (cache) {
			//qDebug () << "Cache size: " << cache->cacheSize();
		} else {
			//qDebug () << "No Cache: ";
		}

		if (statusCode == 200 || statusCode == 201) {
			return responseHandler (statusCode, qMove (data), *reply);
		}

		QJsonDocument doc = QJsonDocument::fromJson(data);
		QJsonObject root = doc.object();

		BackendError error;
		error.deserialize (root);

		qCritical() << reply->url();
		qCritical() << "HTTP error " << statusCode.toInt() << ", message: " << error.message;

		if (statusCode.toInt()) {
			emit onHttpError (statusCode.toInt(), error.message);
		}
	});

	connect(reply, qOverload<QNetworkReply::NetworkError>(&QNetworkReply::error),
			this, [this, reply](QNetworkReply::NetworkError error) {

		emit onNetworkError (error, reply->errorString());
	});
}

} /* namespace Mattermost */

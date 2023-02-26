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

#include "HTTPConnector.h"

#include <QAbstractNetworkCache>
#include <QNetworkAccessManager>
#include <QNetworkDiskCache>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStandardPaths>
#include <QNetworkReply>
#include "QByteArrayCreator.h"
#include "log.h"

namespace Mattermost {

static QNetworkDiskCache* createDiskCache ()
{
	QNetworkDiskCache* diskCache = new QNetworkDiskCache ();
	diskCache->setCacheDirectory (QStandardPaths::writableLocation(QStandardPaths::CacheLocation));
	diskCache->setMaximumCacheSize (300 * 1024 * 1024);
	return diskCache;
}

HTTPConnector::HTTPConnector ()
:qnetworkManager (std::make_unique <QNetworkAccessManager> ())
{
	//qnetworkManager takes ownership over the disk cache
	qnetworkManager->setCache (createDiskCache ());
}

HTTPConnector::~HTTPConnector () = default;

void HTTPConnector::reset ()
{
	//qnetworkManager takes ownership over the disk cache
	qnetworkManager.reset(new QNetworkAccessManager());
	qnetworkManager->setCache (createDiskCache ());
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

	//LOG_DEBUG ("POST " << request.url() << " " << request.rawHeaderList() << data);
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

		//print whether the resource is obtained from the cache
#if 0
		QVariant fromCache = reply->attribute(QNetworkRequest::SourceIsFromCacheAttribute);

		if (fromCache.value<bool>()) {
			qDebug () << "Reply " << reply->request().url() << " is from cache";
		} else {
			qDebug () << "Reply " << reply->request().url() << " is not from cache";
		}
#endif

		QVariant statusCode = reply->attribute( QNetworkRequest::HttpStatusCodeAttribute );
		auto data = reply->readAll();
		reply->deleteLater();

		//print the cache size
#if 0
		QAbstractNetworkCache* cache = qnetworkManager->cache();

		if (cache) {
			qDebug () << "Cache size: " << cache->cacheSize();
		} else {
			qDebug () << "No Cache: ";
		}
#endif

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

#if QT_VERSION <= QT_VERSION_CHECK(5,15,0)
	connect(reply, qOverload<QNetworkReply::NetworkError>(&QNetworkReply::error),
#else
	connect(reply, qOverload<QNetworkReply::NetworkError>(&QNetworkReply::errorOccurred),
#endif
			this, [this, reply](QNetworkReply::NetworkError error) {

		emit onNetworkError (error, reply->errorString());
	});
}

} /* namespace Mattermost */

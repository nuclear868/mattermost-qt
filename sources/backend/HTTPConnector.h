/**
 * @file HTTPConnector.h
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

#pragma once

#include <memory>
#include <QNetworkReply>
#include "backend/types/BackendError.h"

class QNetworkAccessManager;
class QNetworkDiskCache;

namespace Mattermost {

class HTTPConnector: public QObject {
	Q_OBJECT
public:
	HTTPConnector ();
	virtual ~HTTPConnector ();

	void reset ();

	void get (const QNetworkRequest &request, std::function<void(QVariant,QByteArray)> responseHandler);
	void get (const QNetworkRequest &request, std::function<void(QVariant,QByteArray,const QNetworkReply&)> responseHandler);
	void post (const QNetworkRequest &request, const QByteArray &data, std::function<void(QVariant,QByteArray)> responseHandler);
	void post (const QNetworkRequest &request, const QByteArray &data, std::function<void(QVariant,QByteArray,const QNetworkReply&)> responseHandler);
	void put (const QNetworkRequest &request, const QByteArray &data, std::function<void(QVariant,QByteArray)> responseHandler);
	void put (const QNetworkRequest &request, const QByteArray &data, std::function<void(QVariant,QByteArray,const QNetworkReply&)> responseHandler);
	void del (const QNetworkRequest &request);

signals:
	void onNetworkError (uint32_t errorNumber, const QString& errorText);
	void onHttpError (uint32_t errorNumber, const QString& errorText);

private:
	//virtual void setProcessReply (QNetworkReply* reply, std::function<void(QVariant,QByteArray)>&& responseHandler);
	virtual void setProcessReply (QNetworkReply* reply, std::function<void(QVariant,QByteArray,const QNetworkReply&)> responseHandler);
private:
	std::unique_ptr<QNetworkAccessManager> 	qnetworkManager;
	QNetworkDiskCache						*diskCache;
};

} /* namespace Mattermost */


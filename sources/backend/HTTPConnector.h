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

#include <memory>
#include <QNetworkReply>
#include "backend/types/BackendError.h"
#include "backend/HttpResponseCallback.h"

class QNetworkAccessManager;

namespace Mattermost {

class QByteArrayCreator;

class HTTPConnector: public QObject {
	Q_OBJECT
public:
	HTTPConnector ();
	virtual ~HTTPConnector ();

	void reset ();

	void get (const QNetworkRequest &request, HttpResponseCallback responseHandler);
	void post (QNetworkRequest &request, const QByteArrayCreator &data, HttpResponseCallback responseHandler);
	void put (const QNetworkRequest &request, const QByteArrayCreator &data, HttpResponseCallback responseHandler);
	void del (const QNetworkRequest &request);

signals:
	void onNetworkError (uint32_t errorNumber, const QString& errorText);
	void onHttpError (uint32_t errorNumber, const QString& errorText);

private:
	virtual void setProcessReply (QNetworkReply* reply, std::function<void(QVariant,QByteArray,const QNetworkReply&)> responseHandler);
private:
	std::unique_ptr<QNetworkAccessManager> 	qnetworkManager;
};

} /* namespace Mattermost */


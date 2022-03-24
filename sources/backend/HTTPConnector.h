/**
 * @file HTTPConnector.h
 * @brief
 * @author Lyubomir Filipov
 * @date Nov 29, 2021
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


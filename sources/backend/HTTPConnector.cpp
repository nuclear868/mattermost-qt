/**
 * @file HTTPConnector.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Nov 29, 2021
 */

#include "HTTPConnector.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>

namespace Mattermost {

HTTPConnector::HTTPConnector ()
:qnetworkManager (new QNetworkAccessManager)
{
}

HTTPConnector::~HTTPConnector () = default;

void HTTPConnector::reset ()
{
	qnetworkManager.reset(new QNetworkAccessManager());
}

void HTTPConnector::get (const QNetworkRequest& request, std::function<void (QVariant, QByteArray)> responseHandler)
{
	return get (request, [responseHandler] (QVariant status, QByteArray result, const QNetworkReply&) {
		responseHandler (status, result);
	});
}

void HTTPConnector::get (const QNetworkRequest& request, std::function<void (QVariant, QByteArray, const QNetworkReply&)> responseHandler)
{
	QNetworkReply* reply = qnetworkManager->get (request);
	setProcessReply (reply, std::move (responseHandler));
}

void HTTPConnector::post (const QNetworkRequest& request, const QByteArray& data, std::function<void (QVariant, QByteArray)> responseHandler)
{
	return post (request, data, [responseHandler] (QVariant status, QByteArray result, const QNetworkReply&) {
		responseHandler (status, result);
	});
}

void HTTPConnector::post (const QNetworkRequest& request, const QByteArray& data,
		std::function<void (QVariant, QByteArray, const QNetworkReply&)> responseHandler)
{
	QNetworkReply* reply = qnetworkManager->post (request, data);
	setProcessReply (reply, std::move (responseHandler));
}

void HTTPConnector::setProcessReply (QNetworkReply* reply, std::function<void (QVariant, QByteArray, const QNetworkReply&)> responseHandler)
{
	connect(reply, &QNetworkReply::finished, [this, reply, responseHandler]() {

		QVariant statusCode = reply->attribute( QNetworkRequest::HttpStatusCodeAttribute );
		auto data = reply->readAll();
		reply->deleteLater();

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

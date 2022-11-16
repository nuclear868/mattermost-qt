/**
 * @file HttpResponseCallback.h
 * @brief Creates a callback with support for different function signatures
 * @author Lyubomir Filipov
 * @date Nov 8, 2022
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

#include <functional>

class QVariant;
class QByteArray;
class QNetworkReply;
class QJsonDocument;

namespace Mattermost {

class HttpResponseCallback: public std::function<void(QVariant,QByteArray,const QNetworkReply&)> {
public:

	/**
	 * Default callback - receives QVariant, QByteArray and QNetworkReply
	 * @param fn callback. All arguments are forwarded to it.
	 */
	HttpResponseCallback (std::function<void(QVariant,QByteArray, const QNetworkReply&)> fn);

	/**
	 * Callback, which receives QVariant and QByteArray.
	 * @param fn callback. QVariant and QByteArray arguments are forwarded, the QNetworkReply argument is ignored
	 */
	HttpResponseCallback (std::function<void(QVariant,QByteArray)> fn);

	/**
	 * Callback, which receives QByteArray only.
	 * @param fn callback. QVariant and QByteArray arguments are forwarded, the QNetworkReply argument is ignored
	 */
	HttpResponseCallback (std::function<void(QByteArray)> fn);

	/**
	 * Callback, which receives QVariant and QJsonDocument.
	 * @param fn callback. QVariant is forwarded, QByteArray is parsed as QJsonDocuemnt, QNetworkReply is ignored
	 */
	HttpResponseCallback (std::function<void(QVariant,const QJsonDocument&)> fn);

	/**
	 * Callback, which receives QJsonDocument and QNetworkReply.
	 * @param fn callback. QByteArray is parsed as QJsonDocuemnt, QVariant is ignored
	 */
	HttpResponseCallback (std::function<void(const QJsonDocument&, const QNetworkReply&)> fn);

	/**
	 * Callback, which receives only QJsonDocument.
	 * @param fn callback. QByteArray is parsed as QJsonDocuemnt, QVariant and QNetworkReply are ignored
	 */
	HttpResponseCallback (std::function<void(const QJsonDocument&)> fn);

	virtual ~HttpResponseCallback ();
};

} /* namespace Mattermost */

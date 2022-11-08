/**
 * @file HttpResponseCallback.cpp
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

#include "HttpResponseCallback.h"

#include <QJsonDocument>
#include <QVariant>

namespace Mattermost {

HttpResponseCallback::HttpResponseCallback (std::function<void (QVariant, QByteArray, const QNetworkReply&)> fn)
:std::function<void(QVariant,QByteArray,const QNetworkReply&)> (fn)
{}

HttpResponseCallback::HttpResponseCallback (std::function<void (QVariant, QByteArray)> fn)
:HttpResponseCallback ([fn] (QVariant status, QByteArray result, const QNetworkReply&) {
	fn (status, result);
})
{}

HttpResponseCallback::HttpResponseCallback (std::function<void (QVariant, const QJsonDocument&)> fn)
:HttpResponseCallback ([fn] (QVariant status, QByteArray result, const QNetworkReply&) {
	fn (status, QJsonDocument::fromJson(result));
})
{}

HttpResponseCallback::HttpResponseCallback (std::function<void (const QJsonDocument&, const QNetworkReply&)> fn)
:HttpResponseCallback ([fn] (QVariant, QByteArray result, const QNetworkReply& reply) {
	fn (QJsonDocument::fromJson(result), reply);
})
{}

HttpResponseCallback::HttpResponseCallback (std::function<void (const QJsonDocument&)> fn)
:HttpResponseCallback ([fn] (QVariant, QByteArray result, const QNetworkReply&) {
	fn (QJsonDocument::fromJson(result));
})
{
}

HttpResponseCallback::~HttpResponseCallback () = default;

} /* namespace Mattermost */

/**
 * @file BackendUserProps.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Nov 28, 2021
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

#include "BackendUserProps.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <iostream>

namespace Mattermost {

void BackendUserCustomStatus::deserialize (const QJsonObject& json)
{
	emoji = json.value("emoji").toString();
	text = json.value("text").toString();
	duration = json.value("duration").toString();
	expiresAt = json.value("expiresAt").toString();
}

std::ostream& operator<< (std::ostream& os, const BackendUserCustomStatus& status)
{
	return os 	<< "emoji: " << status.emoji.toStdString() << std::endl
				<< "text: " << status.text.toStdString() << std::endl
				<< "duration: " << status.duration.toStdString() << std::endl
				<< "expire at: " << status.expiresAt.toStdString() << std::endl;
}

BackendUserProps::BackendUserProps (const QJsonValue& json)
:lastSearchPointer (0)
{
	if (json == QJsonValue::Undefined) {
		return;
	}
	
	const QJsonObject& jsonObject = json.toObject();
	
	for (auto it = jsonObject.constBegin(); it != jsonObject.constEnd(); ++it) {
		if (it.key() == "customStatus") {
			QString valueString = it.value().toString();
			if (valueString.isEmpty()) {
				continue;
			}
			
			//status sting is a JSON document, represented inside string value
			const QJsonObject statusObj = QJsonDocument::fromJson (valueString.toUtf8()).object();
			customStatus.deserialize (statusObj);
			//std::cout << "customStatus: " << customStatus << std::endl;
		} else if (it.key() == "last_search_pointer") {
			lastSearchPointer = it.value().toInt();
		}
	}
	
	
	const QJsonValue statusJson = jsonObject.value("customStatus");
	if (statusJson == QJsonValue::Undefined) {
		return;
	}
}

BackendUserProps::~BackendUserProps () = default;

#define CHECK_AND_UPDATE_PROPERTY(prop) \
	if (this->prop != other.prop) {\
		ss << "\t" << #prop ": '" << this->prop << "' -> '" << other.prop << "'\n";\
		this->prop = other.prop;\
	}\

static std::ostream& operator<< (std::ostream& os, const QString& qstr)
{
	return os << qstr.toStdString();
}

void BackendUserProps::updateFrom (const BackendUserProps& other, std::ostringstream& ss)
{
	CHECK_AND_UPDATE_PROPERTY (lastSearchPointer);
	CHECK_AND_UPDATE_PROPERTY (customStatus.emoji);
	CHECK_AND_UPDATE_PROPERTY (customStatus.text);
	CHECK_AND_UPDATE_PROPERTY (customStatus.duration);
	CHECK_AND_UPDATE_PROPERTY (customStatus.expiresAt);
}

} /* namespace Mattermost */


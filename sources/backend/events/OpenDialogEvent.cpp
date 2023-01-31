/**
 * @file OpenDialogEvent.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Oct 15, 2022
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

#include "OpenDialogEvent.h"

#include <QJsonDocument>

namespace Mattermost {

OpenDialogEvent::OpenDialogEvent (const QJsonObject& data, const QJsonObject&)
{
	//the dialog object is a JSON string inside the data object, with escaped json elements
	QJsonObject dialogObject = QJsonDocument::fromJson (data.value ("dialog").toString().toUtf8()).object();

	url = dialogObject.value ("url").toString();
	triggerID = dialogObject.value ("trigger_id").toString();
	callbackID = dialogObject.value ("dialog").toObject().value ("callback_id").toString();
}

OpenDialogEvent::OpenDialogEvent (const QString& triggerID)
:triggerID(triggerID)
{
}

OpenDialogEvent::~OpenDialogEvent () = default;

} /* namespace Mattermost */

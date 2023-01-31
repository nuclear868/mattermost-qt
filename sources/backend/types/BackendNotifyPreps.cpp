/**
 * @file BackendNotifyPreps.cpp
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

#include "BackendNotifyPreps.h"

#include <QJsonObject>

namespace Mattermost {

BackendNotifyPreps::BackendNotifyPreps ()
:channel (false)
,desktop_sound (false)
,email (false)
,first_name (false)
{
}

BackendNotifyPreps::~BackendNotifyPreps () = default;

void BackendNotifyPreps::deserialize (const QJsonObject& jsonObject)
{
	channel = jsonObject.value("channel").toBool();
	comments = jsonObject.value("comments").toString();
	desktop = jsonObject.value("desktop").toString();
	desktop_sound = jsonObject.value("desktop_sound").toBool();
	email = jsonObject.value("email").toBool();
	first_name = jsonObject.value("first_name").toBool();
	mention_keys = jsonObject.value("mention_keys").toString().split(',');
	push = jsonObject.value("push").toString();
	push_status = jsonObject.value("push_status").toString();
}

} /* namespace Mattermost */


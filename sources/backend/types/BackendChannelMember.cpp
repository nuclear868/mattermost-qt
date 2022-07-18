/**
 * @file BackendChannelMember.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Jun 13, 2022
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

#include "BackendChannelMember.h"
#include <QVariant>

namespace Mattermost {

BackendChannelMember::BackendChannelMember (const QJsonObject& jsonObject)
:user (nullptr)
{
	last_viewed_at = jsonObject.value("last_viewed_at").toVariant().toULongLong();
	msg_count = jsonObject.value("msg_count").toVariant().toULongLong();
	mention_count = jsonObject.value("mention_count").toVariant().toULongLong();
	user_id = jsonObject.value("user_id").toString();
}

BackendChannelMember::~BackendChannelMember () = default;

} /* namespace Mattermost */

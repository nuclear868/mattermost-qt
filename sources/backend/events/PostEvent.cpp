/**
 * @file PostEvent.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 31, 2021
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

#include <QJsonDocument>
#include "PostEvent.h"

namespace Mattermost {

PostEvent::PostEvent (const QJsonObject& data, const QJsonObject& broadcast)
:teamId (data.value("team_id").toString())
,channelId (broadcast.value ("channel_id").toString())
//the post object is a JSON string inside the data object, with escaped json elements
,postObject (QJsonDocument::fromJson (data.value ("post").toString().toUtf8()).object())
,set_online (data.value("set_online").toBool())
{
}

PostEvent::~PostEvent () = default;

} /* namespace Mattermost */

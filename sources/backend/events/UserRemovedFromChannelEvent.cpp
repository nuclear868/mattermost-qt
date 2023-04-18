/**
 * @file UserRemovedFromChannelEvent.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Feb 19, 2022
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

#include "UserRemovedFromChannelEvent.h"

namespace Mattermost {

/**
 * There are two types of packets here.
 * When user A receives event that user B is removed from a channel,
 * the broadcast->channel_id field and the data->user_id field is set.
 *
 * When user A receives event that user A is removed from a channel,
 * the broadcast->user_id field and the data->channel_id field is set
 */
UserRemovedFromChannelEvent::UserRemovedFromChannelEvent (const QJsonObject& data, const QJsonObject& broadcast)
:removerId (data.value("remover_id").toString())
,userId (data.value("user_id").toString())
,channelId (broadcast.value("channel_id").toString())
{
	if (userId.isEmpty() && channelId.isEmpty()) {
		userId = broadcast.value("user_id").toString();
		channelId = data.value("channel_id").toString();
	}
}

UserRemovedFromChannelEvent::~UserRemovedFromChannelEvent () = default;

} /* namespace Mattermost */

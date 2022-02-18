/**
 * @file ChannelCreatedEvent.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Feb 18, 2022
 */

#include "ChannelCreatedEvent.h"

namespace Mattermost {

ChannelCreatedEvent::ChannelCreatedEvent (const QJsonObject& object)
:channelId (object.value("channel_id").toString())
,teamId (object.value("team_id").toString())
{
}

ChannelCreatedEvent::~ChannelCreatedEvent () = default;

} /* namespace Mattermost */

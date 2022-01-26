/**
 * @file ChannelViewedEvent.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 30, 2021
 */

#include "ChannelViewedEvent.h"

namespace Mattermost {

ChannelViewedEvent::ChannelViewedEvent (const QJsonObject& object)
:channel_id (object.value("channel_id").toString())
{
}

ChannelViewedEvent::~ChannelViewedEvent () = default;

} /* namespace Mattermost */


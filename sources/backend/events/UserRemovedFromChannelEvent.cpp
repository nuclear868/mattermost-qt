/**
 * @file UserRemovedFromChannelEvent.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Feb 19, 2022
 */

#include "UserRemovedFromChannelEvent.h"

namespace Mattermost {

UserRemovedFromChannelEvent::UserRemovedFromChannelEvent (const QJsonObject& data, const QJsonObject& broadcast)
:userId (broadcast.value("user_id").toString())
,channelId (data.value("channel_id").toString())
{
}

UserRemovedFromChannelEvent::~UserRemovedFromChannelEvent () = default;

} /* namespace Mattermost */

/**
 * @file UserAddedToChannelEvent.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Mar 14, 2022
 */

#include "UserAddedToChannelEvent.h"

namespace Mattermost {

UserAddedToChannelEvent::UserAddedToChannelEvent (const QJsonObject& data, const QJsonObject& broadcast)
:userId (data.value("user_id").toString())
,channelId (broadcast.value ("channel_id").toString())
,teamId (data.value("team_id").toString())
{
}

UserAddedToChannelEvent::~UserAddedToChannelEvent () = default;

} /* namespace Mattermost */

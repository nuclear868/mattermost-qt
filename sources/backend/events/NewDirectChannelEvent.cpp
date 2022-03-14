/**
 * @file NewDirectChannelEvent.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Mar 14, 2022
 */

#include "NewDirectChannelEvent.h"

namespace Mattermost {

NewDirectChannelEvent::NewDirectChannelEvent (const QJsonObject& data, const QJsonObject& broadcast)
:channelId (broadcast.value ("channel_id").toString())
,userId (data.value ("creator_id").toString())
{

}

NewDirectChannelEvent::~NewDirectChannelEvent () = default;

} /* namespace Mattermost */

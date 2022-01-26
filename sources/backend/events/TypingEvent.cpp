/**
 * @file TypingEvent.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Jan 24, 2022
 */

#include "TypingEvent.h"

namespace Mattermost {

TypingEvent::TypingEvent (const QJsonObject& data, const QJsonObject& broadcast)
:channel_id (broadcast.value("channel_id").toString())
,user_id (data.value("user_id").toString())
{
}

TypingEvent::~TypingEvent () = default;

} /* namespace Mattermost */

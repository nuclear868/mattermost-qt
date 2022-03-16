/**
 * @file PostEditedEvent.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Mar 16, 2022
 */

#include <QJsonDocument>
#include "PostEditedEvent.h"

namespace Mattermost {

PostEditedEvent::PostEditedEvent (const QJsonObject& data, const QJsonObject& broadcast)
:teamId (data.value("team_id").toString())
,channelId (broadcast.value ("channel_id").toString())
//the post object is a JSON string inside the data object, with escaped json elements
,postObject (QJsonDocument::fromJson (data.value ("post").toString().toUtf8()).object())
{
}

PostEditedEvent::~PostEditedEvent () = default;

} /* namespace Mattermost */

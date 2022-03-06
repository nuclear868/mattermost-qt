/**
 * @file PostDeletedEvent.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Mar 6, 2022
 */

#include <QJsonDocument>
#include "PostDeletedEvent.h"

namespace Mattermost {

PostDeletedEvent::PostDeletedEvent (const QJsonObject& data, const QJsonObject& broadcast)
:channelId (broadcast.value ("channel_id").toString())
,postId (QJsonDocument::fromJson (data.value ("post").toString().toUtf8()).object().value ("id").toString())
{

}

PostDeletedEvent::~PostDeletedEvent () = default;

} /* namespace Mattermost */

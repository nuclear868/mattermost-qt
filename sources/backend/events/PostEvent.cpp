/**
 * @file PostEvent.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 31, 2021
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

PostEvent::~PostEvent ()
{
	// TODO Auto-generated destructor stub
}

} /* namespace Mattermost */

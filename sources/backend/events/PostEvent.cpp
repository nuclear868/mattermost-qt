/**
 * @file PostEvent.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 31, 2021
 */

#include <QJsonDocument>
#include "PostEvent.h"

namespace Mattermost {

PostEvent::PostEvent (const QJsonObject& object)
:team_id (object.value("team_id").toString())
,set_online (object.value("set_online").toBool())
{
	//the post object is a JSON string, with escaped json elements
	QJsonDocument doc = QJsonDocument::fromJson(object.value ("post").toString().toUtf8());
	post.deserialize (doc.object());
}

PostEvent::~PostEvent ()
{
	// TODO Auto-generated destructor stub
}

} /* namespace Mattermost */

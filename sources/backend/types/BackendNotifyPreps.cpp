/**
 * @file BackendNotifyPreps.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Nov 28, 2021
 */

#include "BackendNotifyPreps.h"

#include <QJsonObject>

namespace Mattermost {

BackendNotifyPreps::BackendNotifyPreps ()
:channel (false)
,desktop_sound (false)
,email (false)
,first_name (false)
{
}

BackendNotifyPreps::~BackendNotifyPreps () = default;

void BackendNotifyPreps::deserialize (const QJsonObject& jsonObject)
{
	channel = jsonObject.value("channel").toBool();
	comments = jsonObject.value("comments").toString();
	desktop = jsonObject.value("desktop").toString();
	desktop_sound = jsonObject.value("desktop_sound").toBool();
	email = jsonObject.value("email").toBool();
	first_name = jsonObject.value("first_name").toBool();
	mention_keys = jsonObject.value("mention_keys").toString().split(',');
	push = jsonObject.value("push").toString();
	push_status = jsonObject.value("push_status").toString();
}

} /* namespace Mattermost */


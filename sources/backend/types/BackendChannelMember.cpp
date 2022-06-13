/**
 * @file BackendChannelMember.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Jun 13, 2022
 */

#include "BackendChannelMember.h"
#include <QVariant>

namespace Mattermost {

BackendChannelMember::BackendChannelMember (const QJsonObject& jsonObject)
:user (nullptr)
{
	last_viewed_at = jsonObject.value("last_viewed_at").toVariant().toULongLong();
	msg_count = jsonObject.value("msg_count").toVariant().toULongLong();
	mention_count = jsonObject.value("mention_count").toVariant().toULongLong();
	user_id = jsonObject.value("user_id").toString();
}

BackendChannelMember::~BackendChannelMember () = default;

} /* namespace Mattermost */

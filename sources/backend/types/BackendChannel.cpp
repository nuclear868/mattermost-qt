/**
 * @file BackendChannel.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 1, 2021
 */

#include "BackendChannel.h"

namespace Mattermost {

BackendChannel::BackendChannel (const QJsonObject& jsonObject)
{
	id = jsonObject.value("id").toString();
	create_at = jsonObject.value("create_at").toVariant().toULongLong();
	update_at = jsonObject.value("update_at").toVariant().toULongLong();
	delete_at = jsonObject.value("delete_at").toVariant().toULongLong();
	team_id = jsonObject.value("team_id").toString();
	display_name = jsonObject.value("display_name").toString();
	name = jsonObject.value("name").toString();
	header = jsonObject.value("header").toString();
	purpose = jsonObject.value("purpose").toString();

	switch (jsonObject.value("type").toString()[0].unicode()) {
	case 'O':
		type = publicChannel;
		break;
	case 'P':
		type = privateChannel;
		break;
	case 'D':
		type = directChannel;
		break;
	default:
		break;
	}

	last_post_at = jsonObject.value("last_post_at").toInt();
	total_msg_count = jsonObject.value("total_msg_count").toInt();
	extra_update_at = jsonObject.value("extra_update_at").toInt();
	creator_id = jsonObject.value("creator_id").toString();
	scheme_id = jsonObject.value("scheme_id").toVariant();
	props = jsonObject.value("props").toVariant();
	referenceCount = 1;
}

BackendChannel::~BackendChannel () = default;

} /* namespace Mattermost */


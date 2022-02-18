/**
 * @file BackendTeam.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Nov 30, 2021
 */

#include "BackendTeam.h"

namespace Mattermost {

BackendTeam::BackendTeam (QString id)
:id (id)
,create_at (0)
,update_at (0)
,delete_at (0)
,allow_open_invite (false)
{
}

BackendTeam::BackendTeam (const QJsonObject& jsonObject)
:create_at (0)
,update_at (0)
,delete_at (0)
,allow_open_invite (false)
{
	id = jsonObject.value("id").toString();
	create_at = jsonObject.value("create_at").toVariant().toULongLong();
	update_at = jsonObject.value("update_at").toVariant().toULongLong();
	delete_at = jsonObject.value("delete_at").toVariant().toULongLong();
	display_name = jsonObject.value("display_name").toString();
	name = jsonObject.value("name").toString();
	description = jsonObject.value("description").toString();
	email = jsonObject.value("email").toString();
	type = jsonObject.value("type").toString();
	company_name = jsonObject.value("company_name").toString();
	allowed_domains = jsonObject.value("allowed_domains").toString();
	invite_id = jsonObject.value("invite_id").toString();
	allow_open_invite = jsonObject.value("allow_open_invite").toBool();
	scheme_id = jsonObject.value("scheme_id").toVariant();
}


BackendTeam::~BackendTeam () = default;

} /* namespace Mattermost */


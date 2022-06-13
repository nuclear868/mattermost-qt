/**
 * @file BackendTeamMember.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 1, 2021
 */

#include "BackendTeamMember.h"

namespace Mattermost {

BackendTeamMember::BackendTeamMember (const QJsonObject& jsonObject)
:delete_at (0)
,scheme_admin (0)
,scheme_guest (0)
,scheme_user (0)
,user (nullptr)
{
	delete_at = jsonObject.value("delete_at").toVariant().toULongLong();
	explicit_roles = jsonObject.value("explicit_roles").toString();;
	roles = jsonObject.value("roles").toString();;
	scheme_admin = jsonObject.value("scheme_admin").toBool();
	scheme_guest = jsonObject.value("scheme_guest").toBool();
	scheme_user = jsonObject.value("scheme_user").toBool();
	team_id = jsonObject.value("team_id").toString();
	user_id = jsonObject.value("user_id").toString();
}

BackendTeamMember::~BackendTeamMember () = default;

} /* namespace Mattermost */


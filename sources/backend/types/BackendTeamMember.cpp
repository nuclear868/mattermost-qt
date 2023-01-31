/**
 * @file BackendTeamMember.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 1, 2021
 *
 * Copyright 2021, 2022 Lyubomir Filipov
 *
 * This file is part of Mattermost-QT.
 *
 * Mattermost-QT is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Mattermost-QT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Mattermost-QT. if not, see https://www.gnu.org/licenses/.
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


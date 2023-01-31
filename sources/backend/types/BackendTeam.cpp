/**
 * @file BackendTeam.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Nov 30, 2021
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

#include "BackendTeam.h"
#include <QSet>

namespace Mattermost {

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

QSet<const BackendUser*> BackendTeam::getAllMembers () const
{
	QSet<const BackendUser*> ret;

	for (auto& member: members) {
		ret.insert (member.user);
	}

	return ret;
}

} /* namespace Mattermost */


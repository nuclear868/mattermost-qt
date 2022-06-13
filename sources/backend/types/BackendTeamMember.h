/**
 * @file BackendTeamMember.h
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 1, 2021
 */

#pragma once

#include <QJsonObject>
#include <QVariant>
#include "BackendUser.h"

namespace Mattermost {

class BackendTeamMember {
public:
	BackendTeamMember (const QJsonObject& jsonObject);
	virtual ~BackendTeamMember ();
public:
	uint64_t		delete_at;
	QString			explicit_roles;
	QString			roles;
	bool			scheme_admin;
	bool			scheme_guest;
	bool			scheme_user;
	QString			team_id;
	QString			user_id;

	BackendUser*	user;
};

} /* namespace Mattermost */


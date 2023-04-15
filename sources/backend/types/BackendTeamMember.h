/**
 * @file BackendTeamMember.h
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

#pragma once

#include <QJsonObject>
#include <QVariant>
#include "BackendUser.h"

class QJsonObject;

namespace Mattermost {

class Storage;
class BackendUser;

class BackendTeamMember {
public:
	BackendTeamMember (const Storage& storage, const QJsonObject& jsonObject);
	virtual ~BackendTeamMember ();
public:
	QString getDisplayUsername () const;
public:
	uint64_t			delete_at;
	QString				explicit_roles;
	QString				roles;
	const BackendUser*	user;
	bool				isAdmin;
};

} /* namespace Mattermost */


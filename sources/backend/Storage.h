/**
 * @file Storage.h
 * @brief
 * @author Lyubomir Filipov
 * @date Jan 8, 2022
 *
 * Copyright 2021, 2022 Lyubomir Filipov
 *
 * This file is part of Mattermost-QT.
 *
 * Mattermost-QT is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Mattermost-QT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Mattermost-QT; if not, see https://www.gnu.org/licenses/.
 */

#pragma once

#include <QMap>
#include <map>
#include <QSharedPointer>
#include "backend/types/BackendUser.h"
#include "backend/types/BackendTeam.h"

namespace Mattermost {

const QString DIRECT_TEAM_ID = "0";

class Storage {
public:
	Storage ();
	virtual ~Storage ();
public:
	void reset ();

	BackendTeam* getTeamById (const QString& teamID);
	const BackendTeam* getTeamById (const QString& teamID) const;

	BackendChannel* getChannelById (const QString& channelID);
	BackendChannel* getDirectChannelByUserId (const QString& userID) const;

	const std::map<QString, BackendUser>& getAllUsers () const;

	BackendUser* getUserById (const QString& userID);
	const BackendUser* getUserById (const QString& userID) const;

	BackendTeam* addTeam (const QJsonObject& json);

	BackendChannel* addChannel (BackendTeam& team, const QJsonObject& json);

	BackendUser* addUser (const QJsonObject& json, bool isLoggedInUser = false);

	void eraseTeam (const QString& teamID);

	void eraseChannel (BackendChannel& channel);

	void printTeams ();
public:
	std::map<QString, BackendTeam>					teams;
	BackendTeam										directChannels;
	QMap<QString, BackendChannel*> 					channels;
	QMap<QString, BackendChannel*> 					directChannelsByUser;
	std::map<QString, BackendUser>					users;
	BackendUser*									loginUser;
	uint32_t										totalUsersCount;
};

} /* namespace Mattermost */

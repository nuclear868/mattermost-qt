/**
 * @file Storage.h
 * @brief
 * @author Lyubomir Filipov
 * @date Jan 8, 2022
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

	BackendChannel* getChannelById (const QString& channelID);
	BackendChannel* getDirectChannelByUserId (const QString& userID) const;

	const std::map<QString, BackendUser>& getAllUsers () const;

	BackendUser* getUserById (const QString& userID);
	const BackendUser* getUserById (const QString& userID) const;

	BackendTeam* addTeam (const QJsonObject& json);

	BackendChannel* addChannel (BackendTeam& team, const QJsonObject& json);

	BackendUser* addUser (const QJsonObject& json, bool isLoggedInUser = false);

	void eraseTeam (const QString& teamID);

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

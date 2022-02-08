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

class Storage {
public:
	Storage ();
	virtual ~Storage ();
public:
	void reset ();

	BackendTeam* getTeamById (const QString& teamID);

	BackendChannel* getChannelById (const QString& channelID);

	BackendUser* getUserById (const QString& userID);

	void addTeam (BackendTeam* team);

	void addChannel (BackendTeam& team, BackendChannel* channel);

	BackendUser* addUser (const QJsonObject& json, bool isLoggedInUser = false);

	void eraseTeam (const QString& teamID);

	void printTeams ();
public:
	QMap<QString, QSharedPointer<BackendTeam>>		teams;
	QMap<QString, BackendChannel*> 					channels;
	std::map<QString, BackendUser>					users;
	BackendUser*									loginUser;
	std::vector<std::unique_ptr<BackendChannel>>	directChannels;
	uint32_t										totalUsersCount;
};

} /* namespace Mattermost */

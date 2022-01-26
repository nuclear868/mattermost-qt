/**
 * @file Storage.h
 * @brief
 * @author Lyubomir Filipov
 * @date Jan 8, 2022
 */

#pragma once

#include <QMap>
#include "backend/types/BackendUser.h"
#include "backend/types/BackendTeam.h"

namespace Mattermost {

class Storage {
public:
	Storage ();
	virtual ~Storage ();
public:
	BackendTeam* getTeamById (const QString& teamID);

	BackendChannel* getChannelById (const QString& channelID);

	BackendUser* getUserById (const QString& userID);

	void addChannel (BackendTeam& team, BackendChannel* channel);

	void eraseTeam (const QString& teamID);

	void printTeams ();
public:
	QMap<QString, BackendTeam> 		teams;
	QMap<QString, BackendChannel*> 	channels;
	QMap<QString, BackendUser> 		users;
	BackendUser						loginUser;
	QList<BackendChannel*>			directChannels;
	uint32_t						totalUsersCount;
};

} /* namespace Mattermost */

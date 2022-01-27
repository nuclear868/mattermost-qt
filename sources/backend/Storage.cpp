/**
 * @file Storage.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Jan 8, 2022
 */

#include "Storage.h"
#include "log.h"

namespace Mattermost {

Storage::Storage ()
:totalUsersCount (0)
 ,nonFilledTeams (0)
{
}

Storage::~Storage () = default;

BackendUser* Storage::getUserById (const QString& userID)
{
	auto it = users.find (userID);

	if (it == users.end()) {
		return nullptr;
	}

	return &*it;
}

BackendTeam* Storage::getTeamById (const QString& teamID)
{
	auto it = teams.find (teamID);

	if (it == teams.end()) {
		return nullptr;
	}

	return &*it;
}

BackendChannel* Storage::getChannelById (const QString& channelID)
{
	auto it = channels.find (channelID);

	if (it == channels.end()) {
		return nullptr;
	}

	return *it;
}

void Storage::addTeam (BackendTeam& team)
{
	teams[team.id] = team;
	++nonFilledTeams;
}

void Storage::addChannel (BackendTeam& team, BackendChannel* channel)
{
	if (channel->type == BackendChannel::directChannel) {
		BackendChannel* existingChannel = getChannelById (channel->id);

		if (existingChannel) {
			++existingChannel->referenceCount;
			delete (channel);
			return;
		}


		/*
		 * get pointer to the other participant in the direct channel
		 */

		//the channel name contains the userIDs of it's participants
		QStringList all_users_id = channel->name.split("__");

		//remove the logged-in user from this list
		all_users_id.removeAll (loginUser.id);

		//the remote user ID is the remaining id
		QString userID = all_users_id.first();

		//set the user ID as a channel name in order to be able to access it
		channel->name = userID;

		//get pointer to the user
		BackendUser* user = getUserById (all_users_id.first());

		//set user's name as the channel display name
		if (user) {
			channel->display_name = user->getDisplayName();
		} else {
			channel->display_name = all_users_id.first();
		}

		directChannels.append (channel);
		channels[channel->id] = directChannels.back();

	} else {
		team.channels.append (channel);
		channels[channel->id] = team.channels.back();
	}
}

void Storage::eraseTeam (const QString& teamID)
{
	auto teamIt = teams.find (teamID);

	if (teamIt != teams.end()) {
		for (auto& it: teamIt->channels) {

			LOG_DEBUG ("Team Channel: " << it->id);
			auto channelIt = channels.find (it->id);

			if (channelIt != channels.end()) {
				LOG_DEBUG ("Erase Channel: " << channelIt.key() << " " << channelIt.value() << " " << channelIt.value()->name);
				channels.erase (channelIt);
			}
		}
		LOG_DEBUG ("Erase Team: " << teamIt.key() << " " << &teamIt.value() << " " << teamIt.value().name);
		teams.erase (teamIt);
	}
}

void Storage::printTeams ()
{
	qDebug() << teams.size() << " teams";
	for (auto& team: teams) {
		qDebug() << "Team " << team.id << " " << &team << ":";
		for (auto& channel: team.channels) {
			qDebug() << "\tChannel: " << channel->id << channel;
		}
	}
}


} /* namespace Mattermost */


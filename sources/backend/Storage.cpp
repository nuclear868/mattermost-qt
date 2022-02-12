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
{
}

Storage::~Storage () = default;

void Storage::reset ()
{
	teams.clear();

	directChannels.clear();

	channels.clear();
	users.clear();
	totalUsersCount = 0;
}

BackendUser* Storage::getUserById (const QString& userID)
{
	auto it = users.find (userID);

	if (it == users.end()) {
		return nullptr;
	}

	return &it->second;
}

BackendTeam* Storage::getTeamById (const QString& teamID)
{
	auto it = teams.find (teamID);

	if (it == teams.end()) {
		return nullptr;
	}

	return &it->second;
}

BackendChannel* Storage::getChannelById (const QString& channelID)
{
	auto it = channels.find (channelID);

	if (it == channels.end()) {
		return nullptr;
	}

	return *it;
}

BackendTeam* Storage::addTeam (const QJsonObject& json)
{
	QString teamId (json.value("id").toString());

	auto it = teams.find (teamId);

	BackendTeam* team;

	//team already exists.
	if (it != teams.end()) {
		team = &it->second;
	} else {
		team = &teams.emplace (teamId, json).first->second;
	}

	return team;
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
		all_users_id.removeAll (loginUser->id);

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
			LOG_DEBUG ("Channel used not found for " << channel->id);
			channel->display_name = all_users_id.first();
		}

		directChannels.emplace_back (channel);
		channels[channel->id] = directChannels.back().get();

	} else {
		team.channels.emplace_back (channel);
		channels[channel->id] = team.channels.back().get();
	}
}

BackendUser* Storage::addUser (const QJsonObject& json, bool isLoggedInUser)
{
	QString userId (json.value("id").toString());

	auto it = users.find (userId);

	BackendUser* user;

	//user already exists. This is the case of the LoginUser - it is filled during login
	if (it != users.end()) {
		user = &it->second;
	} else {
		user = &users.emplace (userId, json).first->second;
	}

	if (isLoggedInUser) {
		loginUser = user;
	}

	return user;
}

void Storage::eraseTeam (const QString& teamID)
{
	auto teamIt = teams.find (teamID);

	if (teamIt != teams.end()) {
		auto& team = teamIt->second;
		for (auto& it: team.channels) {

			LOG_DEBUG ("Team Channel: " << it->id);
			auto channelIt = channels.find (it->id);

			if (channelIt != channels.end()) {
				LOG_DEBUG ("Erase Channel: " << channelIt.key() << " " << channelIt.value() << " " << channelIt.value()->name);
				channels.erase (channelIt);
			}
		}
		LOG_DEBUG ("Erase Team: " << teamIt->first << " " << team.name);
		teams.erase (teamIt);
	}
}

void Storage::printTeams ()
{
	qDebug() << teams.size() << " teams";
	for (auto& teamIt: teams) {
		auto& team = teamIt.second;
		qDebug() << "Team " << team.id << " " << team.display_name << ":";
		for (auto& channel: team.channels) {
			qDebug() << "\tChannel: " << channel->id << channel.get();
		}
	}
}

} /* namespace Mattermost */


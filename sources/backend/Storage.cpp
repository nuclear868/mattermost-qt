/**
 * @file Storage.cpp
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

#include "Storage.h"
#include "log.h"

namespace Mattermost {

Storage::Storage ()
:loginUser (nullptr)
,matterpollUser (nullptr)
,totalUsersCount (0)
{
}

Storage::~Storage () = default;

void Storage::reset ()
{
	teams.clear();

	directChannels.channels.clear();

	channels.clear();
	users.clear();
	totalUsersCount = 0;
}

const BackendUser* Storage::getUserById (const QString& userID) const
{
	auto it = users.find (userID);

	if (it == users.end()) {
		return nullptr;
	}

	return &it->second;
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

const BackendTeam* Storage::getTeamById (const QString& teamID) const
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

BackendChannel* Storage::getDirectChannelByUserId (const QString& userID) const
{
	auto it = directChannelsByUser.find (userID);

	if (it == directChannelsByUser.end()) {
		return nullptr;
	}

	if ((*it)->type != BackendChannel::directChannel) {
		return nullptr;
	}

	return *it;
}

const std::map<QString, BackendUser>& Storage::getAllUsers () const
{
	return users;
}

BackendTeam* Storage::addTeam (const QJsonObject& json)
{
	QString teamId (json.value("id").toString());

	auto it = teams.find (teamId);

	//team already exists.
	if (it != teams.end()) {
		return nullptr;
	} else {
		return &teams.emplace (teamId, json).first->second;
	}
}

BackendChannel* Storage::addNonDirectChannel (BackendTeam& team, const QJsonObject& json)
{
	//get channel ID and channel type in order to check if a channel has to be created
	uint32_t channelType = BackendChannel::getChannelType (json);
	QString channelId = json.value("id").toString();

	BackendChannel* newChannel;

	if (channelType == BackendChannel::directChannel) {
		LOG_DEBUG ("Storage::addNonDirectChannel called for direct channel " << newChannel->id << " " << newChannel->display_name);
		return nullptr;
	}

	newChannel = new BackendChannel (*this, json);

	team.channels.emplace_back (newChannel);
	channels[newChannel->id] = team.channels.back().get();
	return newChannel;
}

BackendChannel* Storage::addDirectChannel (const QJsonObject& json)
{
	/**
	 * The Mattermost server adds all direct channels to all teams (wtf?), so
	 * a direct channel may appear multiple times. We create only one channel
	 * instance for such duplicate channels and they are displayed only once
	 */
	QString channelId = json.value("id").toString();

	BackendChannel* existingChannel = getChannelById (channelId);

	/**
	 * Check if the channel is already added
	 */
	if (existingChannel) {
		++existingChannel->referenceCount;
		return existingChannel;
	}

	BackendChannel* newChannel = new BackendChannel (*this, json);

	/*
	 * get pointer to the other participant in the direct channel
	 */

	//the channel name contains the userIDs of it's participants
	QStringList allUserIds = newChannel->name.split("__");

	//allUserIds the logged-in user from this list
	allUserIds.removeAll (loginUser->id);

	QString userID;

	//if the list is empty, the user has a chat with himself
	if (allUserIds.isEmpty()) {
		userID = loginUser->id;
	} else {
	//the remote user ID is the remaining id
		userID = allUserIds.first();
	}

	//set the user ID as a channel name in order to be able to access it
	newChannel->name = userID;

	//get pointer to the user
	BackendUser* user = getUserById (userID);

	//set user's name as the channel display name
	if (user) {
		newChannel->display_name = user->getDisplayName();
		directChannels.members.push_back (user);
	} else {
		LOG_DEBUG ("Channel " << newChannel->id) << ": user name not found";
		newChannel->display_name = userID;
	}

	directChannelsByUser[userID] = newChannel;

	directChannels.channels.emplace_back (newChannel);
	channels[newChannel->id] = directChannels.channels.back().get();
	return newChannel;
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

	if (user->username == "matterpoll") {
		matterpollUser = user;
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

void Storage::eraseChannel (BackendChannel& channel)
{
	auto& teamChannels = channel.team->channels;

	for (auto it = teamChannels.begin(); it != teamChannels.end(); ++it) {
		if (it->get() == &channel) {
			auto channelIt = channels.find (it->get()->id);

			if (channelIt != channels.end()) {
				LOG_DEBUG ("Erase Channel: " << channelIt.key() << " " << channelIt.value() << " " << channelIt.value()->name);
				channels.erase (channelIt);
			}

			teamChannels.erase (it);
			return;
		}
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


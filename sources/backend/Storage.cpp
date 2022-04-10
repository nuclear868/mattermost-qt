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
:directChannels (DIRECT_TEAM_ID)
,totalUsersCount (0)
{
	directChannels.display_name = "Direct Messages";
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

BackendChannel* Storage::getChannelById (const QString& channelID)
{
	auto it = channels.find (channelID);

	if (it == channels.end()) {
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

	BackendTeam* team;

	//team already exists.
	if (it != teams.end()) {
		team = &it->second;
	} else {
		team = &teams.emplace (teamId, json).first->second;
	}

	return team;
}

BackendChannel* Storage::addChannel (BackendTeam& team, const QJsonObject& json)
{
	//team to add channel to. If it is a private channel, it will be changed
	BackendTeam* useTeam = &team;

	//get channel ID and channel type in order to check if a channel has to be created
	uint32_t channelType = BackendChannel::getChannelType (json);
	QString channelId = json.value("id").toString();

	BackendChannel* newChannel;

	if (channelType == BackendChannel::directChannel) {
		BackendChannel* existingChannel = getChannelById (channelId);

		if (existingChannel) {
			++existingChannel->referenceCount;
			return existingChannel;
		}

		newChannel = new BackendChannel (*this, json);

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
		} else {
			LOG_DEBUG ("Channel used not found for " << newChannel->id);
			newChannel->display_name = userID;
		}

		useTeam = &directChannels;
	} else {
		newChannel = new BackendChannel (*this, json);
	}

	useTeam->channels.emplace_back (newChannel);
	channels[newChannel->id] = useTeam->channels.back().get();
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


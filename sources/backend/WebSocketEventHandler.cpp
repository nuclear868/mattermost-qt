/**
 * @file WebSocketEventHandler.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Feb 18, 2022
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

#include "WebSocketEventHandler.h"

#include <QJsonDocument>
#include "Backend.h"
#include "Storage.h"
#include "log.h"

namespace Mattermost {

WebSocketEventHandler::WebSocketEventHandler (Backend& backend)
:backend (backend)
,storage (backend.getStorage())
{
}


WebSocketEventHandler::~WebSocketEventHandler () = default;

void WebSocketEventHandler::handleEvent (const ChannelViewedEvent& event)
{
	BackendChannel* channel = storage.getChannelById (event.channelId);
	QString channelName = channel ? channel->name : event.channelId;

	if (channel) {
		emit channel->onViewed ();
		emit backend.onChannelViewed (*channel);
	}
}

void WebSocketEventHandler::handleEvent (const PostEvent& event)
{
	BackendChannel* channel = storage.getChannelById (event.channelId);

	if (!channel) {
		return;
	}

	BackendPost* post = channel->addPost (event.postObject);

	LOG_DEBUG ("Post in '" << channel->getTeamAndChannelName() << "' by " << post->getDisplayAuthorName() << ": " << post->message);

	emit channel->onNewPost (*post);
	emit backend.onNewPost (*channel, *post);
}

void WebSocketEventHandler::handleEvent (const PostEditedEvent& event)
{
	BackendTeam* team = storage.getTeamById (event.teamId);
	QString teamName = team ? team->name : event.teamId;

	BackendChannel* channel = storage.getChannelById (event.channelId);

	if (!channel) {
		return;
	}

	QString channelName = channel ? channel->name : event.channelId;

	//temporary post object. Used only to apply it's properties to the existing post, after edit
	BackendPost post (event.postObject, storage);

	channel->editPost (post);

#if 0
	BackendPost* post = channel->addPost (event.postObject);

	LOG_DEBUG ("Post edited in  '" << teamName << "' : '" << channelName << "' by " << post->getDisplayAuthorName() << ": " << post->message);
	if (channel) {
		emit channel->onNewPost (*post);
		emit backend.onNewPost (*channel, *post);
	}
#endif
}

void WebSocketEventHandler::handleEvent (const PostDeletedEvent& event)
{
	BackendChannel* channel = storage.getChannelById (event.channelId);

	LOG_DEBUG ("Delete post in  '" << (channel ? channel->name : event.channelId) << "' : '" << event.postId);

	if (channel) {
		emit channel->onPostDeleted (event.postId);
	}
}


void WebSocketEventHandler::handleEvent (const PostReactionAddedEvent& event)
{
	BackendChannel* channel = storage.getChannelById (event.channelId);

	if (!channel) {
		return;
	}

	channel->addPostReaction (event.postId, event.userId, event.emojiName);

	LOG_DEBUG ("Reaction added " << event.emojiName << " from " << event.userId << " for post " << event.postId);
}

void WebSocketEventHandler::handleEvent (const PostReactionRemovedEvent& event)
{
	BackendChannel* channel = storage.getChannelById (event.channelId);

	if (!channel) {
		return;
	}

	channel->removePostReaction (event.postId, event.userId, event.emojiName);

	LOG_DEBUG ("Reaction removed " << event.emojiName << " from " << event.userId << " for post " << event.postId);
}


void WebSocketEventHandler::handleEvent (const TypingEvent& event)
{
	BackendChannel* channel = storage.getChannelById(event.channelID);

	BackendUser* user = storage.getUserById (event.userID);

	if (!user || !channel) {
		return;
	}

	emit (channel->onUserTyping(*user));
}

void WebSocketEventHandler::handleEvent (const StatusChangeEvent& event)
{
	BackendUser* user = storage.getUserById (event.userId);

	if (!user) {
		return;
	}

	LOG_DEBUG ("User " << user->getDisplayName() << " is " << event.statusString);
	user->status = event.statusString;
	emit (user->onStatusChanged());
}

void WebSocketEventHandler::handleEvent (const NewDirectChannelEvent& event)
{
	LOG_DEBUG ("New Direct channel " << event.channelId << " created by: " << event.userId);
	backend.retrieveDirectChannel (event.channelId);
}

void WebSocketEventHandler::handleEvent (const NewUserEvent& event)
{
	LOG_DEBUG ("New User " << event.userId);
}

void WebSocketEventHandler::handleEvent (const UserUpdatedEvent& event)
{
	BackendUser* user = storage.getUserById (event.userID());

	/**
	 * When a new user is created, this is the first sent event about him
	 */
	if (!user) {
		LOG_DEBUG ("User updated: new user " << event.userID());
		storage.addUser (event.userObject);
	} else {
		QString updatedPropertiesString;
		user->updateFrom (BackendUser (event.userObject), updatedPropertiesString);
		LOG_DEBUG ("User updated: existing user " << user->getDisplayName()
		           << ". Modified properties:\n" << updatedPropertiesString);
	}
}

void WebSocketEventHandler::handleEvent (const UserAddedToChannelEvent& event)
{
	BackendTeam* team = storage.getTeamById (event.teamId);
	QString teamName = team ? team->name : event.teamId;

	BackendChannel* channel = storage.getChannelById (event.channelId);
	QString channelName = channel ? channel->name : event.channelId;

	BackendUser* user = storage.getUserById (event.userId);
	QString userName = user ? user->getDisplayName() : event.userId;

	LOG_DEBUG ("UserAddedToChannelEvent: User " << userName << " added to channel '" << channelName << "' of team '" << teamName << "'");

	if (team && !channel) { //new channel
		backend.retrieveChannel (*team, event.channelId);
	}


	auto addChannelMemberFn = [this, channel, team] (const BackendUser& user) {

		/**
		 * Retrieve the team member for this user, if no one
		 */
		if (team && team->members.count (user.id) == 0) {
			backend.retrieveTeamMember (*team, user);
		}

		/**
		 * if the channel does not exist, do not notify.
		 * When the channel is retrieved, it will contain the new user
		 */
		if (channel) {
			backend.retrieveChannelMember (*channel, user);
		}
	};

	if (!user) { //new user
		backend.retrieveUser (event.userId, addChannelMemberFn);
	} else {
		addChannelMemberFn (*user);
	}

	//todo: Add a team member if there is no one
}

void WebSocketEventHandler::handleEvent (const UserAddedToTeamEvent& event)
{
	BackendTeam* team = storage.getTeamById (event.teamId);
	QString teamName = team ? team->name : event.teamId;

	BackendUser* user = storage.getUserById (event.userId);
	QString userName = user ? user->getDisplayName() : event.userId;

	LOG_DEBUG ("UserAddedToTeamEvent: User '" << userName << "' added to team: '" << teamName << "'");

	if (!team) {
		LOG_DEBUG ("UserAddedToTeamEvent: No team " << teamName << " found. The team will be retrieved");
		backend.retrieveTeam (event.teamId);
		return;
	}

	if (!user) { //new user
		//as seen, this event is not sent when a new used is added to the team. To be tested
		LOG_DEBUG ("UserAddedToTeamEvent: No user for ID " << event.userId);
	} else {

		if (team) {
			backend.retrieveTeamMember (*team, *user);
		}
	}
}

void WebSocketEventHandler::handleEvent (const UserLeaveTeamEvent& event)
{
	BackendTeam* team = storage.getTeamById (event.teamId);
	QString teamName = team ? team->name : event.teamId;

	BackendUser* user = storage.getUserById (event.userId);
	QString userName = user ? user->getDisplayName() : event.userId;

	LOG_DEBUG ("UserLeaveTeamEvent: User '" << userName << "' left team '" << teamName << "'");

	if (!team || !user) {
		return;
	}

	//if the logged-in user is being removed, remove the team from the team list
	if (user->id == storage.loginUser->id) {
		for (auto &channel: team->channels) {
			emit channel->onLeave ();
		}

		emit (team->onLeave());
		storage.eraseTeam (team->id);
	} else {
		for (auto &channel: team->channels) {
			channel->members.remove (user->id);
			emit (channel->onUserRemoved (*user));
		}
		team->members.remove (user->id);
		emit (team->onUserRemoved (*user));
	}
	//printTeams ();
}

void WebSocketEventHandler::handleEvent (const UserRemovedFromChannelEvent& event)
{
	BackendChannel* channel = storage.getChannelById (event.channelId);
	QString channelName = channel ? channel->name : event.channelId;

	BackendUser* user = storage.getUserById (event.userId);
	QString userName = user ? user->getDisplayName() : event.userId;

	LOG_DEBUG ("UserRemovedFromChannelEvent: User '" << userName << "' left channel " << channelName << "'");

	if (!channel || !user) {
		return;
	}

	//if the logged-in user is being removed, remove the channel from the team's channel list
	if (user->id == storage.loginUser->id) {
		emit channel->onLeave ();
		storage.eraseChannel (*channel);
	} else {
		channel->members.remove (user->id);
		emit (channel->onUserRemoved (*user));
	}
}

void WebSocketEventHandler::handleEvent (const ChannelCreatedEvent& event)
{
	BackendTeam* team = storage.getTeamById (event.teamId);
	QString teamName = team ? team->name : event.teamId;

	LOG_DEBUG ("Channel created: " << event.channelId << " in team: " << teamName);

	if (!team) {
		return;
	}

	backend.retrieveChannel (*team, event.channelId);
}

void WebSocketEventHandler::handleEvent (const ChannelUpdatedEvent& event)
{
	BackendChannel* channel = storage.getChannelById (event.channelID);

	if (!channel) {
		return;
	}

	LOG_DEBUG ("Channel updated: " << channel->display_name);

	channel->display_name = event.displayName;
	channel->name = event.name;
	channel->header = event.header;
	channel->purpose = event.purpose;

	emit channel->onUpdated();
}

void WebSocketEventHandler::handleEvent (const OpenDialogEvent& event)
{
	backend.getServerDialogsMap().addEvent (event);
}

} /* namespace Mattermost */

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

#include "WebSocketEventHandler.h"
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
	BackendTeam* team = storage.getTeamById (event.teamId);
	QString teamName = team ? team->name : event.teamId;

	BackendChannel* channel = storage.getChannelById (event.channelId);

	if (!channel) {
		return;
	}

	QString channelName = channel ? channel->name : event.channelId;

	BackendPost* post = channel->addPost (event.postObject);

	LOG_DEBUG ("Post in  '" << teamName << "' : '" << channelName << "' by " << post->getDisplayAuthorName() << ": " << post->message);
	if (channel) {
		emit channel->onNewPost (*post);
		emit backend.onNewPost (*channel, *post);
	}
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

	BackendPost post (event.postObject);
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

void WebSocketEventHandler::handleEvent (const TypingEvent& event)
{
	BackendChannel* channel = storage.getChannelById(event.channel_id);

	BackendUser* user = storage.getUserById (event.user_id);

	if (!user || !channel) {
		return;
	}

	emit (channel->onUserTyping(*user));
}

void WebSocketEventHandler::handleEvent (const NewDirectChannelEvent& event)
{
	BackendTeam* team = &storage.directChannels;

	LOG_DEBUG ("New Direct channel " << event.channelId << " created by: " << event.userId);
	if (!team) {
		return;
	}

	backend.retrieveChannel (*team, event.channelId);
}

void WebSocketEventHandler::handleEvent (const UserAddedToChannelEvent& event)
{
	BackendTeam* team = storage.getTeamById (event.teamId);
	QString teamName = team ? team->name : event.teamId;

	BackendChannel* channel = storage.getChannelById (event.channelId);

	//new channel?
	if (team && !channel) {
		backend.retrieveChannel (*team, event.channelId);
	}

	BackendUser* user = storage.getUserById (event.userId);
	if (!user) {
		backend.retrieveUser (event.userId, [] (BackendUser&){});
	}

	LOG_DEBUG ("User " << event.userId << " added to channel " << event.channelId << " of team " << teamName);
}

void WebSocketEventHandler::handleEvent (const UserAddedToTeamEvent& event)
{
	BackendTeam* team = storage.getTeamById (event.team_id);
	QString teamName = team ? team->name : event.team_id;
	LOG_DEBUG ("User " << event.user_id << " added to team: " << teamName);

	//Adds the new team. It's channels and messages in channels will be obtained too
	if (!team) {
		backend.retrieveTeam (event.team_id);
	}
}

void WebSocketEventHandler::handleEvent (const UserLeaveTeamEvent& event)
{
	BackendTeam* team = storage.getTeamById (event.team_id);
	QString teamName = team ? team->name : event.team_id;

	LOG_DEBUG ("User " << event.user_id << " left team: " << teamName);
	emit (team->onLeave());

	storage.eraseTeam (team->id);
	//printTeams ();
}

void WebSocketEventHandler::handleEvent (const UserRemovedFromChannelEvent& event)
{
	BackendChannel* channel = storage.getChannelById (event.channelId);
	BackendUser* user = storage.getUserById (event.userId);

	LOG_DEBUG ("User " << event.userId << " left channel: " << event.channelId);

	if (!channel || !user) {
		return;
	}

	//if the logged-in user is being removed, remove the channel from the list
	if (user->id == storage.loginUser->id) {
		emit channel->onLeave ();
	}

	storage.eraseChannel (*channel);
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

} /* namespace Mattermost */

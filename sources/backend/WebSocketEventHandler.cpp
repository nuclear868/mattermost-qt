/**
 * @file WebSocketEventHandler.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Feb 18, 2022
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
	emit channel->onViewed ();
	emit backend.onChannelViewed (*channel);
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

void WebSocketEventHandler::handleEvent (const TypingEvent& event)
{
	BackendChannel* channel = storage.getChannelById(event.channel_id);

	BackendUser* user = storage.getUserById (event.user_id);

	if (!user || !channel) {
		//return;
	}
	//LOG_DEBUG ("User " << event.user_id << " left team: " << teamName);
	emit (channel->onUserTyping(*user));
}

void WebSocketEventHandler::handleEvent (const UserAddedEvent& event)
{
	BackendTeam* team = storage.getTeamById (event.team_id);
	QString teamName = team ? team->name : event.team_id;
	LOG_DEBUG ("User " << event.user_id << " added to: " << teamName);
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

	if (!channel) {
		return;
	}
#warning "TODO: Get channel's team and remove the channel"
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
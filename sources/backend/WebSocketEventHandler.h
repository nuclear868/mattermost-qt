/**
 * @file WebSocketEventHandler.h
 * @brief
 * @author Lyubomir Filipov
 * @date Feb 18, 2022
 */

#pragma once

#include "events/ChannelCreatedEvent.h"
#include "events/ChannelViewedEvent.h"
#include "events/PostEvent.h"
#include "events/PostDeletedEvent.h"
#include "events/TypingEvent.h"
#include "events/NewDirectChannelEvent.h"
#include "events/UserTeamEvent.h"
#include "events/UserRemovedFromChannelEvent.h"

namespace Mattermost {

class Backend;
class Storage;

class WebSocketEventHandler {
public:
	WebSocketEventHandler (Backend& backend);
	virtual ~WebSocketEventHandler ();
public:
	void handleEvent (const ChannelViewedEvent& event);
	void handleEvent (const PostEvent& event);
	void handleEvent (const PostDeletedEvent& event);
	void handleEvent (const TypingEvent& event);
	void handleEvent (const NewDirectChannelEvent& event);
	void handleEvent (const UserAddedEvent& event);
	void handleEvent (const UserAddedToTeamEvent& event);
	void handleEvent (const UserLeaveTeamEvent& event);
	void handleEvent (const UserRemovedFromChannelEvent& event);
	void handleEvent (const ChannelCreatedEvent& event);
private:
	Backend& backend;
	Storage& storage;

};

} /* namespace Mattermost */

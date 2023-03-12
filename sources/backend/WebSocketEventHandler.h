/**
 * @file WebSocketEventHandler.h
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

#pragma once

#include "events/ChannelCreatedEvent.h"
#include "events/ChannelUpdatedEvent.h"
#include "events/ChannelViewedEvent.h"
#include "events/PostEvent.h"
#include "events/PostEditedEvent.h"
#include "events/PostDeletedEvent.h"
#include "events/PostReactionAddedEvent.h"
#include "events/PostReactionRemovedEvent.h"
#include "events/TypingEvent.h"
#include "events/StatusChangeEvent.h"
#include "events/NewDirectChannelEvent.h"
#include "events/UserTeamEvent.h"
#include "events/UserAddedToChannelEvent.h"
#include "events/UserRemovedFromChannelEvent.h"
#include "events/OpenDialogEvent.h"

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
	void handleEvent (const PostEditedEvent& event);
	void handleEvent (const PostDeletedEvent& event);
	void handleEvent (const PostReactionAddedEvent& event);
	void handleEvent (const PostReactionRemovedEvent& event);
	void handleEvent (const TypingEvent& event);
	void handleEvent (const StatusChangeEvent& event);
	void handleEvent (const NewDirectChannelEvent& event);
	void handleEvent (const UserAddedToChannelEvent& event);
	void handleEvent (const UserAddedToTeamEvent& event);
	void handleEvent (const UserLeaveTeamEvent& event);
	void handleEvent (const UserRemovedFromChannelEvent& event);
	void handleEvent (const ChannelCreatedEvent& event);
	void handleEvent (const ChannelUpdatedEvent& event);
	void handleEvent (const OpenDialogEvent& event);
private:
	Backend& backend;
	Storage& storage;

};

} /* namespace Mattermost */

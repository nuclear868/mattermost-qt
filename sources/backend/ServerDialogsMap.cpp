/**
 * @file ServerDialogsMap.cpp
 * @brief Collection of dialogs, sent from the server
 * @author Lyubomir Filipov
 * @date Oct 17, 2022
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


#include "ServerDialogsMap.h"

#include <QJsonDocument>
#include <QTimer>
#include "Backend.h"
#include "log.h"

namespace Mattermost {

ServerDialogsMap::ServerDialogsMap (Backend& backend)
:backend (backend)
{
}

ServerDialogsMap::~ServerDialogsMap () = default;

/**
 * Receiver WebSocket event
 * @param event event
 */
void ServerDialogsMap::addEvent (const OpenDialogEvent& event)
{
	LOG_DEBUG ("ServerDialogsMap::total events: " << events.size());
	//LOG_DEBUG ("ServerDialogsMap::addEvent - WebSocket: " << event.triggerID);
	auto it = events.find (event.triggerID);

	bool hasHttpResponse = (it != events.end());

	if (hasHttpResponse) {	//if there is previous HTTP response, send the event
		sendEvent (event);
	} else {				//delete the event if no HTTP response comes
		events.insert (event.triggerID, event);
		QTimer::singleShot (5000, [this, triggerID = event.triggerID] {
			auto it = events.find (triggerID);
			if (it != events.end ()) {
				events.erase (it);
			}
		});
	}
}

/**
 * Received Http event
 * @param triggerID trigger ID
 */
void ServerDialogsMap::addEvent (const QString& triggerID)
{
	LOG_DEBUG ("ServerDialogsMap::total events: " << events.size());
	//LOG_DEBUG ("ServerDialogsMap::addEvent - HTTP: " << triggerID);

	auto it = events.find (triggerID);

	bool hasWsResponse = (it != events.end());

	if (hasWsResponse) { 	//if there is previous WS response, send the event
		sendEvent (*it);
	} else {				//delete the event if no WS response comes
		events.insert (triggerID, OpenDialogEvent (triggerID));
		QTimer::singleShot (5000, [this, triggerID] {
			auto it = events.find (triggerID);
			if (it != events.end ()) {
				events.erase (it);
			}
		});
	}
}

void ServerDialogsMap::sendEvent (const OpenDialogEvent& event)
{
	BackendChannel* currentChannel = backend.getCurrentChannel();

	if (!currentChannel) {
		LOG_DEBUG ("WebSocketEventHandler::handleEvent (OpenDialogEvent): no current channel set");
		return;
	}

	if (!currentChannel->team) {
		LOG_DEBUG ("WebSocketEventHandler::handleEvent (OpenDialogEvent): no current channel's team set");
		return;
	}

	QJsonObject json {
		{"channel_id", 	currentChannel->id},
		{"callback_id", event.callbackID},
		{"state", 		""},
		{"submission", 	QJsonObject()},
		{"team_id", 	currentChannel->team->id},
		{"url", 		event.url}
	};

	backend.sendSubmitDialog (QJsonDocument (json));

	auto it = events.find (event.triggerID);
	if (it != events.end ()) {
		events.erase (it);
	}
}

} /* namespace Mattermost */

/**
 * @file ServerDialogsMap.h
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


#pragma once

#include <QMap>
#include "fwd.h"

namespace Mattermost {

class OpenDialogEvent;

/**
 * Some Mattermost actions - for example, deleting a poll are represented by dialog events as follows:
 *
 * 1. The client sends a request to delete a poll (Backend::sendPostAction)
 * 2a. The server replies with "status": "OK", "trigger_id": "XXXX"
 * 2b. The server sends a websocket packet open_dialog with the same "trigger_id": "XXXX"
 * 3. The client sends submit dialog request (Backend::sendSubmitDialog), when both 2a and 2b happen
 *
 * if 2b is received, without 2a, nothing should be performed. This happens when the event is sent from another Mattermost client
 *
 */
class ServerDialogsMap {
public:
	ServerDialogsMap (Backend& backend);
	virtual ~ServerDialogsMap ();
public:
	void addEvent (const OpenDialogEvent& event);
	void addEvent (const QString& eventByTriggerID);
private:
	void sendEvent (const OpenDialogEvent& event);
private:
	QMap<QString, OpenDialogEvent> 	events;
	Backend&						backend;
};

} /* namespace Mattermost */

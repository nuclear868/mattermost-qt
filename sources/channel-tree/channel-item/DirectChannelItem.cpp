/**
 * @file DirectChannelItem.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Jun 22, 2022
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

#include "DirectChannelItem.h"

#include <QMenu>
#include "chat-area/ChatArea.h"
#include "backend/Backend.h"
#include "info-dialogs/UserProfileDialog.h"

namespace Mattermost {

void DirectChannelItem::showContextMenu (const QPoint& pos)
{
	// Create menu and insert some actions
	QMenu myMenu;

	ChatArea *chatArea = data(0, Qt::UserRole).value<ChatArea*>();
	BackendChannel& channel = chatArea->getChannel();
	BackendUser* user = chatArea->backend.getStorage().getUserById (channel.name);

	if (user) {
		myMenu.addAction ("View Profile", [this, user] {
			UserProfileDialog* dialog = new UserProfileDialog (*user, treeWidget());
			dialog->show ();
		});
	}

	myMenu.exec (pos);
}

} /* namespace Mattermost */

/**
 * @file DirectTeamItem.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Jun 21, 2022
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

#include "DirectTeamItem.h"

#include <QMenu>
#include "chat-area/ChatArea.h"
#include "backend/Backend.h"
#include "channel-tree/channel-item/DirectChannelItem.h"
#include "channel-tree-dialogs/UserListDialog.h"

namespace Mattermost {

ChannelItem* DirectTeamItem::createChannelItem (Backend& backend, ChannelItemWidget* itemWidget)
{
	return new DirectChannelItem (backend, itemWidget);
}

void DirectTeamItem::showContextMenu (const QPoint& pos)
{
	// Create menu and insert some actions
	QMenu myMenu;

	myMenu.addAction ("Add direct channel", [this] {
		qDebug() << "Add direct channel ";
		QSet<const BackendUser*> allDirectChannelUsers = backend.getStorage().directChannels.getAllMembers();

		UserListDialogConfig dialogCfg {
			"New Direct Channel - Mattermost",
			"Select a user to start direct message channel with:"
		};

		UserListDialog* dialog = new UserListDialog (dialogCfg, backend.getStorage().getAllUsers(), &allDirectChannelUsers, treeWidget());
		dialog->show ();

		connect (dialog, &UserListDialog::accepted, [this, dialog] {
			const BackendUser* user = dialog->getSelectedUser();

			if (!user) {
				qDebug() << "dialog->getSelectedUser() returned nullptr";
				return;
			}

			//if the channel already exists, switch to it
			const BackendChannel* existingChannel = backend.getStorage().getDirectChannelByUserId(user->id);
			if (existingChannel) {
				for (auto& chatArea: chatAreas) {
					if (&chatArea->channel == existingChannel) {
						qDebug() << "Open Direct channel requested with " << user->getDisplayName();
						treeWidget()->setCurrentItem (chatArea->treeItem);
						return;
					}
				}
			} else {
				qDebug() << "New Direct channel requested with " << user->getDisplayName();
				backend.createDirectChannel (*user);
			}

		});
	});

	myMenu.exec (pos);
}

} /* namespace Mattermost */

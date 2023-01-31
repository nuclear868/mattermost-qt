/**
 * @file GroupChannelItem.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Jun 22, 2022
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

#include "GroupChannelItem.h"

#include <QMenu>
#include <QMessageBox>
#include "chat-area/ChatArea.h"
#include "backend/Backend.h"
#include "info-dialogs/ChannelInfoDialog.h"
#include "channel-tree-dialogs/UserListDialogForTeam.h"
#include "channel-tree-dialogs/EditChannelPropertiesDialog.h"

namespace Mattermost {

void GroupChannelItem::showContextMenu (const QPoint& pos)
{
	// Create menu and insert some actions
	QMenu myMenu;

	ChatArea *chatArea = data(0, Qt::UserRole).value<ChatArea*>();
	BackendChannel& channel = chatArea->getChannel();

	myMenu.addAction ("View Channel details", [this, &channel] {
		ChannelInfoDialog* dialog = new ChannelInfoDialog (channel, treeWidget());
		dialog->show ();
	});

	myMenu.addAction ("View Channel members", [this, &channel] {
		qDebug() << "View Channel members ";

		std::vector<const BackendUser*> channelMembers;

		for (auto& it: channel.members) {

			if (!it.user) {
				qDebug () << "user " << it.user_id << " is nullptr";
				continue;
			}

			channelMembers.push_back (it.user);
		}

		UserListDialogConfig dialogCfg {
			"Team Members - Mattermost",
			"Members of channel '" + channel.display_name + "':"
		};

		UserListDialogForTeam* dialog = new UserListDialogForTeam (dialogCfg, channelMembers, treeWidget());
		dialog->show ();
	});

	myMenu.addAction ("Add new members to the channel", [this, &channel] {

		std::vector<const BackendUser*> availableUsers;

		for (auto& member: channel.team->members) {

			if (!member.user) {
				qDebug() << "null user with id " << member.user_id;
				continue;
			}

			availableUsers.emplace_back (member.user);
		}

		QSet<const BackendUser*> channelMembers = channel.getAllMembers();

		UserListDialogConfig dialogCfg {
			"Add user to channel - Mattermost",
			"Select a user to add to the '" + channel.display_name + "' channel:"
		};

		UserListDialog* dialog = new UserListDialog (dialogCfg, availableUsers, &channelMembers, treeWidget());
		dialog->show ();

		QObject::connect (dialog, &UserListDialog::accepted, [this, &channel, dialog] {
			const BackendUser* user = dialog->getSelectedUser();

			if (!user) {
				qDebug() << "dialog->getSelectedUser() returned nullptr";
				return;
			}

			backend.addUserToChannel (channel, user->id);
		});
	});

	myMenu.addAction ("Edit channel propeties", [this, &channel] {
		EditChannelPropertiesDialog* dialog = new EditChannelPropertiesDialog (channel);
		dialog->show ();

		QObject::connect (dialog, &EditChannelPropertiesDialog::accepted, [this, &channel, dialog] {
			backend.editChannelProperties (channel, dialog->getNewProperties ());
		});
	});

	myMenu.addAction ("Leave Channel", [this, &channel] {

		if (QMessageBox::question (treeWidget(), "Are you sure?", "Are you sure that you want to leave the '" + channel.display_name + "' channel?") == QMessageBox::Yes) {
			backend.leaveChannel (channel);
		}
	});

	myMenu.exec (pos);
}

} /* namespace Mattermost */

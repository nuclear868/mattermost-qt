/**
 * @file GroupTeamItem.cpp
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

#include "GroupTeamItem.h"

#include <QMenu>
#include "channel-tree/channel-item/GroupChannelItem.h"
#include "backend/Backend.h"
#include "channel-tree-dialogs/TeamChannelsListDialog.h"
#include "channel-tree-dialogs/UserListDialogForTeam.h"

namespace Mattermost {

ChannelItem* GroupTeamItem::createChannelItem (Backend& backend, ChannelItemWidget* itemWidget)
{
	return new GroupChannelItem (backend, itemWidget);
}

void GroupTeamItem::showContextMenu (const QPoint& pos)
{
	// Create menu and insert some actions
	QMenu myMenu;

	myMenu.addAction ("View Team Members", [this] {

		BackendTeam* team = backend.getStorage().getTeamById(teamId);

		if (!team) {
			return;
		}

		std::vector<BackendUser*> teamMembers;

		for (auto& it: team->members) {

			if (!it.user) {
				qDebug () << "user " << it.user_id << " is nullptr";
				continue;
			}

			teamMembers.push_back (it.user);
		}
		qDebug() << "View Team members " << team->members.size();

		UserListDialogForTeam* dialog = new UserListDialogForTeam (team->display_name, teamMembers, treeWidget());
		dialog->show ();
	});

	myMenu.addAction ("View Public Channels", [this] {
			BackendTeam* team = backend.getStorage().getTeamById(teamId);

			backend.retrieveTeamPublicChannels (team->id, [this, team] (std::list<BackendChannel>& channels) {
				TeamChannelsListDialog* dialog = new TeamChannelsListDialog (backend, team->display_name, channels, treeWidget());
				dialog->show ();
			});
	});

	myMenu.exec (pos);
}

} /* namespace Mattermost */

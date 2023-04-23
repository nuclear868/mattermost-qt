/**
 * @file ViewTeamMembersListDialog.cpp
 * @brief 'View Team Members' context menu item dialog
 * @author Lyubomir Filipov
 * @date Apr 17, 2023
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

#include "ViewTeamMembersListDialog.h"

#include <QMenu>
#include "backend/types/BackendTeam.h"
#include "backend/Backend.h"

namespace Mattermost {

ViewTeamMembersListDialog::ViewTeamMembersListDialog (Backend& backend, const BackendTeam& team, QWidget* parent)
:UserListDialog (parent)
,team (team)
,backend (backend)
{
	FilterListDialogConfig dialogCfg {
		"Team Members - Mattermost",
		"Members of team '" + team.display_name + "':",
		"Filter users by name:",
		QDialogButtonBox::Close,
		""
	};

	std::set<UserListEntry> entrySet;

	for (auto& it: team.members) {
		if (it.user) {
			entrySet.emplace (it);
		}
	}

	create (dialogCfg, entrySet, {"Full Name", "Status"});

	connect (&team, &BackendTeam::onUserAdded, [this] (const BackendUser&) {

	});

	connect (&team, &BackendTeam::onUserRemoved, [this] (const BackendUser& user) {
		removeRowByData (&user);
	});
}

ViewTeamMembersListDialog::~ViewTeamMembersListDialog () = default;

void ViewTeamMembersListDialog::addContextMenuActions (QMenu& menu, const QVariant& selectedItemData)
{
	BackendUser *user = selectedItemData.value<BackendUser*>();

	if (!user) {
		qDebug() << "No user at pointed item";
		return;
	}

	UserListDialog::addContextMenuActions (menu, selectedItemData);

	menu.addAction ("Remove from team", [this, user] {
		backend.removeUserFromTeam (team, user->id);
	});
}

} /* namespace Mattermost */

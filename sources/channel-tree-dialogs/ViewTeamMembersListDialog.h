/**
 * @file ViewTeamMembersListDialog.h
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

#pragma once

#include "UserListDialog.h"

namespace Mattermost {

class ViewTeamMembersListDialog: public UserListDialog {
public:
	ViewTeamMembersListDialog (Backend& backend, const BackendTeam& team, QWidget *parent);
	virtual ~ViewTeamMembersListDialog ();
private:
	void addContextMenuActions (QMenu& menu, const QVariant& selectedItemData)		override;
private:
	const BackendTeam&		team;
	Backend& 				backend;
};

} /* namespace Mattermost */

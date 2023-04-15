/**
 * @file UserListDialog.h
 * @brief
 * @author Lyubomir Filipov
 * @date Apr 16, 2022
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

#include <set>
#include "FilterListDialog.h"

namespace Mattermost {

class BackendTeamMember;
class BackendChannelMember;
class UserListEntry;

class UserListDialog: public FilterListDialog {
public:
	//"Add direct channel"
	UserListDialog (const FilterListDialogConfig& cfg, const std::map<QString, BackendUser>& allUsers, const QSet<const BackendUser*>* alreadyExistingUsers, QWidget *parent);

	//"View Channel members"
	UserListDialog (const FilterListDialogConfig& cfg, const QList<BackendChannelMember>& allTeamMembers, QWidget *parent);

	//"View Team members"
	UserListDialog (const FilterListDialogConfig& cfg, const QList<BackendTeamMember>& allTeamMembers, QWidget *parent);

	UserListDialog (const FilterListDialogConfig& cfg, const std::vector<const BackendUser*>& allUsers, const QSet<const BackendUser*>* alreadyExistingUsers, QWidget *parent);
	virtual ~UserListDialog ();
public:
    const BackendUser* getSelectedUser ();
    void showContextMenu (const QPoint& pos, QVariant&& selectedItemData)	override;
    void setItemCountLabel (uint32_t count) 								override;
private:

    struct NameComparator {
    	bool operator () (const BackendUser* const& lhs, const BackendUser* const& rhs);
    };
    void create (const FilterListDialogConfig& cfg, const std::set<UserListEntry>& users, const QStringList& columnNames);

};

using ViewTeamMembersDialog = UserListDialog;
using ViewChannelMembersDialog = UserListDialog;

} /* namespace Mattermost */

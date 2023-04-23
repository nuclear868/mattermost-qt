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

#include <array>
#include <set>
#include <QVariant>
#include "FilterListDialog.h"

class QTableWidgetItem;

namespace Mattermost {

class BackendTeamMember;
class BackendChannelMember;
class UserListEntry;

class UserListDialog: public FilterListDialog {
public:
	using FilterListDialog::FilterListDialog;

	//"Add direct channel"
	UserListDialog (const FilterListDialogConfig& cfg, const std::map<QString, BackendUser>& allUsers, const QSet<const BackendUser*>* alreadyExistingUsers, QWidget *parent);

	UserListDialog (const FilterListDialogConfig& cfg, const std::vector<const BackendUser*>& allUsers, const QSet<const BackendUser*>* alreadyExistingUsers, QWidget *parent);
	virtual ~UserListDialog ();
public:
    const BackendUser* getSelectedUser ();
    void addContextMenuActions (QMenu& menu, const QVariant& selectedItemData)	override;
    void setItemCountLabel (uint32_t count) 								override;
    void removeRowByData (const BackendUser& user);
protected:
    void create (const FilterListDialogConfig& cfg, const std::set<UserListEntry>& users, const QStringList& columnNames);

    QMap<const BackendUser*, QTableWidgetItem*> dataToItemMap;
};

using ViewTeamMembersDialog = UserListDialog;

struct UserListEntry {
public:

	enum fields {
		userName,
		userStatus,
		userMessageCount,
	};

	UserListEntry (const BackendTeamMember& teamMember);
	UserListEntry (const BackendChannelMember& teamMember);
	UserListEntry (const BackendUser* user, bool disabledItem = false);
	bool operator < (const UserListEntry& other) const
	{
		return fields[userName] < other.fields[userName];
	}
public:
	const QByteArray*		userAvatar;
	const BackendUser*		dataPointer;

	std::array<QString, 4> 	fields;
	bool					disabledItem;
	bool					highlight;
};


} /* namespace Mattermost */

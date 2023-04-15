/**
 * @file UserListDialog.cpp
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

#include "UserListDialog.h"

#include <set>
#include <QMenu>
#include <QDebug>
#include <QDateTime>
#include "backend/types/BackendUser.h"
#include "backend/types/BackendTeamMember.h"
#include "backend/types/BackendChannelMember.h"
#include "info-dialogs/UserProfileDialog.h"
#include "ui_FilterListDialog.h"


namespace Mattermost {

bool UserListDialog::NameComparator::operator () (const BackendUser*const& lhs, const BackendUser*const& rhs)
{
	return lhs->username < rhs->username;
}


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
	QVariant				dataPointer;

	std::array<QString, 4> 	fields;
	bool					disabledItem;
	bool					highlight;
};


inline UserListEntry::UserListEntry (const BackendUser* user, bool disabledItem)
:disabledItem (disabledItem)
,highlight (false)
{
	if (!user) {
		return;
	}

	fields[userName] = user->getDisplayName();

	if (!user->nickname.isEmpty()) {
		fields[userName] += " (" + user->nickname + ")";
	}

	userAvatar = &user->avatar;
	fields[userStatus] = user->status;
	dataPointer = QVariant::fromValue ((BackendUser*)user);

}

inline UserListEntry::UserListEntry (const BackendTeamMember& teamMember)
:UserListEntry (teamMember.user)
{
	if (teamMember.isAdmin) {
		highlight = true;
	}
}

static QString timeToString (uint64_t timestamp)
{
	QDate currentDate = QDateTime::currentDateTime().date();
	QDateTime targetTime = QDateTime::fromMSecsSinceEpoch (timestamp);
	QDate targetDate = targetTime.date();

	QString format;

	if (currentDate.year() != targetDate.year()) {
		format = "dd MMM yyyy, hh:mm:ss";
	} else {
		format = "dd MMM, hh:mm:ss";
	}

	return targetTime.toString (format);
}

inline UserListEntry::UserListEntry (const BackendChannelMember& channelMember)
:UserListEntry (channelMember.user)
{
//	QString timeString;
//	int64_t diffSeconds = (QDateTime::currentMSecsSinceEpoch() - channelMember.last_viewed_at) / 1000;
//
//
//	int64_t secondsInDay = 3600 * 24;
//	int64_t secondsInHour = 3600;
//	int64_t secondsInMinute = 60;
//
//
//	if (diffSeconds > secondsInDay) {
//		int64_t days = diffSeconds / secondsInDay;
//		timeString += QString::number (days) + " days, ";
//		diffSeconds %= days * secondsInDay;
//	}
//
//	if (diffSeconds > secondsInHour) {
//		int64_t hours = diffSeconds / secondsInHour;
//		timeString += QString::number (hours) + " hours";
//		diffSeconds %= hours * secondsInHour;
//	}
//
//	if (diffSeconds > secondsInMinute) {
//		int64_t minutes = diffSeconds / secondsInMinute;
//		timeString += QString::number (minutes) + " minutes";
//		diffSeconds %= minutes * secondsInMinute;
//	}

	fields[userMessageCount] = timeToString (channelMember.last_viewed_at);

	if (channelMember.isAdmin) {
		highlight = true;
	}
}

UserListDialog::UserListDialog (const FilterListDialogConfig& cfg, const std::map<QString, BackendUser>& allUsers, const QSet<const BackendUser*>* alreadyExistingUsers, QWidget* parent)
:FilterListDialog (parent)
{
	std::set<UserListEntry> entrySet;

	for (auto& it: allUsers) {
		bool isAlreadyExisting = alreadyExistingUsers->find (&it.second) != alreadyExistingUsers->end();
		entrySet.emplace (&it.second, isAlreadyExisting);
	}

	create (cfg, entrySet, {"Full Name", "Status"});
}

UserListDialog::UserListDialog (const FilterListDialogConfig& cfg, const QList<BackendTeamMember>& allTeamMembers, QWidget* parent)
:FilterListDialog (parent)
{
	std::set<UserListEntry> entrySet;

	for (auto& it: allTeamMembers) {
		if (it.user) {
			entrySet.emplace (it);
		}
	}

	create (cfg, entrySet, {"Full Name", "Status"});
}

UserListDialog::UserListDialog (const FilterListDialogConfig& cfg, const QList<BackendChannelMember>& allChannelMembers, QWidget* parent)
:FilterListDialog (parent)
{
	std::set<UserListEntry> entrySet;

	for (auto& it: allChannelMembers) {
		if (it.user) {
			entrySet.emplace (it);
		}
	}

	create (cfg, entrySet, {"Full Name", "Status", "Channel was last viewed"});
}

UserListDialog::UserListDialog (const FilterListDialogConfig& cfg, const std::vector<const BackendUser*>& allUsers, const QSet<const BackendUser*>* alreadyExistingUsers, QWidget* parent)
:FilterListDialog (parent)
{
    std::set<UserListEntry> entrySet;

	for (auto& it: allUsers) {
		bool isAlreadyExisting = alreadyExistingUsers->find (it) != alreadyExistingUsers->end();
		entrySet.emplace (it, isAlreadyExisting);
	}

    create (cfg, entrySet, {"Full Name", "Status"});
}

UserListDialog::~UserListDialog () = default;

const BackendUser* UserListDialog::getSelectedUser ()
{
	auto selection = ui->tableWidget->selectedItems();

	if (selection.size() == 0) {
		return nullptr;
	}

	return selection.first()->data(Qt::UserRole).value<BackendUser*>();
}

void UserListDialog::create (const FilterListDialogConfig& cfg, const std::set<UserListEntry>& users, const QStringList& columnNames)
{
	FilterListDialog::create (cfg);

	//2 columns: name (with image) and status
	ui->tableWidget->setColumnCount (columnNames.size());
	for (int i = 0; i < columnNames.size(); ++i) {
		ui->tableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(columnNames[i]));

		if (i > 0) {
			ui->tableWidget->horizontalHeader()->setSectionResizeMode (i, QHeaderView::ResizeToContents);
		}
	}

	ui->tableWidget->setRowCount (users.size());
	uint32_t usersCount = 0;

	for (const UserListEntry& entry: users) {

		QTableWidgetItem* nameItem = new QTableWidgetItem (QIcon(QPixmap::fromImage(QImage::fromData (*entry.userAvatar))), entry.fields[0]);
		nameItem->setData (Qt::UserRole, entry.dataPointer);
		ui->tableWidget->setItem (usersCount, 0, nameItem);

		/**
		 * Mark entries for already existing users, so that they can be distinguished. They will be still selectable.
		 */
		if (entry.disabledItem) {
			nameItem->setForeground (QBrush (QColor (150,150,150)));
			nameItem->setToolTip (entry.fields[0] + cfg.disabledItemTooltip);
		}

		/**
		 * Highlight entry (for example, for users with admin roles)
		 */
		if (entry.highlight) {
			QFont font (nameItem->font());
			font.setBold(true);
			nameItem->setFont(font);
		}

		for (int fi = 1; fi < columnNames.size(); ++fi) {
			ui->tableWidget->setItem (usersCount, fi, new QTableWidgetItem (entry.fields[fi]));
		}

		++usersCount;
	}

	ui->tableWidget->setIconSize(QSize (24,24));
	ui->tableWidget->horizontalHeader()->setSectionResizeMode (0, QHeaderView::Stretch);

	setItemCountLabel (usersCount);
}

void UserListDialog::setItemCountLabel (uint32_t count)
{
	ui->usersCountLabel->setText(QString::number(count) + (count == 1 ? " user" : " users"));
}

void UserListDialog::showContextMenu (const QPoint& pos, QVariant&& selectedItemData)
{
	// Create menu and insert some actions
	QMenu myMenu;

	BackendUser *user = selectedItemData.value<BackendUser*>();

	if (!user) {
		qDebug() << "No user at pointed item at " << pos;
		return;
	}

	//direct channel
	myMenu.addAction ("View Profile", [this, user] {
	//	qDebug() << "View Profile for " << user->getDisplayName();
		UserProfileDialog* dialog = new UserProfileDialog (*user, ui->tableWidget);
		dialog->show ();
	});

	// Handle global position
	QPoint globalPos = ui->tableWidget->mapToGlobal (pos);
	myMenu.exec (globalPos + QPoint (15, 35));
}

} /* namespace Mattermost */


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

#include "UserListDialog.h"

#include <set>
#include <QMenu>
#include "backend/types/BackendUser.h"
#include "info-dialogs/UserProfileDialog.h"
#include "ui_FilterListDialog.h"


namespace Mattermost {

namespace {

auto nameComparator = [] (const BackendUser* const& lhs, const BackendUser* const& rhs)
{
	return lhs->username < rhs->username;
};

}

UserListDialog::UserListDialog (const std::map<QString, BackendUser>& users, QWidget* parent)
:FilterListDialog (parent)
{
	std::set<const BackendUser*, decltype (nameComparator)> set (nameComparator);

	for (auto& it: users) {
		set.insert (&it.second);
	}

	uint32_t usersCount = 0;
	for (auto& user: set) {
		QString displayName (user->getDisplayName());

		if (!user->nickname.isEmpty()) {
			displayName += " (" + user->nickname + ")";
		}

		QTreeWidgetItem* item = new QTreeWidgetItem (ui->treeWidget, QStringList() << displayName << user->status);
		QImage img = QImage::fromData (user->avatar);
		item->setIcon (0, QIcon(QPixmap::fromImage(QImage::fromData (user->avatar)).scaled(32, 32)));
		item->setData (0, Qt::UserRole, QVariant::fromValue ((BackendUser*)user));
		ui->treeWidget->addTopLevelItem (item);
		++usersCount;
	}

	ui->treeWidget->header()->setSectionResizeMode (0, QHeaderView::Stretch);
	ui->treeWidget->header()->setSectionResizeMode (1, QHeaderView::ResizeToContents);
	ui->usersCountLabel->setText(QString::number(usersCount) + " users");
}

UserListDialog::UserListDialog (const std::vector<BackendUser*>& users, QWidget* parent)
:FilterListDialog (parent)
{
    std::set<const BackendUser*, decltype (nameComparator)> set (nameComparator);

    for (auto& it: users) {
    	set.insert (it);
    }

    uint32_t usersCount = 0;
    for (auto& user: set) {
    	QString displayName (user->getDisplayName());

    	if (!user->nickname.isEmpty()) {
    		displayName += " (" + user->nickname + ")";
    	}

    	QTreeWidgetItem* item = new QTreeWidgetItem (ui->treeWidget, QStringList() << displayName << user->status);
    	QImage img = QImage::fromData (user->avatar);
    	item->setIcon (0, QIcon(QPixmap::fromImage(QImage::fromData (user->avatar)).scaled(32, 32)));
    	item->setData (0, Qt::UserRole, QVariant::fromValue ((BackendUser*)user));
    	ui->treeWidget->addTopLevelItem (item);
    	++usersCount;
    }

    ui->treeWidget->header()->setSectionResizeMode (0, QHeaderView::Stretch);
    ui->treeWidget->header()->setSectionResizeMode (1, QHeaderView::ResizeToContents);
    ui->usersCountLabel->setText(QString::number(usersCount) + " users");
}

UserListDialog::~UserListDialog () = default;

const BackendUser* UserListDialog::getSelectedUser ()
{
	auto selection = ui->treeWidget->selectedItems();

	if (selection.size() == 0) {
		return nullptr;
	}

	return selection.first()->data(0, Qt::UserRole).value<BackendUser*>();
}

void UserListDialog::showContextMenu (const QPoint& pos)
{
	// Create menu and insert some actions
	QMenu myMenu;

	// Handle global position
	QPoint globalPos = ui->treeWidget->mapToGlobal(pos);

	QTreeWidgetItem* pointedItem = ui->treeWidget->itemAt(pos);

	if (!pointedItem) {
		return;
	}

	BackendUser *user = pointedItem->data(0, Qt::UserRole).value<BackendUser*>();

	//direct channel
	myMenu.addAction ("View Profile", [this, user] {
	//	qDebug() << "View Profile for " << user->getDisplayName();
		UserProfileDialog* dialog = new UserProfileDialog (*user, ui->treeWidget);
		dialog->show ();
	});

	myMenu.exec (globalPos + QPoint (15, 35));
}

} /* namespace Mattermost */

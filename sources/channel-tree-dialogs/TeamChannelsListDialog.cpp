/**
 * @file TeamChannelsListDialog.cpp
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

#include "TeamChannelsListDialog.h"

#include <set>
#include <QMenu>
#include "backend/Backend.h"
#include "backend/types/BackendChannel.h"
#include "info-dialogs/ChannelInfoDialog.h"
#include "ui_FilterListDialog.h"


namespace Mattermost {

namespace {

auto nameComparator = [] (const BackendChannel* const& lhs, const BackendChannel* const& rhs)
{
	return lhs->name < rhs->name;
};

}

TeamChannelsListDialog::TeamChannelsListDialog (Backend& backend, FilterListDialogConfig& cfg, const std::list<BackendChannel>& channels, QWidget *parent)
:FilterListDialog (parent)
,backend (backend)
{
	create (cfg, channels, {"Channel Name", "Channel Header"});
}

TeamChannelsListDialog::~TeamChannelsListDialog () = default;

void TeamChannelsListDialog::create (const FilterListDialogConfig& cfg, const std::list<BackendChannel>& channels, const QStringList& columnNames)
{
	FilterListDialog::create (cfg);

	//2 columns: Channel Name and Channel Header
	ui->tableWidget->setColumnCount (columnNames.size());
	for (int i = 0; i < columnNames.size(); ++i) {
		ui->tableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(columnNames[i]));

		if (i > 0) {
			ui->tableWidget->horizontalHeader()->setSectionResizeMode (i, QHeaderView::ResizeToContents);
		}
	}

	std::set<const BackendChannel*, decltype (nameComparator)> set (nameComparator);

	for (auto& it: channels) {
		set.insert (&it);
	}

	ui->tableWidget->setRowCount (set.size());
	uint32_t channelsCount = 0;

	for (auto& channel: set) {

		QTableWidgetItem* nameItem = new QTableWidgetItem (channel->display_name);
		ui->tableWidget->setItem (channelsCount, 0, nameItem);
		nameItem->setData (Qt::UserRole, QVariant::fromValue ((BackendChannel*)channel));

		QTableWidgetItem* headerItem = new QTableWidgetItem (channel->header);
		ui->tableWidget->setItem (channelsCount, 1, headerItem);
		++channelsCount;
	}

	ui->tableWidget->horizontalHeader()->setSectionResizeMode (0, QHeaderView::ResizeToContents);
	ui->tableWidget->horizontalHeader()->setSectionResizeMode (1, QHeaderView::Stretch);
	ui->tableWidget->resizeRowsToContents();

	setItemCountLabel (channelsCount);
	connect (ui->tableWidget->horizontalHeader(), &QHeaderView::sectionResized, ui->tableWidget, &QTableWidget::resizeRowsToContents);
}

void TeamChannelsListDialog::setItemCountLabel (uint32_t count)
{
	ui->usersCountLabel->setText(QString::number(count) + (count == 1 ? " channel" : " channels"));
}

void TeamChannelsListDialog::showContextMenu (const QPoint& pos, QVariant&& selectedItemData)
{
	// Create menu and insert some actions
	QMenu myMenu;

	BackendChannel *channel = selectedItemData.value<BackendChannel*>();

	if (!channel) {
		qDebug() << "No channel at pointed item at " << pos;
		return;
	}

	//direct channel
	myMenu.addAction ("Join this channel", [this, channel] {
		backend.joinChannel (*channel);
	//	qDebug() << "View Profile for " << user->getDisplayName();
		//UserProfileDialog* dialog = new UserProfileDialog (*user, ui->treeWidget);
		//dialog->show ();
	});

	myMenu.addAction ("View channel details", [this, channel] {
		ChannelInfoDialog* dialog = new ChannelInfoDialog (*channel, this);
		dialog->show ();
	});

	// Handle global position
	QPoint globalPos = ui->tableWidget->mapToGlobal(pos);
	myMenu.exec (globalPos + QPoint (15, 35));
}

} /* namespace Mattermost */

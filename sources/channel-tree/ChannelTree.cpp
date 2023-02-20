/**
 * @file ChannelTree.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 18, 2021
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

#include "ChannelTree.h"
#include <QHeaderView>
#include <QStackedWidget>
#include "chat-area/ChatArea.h"
#include "team-item/DirectTeamItem.h"
#include "team-item/GroupTeamItem.h"
#include "backend/types/BackendTeam.h"
#include "backend/Backend.h"
#include "log.h"

namespace Mattermost {

ChannelTree::ChannelTree (QWidget* parent)
:QTreeWidget (parent)
{
	connect (this, &QTreeWidget::customContextMenuRequested, this, &ChannelTree::showContextMenu);

	connect (this, &QTreeWidget::currentItemChanged, [this] (QTreeWidgetItem* item, QTreeWidgetItem*) {
		ChatArea *newPage = item->data(0, Qt::UserRole).value<ChatArea*>();

		if (!newPage) {
			qCritical() << "chatArea is null";
			return;
		}

		//same page, nothing to do
		if (newPage == getCurrentPage ()) {
			return;
		}

		chatAreaStackedWidget->setCurrentWidget (newPage);
		newPage->onActivate ();

		qDebug() << "Item Activated: " << newPage->channel.display_name;

	#if 0
		if (channelsWithNewPosts.remove (&currentPage->getChannel())) {
			setNotificationsCountVisualization (channelsWithNewPosts.size());
		}
	#endif
	});

//	setColumnCount (2);
//	setIconSize (QSize(24,24));
//	header()->resizeSection(0 /*column index*/, 50 /*width*/);
//	header()->resizeSection(1 /*column index*/, 50 /*width*/);
}

ChannelTree::~ChannelTree () = default;

bool ChannelTree::isChannelActive (const BackendChannel& channel)
{
	return getCurrentPage () && &getCurrentPage()->getChannel() == &channel;
}

/**
 * For this team, performs the following actions:
 * 1. adds an entry in the teamComboBox
 * 2. creates a QTreeWidgetItem for this team
 * 3. gets all channels of the team, where the user is member and creates QTreeWidgetItem for each of them
 */
void ChannelTree::addTeam (Backend& backend, BackendTeam& team)
{
	TeamItem* teamList = new GroupTeamItem (*this, backend, team.display_name, team.id);

	addTopLevelItem (teamList);
	header()->setSectionResizeMode(0, QHeaderView::Stretch);
	header()->setSectionResizeMode(1, QHeaderView::ResizeToContents);

	connect (&team, &BackendTeam::onNewChannel, [this, teamList] (BackendChannel& channel) {
		teamList->addChannel (channel, parentWidget(), chatAreaStackedWidget);
	});

	connect (&team, &BackendTeam::onLeave, [this, &team, teamList] {
		int index = indexOfTopLevelItem (teamList);

		if (index == -1) {
			qDebug() << "remove team " << team.display_name << ": indexOfTopLevelItem returned -1";
			return;
		}

		qDebug() << "delete() team " << team.id;
		QTreeWidgetItem* item = takeTopLevelItem (index);

		delete (item);
	});

	backend.retrieveOwnChannelMembershipsForTeam (team, [this, teamList] (BackendChannel& channel) {
		teamList->addChannel (channel, parentWidget(), chatAreaStackedWidget);
	});

	backend.retrieveTeamMembers (team);
}

void ChannelTree::addGroupChannelsList (Backend& backend)
{
	auto& team = backend.getStorage().groupChannels;

	//Do not add group channel menu, if no group channels
	if (team.channels.empty()) {
		return;
	}

	TeamItem* teamList = new DirectTeamItem (*this, backend, "Group Channels", "0");

	addTopLevelItem (teamList);
	header()->setSectionResizeMode(0, QHeaderView::Stretch);
	header()->setSectionResizeMode(1, QHeaderView::ResizeToContents);

	connect (&team, &BackendDirectChannelsTeam::onNewChannel, [this, teamList] (BackendChannel& channel) {
		teamList->addChannel (channel, parentWidget(), chatAreaStackedWidget);
	});

	for (auto &channel: team.channels) {
		teamList->addChannel (*channel, parentWidget(), chatAreaStackedWidget);
	}
}

void ChannelTree::addDirectChannelsList (Backend& backend)
{
	TeamItem* teamList = new DirectTeamItem (*this, backend, "Direct Channels", "0");

	auto& team = backend.getStorage().directChannels;

	addTopLevelItem (teamList);
	header()->setSectionResizeMode(0, QHeaderView::Stretch);
	header()->setSectionResizeMode(1, QHeaderView::ResizeToContents);

	connect (&team, &BackendDirectChannelsTeam::onNewChannel, [this, teamList] (BackendChannel& channel) {
		teamList->addChannel (channel, this, chatAreaStackedWidget);
	});

	for (auto &channel: team.channels) {
		teamList->addChannel (*channel, this, chatAreaStackedWidget);
	}
}

void ChannelTree::setChatAreaStackedWidget (QStackedWidget* chatAreaStackedWidget)
{
	this->chatAreaStackedWidget = chatAreaStackedWidget;
}

void ChannelTree::openChannel (QString channelID)
{
	auto it = channelToItemMap.find (channelID);

	if (it == channelToItemMap.end()) {
		qDebug() << "openChannel " << channelID << ": channel not found";
		return;
	}

	setCurrentItem (it.value());
}

void ChannelTree::addChannelToItem (QString channelID, QTreeWidgetItem* item)
{
	channelToItemMap[channelID] = item;
}

void ChannelTree::removeChannelToItem (QString channelID)
{
	channelToItemMap.remove (channelID);
}

void ChannelTree::showContextMenu (const QPoint& pos)
{
	// Handle global position
	QPoint globalPos = mapToGlobal(pos);

	ChannelTreeItem* pointedItem = static_cast<ChannelTreeItem*> (itemAt(pos));
	pointedItem->showContextMenu (globalPos + QPoint (25, 15));
}

ChatArea* ChannelTree::getCurrentPage ()
{
	return static_cast<ChatArea*> (chatAreaStackedWidget->currentWidget());
}


} /* namespace Mattermost */


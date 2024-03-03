/**
 * @file ChannelTree.h
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

#pragma once

#include <QVector>
#include <QTreeWidget>

class QStackedWidget;
class QListWidget;
class QTreeWidgetItem;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace Mattermost {

class Backend;
class BackendChannel;
class BackendTeam;
class ChatArea;
class TeamItem;
class ChannelItem;

class ChannelTree: public QTreeWidget {
	Q_OBJECT
public:
	ChannelTree (QWidget* parent = nullptr);
	virtual ~ChannelTree ();
public:
	bool isChannelActive (const BackendChannel& channel);

	void addTeam (Backend& backend, BackendTeam& team);
	void addDirectChannelsList (Backend& backend);
	void addGroupChannelsList (Backend& backend);

	void setChatAreaStackedWidget (QStackedWidget* chatAreaStackedWidget);
	ChatArea* getCurrentPage ();

	void openChannel (QString channelID);
	void addChannelToItem (QString channelID, QTreeWidgetItem* item);
	void removeChannelToItem (QString channelID);
private:
	void showContextMenu (const QPoint& pos);
	QStackedWidget*						chatAreaStackedWidget = nullptr;
	QMap<QString, QTreeWidgetItem*>		channelToItemMap;
};

} /* namespace Mattermost */


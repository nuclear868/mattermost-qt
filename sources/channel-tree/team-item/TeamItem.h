/**
 * @file TeamItem.h
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 27, 2021
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

#include "channel-tree/ChannelTreeItem.h"
#include <QObject>

class QListWidget;
class QTreeWidgetItem;
class QTreeWidget;
class QStackedWidget;
class ChannelItemWidget;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace Mattermost {

class Backend;
class BackendTeam;
class BackendChannel;
class ChannelItem;

class TeamItem: public QObject, public ChannelTreeItem {
	Q_OBJECT
public:
	TeamItem (QTreeWidget& parent, Backend& backend, const QString& name, const QString& teamId);
	virtual ~TeamItem ();
public:
	void addChannel (BackendChannel& channel, QWidget *parent, QStackedWidget* chatAreaParent);
	virtual ChannelItem* createChannelItem (Backend& backend, ChannelItemWidget* itemWidget) = 0;
private:
	int getChannelIndex (const BackendChannel& channel);
public:
	Backend&							backend;
	QString								teamId;
};

} /* namespace Mattermost */


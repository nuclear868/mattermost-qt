/**
 * @file ChannelTreeItem.h
 * @brief
 * @author Lyubomir Filipov
 * @date Mar 31, 2022
 */

#pragma once

#include <QTreeWidgetItem>

namespace Mattermost {

class ChannelTreeItem: public QTreeWidgetItem {
public:
	using QTreeWidgetItem::QTreeWidgetItem;
public:
	virtual void showContextMenu (const QPoint& pos) = 0;
};

} /* namespace Mattermost */

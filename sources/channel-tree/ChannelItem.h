/**
 * @file ChannelItem.h
 * @brief
 * @author Lyubomir Filipov
 * @date Mar 30, 2022
 */

#pragma once

#include "ChannelTreeItem.h"

class ChannelItemWidget;

namespace Mattermost {

class ChannelItem: public ChannelTreeItem {
public:
	explicit ChannelItem (QTreeWidgetItem *parent, ChannelItemWidget* widget);
	virtual ~ChannelItem ();
public:
    void setIcon (const QIcon &icon);
    void setLabel (const QString& label);
    void showContextMenu (const QPoint& pos) override;
private:
    ChannelItemWidget* widget;
};

} /* namespace Mattermost */

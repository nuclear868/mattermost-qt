/**
 * @file ChannelItem.h
 * @brief
 * @author Lyubomir Filipov
 * @date Mar 30, 2022
 */

#pragma once

#include <QTreeWidgetItem>

class ChannelItemWidget;

namespace Mattermost {

class ChannelItem: public QTreeWidgetItem {
public:
	explicit ChannelItem (QTreeWidgetItem *parent, ChannelItemWidget* widget);
	virtual ~ChannelItem ();
public:
    void setIcon (const QIcon &icon);
    void setLabel (const QString& label);
private:
    ChannelItemWidget* widget;
};

} /* namespace Mattermost */

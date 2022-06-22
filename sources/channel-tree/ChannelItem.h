/**
 * @file ChannelItem.h
 * @brief
 * @author Lyubomir Filipov
 * @date Mar 30, 2022
 */

#pragma once

#include "ChannelTreeItem.h"
#include "fwd.h"

class ChannelItemWidget;

namespace Mattermost {

class ChannelItem: public ChannelTreeItem {
public:
	explicit ChannelItem (Backend& backend, ChannelItemWidget* widget);
	virtual ~ChannelItem ();
public:
    void setIcon (const QIcon &icon);
    void setLabel (const QString& label);
protected:
    Backend& 			backend;
    ChannelItemWidget* 	widget;
};

} /* namespace Mattermost */

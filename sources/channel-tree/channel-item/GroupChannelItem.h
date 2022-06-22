/**
 * @file GroupChannelItem.h
 * @brief
 * @author Lyubomir Filipov
 * @date Jun 22, 2022
 */

#pragma once

#include "channel-tree/ChannelItem.h"

namespace Mattermost {

class GroupChannelItem: public ChannelItem {
public:
	using ChannelItem::ChannelItem;
public:
	void showContextMenu (const QPoint& pos) override;
};

} /* namespace Mattermost */

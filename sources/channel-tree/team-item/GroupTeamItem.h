/**
 * @file GroupTeamItem.h
 * @brief
 * @author Lyubomir Filipov
 * @date Jun 21, 2022
 */

#pragma once

#include "TeamItem.h"

namespace Mattermost {

class GroupTeamItem: public TeamItem {
public:
	using TeamItem::TeamItem;
protected:
	ChannelItem* createChannelItem (Backend& backend, ChannelItemWidget* itemWidget) 	override;
	void showContextMenu (const QPoint& pos)											override;
};

} /* namespace Mattermost */

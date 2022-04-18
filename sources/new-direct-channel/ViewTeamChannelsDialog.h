/**
 * @file ViewTeamChannelsDialog.h
 * @brief
 * @author Lyubomir Filipov
 * @date Apr 16, 2022
 */

#pragma once

#include <list>
#include "FilterListDialog.h"

namespace Mattermost {

class ViewTeamChannelsDialog: public FilterListDialog {
public:
	ViewTeamChannelsDialog (const QString& teamName, const std::list<BackendChannel>& channels, QWidget *parent = nullptr);
	virtual ~ViewTeamChannelsDialog ();
public:
	void showContextMenu (const QPoint& pos)	override;
};

} /* namespace Mattermost */

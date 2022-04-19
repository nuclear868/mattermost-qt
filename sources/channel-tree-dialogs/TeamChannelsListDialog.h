/**
 * @file TeamChannelsListDialog.h
 * @brief
 * @author Lyubomir Filipov
 * @date Apr 16, 2022
 */

#pragma once

#include <list>
#include "FilterListDialog.h"

namespace Mattermost {

class TeamChannelsListDialog: public FilterListDialog {
public:
	TeamChannelsListDialog (const QString& teamName, const std::list<BackendChannel>& channels, QWidget *parent = nullptr);
	virtual ~TeamChannelsListDialog ();
public:
	void showContextMenu (const QPoint& pos)	override;
};

} /* namespace Mattermost */

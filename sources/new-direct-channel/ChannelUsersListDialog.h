/**
 * @file ChannelUsersListDialog.h
 * @brief
 * @author Lyubomir Filipov
 * @date Apr 10, 2022
 */

#pragma once

#include "UserListDialog.h"

namespace Mattermost {

class ChannelUsersListDialog: public UserListDialog {
public:
	ChannelUsersListDialog (const QString& teamName, const std::vector<BackendUser*>& users, QWidget *parent = nullptr);
	virtual ~ChannelUsersListDialog ();
};

} /* namespace Mattermost */

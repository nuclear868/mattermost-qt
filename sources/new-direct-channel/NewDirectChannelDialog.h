/**
 * @file NewDirectChannelDialog.h
 * @brief
 * @author Lyubomir Filipov
 * @date Apr 10, 2022
 */

#pragma once

#include "UserListDialog.h"
#include "ui_FilterListDialog.h"

namespace Mattermost {

class NewDirectChannelDialog: public UserListDialog {
public:
	NewDirectChannelDialog (const std::map<QString, BackendUser>& users, QWidget *parent);
private:
};

} /* namespace Mattermost */

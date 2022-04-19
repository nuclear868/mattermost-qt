/**
 * @file UserListDialogForNewDirect.h
 * @brief
 * @author Lyubomir Filipov
 * @date Apr 10, 2022
 */

#pragma once

#include "UserListDialog.h"
#include "ui_FilterListDialog.h"

namespace Mattermost {

class UserListDialogForNewDirect: public UserListDialog {
public:
	UserListDialogForNewDirect (const std::map<QString, BackendUser>& users, QWidget *parent);
private:
};

} /* namespace Mattermost */

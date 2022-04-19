/**
 * @file UserListDialogForTeam.h
 * @brief
 * @author Lyubomir Filipov
 * @date Apr 10, 2022
 */

#pragma once

#include "UserListDialog.h"

namespace Mattermost {

class UserListDialogForTeam: public UserListDialog {
public:
	UserListDialogForTeam (const QString& teamName, const std::vector<BackendUser*>& users, QWidget *parent = nullptr);
	virtual ~UserListDialogForTeam ();
};

} /* namespace Mattermost */

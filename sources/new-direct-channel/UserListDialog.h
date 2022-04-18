/**
 * @file UserListDialog.h
 * @brief
 * @author Lyubomir Filipov
 * @date Apr 16, 2022
 */

#pragma once

#include "FilterListDialog.h"

namespace Mattermost {

class UserListDialog: public FilterListDialog {
public:
	UserListDialog (const std::map<QString, BackendUser>& users, QWidget *parent);
	UserListDialog (const std::vector<BackendUser*>& users, QWidget *parent);
	virtual ~UserListDialog ();
public:
    const BackendUser* getSelectedUser ();
    void showContextMenu (const QPoint& pos)	override;
};

} /* namespace Mattermost */

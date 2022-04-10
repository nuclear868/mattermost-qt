/**
 * @file NewDirectChannelDialog.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Apr 10, 2022
 */

#include "NewDirectChannelDialog.h"

namespace Mattermost {

NewDirectChannelDialog::NewDirectChannelDialog (const std::map<QString, BackendUser>& users, QWidget* parent)
:UserListDialog (users, parent)
{
	ui->selectUserLabel->setText(QCoreApplication::translate("UserListDialog", "Select a user to start direct message with", nullptr));
}

} /* namespace Mattermost */

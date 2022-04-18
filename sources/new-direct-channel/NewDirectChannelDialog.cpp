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
	setWindowTitle("New Direct Channel - Mattermost");
	ui->selectUserLabel->setText(QCoreApplication::translate("FilterListDialog", "Select a user to start direct message with:", nullptr));
}

} /* namespace Mattermost */

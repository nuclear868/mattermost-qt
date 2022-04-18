/**
 * @file ChannelUsersListDialog.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Apr 10, 2022
 */

#include "ChannelUsersListDialog.h"
#include "ui_FilterListDialog.h"

namespace Mattermost {

ChannelUsersListDialog::ChannelUsersListDialog (const QString& teamName, const std::vector<BackendUser*>& users, QWidget *parent)
:UserListDialog (users, parent)
{
	setWindowTitle("Team Members - Mattermost");
	ui->selectUserLabel->setText ("Members of team '" + teamName + "':");
	ui->buttonBox->setStandardButtons(QDialogButtonBox::Close);
}

ChannelUsersListDialog::~ChannelUsersListDialog () = default;

} /* namespace Mattermost */

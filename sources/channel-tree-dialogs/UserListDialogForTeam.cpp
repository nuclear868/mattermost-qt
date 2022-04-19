/**
 * @file UserListDialogForTeam.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Apr 10, 2022
 */

#include "UserListDialogForTeam.h"
#include "ui_FilterListDialog.h"

namespace Mattermost {

UserListDialogForTeam::UserListDialogForTeam (const QString& teamName, const std::vector<BackendUser*>& users, QWidget *parent)
:UserListDialog (users, parent)
{
	setWindowTitle("Team Members - Mattermost");
	ui->selectUserLabel->setText ("Members of team '" + teamName + "':");
	ui->buttonBox->setStandardButtons(QDialogButtonBox::Close);
}

UserListDialogForTeam::~UserListDialogForTeam () = default;

} /* namespace Mattermost */

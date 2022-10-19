/**
 * @file AddUserToChannelDialog.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Oct 18, 2022
 *
 * Copyright 2021, 2022 Lyubomir Filipov
 *
 * This file is part of Mattermost-QT.
 *
 * Mattermost-QT is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Mattermost-QT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Mattermost-QT; if not, see https://www.gnu.org/licenses/.
 */

#include "AddUserToChannelDialog.h"
#include "ui_FilterListDialog.h"

namespace Mattermost {

AddUserToChannelDialog::AddUserToChannelDialog (const std::vector<BackendUser*>& allUsers, const QSet<const BackendUser*>* alreadyExistingUsers, const QString& channelName, QWidget* parent)
:UserListDialog (allUsers, alreadyExistingUsers, parent)
{
	setWindowTitle("Add user to channel - Mattermost");
	QString str ("Select a user to add to the " + channelName + " channel:");
	ui->selectUserLabel->setText(QCoreApplication::translate("FilterListDialog", str.toStdString().c_str(), nullptr));
}

} /* namespace Mattermost */

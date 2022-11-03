/**
 * @file UserListDialogForTeam.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Apr 10, 2022
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

#include "UserListDialogForTeam.h"
#include "ui_FilterListDialog.h"

namespace Mattermost {

UserListDialogForTeam::UserListDialogForTeam (const UserListDialogConfig& cfg, const std::vector<const BackendUser*>& users, QWidget *parent)
:UserListDialog (cfg, users, nullptr, parent)
{
	ui->buttonBox->setStandardButtons(QDialogButtonBox::Close);
}

UserListDialogForTeam::~UserListDialogForTeam () = default;

} /* namespace Mattermost */

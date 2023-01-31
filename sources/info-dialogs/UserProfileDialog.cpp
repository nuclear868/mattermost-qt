/**
 * Copyright 2021, 2022 Lyubomir Filipov
 *
 * This file is part of Mattermost-QT.
 *
 * Mattermost-QT is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Mattermost-QT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Mattermost-QT. if not, see https://www.gnu.org/licenses/.
 */

#include "UserProfileDialog.h"
#include "ui_UserProfileDialog.h"

#include "backend/types/BackendUser.h"

namespace Mattermost {

static QString getString (const QString& str)
{
	return str.isEmpty() ? "N/A" : str;
}

UserProfileDialog::UserProfileDialog (const BackendUser& user, QWidget *parent)
:QDialog(parent)
,ui(new Ui::UserProfileDialog)
{
    ui->setupUi(this);

    setWindowTitle ("Profile for " + user.getDisplayName() + " - Mattermost");

	QImage img = QImage::fromData (user.avatar).scaled (128, 128, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->avatar->setPixmap (QPixmap::fromImage(img));
    ui->fullnameValue->setText (user.first_name + " " + user.last_name);
    ui->nicknameValue->setText (getString (user.nickname));
    ui->usernameValue->setText (user.username);
    ui->emailValue->setText (user.email);
    ui->positionValue->setText (getString (user.position));
    ui->statusValue->setText (user.status);
    ui->timezoneValue->setText (user.timezone.automaticTimezone);
}

UserProfileDialog::~UserProfileDialog()
{
    delete ui;
}

} /* namespace Mattermost */

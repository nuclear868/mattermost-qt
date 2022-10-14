/**
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

#include "EditChannelPropertiesDialog.h"
#include "ui_EditChannelPropertiesDialog.h"

#include "backend/types/BackendChannel.h"

namespace Mattermost {

EditChannelPropertiesDialog::EditChannelPropertiesDialog (const BackendChannel& channel, QWidget *parent)
:QDialog(parent)
,ui(new Ui::EditChannelPropertiesDialog)
{
    ui->setupUi(this);

    setWindowTitle ("Edit properties for channel '" + channel.display_name + "' - Mattermost");

    ui->displayNameValue->setText (channel.display_name);
    ui->channelHeaderValue->setText (channel.header);
	ui->purposeValue->setText (channel.purpose);
}

EditChannelPropertiesDialog::~EditChannelPropertiesDialog()
{
    delete ui;
}

BackendChannelProperties EditChannelPropertiesDialog::getNewProperties ()
{
	BackendChannelProperties ret;
	ret.displayName = ui->displayNameValue->text ();
	ret.header = ui->channelHeaderValue->toPlainText ();
	ret.purpose = ui->purposeValue->toPlainText ();
	return ret;
}

} /* namespace Mattermost */

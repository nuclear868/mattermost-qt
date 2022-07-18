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

#include "ChannelInfoDialog.h"
#include "ui_ChannelInfoDialog.h"

#include "backend/types/BackendChannel.h"
#include "backend/types/BackendTeam.h"

namespace Mattermost {

static QString getString (const QString& str)
{
	return str.isEmpty() ? "N/A" : str;
}


ChannelInfoDialog::ChannelInfoDialog (const BackendChannel& channel, QWidget *parent)
:QDialog(parent)
,ui(new Ui::ChannelInfoDialog)
{
    ui->setupUi(this);

    setWindowTitle ("Information for channel '" + channel.display_name + "' - Mattermost");

    ui->nameValue->setText (channel.name);
	ui->teamValue->setText (channel.team ? channel.team->display_name : "N/A");
    ui->headerValue->setText (getString (channel.header));
	ui->purposeValue->setText (getString (channel.purpose));
    ui->creatorValue->setText (channel.creator ? channel.creator->getDisplayName() : "N/A");
    ui->messageCountValue->setText (QString::number (channel.total_msg_count));
}

ChannelInfoDialog::~ChannelInfoDialog()
{
    delete ui;
}

} /* namespace Mattermost */

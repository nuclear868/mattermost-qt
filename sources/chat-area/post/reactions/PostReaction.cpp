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

#include "PostReaction.h"
#include "backend/types/BackendPost.h"
#include "ui_PostReaction.h"

namespace Mattermost {

PostReaction::PostReaction (const QString& emojiName, const QString& emojiValue, const BackendPostReaction& reactionData, QWidget *parent)
:QWidget(parent)
,ui(new Ui::PostReaction)
{
    ui->setupUi (this);

    QString emojiWidgetValue (emojiValue);
    emojiWidgetValue.replace("width=32 height=32", "width=20 height=20");
    ui->emoji->setText (emojiWidgetValue);
    ui->count->setText (QString::number (reactionData.size()));

    QString tooltip (emojiName + "  " + emojiValue + "\n");

    for (auto& it: reactionData) {
    	tooltip += it + "\n";
    }

    //remove the last '\n'
    tooltip.chop (1);
    setToolTip (tooltip);

	QPalette pal = palette();
	pal.setColor(QPalette::Base, QColor (230,230,230));
	setAutoFillBackground(true);
    setPalette(pal);
}

PostReaction::~PostReaction()
{
    delete ui;
}

} /* namespace Mattermost */

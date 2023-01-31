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

#include "PostReactionList.h"

#include <QLabel>
#include "PostReaction.h"
#include "ui_PostReactionList.h"

namespace Mattermost {

PostReactionList::PostReactionList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PostReactionList)
{
    ui->setupUi(this);
}

PostReactionList::~PostReactionList()
{
    delete ui;
}

void PostReactionList::addReaction (const QString& emojiName, const QString& emojiValue, const BackendPostReaction& reactionData)
{
	PostReaction* reaction = new PostReaction (emojiName, emojiValue, reactionData, this);
	ui->horizontalLayout_2->addWidget (reaction, 0, Qt::AlignLeft);
}

} /* namespace Mattermost */

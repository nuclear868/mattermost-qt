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

#include "PostSeparatorWidget.h"
#include "ui_PostSeparatorWidget.h"

PostSeparatorWidget::PostSeparatorWidget (const QString& text)
:QWidget(nullptr)
,ui(new Ui::PostSeparatorWidget)
{
    ui->setupUi(this);
    setText (text);
}

PostSeparatorWidget::~PostSeparatorWidget()
{
    delete ui;
}

void PostSeparatorWidget::setText (const QString& text)
{
	ui->label->setText (text);
}


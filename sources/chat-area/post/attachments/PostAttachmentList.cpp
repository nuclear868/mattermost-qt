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

#include "PostAttachmentList.h"
#include "ui_PostAttachmentList.h"

#include <QLabel>
#include <QDebug>
#include <QListWidgetItem>
#include "AttachedBinaryFile.h"
#include "AttachedImageFile.h"
#include "AttachedVideoFile.h"
#include "../PostWidget.h"
#include "backend/types/BackendFile.h"

namespace Mattermost {

PostAttachmentList::PostAttachmentList (Backend& backend, QWidget *parent)
:QWidget(parent)
,backend (backend)
,ui (new Ui::PostAttachmentList)
{
    ui->setupUi(this);
    ui->listWidget->viewport()->setAutoFillBackground(false);
}

PostAttachmentList::~PostAttachmentList()
{
    delete ui;
}

void PostAttachmentList::addFile (const BackendFile& file, const QString& authorName)
{
	QListWidgetItem* newItem = new QListWidgetItem();
	QWidget* fileWidget = nullptr;

	bool sizeKnown = true;

#if BUILD_MULTIMEDIA
	if (file.name.endsWith(".mp4", Qt::CaseInsensitive) || file.name.endsWith(".mov", Qt::CaseInsensitive)) {
		fileWidget = new AttachedVideoFile (backend, file, this);
	} else
#endif
	if (file.mini_preview.isEmpty()) {
		fileWidget = new AttachedBinaryFile (backend, file, this);
	} else {
		fileWidget = new AttachedImageFile (backend, file, authorName, this);
		sizeKnown = false;
		connect ((AttachedImageFile*)fileWidget, &AttachedImageFile::dimensionsChanged, [newItem, fileWidget, this] {
			newItem->setSizeHint(QSize (fileWidget->width(), fileWidget->height() + 10));

			PostWidget* widget = static_cast<PostWidget*> (parent());
			//ui->listWidget->setMinimumSize(ui->listWidget->sizeHint());
			//ui->listWidget->setMaximumSize(ui->listWidget->sizeHint());
			adjustSize();
			//widget->adjustSize();
			emit widget->dimensionsChanged ();
		});
	}

	ui->listWidget->addItem (newItem);
	ui->listWidget->setItemWidget (newItem, fileWidget);

	if (sizeKnown) {
		newItem->setSizeHint(QSize (fileWidget->width(), fileWidget->height() + 10));
		//ui->listWidget->updateGeometry();
		return;
	}
}

} /* namespace Mattermost */


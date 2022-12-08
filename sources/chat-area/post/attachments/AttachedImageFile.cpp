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

#include "AttachedImageFile.h"
#include "ui_AttachedImageFile.h"

#include <QDebug>
#include <QSettings>
#include "backend/types/BackendFile.h"
#include "Settings.h"

namespace Mattermost {

AttachedImageFile::AttachedImageFile(const BackendFile& file, QWidget *parent)
:QWidget(parent)
,ui(new Ui::AttachedImageFile)
{
    ui->setupUi(this);

    QImage img = QImage::fromData (file.mini_preview);
    ui->imageName->setText (file.name);
    ui->imagePreview->setPixmap (QPixmap::fromImage(img));

    if (file.contents.isEmpty()) {
    	connect (&file, &BackendFile::onContentsAvailable, [&file, /*label, newItem, authorName, */this] (const QByteArray& fileContents){

			QSettings settings;

			int maxWidth = settings.value(DOWNLOAD_IMAGE_MAX_WIDTH, 500).toInt();
			int maxHeight = settings.value(DOWNLOAD_IMAGE_MAX_HEIGHT, 500).toInt();

			QImage img = QImage::fromData (fileContents);
			if (img.width() > maxWidth) {
				img = img.scaledToWidth (maxWidth, Qt::SmoothTransformation);
			}

			if (img.height() > maxHeight) {
				img = img.scaledToHeight (maxHeight, Qt::SmoothTransformation);
			}

			ui->imagePreview->setPixmap (QPixmap::fromImage(img));
			ui->imagePreview->adjustSize();

			adjustSize();
			//parentWidget()->adjustSize();
    	});
    }
}

AttachedImageFile::~AttachedImageFile()
{
    delete ui;
}

} /* namespace Mattermost */

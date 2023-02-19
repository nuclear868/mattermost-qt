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

#include "AttachedImageFile.h"
#include "ui_AttachedImageFile.h"

#include <QDebug>
#include <QFileDialog>
#include <QSettings>
#include <QMenu>
#include "backend/types/BackendFile.h"
#include "backend/Backend.h"
#include "Settings.h"

namespace Mattermost {

std::map <const QWidget*, FilePreview*> AttachedImageFile::currentlyOpenFiles;

AttachedImageFile::AttachedImageFile (Backend& backend, const BackendFile& file, const QString& authorName, QWidget *parent)
:QWidget(parent)
,ui(new Ui::AttachedImageFile)
{
    ui->setupUi(this);

    QImage img = QImage::fromData (file.mini_preview);
    ui->imageName->setText (file.name);
    ui->imagePreview->setPixmap (QPixmap::fromImage(img));

    backend.retrieveFile (file.id, [&file, authorName, this] (const QByteArray& fileContents){

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

		filePreviewData = FilePreviewData {fileContents, file.name, authorName};

		emit dimensionsChanged ();
		//parentWidget()->adjustSize();
	});

	connect (this, &QWidget::customContextMenuRequested, [this, &backend, &file] (const QPoint& pos) {
		QMenu menu (this);

		menu.addAction("Save image", [this, &backend, &file] {
			QSettings settings;
			QDir downloadDir = settings.value(DOWNLOAD_LOCATION, QDir::currentPath()).toString();
			QString saveFileDestination = QFileDialog::getSaveFileName (this, "Save image as... - Mattermost", downloadDir.filePath(file.name));

			//the user has pressed the cancel button
			if (saveFileDestination.isEmpty()) {
				return;
			}

			backend.retrieveFile (file.id, [&backend, saveFileDestination] (const QByteArray& fileContents) {
				QFile destFile (saveFileDestination);
				destFile.open (QIODevice::WriteOnly);
				destFile.write (fileContents);
				destFile.close ();
			});

		});

		menu.exec (mapToGlobal(pos) + QPoint (10, 0));
	});
}

AttachedImageFile::~AttachedImageFile()
{
    delete ui;
}

void AttachedImageFile::mouseReleaseEvent (QMouseEvent*)
{
	qDebug() << "mouseRelease";
	auto openFile = currentlyOpenFiles.find (this);

	FilePreview* filePreview;

	/*
	 * If the file's Preview window is currently open, show it.
	 * Otherwise, open a new Preview eindow
	 */
	if (openFile == currentlyOpenFiles.end()) {
		auto it = currentlyOpenFiles.emplace (this, new FilePreview (filePreviewData, nullptr));
		filePreview = it.first->second;
		filePreview->setAttribute (Qt::WA_DeleteOnClose);
		filePreview->show ();

		connect (filePreview, &QDialog::rejected, [this] {
				qDebug() << "Rejected";
				currentlyOpenFiles.erase (this);
		});
	} else {
		filePreview = openFile->second;
		filePreview->raise ();
	}
}

} /* namespace Mattermost */

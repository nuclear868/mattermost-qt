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

#include <QMimeDatabase>
#include <QStyle>
#include <QDesktopServices>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include "Settings.h"
#include "AttachedBinaryFile.h"
#include "ui_AttachedBinaryFile.h"
#include "backend/types/BackendFile.h"
#include "backend/Backend.h"
#include "config/Config.h"

namespace Mattermost {

AttachedBinaryFile::AttachedBinaryFile (Backend& backend, const BackendFile& file, QWidget *parent)
:QWidget(parent)
,ui(new Ui::AttachedBinaryFile)
{
	ui->setupUi(this);
	ui->fileNameLabel->setText ("File: " + file.name);
	ui->downloadedLabel->setText ("");

	static QLocale locale = QLocale::system();
	locale.formattedDataSize (file.size, 2, QLocale::DataSizeTraditionalFormat);
	ui->fileSizeLabel->setText ("Size: " + locale.formattedDataSize (file.size, 2, QLocale::DataSizeTraditionalFormat));

	setFileMimeIcon (file.name);

	/*
	 * Download the file to provided destination
	 */
	connect (ui->downloadButton, &QPushButton::clicked, [this, &backend, &file] {

		QSettings settings;
		QDir downloadDir = settings.value(DOWNLOAD_LOCATION, QDir::currentPath()).toString();
		QString fileDestination (downloadDir.filePath(file.name));
		QFileInfo fileInfo (fileDestination);

		if (fileInfo.isFile() && (uint64_t)fileInfo.size() == file.size) {

			QMessageBox *msgBox = new QMessageBox (QMessageBox::Question,
					"File exists - Mattermost",
					"The file '" + file.name + "' is already downloaded to \n'" + downloadDir.absolutePath() + "'");

			msgBox->setInformativeText("Please choose:");
			msgBox->setStandardButtons(QMessageBox::Open);
			msgBox->addButton ("Download Again", QMessageBox::AcceptRole);
			QPushButton* openButton = msgBox->addButton ("Open File", QMessageBox::AcceptRole);
			msgBox->setStandardButtons(QMessageBox::Cancel);
			msgBox->setDefaultButton(QMessageBox::Cancel);
			msgBox->exec();

			if (msgBox->clickedButton() == msgBox->button(QMessageBox::Cancel)) {
				return; //do nothing
			} else if (msgBox->clickedButton() == openButton) {
				QDesktopServices::openUrl ("file://" + fileDestination);
				return;
			}
			//download again
		}

		ui->openButton->setDisabled (true);
		backend.retrieveFile (file.id, [this, &file, downloadDir] (const QByteArray& data){

			QString fileDestination (downloadDir.filePath(file.name));

			QFile destFile (fileDestination);
			destFile.open (QIODevice::WriteOnly);
			destFile.write (data);
			destFile.close ();
			ui->downloadedLabel->setText ("File downloaded to '" + downloadDir.absolutePath() + "'");
			downloadedPath = fileDestination;
			ui->openButton->setDisabled (false);
		});

		ui->downloadedLabel->setText ("Downloading...");
	});

	/*
	 * Download the file to the temp dir and open it
	 */
	connect (ui->openButton, &QPushButton::clicked, [this, &backend, &file] {

		if (!downloadedPath.isEmpty()) {
			QDesktopServices::openUrl ("file://" + downloadedPath);
			return;
		}

		backend.retrieveFile (file.id, [this, &file] (const QByteArray& data){

			QString tmpName (file.name);
			int dot = tmpName.indexOf (".");

			tmpName.insert (dot, "XXXXXX");


			tempFile.setFileTemplate (Config::tempDirectory().filePath (tmpName));
			bool result = tempFile.open ();

			if (!result) {
				qDebug() << tempFile.errorString();
				return;
			}

			tempFile.write (data);
			tempFile.close ();
			QDesktopServices::openUrl ("file://" + tempFile.fileName());
		});
	});
}

AttachedBinaryFile::~AttachedBinaryFile()
{
    delete ui;
}

void AttachedBinaryFile::setFileMimeIcon (const QString& filename)
{
	static QMimeDatabase mimeDatabase;

	QMimeType mimeType = mimeDatabase.mimeTypeForUrl (filename);

	QIcon icon = QIcon::fromTheme (mimeType.iconName());

	ui->fileTypeLabel->setText ("Type: " + mimeType.name());

	if (icon.isNull()) {
		icon = QApplication::style()->standardIcon(QStyle::SP_FileIcon);
	}

	if (!icon.isNull()) {
		//QPixmap pixmap = icon.pixmap (QSize (32, 32));
		QPixmap pixmap = icon.pixmap (QSize (64, 64));
		ui->fileIcon->setPixmap (pixmap);
		ui->fileIcon->setFixedSize (pixmap.size());
	}
}

} /* namespace Mattermost */

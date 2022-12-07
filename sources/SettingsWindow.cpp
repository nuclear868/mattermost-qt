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

#include "SettingsWindow.h"

#include <QFileDialog>
#include <QSettings>
#include <QIntValidator>
#include <QStandardPaths>
#include "ui_SettingsWindow.h"

namespace Mattermost {

static const char* DOWNLOAD_LOCATION = "config/downloadLocation";
static const char* DOWNLOAD_ASK = "config/downloadAsk";
static const char* DOWNLOAD_IMAGE_MAX_WIDTH = "config/imageMaxWidth";
static const char* DOWNLOAD_IMAGE_MAX_HEIGHT = "config/imageMaxHeight";

SettingsWindow::SettingsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsWindow)
{
	ui->setupUi(this);
	ui->imageMaxWidthValue->setValidator(new QIntValidator (10, 1000, this));
	ui->imageMaxHeightValue->setValidator(new QIntValidator (10, 1000, this));

	QString defaultDownloadDir (QStandardPaths::writableLocation (QStandardPaths::DownloadLocation));

	QSettings settings;
	ui->downloadLocationValue->setText (settings.value (DOWNLOAD_LOCATION, defaultDownloadDir).toString());
	ui->askLocationCheckBox->setChecked (settings.value (DOWNLOAD_ASK, 0).toBool());
	ui->imageMaxWidthValue->setText (settings.value (DOWNLOAD_IMAGE_MAX_WIDTH, 400).toString());
	ui->imageMaxHeightValue->setText (settings.value (DOWNLOAD_IMAGE_MAX_HEIGHT, 400).toString());

	connect (ui->downloadLocationButton, &QPushButton::clicked, [this] {
		QDir defaultDir (ui->downloadLocationValue->text());

		if (!defaultDir.exists()) {
			defaultDir = QDir::home();
		}
		ui->downloadLocationValue->setText (QFileDialog::getExistingDirectory (this, "Select destination directory", defaultDir.absolutePath()));
	});
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::applyNewSettings ()
{
	QSettings settings;
	settings.setValue (DOWNLOAD_LOCATION, ui->downloadLocationValue->text());
	settings.setValue (DOWNLOAD_ASK, ui->askLocationCheckBox->text());
	settings.setValue (DOWNLOAD_IMAGE_MAX_WIDTH, ui->imageMaxWidthValue->text());
	settings.setValue (DOWNLOAD_IMAGE_MAX_HEIGHT, ui->imageMaxHeightValue->text());
	settings.sync ();
}

} /* namespace Mattermost */

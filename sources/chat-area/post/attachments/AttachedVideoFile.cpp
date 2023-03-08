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

#include "build-config.h"

#if BUILD_MULTIMEDIA

#include "AttachedVideoFile.h"
#include <QBuffer>
#include "ui_AttachedVideoFile.h"
#include "backend/types/BackendFile.h"
#include "backend/Backend.h"

namespace Mattermost {

AttachedVideoFile::AttachedVideoFile (Backend& backend, BackendFile& file, QWidget *parent)
:QWidget (parent)
,ui (new Ui::AttachedVideoFile)
,backend (backend)
,file (file)
,init (true)
{
    ui->setupUi(this);
    videoWidget = new QVideoWidget (parent);
    mediaPlayer = new QMediaPlayer ();

	ui->videoName->setText (file.name);
	ui->verticalLayout->addWidget (videoWidget);
	mediaPlayer->setVideoOutput (videoWidget);
	videoWidget->show ();

	//sudo apt install gstreamer1.0-libav
}

AttachedVideoFile::~AttachedVideoFile()
{
    delete ui;
}

void AttachedVideoFile::mousePressEvent (QMouseEvent* event)
{
	backend.retrieveFile (file.id, [this] (const QByteArray& data) {
		qDebug() << "=====================PLAY VIDEO!!==============";
		QByteArray* fileContentsCopy = new QByteArray (data);
		QBuffer* mediaStream = new QBuffer (fileContentsCopy);
		mediaStream->open(QIODevice::ReadOnly);
		mediaPlayer->setMedia (QMediaContent(), mediaStream);
		mediaPlayer->play();
	});
}

} /* namespace Mattermost */

#endif //BUILD_MULTIMEDIA

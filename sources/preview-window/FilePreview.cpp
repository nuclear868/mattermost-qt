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

#include "FilePreview.h"
#include "ui_FilePreview.h"

#include <QResizeEvent>
#include <QDesktopWidget>
#include <QDebug>

namespace Mattermost  {

FilePreview::FilePreview (const FilePreviewData& file, QWidget *parent)
:QDialog(parent)
,ui(new Ui::FilePreview)
{
	ui->setupUi(this);
	setWindowTitle(file.fileName + " [" + file.fileAuthor + "] - Mattermost");

	QImage img = QImage::fromData (file.fileContents);
	pixmap = QPixmap::fromImage(img);
	ui->fileContents->setPixmap (pixmap);
	ui->fileContents->setMinimumSize (getMinimumSize (pixmap));

	ui->fileInfo->setText (file.fileName);
	adjustSize();

	resizeTimer.setSingleShot (true);
	connect (&resizeTimer, &QTimer::timeout, [this] {
		resize (newWindowSize);
	});
}

FilePreview::~FilePreview()
{
    delete ui;
}

QSize FilePreview::getMinimumSize (const QPixmap& pixmap)
{
	QSize ret = pixmap.size();

	QRect screenGeometry = QApplication::desktop()->screenGeometry (this);

	screenGeometry.setWidth(screenGeometry.width() * 0.9);
	screenGeometry.setHeight(screenGeometry.height() * 0.8);

	ret.scale (std::min (pixmap.width(), screenGeometry.width()), std::min (pixmap.height(), screenGeometry.height()), Qt::KeepAspectRatio);
	return ret;
}

void FilePreview::resizeEvent (QResizeEvent* event)
{
	//new window size
	QSize newWindowSize (event->size());

	//difference between the current and the previous size. Used to determine whether the user wants to expand or to shrink the window
	QSize diff (event->size() - event->oldSize());
	//qDebug () << "Window Resize to:" << event->size();

	/*
	 * Apply the new size in order to get the new image size
	 */
	QDialog::resizeEvent (event);

	/*
	 * Get the new image size. It will be scaled, so that the aspect ratio is preserved
	 */
	QSize newImageSize (ui->fileContents->size());
	//qDebug () << "Image Resize to:" << newImageSize;

	QSize newImageSizeScaled (pixmap.size());

	//if the window is being expanded, keep aspect ratio by expanding
	if (diff.width() > 0 || diff.height() > 0) {
		newImageSizeScaled.scale (newImageSize, Qt::KeepAspectRatioByExpanding);
	} else {
		newImageSizeScaled.scale (newImageSize, Qt::KeepAspectRatio);
	}

	/*
	 * Get the difference between the new image size and the new image size, with preserved aspect ratio
	 * The same difference will be applied to the window
	 */
	QSize aspectRatioDiff = newImageSizeScaled - newImageSize;
	//qDebug () << "Image Scale to:" << newImageSizeScaled;

	/*
	 * Apply this difference to the window, so that the aspect ratio is preserved.
	 * Use a timer, so that the resize is done (hopefully) only when the user stops resizing
	 */
	int absWidth = abs (aspectRatioDiff.width());
	int absHeight = abs (aspectRatioDiff.height());

	if (absWidth > newImageSizeScaled.width() * 0.05 || absHeight > newImageSizeScaled.height() * 0.05) {
		this->newWindowSize = newWindowSize + aspectRatioDiff;
		//qDebug () << "Window start resize timer:" << aspectRatioDiff << " new size: " << newWindowSize + aspectRatioDiff;
		resizeTimer.start (200);
	}

	qDebug () << " ";
}

} /* namespace Mattermost */


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
	QSize newWindowSize (event->size());
	//qDebug () << "Window Resize to:" << event->size();

	/*
	 * Apply the new size in order to get the new image size
	 */
	QDialog::resizeEvent (event);
	QSize newImageSize (ui->fileContents->size());
	//qDebug () << "Image Resize to:" << newImageSize;

	QSize newImageSizeScaled (pixmap.size());
	newImageSizeScaled.scale (newImageSize, Qt::KeepAspectRatio);

	/*
	 * Get the difference between the new image size and the new image size, with preserved aspect ration
	 */
	QSize aspectRatioDiff = newImageSizeScaled - newImageSize;
	//qDebug () << "Image Scale to:" << newImageSizeScaled;

	/*
	 * Apply this difference to the window, so that the aspect ratio is preserved
	 */
	if (abs (aspectRatioDiff.width()) > 100 || abs (aspectRatioDiff.height()) > 100) {
		//qDebug () << "Window add resize:" << newImageSizeScaled - newImageSize;
		resize (newWindowSize + aspectRatioDiff);
	}

	//qDebug () << " ";
}

} /* namespace Mattermost */

#include "FilePreview.h"
#include "ui_FilePreview.h"

#include <QResizeEvent>

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
	ui->fileInfo->setText (file.fileName);
	resize (pixmap.width(), pixmap.height());
}

FilePreview::~FilePreview()
{
    delete ui;
}

} /* namespace Mattermost */

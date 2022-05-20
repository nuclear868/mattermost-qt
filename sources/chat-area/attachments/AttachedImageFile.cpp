
#include "AttachedImageFile.h"
#include "ui_AttachedImageFile.h"

#include <QDebug>
#include "backend/types/BackendFile.h"

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

			QImage img = QImage::fromData (fileContents);
			if (img.width() > 500) {
				img = img.scaledToWidth (500, Qt::SmoothTransformation);
			}

			if (img.height() > 500) {
				img = img.scaledToHeight (500, Qt::SmoothTransformation);
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

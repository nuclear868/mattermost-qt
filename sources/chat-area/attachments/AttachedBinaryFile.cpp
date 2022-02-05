

#include <QMimeDatabase>
#include "AttachedBinaryFile.h"
#include "ui_AttachedBinaryFile.h"
#include "backend/types/BackendFile.h"

namespace Mattermost {

AttachedBinaryFile::AttachedBinaryFile (const BackendFile& file, QWidget *parent)
:QWidget(parent)
,ui(new Ui::AttachedBinaryFile)
{
    ui->setupUi(this);
    ui->fileName->setText ("File: " + file.name);

    static QLocale locale = QLocale::system();
    locale.formattedDataSize (file.size, 2, QLocale::DataSizeTraditionalFormat);
    ui->fileSize->setText ("Size: " + locale.formattedDataSize(file.size, 2, QLocale::DataSizeTraditionalFormat));

    static QMimeDatabase mimeDatabase;

    for (auto& mimeType: mimeDatabase.mimeTypesForFileName (file.name)) {
    	QIcon icon = QIcon::fromTheme (mimeType.iconName());

    	//if (ui->fileType->text().isEmpty()) {
    		ui->fileType->setText ("Type: " + mimeType.name());
    //	}

    	if (!icon.isNull()) {
    		ui->fileIcon->setPixmap (icon.pixmap (QSize (128, 128)));
    		break;
    	}
    }
}

AttachedBinaryFile::~AttachedBinaryFile()
{
    delete ui;
}

} /* namespace Mattermost */

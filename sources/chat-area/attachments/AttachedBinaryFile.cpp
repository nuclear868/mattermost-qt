

#include <QMimeDatabase>
#include <QDesktopServices>
#include <QMessageBox>
#include <QFile>
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
		ui->downloadedLabel->setText ("Downloading...");

#if 0
		if (!downloadedPath.isEmpty()) {
			QMessageBox *_msgBox = new QMessageBox (QMessageBox::Question,
					"File already downloaded - Mattermost",
					"The file is already downloaded in " + downloadedPath + ".");
			QMessageBox &msgBox = *_msgBox;

			msgBox.setInformativeText("Please choose:");
			msgBox.setStandardButtons(QMessageBox::Open);
			msgBox.addButton (new QPushButton ("Download Again", &msgBox), QMessageBox::AcceptRole);
			msgBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Open);
			msgBox.setDefaultButton(QMessageBox::Open);
			msgBox.open();
		}
#endif

		ui->openButton->setDisabled (true);
		backend.getFile (file.id, [this, &file] (const QByteArray& data){
			QFile destFile (file.name);
			destFile.open (QIODevice::WriteOnly);
			destFile.write (data);
			destFile.close ();
			ui->downloadedLabel->setText ("Download complete");
			downloadedPath = file.name;
			ui->openButton->setDisabled (false);
		});
	});

	/*
	 * Download the file to the temp dir and open it
	 */
	connect (ui->openButton, &QPushButton::clicked, [this, &backend, &file] {

		if (!downloadedPath.isEmpty()) {
			QDesktopServices::openUrl (downloadedPath);
			return;
		}

		backend.getFile (file.id, [this, &file] (const QByteArray& data){

			QString tmpName (file.name);
			int dot = tmpName.indexOf (".");

			tmpName.insert (dot, "XXXXXX");


			tempFile.setFileTemplate (Config::tempDirectory() + tmpName);
			bool result = tempFile.open ();

			if (!result) {
				qDebug() << tempFile.errorString();
				return;
			}

			tempFile.write (data);
			tempFile.close ();
			QDesktopServices::openUrl (tempFile.fileName());
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

	for (auto& mimeType: mimeDatabase.mimeTypesForFileName (filename)) {
		QIcon icon = QIcon::fromTheme (mimeType.iconName());

		ui->fileTypeLabel->setText ("Type: " + mimeType.name());

		if (!icon.isNull()) {
			//QPixmap pixmap = icon.pixmap (QSize (32, 32));
			QPixmap pixmap = icon.pixmap (QSize (128, 128));
			ui->fileIcon->setPixmap (pixmap);
			ui->fileIcon->setFixedSize (pixmap.size());
			break;
		}
	}
}

} /* namespace Mattermost */


#include "PostAttachmentList.h"
#include "ui_PostAttachmentList.h"

#include <QLabel>
#include <QDebug>
#include <QListWidgetItem>
#include "AttachedBinaryFile.h"
#include "AttachedImageFile.h"
#include "../PostWidget.h"
#include "backend/types/BackendFile.h"
#include "preview-window/FilePreview.h"

namespace Mattermost {

std::map <const FilePreviewData*, FilePreview*> PostAttachmentList::currentlyOpenFiles;

PostAttachmentList::PostAttachmentList (Backend& backend, QWidget *parent)
:QWidget(parent)
,backend (backend)
,ui (new Ui::PostAttachmentList)
{
    ui->setupUi(this);
    ui->listWidget->viewport()->setAutoFillBackground(false);

    connect (ui->listWidget, &QListWidget::itemClicked, [this] (QListWidgetItem *item) {

		const FilePreviewData* file = static_cast <FilePreviewData*> (item->data (Qt::UserRole).value<void*>());

		/*
		 * the file does not open a preview window
		 */
		if (!file) {
			return;
		}

		auto openFile = currentlyOpenFiles.find (file);

		FilePreview* filePreview;

		/*
		 * If the file's Preview window is currently open, show it.
		 * Otherwise, open a new Preview eindow
		 */
		if (openFile == currentlyOpenFiles.end()) {
			auto it = currentlyOpenFiles.emplace (file, new FilePreview (*file, nullptr));
			filePreview = it.first->second;
			filePreview->setAttribute (Qt::WA_DeleteOnClose);
			filePreview->show ();

			connect (filePreview, &QDialog::rejected, [file] {
					qDebug() << "Rejected";
					currentlyOpenFiles.erase (file);
			});
		} else {
			filePreview = openFile->second;
			filePreview->raise ();
		}

    });
}

PostAttachmentList::~PostAttachmentList()
{
    delete ui;
}

void PostAttachmentList::addFile (const BackendFile& file, const QString& authorName)
{
	QWidget* fileWidget = nullptr;

	if (file.mini_preview.isEmpty()) {
		fileWidget = new AttachedBinaryFile (backend, file, this);
	} else {
		fileWidget = new AttachedImageFile (file, this);
	}

	QListWidgetItem* newItem = new QListWidgetItem();

	ui->listWidget->addItem (newItem);
	ui->listWidget->setItemWidget (newItem, fileWidget);


	if (file.mini_preview.isEmpty()) {
		newItem->setSizeHint(QSize (fileWidget->width(), fileWidget->height() + 10));

		//ui->listWidget->updateGeometry();
		return;
	}


	connect (&file, &BackendFile::onContentsAvailable, [&file, newItem, fileWidget, authorName, this] (const QByteArray& fileContents){

		newItem->setSizeHint(QSize (fileWidget->width(), fileWidget->height() + 10));

		filesPreviewData.emplace_back (FilePreviewData {fileContents, file.name, authorName});
		newItem->setData (Qt::UserRole, QVariant::fromValue ((void*)&filesPreviewData.back()));

		PostWidget* widget = static_cast<PostWidget*> (parent());
		ui->listWidget->setMinimumSize(ui->listWidget->sizeHint());
		ui->listWidget->setMaximumSize(ui->listWidget->sizeHint());
		adjustSize();
		widget->adjustSize();
		emit widget->dimensionsChanged ();
	});


}

} /* namespace Mattermost */


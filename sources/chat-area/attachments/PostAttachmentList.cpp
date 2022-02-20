
#include "PostAttachmentList.h"
#include "ui_PostAttachmentList.h"

#include <QLabel>
#include <QDebug>
#include <QListWidgetItem>
#include "AttachedBinaryFile.h"
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
	if (file.mini_preview.isEmpty()) {
		QWidget* fileWidget = new AttachedBinaryFile (backend, file, this);
	    QListWidgetItem* newItem = new QListWidgetItem();

		ui->listWidget->addItem (newItem);
		ui->listWidget->setItemWidget (newItem, fileWidget);

		newItem->setSizeHint(QSize (fileWidget->width(), fileWidget->height()));

		ui->listWidget->updateGeometry();
		return;
	}

    QLabel* label = new QLabel (this);
	QListWidgetItem* newItem = new QListWidgetItem();
	QImage img = QImage::fromData (file.mini_preview);

	ui->listWidget->addItem (newItem);
	ui->listWidget->setItemWidget (newItem, label);
    label->setPixmap (QPixmap::fromImage(img));

	/*
	 * Parent of PostAttachmentList is PostWidget.
	 * Parent of PostWidget is PostListWidget.
	 * However, no idea why the last parentWidget() is needed
	 */
    parentWidget()->parentWidget()->parentWidget()->adjustSize();

    if (file.contents.isEmpty()) {
    	connect (&file, &BackendFile::onContentsAvailable, [&file, label, newItem, authorName, this] (const QByteArray& fileContents){

			QImage img = QImage::fromData (fileContents);
			if (img.width() > 500) {
				img = img.scaledToWidth (500, Qt::SmoothTransformation);
			}
			label->setPixmap (QPixmap::fromImage(img));
			label->adjustSize();
			newItem->setSizeHint(QSize (label->width(), label->height()));

			filesPreviewData.emplace_back (FilePreviewData {fileContents, file.name, authorName});
			newItem->setData (Qt::UserRole, QVariant::fromValue ((void*)&filesPreviewData.back()));

			/*
			 * Parent of PostAttachmentList is PostWidget.
			 * Parent of PostWidget is PostListWidget.
			 * However, no idea why the last parentWidget() is needed
			 */
			parentWidget()->parentWidget()->parentWidget()->adjustSize();
    	});
    }
}

} /* namespace Mattermost */


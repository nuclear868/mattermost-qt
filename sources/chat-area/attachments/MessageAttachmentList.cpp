
#include "MessageAttachmentList.h"
#include "ui_MessageAttachmentList.h"

#include <QLabel>
#include <QDebug>
#include <QListWidgetItem>
#include "AttachedBinaryFile.h"
#include "backend/types/BackendFile.h"
#include "backend/types/BackendUser.h"
#include "preview-window/FilePreview.h"

namespace Mattermost {

std::map <const FilePreviewData*, FilePreview*> MessageAttachmentList::currentlyOpenFiles;

MessageAttachmentList::MessageAttachmentList (QWidget *parent)
:QWidget(parent)
,ui(new Ui::MessageAttachmentList)
{
    ui->setupUi(this);

    connect (ui->listWidget, &QListWidget::itemClicked, [this] (QListWidgetItem *item) {

		const FilePreviewData* file = static_cast <FilePreviewData*> (item->data (Qt::UserRole).value<void*>());

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

MessageAttachmentList::~MessageAttachmentList()
{
    delete ui;
}

void MessageAttachmentList::addFile (const BackendFile& file, const BackendUser& author)
{
	if (file.mini_preview.isEmpty()) {
		QWidget* fileWidget = new AttachedBinaryFile (file, this);
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
	 * Parent of MessageAttachmentList is MessageWidget.
	 * Parent of MessageWidget is PostListWidget.
	 * However, no idea why the last parentWidget() is needed
	 */
    parentWidget()->parentWidget()->parentWidget()->adjustSize();

    if (file.contents.isEmpty()) {
    	connect (&file, &BackendFile::onContentsAvailable, [&file, label, newItem, &author, this](){

			QImage img = QImage::fromData (file.contents);
			if (img.width() > 500) {
				img = img.scaledToWidth (500, Qt::SmoothTransformation);
			}
			label->setPixmap (QPixmap::fromImage(img));
			label->adjustSize();
			newItem->setSizeHint(QSize (label->width(), label->height()));

			filesPreviewData.emplace_back (FilePreviewData {file.contents, file.name, author.getDisplayName()});
			newItem->setData (Qt::UserRole, QVariant::fromValue ((void*)&filesPreviewData.back()));

			/*
			 * Parent of MessageAttachmentList is MessageWidget.
			 * Parent of MessageWidget is PostListWidget.
			 * However, no idea why the last parentWidget() is needed
			 */
			parentWidget()->parentWidget()->parentWidget()->adjustSize();
    	});
    }
}

} /* namespace Mattermost */


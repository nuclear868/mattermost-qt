
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

MessageAttachmentList::MessageAttachmentList(QWidget *parent)
:QWidget(parent)
,ui(new Ui::MessageAttachmentList)
{
    ui->setupUi(this);

    connect (ui->listWidget, &QListWidget::itemClicked, [this] (QListWidgetItem *item) {

    	auto it = itemToFileMap.find (item);

    	if (it == itemToFileMap.end()) {
    		return;
    	}

    	const FilePreviewData& file = it->second;

   		FilePreview filePreview (file, nullptr);
   		filePreview.exec();
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

    		/*
    		 * Parent of MessageAttachmentList is MessageWidget.
    		 * Parent of MessageWidget is PostListWidget.
    		 * However, no idea why the last parentWidget() is needed
    		 */
    		parentWidget()->parentWidget()->parentWidget()->adjustSize();

    		itemToFileMap.emplace(newItem, FilePreviewData{file.contents, file.name, author.getDisplayName()});
    	});
    }
}

} /* namespace Mattermost */


/**
 * @file OutgoingAttachmentList.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Feb 20, 2022
 */

#include <QCoreApplication>
#include <QApplication>
#include <QHeaderView>
#include <QPushButton>
#include <QLabel>
#include <QLocale>
#include <QFileInfo>
#include <QDebug>
#include <QMimeDatabase>
#include "OutgoingAttachmentList.h"

namespace Mattermost {

OutgoingAttachmentList::OutgoingAttachmentList (QWidget* parent)
:QTreeWidget (parent)
{
    setObjectName(QString::fromUtf8("treeWidget"));
    header()->setFixedHeight (20);

    headerItem()->setText (0, QCoreApplication::translate("ChatArea", "File To Attach", nullptr));
    headerItem()->setText (1, QCoreApplication::translate("ChatArea", "Size", nullptr));
    headerItem()->setText (2, QCoreApplication::translate("ChatArea", "Remove", nullptr));

    QSizePolicy sizePolicy2 (QSizePolicy::Expanding, QSizePolicy::Fixed);
    setSizePolicy (sizePolicy2);

	setMaximumWidth (600);
   // header()->setSectionResizeMode (QHeaderView::Interactive);
    header()->setSectionResizeMode (0, QHeaderView::Stretch);
    header()->setSectionResizeMode (1, QHeaderView::ResizeToContents);
    header()->setSectionResizeMode (2, QHeaderView::Fixed);
    header()->setStretchLastSection(false);
    header()->resizeSection (2, 80);
}

void OutgoingAttachmentList::addFile (const QString& filename)
{
	QFileInfo fileInfo (filename);

	QTreeWidgetItem* newItem = new QTreeWidgetItem (this, QStringList() << fileInfo.baseName());
	newItem->setData (0, Qt::UserRole, filename);
	newItem->setToolTip (0, filename);

	static QMimeDatabase mimeDatabase;

	QIcon icon;

	for (auto& mimeType: mimeDatabase.mimeTypesForFileName (filename)) {
		icon = QIcon::fromTheme (mimeType.iconName());

		if (!icon.isNull()) {
			newItem->setIcon (0, icon);
			break;
		}
	}

	if (icon.isNull()) {
		newItem->setIcon (0, QApplication::style()->standardIcon(QStyle::SP_FileIcon));
	}

	static QLocale locale = QLocale::system();
	locale.formattedDataSize (fileInfo.size(), 2, QLocale::DataSizeTraditionalFormat);
	setItemWidget (newItem, 1, new QLabel (locale.formattedDataSize (fileInfo.size(), 2, QLocale::DataSizeTraditionalFormat) + " "));

	QPushButton* button = new QPushButton ("Remove");
	button->setMaximumWidth (70);
	button->setMaximumHeight (25);
	connect (button, &QPushButton::clicked, [this, newItem] {
		delete (newItem);

		if (topLevelItemCount() == 0) {
			emit deleted ();
		}
	});

	setItemWidget (newItem, 2, button);

	addTopLevelItem (newItem);
	updateGeometry();
}

QSize OutgoingAttachmentList::sizeHint () const
{
	QSize size = QTreeWidget::sizeHint ();

	if (topLevelItemCount() > 0) {
		size.setHeight (30 + topLevelItemCount() * visualItemRect (topLevelItem(0)).height());
	} else {
		size.setHeight (30);
	}

	qDebug () << "sizehint: " << size;
	return size;
}

QList<QString> OutgoingAttachmentList::getAllFiles ()
{
	QList<QString> ret;

	for (int i = 0; i < topLevelItemCount(); ++i) {
		ret.push_back (topLevelItem (i)->data (0, Qt::UserRole).toString());
	}

	return ret;
}

} /* namespace Mattermost */

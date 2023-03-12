/**
 * @file OutgoingAttachmentList.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Feb 20, 2022
 *
 * Copyright 2021, 2022 Lyubomir Filipov
 *
 * This file is part of Mattermost-QT.
 *
 * Mattermost-QT is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Mattermost-QT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Mattermost-QT. if not, see https://www.gnu.org/licenses/.
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

void OutgoingAttachmentList::setDisableInput (bool flag)
{
	for (int i = 0; i < topLevelItemCount(); ++i) {
		itemWidget(topLevelItem (i), 2)->setDisabled (flag);
	}
}

} /* namespace Mattermost */

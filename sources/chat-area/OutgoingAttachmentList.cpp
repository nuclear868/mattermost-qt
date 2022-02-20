/**
 * @file OutgoingAttachmentList.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Feb 20, 2022
 */

#include <QCoreApplication>
#include <QHeaderView>
#include <QDebug>
#include <QMimeDatabase>
#include "OutgoingAttachmentList.h"

namespace Mattermost {

OutgoingAttachmentList::OutgoingAttachmentList (QWidget* parent)
:QTreeWidget (parent)
{
    setObjectName(QString::fromUtf8("treeWidget"));
    header()->setFixedHeight (20);
    headerItem()->setText(0, QCoreApplication::translate("ChatArea", "Attachments", nullptr));

    QSizePolicy sizePolicy2 (QSizePolicy::Expanding, QSizePolicy::Fixed);
    setSizePolicy (sizePolicy2);
}

void OutgoingAttachmentList::addFile (const QString& filename)
{
	QTreeWidgetItem* newItem = new QTreeWidgetItem (this, QStringList() << filename);

	static QMimeDatabase mimeDatabase;

	for (auto& mimeType: mimeDatabase.mimeTypesForFileName (filename)) {
		QIcon icon = QIcon::fromTheme (mimeType.iconName());

		if (!icon.isNull()) {
			newItem->setIcon (0, icon);
			break;
		}
	}

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
		ret.push_back (topLevelItem (i)->text(0));
	}

	return ret;
}

} /* namespace Mattermost */

/**
 * @file AttachmentListWidget.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Jan 21, 2022
 */

#include <QDebug>
#include "AttachmentListWidget.h"

#define ATTACHMENT_LIST_MAX_SIZE 1000

namespace Mattermost {

QSize AttachmentListWidget::sizeHint () const
{
	QSize size (0,0);

	for (int i = 0; i < count(); ++i) {
		QListWidgetItem* item = this->item(i);
		QSize itemSize (item->sizeHint());
		itemSize += QSize (5, 0);

		if (itemSize.width() > size.width()) {
			size.setWidth (itemSize.width());
		}

		size.setHeight (size.height() + itemSize.height());

		if (size.height() > ATTACHMENT_LIST_MAX_SIZE) {
			size.setHeight (ATTACHMENT_LIST_MAX_SIZE);
			break;
		}
	}

	size += QSize (0,6);
	return size;
}

} /* namespace Mattermost */

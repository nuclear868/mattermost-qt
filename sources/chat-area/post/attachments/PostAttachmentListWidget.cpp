/**
 * @file PostAttachmentListWidget.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Jan 21, 2022
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

#include <QDebug>
#include "PostAttachmentListWidget.h"

#define ATTACHMENT_LIST_MAX_SIZE 1000

namespace Mattermost {

QSize PostAttachmentListWidget::sizeHint () const
{
	QSize size (0,0);

	for (int i = 0; i < count(); ++i) {
		QListWidgetItem* item = this->item(i);
		QSize itemSize (item->sizeHint());
		//itemSize += QSize (5, 0);

		if (itemSize.width() > size.width()) {
			size.setWidth (itemSize.width());
		}

		size.setHeight (size.height() + itemSize.height());

//		if (size.height() > ATTACHMENT_LIST_MAX_SIZE) {
//			size.setHeight (ATTACHMENT_LIST_MAX_SIZE);
//			break;
//		}
	}

	size += QSize (1,6);
	return size;
}

} /* namespace Mattermost */

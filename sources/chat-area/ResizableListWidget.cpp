/**
 * @file ResizableListWidget.cpp
 * @brief QListWidget wrapper, which adjust items' sizes when resized
 * @author Lyubomir Filipov
 * @date Apr 1, 2023
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

#include "ResizableListWidget.h"
#include <QResizeEvent>
#include <QScrollBar>
#include <QDebug>

/**
 * Overriding resizeEvent is needed, so that
 * the QListWidget will adjust it's items' sizes to the size of
 * contained widgets (which may change because of text wrapping)
 *
 * https://stackoverflow.com/questions/67961282/qlistwidgetitems-adjust-to-contents
 *
 * @param event resiseEvent
 */
void ResizableListWidget::resizeEvent (QResizeEvent* event)
{
	for (int i = 0; i < count(); ++i) {
		QListWidgetItem* item = this->item(i);
		QWidget* widget = (QWidget*)itemWidget (item);

		if (!widget) {
			qDebug() << "ResizeEvent: Item has null widget";
			return;
		}

		if (widget->heightForWidth(event->size().width()) != -1) {
			item->setSizeHint(QSize (viewportSizeHint().width(), widget->heightForWidth(event->size().width())));
		}
	}

	QListWidget::resizeEvent (event);
}

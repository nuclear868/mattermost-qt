/**
 * @file PostsListWidget.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 27, 2021
 */

#include <QScrollBar>
#include <QDebug>
#include <QResizeEvent>
#include "PostsListWidget.h"
#include "MessageWidget.h"

void PostsListWidget::resizeEvent (QResizeEvent* event)
{
	for (int i = 0; i < count(); ++i) {
		QListWidgetItem* item = this->item(i);
		QWidget* widget = (QWidget*)itemWidget (item);

		if (!widget) {
			qDebug() << "ResizeEvent: Item has null widget";
			return;
		}

		item->setSizeHint(QSize (event->size().width(), widget->heightForWidth(event->size().width())));
	}

	QListWidget::resizeEvent (event);

	if (verticalScrollBar()->maximum() - verticalScrollBar()->value() < 10) {
		scrollToBottom ();
	}
}


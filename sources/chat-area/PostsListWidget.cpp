/**
 * @file PostsListWidget.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 27, 2021
 */

#include <QScrollBar>
#include <QDebug>
#include <QResizeEvent>
#include "PostSeparatorWidget.h"
#include "backend/types/BackendPost.h"
#include "PostWidget.h"
#include "PostsListWidget.h"
#include "PostWidget.h"

namespace Mattermost {

PostsListWidget::PostsListWidget (QWidget* parent)
:QListWidget (parent)
,newMessagesSeparator (nullptr)
{
	verticalScrollBar()->setSingleStep (10);
	removeNewMessagesSeparatorTimer.setSingleShot (true);
	connect (&removeNewMessagesSeparatorTimer, &QTimer::timeout, this, &PostsListWidget::removeNewMessagesSeparator);
}

void PostsListWidget::insertPost (int position, PostWidget* postWidget)
{
	QListWidgetItem* newItem = new QListWidgetItem();
	insertItem (position, newItem);
	setItemWidget (newItem, postWidget);
}

void PostsListWidget::insertPost (PostWidget* postWidget)
{
	QListWidgetItem* newItem = new QListWidgetItem();
	addItem (newItem);
	setItemWidget (newItem, postWidget);
}

int PostsListWidget::findPostByIndex (const QString& postId, int startIndex)
{
	if (postId.isEmpty()) {
		return -1;
	}

	while (startIndex < count()) {

		PostWidget* message = static_cast <PostWidget*> (itemWidget (item (startIndex)));

		if (message->post.id == postId) {
			return startIndex;
		}

		++startIndex;
	}

	qDebug() << "Post with id " << postId << " not found";
	return -1;
}

void PostsListWidget::scrollToUnreadPostsOrBottom ()
{
	if (newMessagesSeparator) {
		scrollToItem (newMessagesSeparator, QAbstractItemView::PositionAtCenter);
	} else {
		scrollToBottom ();
	}
}

void PostsListWidget::addNewMessagesSeparator ()
{
	if (newMessagesSeparator) {
		return;
	}

	PostSeparatorWidget* separator = new PostSeparatorWidget ("New messages");
	newMessagesSeparator = new QListWidgetItem();
	addItem (newMessagesSeparator);
	setItemWidget (newMessagesSeparator, separator);
}

void PostsListWidget::removeNewMessagesSeparator ()
{
	if (!newMessagesSeparator) {
		return;
	}

	delete newMessagesSeparator;
	newMessagesSeparator = nullptr;
}

void PostsListWidget::removeNewMessagesSeparatorAfterTimeout (int timeoutMs)
{
	if (newMessagesSeparator) {
		removeNewMessagesSeparatorTimer.start (timeoutMs);
	}
}

void PostsListWidget::resizeEvent (QResizeEvent* event)
{
	for (int i = 0; i < count(); ++i) {
		QListWidgetItem* item = this->item(i);
		QWidget* widget = (QWidget*)itemWidget (item);

		if (!widget) {
			qDebug() << "ResizeEvent: Item has null widget";
			return;
		}

		if (widget->heightForWidth(event->size().width()) != -1) {
			item->setSizeHint(QSize (event->size().width(), widget->heightForWidth(event->size().width())));
			//qDebug() << "SetSizeHint " << event->size().width() << " " << widget->heightForWidth(event->size().width());
		}
	}

	QListWidget::resizeEvent (event);

	if (verticalScrollBar()->maximum() - verticalScrollBar()->value() < 10) {
		scrollToBottom ();
	}
}

} /* namespace Mattermost */

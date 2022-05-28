/**
 * @file PostsListWidget.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 27, 2021
 */

#include <QScrollBar>
#include <QDebug>
#include <set>
#include <QMenu>
#include <QApplication>
#include <QClipboard>
#include <QResizeEvent>
#include "PostSeparatorWidget.h"
#include "backend/Backend.h"
#include "backend/types/BackendPost.h"
#include "info-dialogs/UserProfileDialog.h"
#include "PostsListWidget.h"

namespace Mattermost {

PostsListWidget::PostsListWidget (QWidget* parent)
:QListWidget (parent)
,backend (nullptr)
,newMessagesSeparator (nullptr)
,lastOwnPost (nullptr)
,currentEditedItem (nullptr)
,menuShown (false)
{
	removeNewMessagesSeparatorTimer.setSingleShot (true);
	connect (&removeNewMessagesSeparatorTimer, &QTimer::timeout, this, &PostsListWidget::removeNewMessagesSeparator);

	connect (this, &QListWidget::customContextMenuRequested, this, &PostsListWidget::showContextMenu);

	connect (verticalScrollBar(), &QAbstractSlider::valueChanged, [this] (int value) {
		if (value == 0) {
			emit scrolledToTop ();
		}
	});
}

void PostsListWidget::insertPost (int position, PostWidget* postWidget)
{
	QListWidgetItem* newItem = new QListWidgetItem();
	newItem->setData(Qt::UserRole, ItemType::post);
	//newItem->setSizeHint (postWidget->sizeHint());
	newItem->setSizeHint (QSize (viewportSizeHint().width(), postWidget->heightForWidth(width())));
	insertItem (position, newItem);

	setItemWidget (newItem, postWidget);
	verticalScrollBar()->setSingleStep (10);

	if (postWidget->post.isOwnPost()) {
		lastOwnPost = newItem;
	}

	connect (postWidget, &PostWidget::dimensionsChanged, [this, postWidget, newItem] {
		QListWidgetItem* firstPost = itemAt (QPoint(0,10));
		newItem->setSizeHint (postWidget->sizeHint());
		scrollToItem(firstPost, QAbstractItemView::PositionAtTop);
	});
}

void PostsListWidget::insertPost (PostWidget* postWidget)
{
	return insertPost (count (), postWidget);
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

PostWidget* PostsListWidget::findPost (const QString& postId)
{
	if (postId.isEmpty()) {
		return nullptr;
	}

	int startIndex = 0;

	while (startIndex < count()) {

		PostWidget* message = static_cast <PostWidget*> (itemWidget (item (startIndex)));

		if (message->post.id == postId) {
			return message;
		}

		++startIndex;
	}

	return nullptr;
}

void PostsListWidget::scrollToUnreadPostsOrBottom ()
{
	if (newMessagesSeparator) {
		scrollToItem (newMessagesSeparator, QAbstractItemView::PositionAtCenter);
	} else {
		scrollToBottom ();
	}
}

static QString getDayString (int daysAgo)
{
	switch (daysAgo) {
	case 0:
		return "Today";
	case 1:
		return "Yesterday";
	default:
		return QDateTime::currentDateTime().date().addDays(-daysAgo).toString("dd MMM yyyy");
	}

	return "";
}

void PostsListWidget::addDaySeparator (int daysAgo)
{
	PostSeparatorWidget* separator = new PostSeparatorWidget (getDayString (daysAgo));
	QListWidgetItem* newItem = new QListWidgetItem();
	newItem->setData(Qt::UserRole, ItemType::separator);
	addItem (newItem);
	setItemWidget (newItem, separator);
}

void PostsListWidget::addDaySeparator (int insertPos, int daysAgo)
{
	PostSeparatorWidget* separator = new PostSeparatorWidget (getDayString (daysAgo));
	QListWidgetItem* newItem = new QListWidgetItem();
	newItem->setData(Qt::UserRole, ItemType::separator);
	insertItem (insertPos, newItem);
	setItemWidget (newItem, separator);
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

QListWidgetItem* PostsListWidget::getLastOwnPost () const
{
	return lastOwnPost;
}

void PostsListWidget::initiatePostEdit (QListWidgetItem& postItem)
{
	if (currentEditedItem) {
		qDebug () << "Post edit requested while editing post";
		return;
	}

	PostWidget* post = static_cast <PostWidget*> (itemWidget (&postItem));

	qDebug() << "Edit " << post->post.message;
	currentEditedItem = &postItem;
	postItem.setBackground(Qt::yellow);
	clearSelection ();
	emit postEditInitiated (post->post);
}

void PostsListWidget::postEditFinished ()
{
	if (currentEditedItem) {
		currentEditedItem->setBackground(QBrush());
		currentEditedItem = nullptr;
	}
}

void PostsListWidget::keyPressEvent (QKeyEvent* event)
{
	/*
	 * Handle the key sequence for 'Copy' and copy all posts to clipboard (properly formatted)
	 */
	if (event->matches (QKeySequence::Copy)) {
		copySelectedItemsToClipboard (PostWidget::entirePost);
		return;
	}

	QListWidget::keyPressEvent (event);
}

/*
 * get selected items in the order, in which they appear in the PostsListWidget
 */
QList<QListWidgetItem*> PostsListWidget::sortedSelectedItems () const
{
	auto cmp = [this] (const QListWidgetItem* lhs, const QListWidgetItem* rhs) {
		return row (lhs) < row (rhs);
	};

	std::set<QListWidgetItem*, decltype (cmp)> set (cmp);

	for (auto& item: selectedItems()) {
		set.insert (item);
	}

	QList<QListWidgetItem*> sortedItems;

	for (auto item: set) {
		sortedItems.push_back (item);
	}

	return sortedItems;
}

void PostsListWidget::copySelectedItemsToClipboard (PostWidget::FormatType formatType)
{
	QString str;
	for (auto& item: sortedSelectedItems ()) {

		if (item->data(Qt::UserRole) == ItemType::post) {
			PostWidget* post = static_cast <PostWidget*> (itemWidget (item));
			str += post->formatForClipboardSelection (formatType);
		}
	}

	qDebug() << "Copy Posts Selection";
	QApplication::clipboard()->setText (str);
}

void PostsListWidget::showContextMenu (const QPoint& pos)
{
	// Handle global position
	QPoint globalPos = mapToGlobal(pos);

	QListWidgetItem* pointedItem = itemAt(pos);

	if (pointedItem->data(Qt::UserRole) != ItemType::post) {
		return;
	}

	uint32_t selectedItemsCount = selectedItems().size();

	PostWidget* post = static_cast <PostWidget*> (itemWidget (pointedItem));

	if (post->post.isDeleted) {
		return;
	}

	// Create menu and insert some actions
	QMenu myMenu;

	if (post->post.isOwnPost()) {

		if (selectedItemsCount == 1) {
			myMenu.addAction ("Edit", [this, pointedItem, post] {
				initiatePostEdit (*pointedItem);
			});

			myMenu.addAction ("Delete", [this, post] {
				qDebug() << "Delete " << post->post.message;
				backend->deletePost (post->post.id);
			});

			myMenu.addSeparator();
		}
	}

	myMenu.addAction ("View " + post->post.author->getDisplayName() + "'s profile", [this, post] {
		//qDebug() << "Copy " << post->post.message;
		UserProfileDialog* dialog = new UserProfileDialog (*post->post.author, this);
		dialog->show ();
	});

	myMenu.addAction ("Copy to clipboard (formatted)", [this, post] {
		//qDebug() << "Copy " << post->post.message;
		copySelectedItemsToClipboard (PostWidget::entirePost);
	});

	if (selectedItemsCount == 1) {
		myMenu.addAction ("Copy to clipboard (text only)", [this, post] {
			//qDebug() << "Copy " << post->post.message;
			copySelectedItemsToClipboard (PostWidget::messageOnly);
		});
	}

#if 0
	if (selectedItemsCount == 1) {
		myMenu.addAction ("Reply", [post] {
			qDebug() << "Reply " << post->post.message;
		});
	}

	myMenu.addAction ("Pin", [post] {
		qDebug() << "Pin " << post->post.message;
	});
#endif

	// Show context menu at handling position. And do not focus-out
	menuShown = true;
	myMenu.exec(globalPos + QPoint (10, 0));
	menuShown = false;
}

void PostsListWidget::resizeEvent (QResizeEvent* event)
{
	qDebug() << "ResizeEvent " << event->size();
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

void PostsListWidget::focusOutEvent (QFocusEvent* event)
{
	//qDebug() << "FocusOutEvent";
	if (!menuShown) {
		clearSelection ();
	}
	QListWidget::focusOutEvent (event);
}

} /* namespace Mattermost */

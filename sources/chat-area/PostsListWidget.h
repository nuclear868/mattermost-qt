/**
 * @file PostsListWidget.h
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 27, 2021
 */

#pragma once

#include <QListWidget>
#include <QTimer>
#include "PostWidget.h"

namespace Mattermost {

class PostWidget;

namespace ItemType {
enum id {
	post,
	separator,
};
}

class PostsListWidget: public QListWidget {
	Q_OBJECT
public:
	explicit PostsListWidget (QWidget* parent);
public:
	void insertPost (int position, PostWidget* postWidget);
	void insertPost (PostWidget* postWidget);
	PostWidget* findPost (const QString& postId);
	int findPostByIndex (const QString& postId, int startIndex);

	void scrollToUnreadPostsOrBottom ();
	void addDaySeparator (int daysAgo);
	void addDaySeparator (int insertPos, int daysAgo);
	void addNewMessagesSeparator ();
	void removeNewMessagesSeparator ();
	void removeNewMessagesSeparatorAfterTimeout (int timeoutMs);
	QListWidgetItem* getLastOwnPost () const;
	void initiatePostEdit (QListWidgetItem& postItem);
	void postEditFinished ();
	Backend*						backend;
signals:
	void postEditInitiated (BackendPost& post);
	void scrolledToTop ();
private:
	QList<QListWidgetItem*> sortedSelectedItems () const;

	void copySelectedItemsToClipboard (PostWidget::FormatType formatType);
	void keyPressEvent (QKeyEvent* event)		override;
	void resizeEvent (QResizeEvent* event)		override;
	void focusOutEvent (QFocusEvent* event)		override;
	void showContextMenu (const QPoint &pos);
private:
	QTimer							removeNewMessagesSeparatorTimer;
	QListWidgetItem*				newMessagesSeparator;
	QListWidgetItem*				lastOwnPost;
	QListWidgetItem*				currentEditedItem;
	bool							menuShown;
};

} /* namespace Mattermost */

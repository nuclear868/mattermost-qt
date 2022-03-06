/**
 * @file PostsListWidget.h
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 27, 2021
 */

#pragma once

#include <QListWidget>
#include <QTimer>

namespace Mattermost {

class PostWidget;

class PostsListWidget: public QListWidget {
public:
	explicit PostsListWidget (QWidget* parent);
public:
	void insertPost (int position, PostWidget* postWidget);
	void insertPost (PostWidget* postWidget);
	PostWidget* findPost (const QString& postId);
	int findPostByIndex (const QString& postId, int startIndex);

	void scrollToUnreadPostsOrBottom ();
	void addNewMessagesSeparator ();
	void removeNewMessagesSeparator ();
	void removeNewMessagesSeparatorAfterTimeout (int timeoutMs);
	Backend*						backend;
private:
	void resizeEvent (QResizeEvent *event)		override;
	void showContextMenu (const QPoint &pos);
private:
	QTimer							removeNewMessagesSeparatorTimer;
	QListWidgetItem					*newMessagesSeparator;
};

} /* namespace Mattermost */

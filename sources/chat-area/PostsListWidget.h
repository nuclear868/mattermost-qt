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

class MessageWidget;

class PostsListWidget: public QListWidget {
public:
	explicit PostsListWidget (QWidget* parent);
public:
	void insertPost (int position, MessageWidget* postWidget);
	void insertPost (MessageWidget* postWidget);
	int findPostByIndex (const QString& postId, int startIndex);

	void scrollToUnreadPostsOrBottom ();
	void addNewMessagesSeparator ();
	void removeNewMessagesSeparator ();
	void removeNewMessagesSeparatorAfterTimeout (int timeoutMs);
private:
	void resizeEvent (QResizeEvent *event)	override;
private:
	QTimer							removeNewMessagesSeparatorTimer;
	QListWidgetItem					*newMessagesSeparator;
};

} /* namespace Mattermost */

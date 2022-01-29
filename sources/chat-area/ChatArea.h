
#pragma once

#include <QWidget>
#include <QTimer>
#include <QTreeWidgetItem>

namespace Ui {
class ChatArea;
}

class QListWidgetItem;

namespace Mattermost {

class Backend;
class BackendChannel;
class BackendPost;
class BackendUser;

class ChatArea: public QWidget {
	Q_OBJECT
public:
	explicit ChatArea (Backend& backend, BackendChannel& channel, QTreeWidgetItem* tree, QWidget *parent = nullptr);
	~ChatArea();
public:
	BackendChannel& getChannel ();
	void fillChannelPosts (const QString& lastReadPostID);
	void appendChannelPost (const BackendPost& post);
	void handleUserTyping (const BackendUser& user);
	void sendNewPost ();

	/**
	 * Called when the chat area is being selected from the channels menu (so that it's contents is shown)
	 */
	void onActivate ();

	/**
	 * Called when the entire Mattermost window is being activated (gains focus).
	 * Called only if the chat area is the currently active one (so that it's contents is shown)
	 */
	void onWindowActivate ();
private:
	void addNewMessagesSeparator ();
	void removeNewMessagesSeparator ();
	void setUnreadMessagesCount (uint32_t count);
private:
	Ui::ChatArea 		*ui;
	Backend& 			backend;
	BackendChannel& 	channel;
	QTimer				removeNewMessagesSeparatorTimer;
	QTreeWidgetItem		*treeItem;
	QListWidgetItem		*newMessagesSeparator;
	uint32_t			unreadMessagesCount;
};

} /* namespace Mattermost */


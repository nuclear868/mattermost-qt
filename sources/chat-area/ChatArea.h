
#pragma once

#include <QWidget>
#include <QTreeWidgetItem>

namespace Ui {
class ChatArea;
}

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
	void fillChannelPosts ();
	void appendChannelPost (const BackendPost& post);
	void handleUserTyping (const BackendUser& user);
	void sendNewPost ();

	/**
	 * Called when the chat area is being selected from the channels menu (so that it's contents is shown)
	 */
	void onActivate ();

	/**
	 * Called when the entire Mattermost window is being activated (gains focus)
	 */
	void onWindowActivate ();
private:
	Ui::ChatArea 		*ui;
	Backend& 			backend;
	BackendChannel& 	channel;
	QTreeWidgetItem		*treeItem;
	uint32_t			unreadMessagesCount;
};

} /* namespace Mattermost */


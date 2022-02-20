
#pragma once

#include <QWidget>
#include <QTreeWidgetItem>

namespace Ui {
class ChatArea;
}

class QListWidgetItem;

namespace Mattermost {

class BackendFile;
class Backend;
class BackendChannel;
class BackendPost;
class BackendUser;
class ChannelMissingPosts;

class ChatArea: public QWidget {
	Q_OBJECT
public:
	explicit ChatArea (Backend& backend, BackendChannel& channel, QTreeWidgetItem* tree, QWidget *parent = nullptr);
	~ChatArea();
public:
	BackendChannel& getChannel ();
	void fillChannelPosts (const ChannelMissingPosts& collection);
	void appendChannelPost (BackendPost& post);
	void handleUserTyping (const BackendUser& user);
	void sendNewPost ();

	/**
	 * Called when the chat area is being selected from the channels menu (so that it's contents is shown)
	 */
	void onActivate ();

	/**
	 * Called when the main Mattermost window is being activated (gains focus).
	 * Called only if the chat area is the currently active one (so that it's contents is visible)
	 */
	void onMainWindowActivate ();

	void addFileToload (BackendFile* file);
private:
	void setUserAvatar (const BackendUser& user);
	void setUnreadMessagesCount (uint32_t count);
	void setTextEditWidgetHeight (int height);
private:
	Ui::ChatArea 					*ui;
	Backend& 						backend;
	BackendChannel& 				channel;
	std::vector<BackendFile*>		filesToLoad;
	QString 						lastReadPostId;

	QTreeWidgetItem					*treeItem;

	uint32_t						unreadMessagesCount;
	int 							texteditDefaultHeight;
};

} /* namespace Mattermost */


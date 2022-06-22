/**
 * @file GroupChannelItem.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Jun 22, 2022
 */

#include "GroupChannelItem.h"

#include <QMenu>
#include <QMessageBox>
#include "chat-area/ChatArea.h"
#include "backend/Backend.h"
#include "info-dialogs/ChannelInfoDialog.h"
#include "channel-tree-dialogs/UserListDialogForTeam.h"

namespace Mattermost {

void GroupChannelItem::showContextMenu (const QPoint& pos)
{
	// Create menu and insert some actions
	QMenu myMenu;

	ChatArea *chatArea = data(0, Qt::UserRole).value<ChatArea*>();
	BackendChannel& channel = chatArea->getChannel();

	myMenu.addAction ("View Channel details", [this, &channel] {
		ChannelInfoDialog* dialog = new ChannelInfoDialog (channel, treeWidget());
		dialog->show ();
	});

	myMenu.addAction ("View Channel members", [this, &channel] {
		qDebug() << "View Channel members ";

		std::vector<BackendUser*> channelMembers;

		for (auto& it: channel.members) {

			if (!it.user) {
				qDebug () << "user " << it.user_id << " is nullptr";
				continue;
			}

			channelMembers.push_back (it.user);
		}

		UserListDialogForTeam* dialog = new UserListDialogForTeam (channel.display_name, channelMembers, treeWidget());
		dialog->show ();
	});

	myMenu.addAction ("Add users to channel", [this, &channel] {
		//ChannelInfoDialog* dialog = new ChannelInfoDialog (channel, treeWidget());
		//dialog->show ();
	});

	myMenu.addAction ("Leave Channel", [this, &channel] {

		if (QMessageBox::question (treeWidget(), "Are you sure?", "Are you sure that you want to leave the '" + channel.display_name + "' channel?") == QMessageBox::Yes) {
			backend.leaveChannel (channel);
		}
	});

	myMenu.exec (pos);
}

} /* namespace Mattermost */

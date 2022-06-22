/**
 * @file DirectChannelItem.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Jun 22, 2022
 */

#include "DirectChannelItem.h"

#include <QMenu>
#include "chat-area/ChatArea.h"
#include "backend/Backend.h"
#include "info-dialogs/UserProfileDialog.h"

namespace Mattermost {

void DirectChannelItem::showContextMenu (const QPoint& pos)
{
	// Create menu and insert some actions
	QMenu myMenu;

	ChatArea *chatArea = data(0, Qt::UserRole).value<ChatArea*>();
	BackendChannel& channel = chatArea->getChannel();
	BackendUser* user = chatArea->backend.getStorage().getUserById (channel.name);

	if (user) {
		myMenu.addAction ("View Profile", [this, user] {
			UserProfileDialog* dialog = new UserProfileDialog (*user, treeWidget());
			dialog->show ();
		});
	}

	myMenu.exec (pos);
}

} /* namespace Mattermost */

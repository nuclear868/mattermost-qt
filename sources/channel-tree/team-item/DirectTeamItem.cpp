/**
 * @file DirectTeamItem.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Jun 21, 2022
 */

#include "DirectTeamItem.h"

#include <QMenu>
#include "channel-tree/channel-item/DirectChannelItem.h"
#include "chat-area/ChatArea.h"
#include "backend/Backend.h"
#include "channel-tree-dialogs/UserListDialogForNewDirect.h"

namespace Mattermost {

ChannelItem* DirectTeamItem::createChannelItem (Backend& backend, ChannelItemWidget* itemWidget)
{
	return new DirectChannelItem (backend, itemWidget);
}

void DirectTeamItem::showContextMenu (const QPoint& pos)
{
	// Create menu and insert some actions
	QMenu myMenu;

	myMenu.addAction ("Add direct channel", [this] {
		qDebug() << "Add direct channel ";
		UserListDialogForNewDirect* dialog = new UserListDialogForNewDirect (backend.getStorage().getAllUsers(), treeWidget());
		dialog->show ();

		connect (dialog, &UserListDialogForNewDirect::accepted, [this, dialog] {
			const BackendUser* user = dialog->getSelectedUser();

			if (!user) {
				qDebug() << "dialog->getSelectedUser() returned nullptr";
				return;
			}

			//if the channel already exists, switch to it
			const BackendChannel* existingChannel = backend.getStorage().getDirectChannelByUserId(user->id);
			if (existingChannel) {
				for (auto& chatArea: chatAreas) {
					if (&chatArea->channel == existingChannel) {
						qDebug() << "Open Direct channel requested with " << user->getDisplayName();
						treeWidget()->setCurrentItem (chatArea->treeItem);
						return;
					}
				}
			} else {
				qDebug() << "New Direct channel requested with " << user->getDisplayName();
				backend.createDirectChannel (*user);
			}

		});
	});

	myMenu.exec (pos);
}

} /* namespace Mattermost */

/**
 * @file TeamItem.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 27, 2021
 */

#include "TeamItem.h"

#include <QMenu>
#include "ChannelItemWidget.h"
#include "ChannelItem.h"
#include "chat-area/ChatArea.h"
#include "backend/Backend.h"
#include "channel-tree-dialogs/UserListDialogForNewDirect.h"
#include "channel-tree-dialogs/UserListDialogForTeam.h"
#include "channel-tree-dialogs/TeamChannelsListDialog.h"

namespace Mattermost {

TeamItem::TeamItem (QTreeWidget& parent, Backend& backend, const QString& name, const QString& teamId)
:ChannelTreeItem (&parent, QStringList() << name)
,backend (backend)
,teamId (teamId)
{
	QFont font;
	font.setBold (true);
	font.setPixelSize (14);
	setFont (0, font);

	setExpanded (true);
}

TeamItem::~TeamItem () = default;

void TeamItem::addChannel (BackendChannel& channel, QWidget *parent)
{
	ChannelItemWidget* itemWidget = new ChannelItemWidget (parent);
	itemWidget->setLabel (channel.display_name);

	ChannelItem* item = new ChannelItem (backend, this, itemWidget);

	chatAreas.emplace_back(std::make_unique<ChatArea> (backend, channel, item, parent));
	ChatArea* chatArea = chatAreas.back ().get();

	item->setData(0, Qt::UserRole, QVariant::fromValue (chatArea));

	treeWidget()->setItemWidget (item, 0, itemWidget);

	connect (&channel, &BackendChannel::onLeave, [this, &channel, item, &chatArea = chatAreas.back ()] {
		qDebug() << "delete channel " << channel.name;

		chatAreas.remove (chatArea);
		removeChild (item);
		delete (item);
	});

}

void TeamItem::showContextMenu (const QPoint& pos)
{
	// Create menu and insert some actions
	QMenu myMenu;

	//direct channel
	if (teamId == "0") {
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
	} else {
		myMenu.addAction ("View Team Members", [this] {

			BackendTeam* team = backend.getStorage().getTeamById(teamId);

			if (!team) {
				return;
			}

			std::vector<BackendUser*> teamUsers;

			for (auto& it: team->members) {

				if (!it.user) {
					qDebug () << "user " << it.user_id << " is nullptr";
					continue;
				}

				teamUsers.push_back (it.user);
			}
			qDebug() << "View Team members " << team->members.size();

			UserListDialogForTeam* dialog = new UserListDialogForTeam (team->display_name, teamUsers, treeWidget());
			dialog->show ();
		});

		myMenu.addAction ("View Public Channels", [this] {
				BackendTeam* team = backend.getStorage().getTeamById(teamId);

				backend.retrieveTeamPublicChannels (team->id, [this, team] (std::list<BackendChannel>& channels) {
					TeamChannelsListDialog* dialog = new TeamChannelsListDialog (backend, team->display_name, channels, treeWidget());
					dialog->show ();
				});
		});
	}


	myMenu.exec (pos);
}

} /* namespace Mattermost */


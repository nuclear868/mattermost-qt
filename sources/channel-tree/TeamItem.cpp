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
#include "new-direct-channel/NewDirectChannelDialog.h"
#include "new-direct-channel/ChannelUsersListDialog.h"
#include "new-direct-channel/ViewTeamChannelsDialog.h"

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

	ChannelItem* item = new ChannelItem (this, itemWidget);

	chatAreas.emplace_back(std::make_unique<ChatArea> (backend, channel, item, parent));
	ChatArea* chatArea = chatAreas.back ().get();

	item->setData(0, Qt::UserRole, QVariant::fromValue (chatArea));

	treeWidget()->setItemWidget (item, 0, itemWidget);
}

void TeamItem::showContextMenu (const QPoint& pos)
{
	// Create menu and insert some actions
	QMenu myMenu;

	//direct channel
	if (teamId == "0") {
		myMenu.addAction ("Add direct channel", [this] {
			qDebug() << "Add direct channel ";
			NewDirectChannelDialog* dialog = new NewDirectChannelDialog (backend.getStorage().getAllUsers(), treeWidget());
			dialog->show ();

			connect (dialog, &NewDirectChannelDialog::accepted, [this, dialog] {
				const BackendUser* user = dialog->getSelectedUser();

				if (user) {
					qDebug() << "New Direct channel requested with " << user->getDisplayName();
					backend.createDirectChannel (*user);
				} else {
					qDebug() << "dialog->getSelectedUser() returned nullptr";
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

			ChannelUsersListDialog* dialog = new ChannelUsersListDialog (team->display_name, teamUsers, treeWidget());
			dialog->show ();
		});
	}

	myMenu.addAction ("View Public Channels", [this] {
			BackendTeam* team = backend.getStorage().getTeamById(teamId);

			backend.retrieveTeamPublicChannels (team->id, [this, team] (std::list<BackendChannel>& channels) {
				ViewTeamChannelsDialog* dialog = new ViewTeamChannelsDialog (team->display_name, channels, treeWidget());
				dialog->show ();
			});
	});

	myMenu.exec (pos);
}

} /* namespace Mattermost */


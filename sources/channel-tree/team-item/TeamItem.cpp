/**
 * @file TeamItem.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 27, 2021
 */

#include "TeamItem.h"

#include <QMenu>
#include "channel-tree/ChannelItemWidget.h"
#include "channel-tree/ChannelItem.h"
#include "chat-area/ChatArea.h"
#include "backend/Backend.h"

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

	ChannelItem* item = createChannelItem (backend, itemWidget);
	insertChild (getChannelIndex (channel), item);

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

	backend.retrieveChannelMembers (channel);
}

int TeamItem::getChannelIndex (const BackendChannel& channel)
{
	int i = 0;
	for (; i < childCount(); ++i) {

		//item->setData(0, Qt::UserRole, QVariant::fromValue (chatArea));

		ChatArea* area = child(i)->data (0, Qt::UserRole).value<ChatArea*>();

		if (channel.last_post_at > area->channel.last_post_at) {
			break;
		}
	}

	return i;
}

} /* namespace Mattermost */


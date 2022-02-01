/**
 * @file ChannelListForTeam.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 27, 2021
 */

#include "ChannelListForTeam.h"
#include "chat-area/ChatArea.h"
#include "backend/Backend.h"

namespace Mattermost {

ChannelListForTeam::ChannelListForTeam (QTreeWidget& parent, Backend& backend, const QString& name, const QString& teamId)
:QTreeWidgetItem (&parent, QStringList() << name)
,backend (backend)
,teamId (teamId)
{
	QFont font;
	font.setBold (true);
	font.setPixelSize (14);
	setFont (0, font);

	setExpanded (true);
}

ChannelListForTeam::~ChannelListForTeam () = default;

void ChannelListForTeam::addChannel (BackendChannel& channel, QWidget *parent)
{
	chatAreas.emplace_back(std::make_unique<ChatArea> (backend, channel, this, parent));
}

} /* namespace Mattermost */


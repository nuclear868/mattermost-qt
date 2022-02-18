/**
 * @file ChannelList.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 18, 2021
 */

#include "ChannelList.h"
#include <QHeaderView>
#include "ChannelListForTeam.h"
#include "backend/types/BackendTeam.h"
#include "backend/Backend.h"
#include "log.h"

namespace Mattermost {

ChannelList::ChannelList (QWidget* parent)
:QTreeWidget (parent)
{
//	setColumnCount (2);
//	setIconSize (QSize(24,24));
//	header()->resizeSection(0 /*column index*/, 50 /*width*/);
//	header()->resizeSection(1 /*column index*/, 50 /*width*/);
}

ChannelList::~ChannelList () = default;

/**
 * For this team, performs the following actions:
 * 1. adds an entry in the teamComboBox
 * 2. creates a QTreeWidgetItem for this team
 * 3. gets all channels of the team, where the user is member and creates QTreeWidgetItem for each of them
 */
ChannelListForTeam* ChannelList::addTeam (Backend& backend, BackendTeam& team)
{
	ChannelListForTeam* teamList = new ChannelListForTeam (*this, backend, team.display_name, team.id);

	addTopLevelItem (teamList);
	//header()->resizeSection (0, 200);
	header()->setSectionResizeMode(0, QHeaderView::Stretch);
	header()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
	//header()->resizeSection (1, 30);

	connect (&team, &BackendTeam::onNewChannel, [this, &team, teamList] (BackendChannel& channel) {
		teamList->addChannel (channel, parentWidget());
	});

	connect (&team, &BackendTeam::onLeave, [this, &team, teamList] {
		int index = indexOfTopLevelItem (teamList);

		if (index == -1) {
			qDebug() << "remove team " << team.display_name << ": indexOfTopLevelItem returned -1";
			return;
		}

		qDebug() << "delete() team " << team.id;
		QTreeWidgetItem* item = takeTopLevelItem (index);

		delete (item);
	});

	if (team.id == DIRECT_TEAM_ID) {
		for (auto &channel: team.channels) {
			teamList->addChannel (*channel, parentWidget());
		}
	} else {
		backend.retrieveOwnChannelMemberships (team, [this, teamList] (BackendChannel& channel) {
			teamList->addChannel (channel, parentWidget());
		});
	}

	return teamList;
}

} /* namespace Mattermost */


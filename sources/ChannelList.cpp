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
ChannelListForTeam* ChannelList::addTeam (Backend& backend, const QString& name)
{
	ChannelListForTeam* teamList = new ChannelListForTeam (*this, backend, name);
	teams.push_back (teamList);
	addTopLevelItem (teamList);
	//header()->resizeSection (0, 200);
	header()->setSectionResizeMode(0, QHeaderView::Stretch);
	header()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
	//header()->resizeSection (1, 30);
	return teams.back();
}

void ChannelList::removeTeam (BackendTeam& team)
{
	qDebug() << "Remove team " << team.id;

#warning "fix"
#if 0
	for (int i = 0; i < teams.size(); ++i) {		
		if (teams[i]->team.id == team.id) {
			delete (*(teams.begin() + i));
			teams.erase (teams.begin() + i);
		}
	}
#endif
}

} /* namespace Mattermost */


/**
 * @file BackendDirectChannelsTeam.h
 * @brief
 * @author Lyubomir Filipov
 * @date Oct 19, 2022
 *
 * Copyright 2021, 2022 Lyubomir Filipov
 *
 * This file is part of Mattermost-QT.
 *
 * Mattermost-QT is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Mattermost-QT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Mattermost-QT. if not, see https://www.gnu.org/licenses/.
 */

#pragma once

#include <vector>
#include <memory>
#include <QList>

#include "BackendChannel.h"

namespace Mattermost {

class BackendDirectChannelsTeam: public QObject {
	Q_OBJECT
public:
	BackendDirectChannelsTeam ();
	virtual ~BackendDirectChannelsTeam ();
public:
	QSet<const BackendUser*> getAllMembers () const;
signals:
	void onNewChannel (BackendChannel& channel);
public:
	QList<BackendUser*>		 							members;
	std::list<BackendChannel>							allPublicChannels;
	std::vector<std::unique_ptr<BackendChannel>>		channels;
};

} /* namespace Mattermost */

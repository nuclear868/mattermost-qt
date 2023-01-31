/**
 * @file BackendTeam.h
 * @brief
 * @author Lyubomir Filipov
 * @date Nov 30, 2021
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
#include <QJsonObject>
#include <QVariant>

#include "BackendChannel.h"
#include "BackendTeamMember.h"

namespace Mattermost {

class BackendTeam: public QObject {
	Q_OBJECT
public:
	BackendTeam (const QJsonObject& jsonObject);
	virtual ~BackendTeam ();
public:
	QSet<const BackendUser*> getAllMembers () const;
signals:
	void onLeave ();
	void onNewChannel (BackendChannel& channel);
	void onChannelDeleted (BackendChannel& channel);
public:
    QString			id;
    uint64_t		create_at;
    uint64_t		update_at;
    uint64_t		delete_at;
    QString			display_name;
    QString			name;
    QString			description;
    QString			email;
    QString			type;
    QString			company_name;
    QString			allowed_domains;
    QString			invite_id;
    bool 			allow_open_invite;
    QVariant 		scheme_id;

	QList<BackendTeamMember> 							members;
	std::list<BackendChannel>							allPublicChannels;
	std::vector<std::unique_ptr<BackendChannel>>		channels;
};

} /* namespace Mattermost */


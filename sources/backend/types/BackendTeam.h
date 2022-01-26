/**
 * @file BackendTeam.h
 * @brief
 * @author Lyubomir Filipov
 * @date Nov 30, 2021
 */

#pragma once

#include <QJsonObject>
#include <QVariant>

#include "BackendChannel.h"
#include "BackendTeamMember.h"

namespace Mattermost {

class BackendTeam {
public:
	BackendTeam ();
	virtual ~BackendTeam ();
public:
	void deserialize (const QJsonObject& jsonObject);
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

	QList<BackendTeamMember> 	members;
	QList<BackendChannel*>		channels;
};

} /* namespace Mattermost */


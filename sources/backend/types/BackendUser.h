/**
 * @file BackendUser.h
 * @brief
 * @author Lyubomir Filipov
 * @date Nov 28, 2021
 */

#pragma once

#include "BackendTimeZone.h"
#include "BackendNotifyPreps.h"

class QJsonObject;

namespace Mattermost {

class BackendUser {
public:
	BackendUser ();
	BackendUser (const QJsonObject& jsonObject);
	virtual ~BackendUser ();
public:

	QString getDisplayName () const;
public:
    QString 			id;
    QByteArray			avatar;
    uint64_t 			create_at;
    uint64_t			update_at;
    uint64_t 			delete_at;
    QString 			username;
    QString 			auth_data;
    QString 			auth_service;
    QString 			email;
    QString 			nickname;
    QString 			first_name;
    QString 			last_name;
    QString 			position;
    QStringList 		roles;
    bool 				allow_marketing;
    BackendNotifyPreps 	notify_preps;
    uint64_t 			last_password_update;
    QString 			locale;
    BackendTimeZone		timezone;
    bool				isLoginUser;
};

} /* namespace Mattermost */

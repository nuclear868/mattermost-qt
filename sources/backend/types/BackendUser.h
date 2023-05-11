/**
 * @file BackendUser.h
 * @brief
 * @author Lyubomir Filipov
 * @date Nov 28, 2021
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

#include "BackendTimeZone.h"
#include "BackendNotifyPreps.h"
#include "BackendUserProps.h"

class QJsonObject;

namespace Mattermost {

/**
 * Holds settings that control the behavior of the Mattermost client
 * for a particular user. For example: display settings, visible channels and recent statuses
 */ 
struct BackendUserPreferences {
	QString category;
	QString	name;
	QString	value;
};

class BackendUser: public QObject {
	Q_OBJECT
public:
	BackendUser (const QJsonObject& jsonObject);
	virtual ~BackendUser ();
signals:

	/**
	 * Called when the user's avatar is obtained (after login)
	 * or when the user changes it's avatar
	 */
	void onAvatarChanged ();

	void onStatusChanged ();
public:
	QString getDisplayName () const;
	void updateFrom (const BackendUser& other, QString& resultString);
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
	BackendUserProps	props;
	uint64_t 			last_password_update;
	QString 			locale;
	BackendTimeZone		timezone;
	bool				isLoginUser;

    //filled when status is requested
	QString 			status;
	uint64_t			lastActivity;
};

} /* namespace Mattermost */

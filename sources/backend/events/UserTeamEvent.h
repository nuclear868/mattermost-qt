/**
 * @file UserTeamEvent.h
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 31, 2021
 */

#pragma once

#include <QJsonObject>

namespace Mattermost {

class UserTeamEvent {
public:
	UserTeamEvent (const QJsonObject& object);
	virtual ~UserTeamEvent ();
public:
	QString team_id;
	QString user_id;
};

} /* namespace Mattermost */


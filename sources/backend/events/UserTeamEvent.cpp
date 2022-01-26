/**
 * @file UserTeamEvent.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 31, 2021
 */

#include "UserTeamEvent.h"

namespace Mattermost {

UserTeamEvent::UserTeamEvent (const QJsonObject& object)
:team_id (object.value("team_id").toString())
,user_id (object.value("user_id").toString())
{
}

UserTeamEvent::~UserTeamEvent () = default;

} /* namespace Mattermost */


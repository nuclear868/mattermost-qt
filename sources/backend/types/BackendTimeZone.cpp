/**
 * @file BackendTimeZone.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Nov 28, 2021
 */

#include "BackendTimeZone.h"

#include <QJsonObject>

namespace Mattermost {

BackendTimeZone::BackendTimeZone ()
:useAutomaticTimezone (false)
{
}

BackendTimeZone::~BackendTimeZone () = default;

void BackendTimeZone::deserialize (const QJsonObject& jsonObject)
{
	automaticTimezone = jsonObject.value("automaticTimezone").toString();
	manualTimezone = jsonObject.value("manualTimezone").toString();
	useAutomaticTimezone = jsonObject.value("useAutomaticTimezone").toBool();
}

} /* namespace Mattermost */


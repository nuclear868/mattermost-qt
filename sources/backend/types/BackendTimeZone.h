/**
 * @file BackendTimeZone.h
 * @brief
 * @author Lyubomir Filipov
 * @date Nov 28, 2021
 */

#pragma once

#include <QObject>

namespace Mattermost {

class BackendTimeZone {
public:
	BackendTimeZone ();
	virtual ~BackendTimeZone ();
public:
	void deserialize (const QJsonObject& jsonObject);
public:
    QString 			automaticTimezone;
    QString 			manualTimezone;
    bool 				useAutomaticTimezone;
};

} /* namespace Mattermost */

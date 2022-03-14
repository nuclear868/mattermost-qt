/**
 * @file UserAddedToChannelEvent.h
 * @brief
 * @author Lyubomir Filipov
 * @date Mar 14, 2022
 */

#pragma once

#include <QJsonObject>

namespace Mattermost {

class UserAddedToChannelEvent {
public:
	UserAddedToChannelEvent (const QJsonObject& data, const QJsonObject& broadcast);
	virtual ~UserAddedToChannelEvent ();
public:
	QString userId;
	QString channelId;
	QString teamId;
};

} /* namespace Mattermost */

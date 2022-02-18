/**
 * @file UserRemovedFromChannelEvent.h
 * @brief
 * @author Lyubomir Filipov
 * @date Feb 19, 2022
 */

#pragma once

#include <QJsonObject>

namespace Mattermost {

class UserRemovedFromChannelEvent {
public:
	UserRemovedFromChannelEvent (const QJsonObject& data, const QJsonObject& broadcast);
	virtual ~UserRemovedFromChannelEvent ();
public:
	QString userId;
	QString channelId;
};

} /* namespace Mattermost */

/**
 * @file ChannelCreatedEvent.h
 * @brief
 * @author Lyubomir Filipov
 * @date Feb 18, 2022
 */

#pragma once

#include <QJsonObject>

namespace Mattermost {

class ChannelCreatedEvent {
public:
	ChannelCreatedEvent (const QJsonObject& object);
	virtual ~ChannelCreatedEvent ();
public:
	QString channelId;
	QString teamId;
};

} /* namespace Mattermost */

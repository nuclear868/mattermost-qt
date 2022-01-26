/**
 * @file ChannelViewedEvent.h
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 30, 2021
 */

#pragma once

#include <QJsonObject>

namespace Mattermost {

class ChannelViewedEvent {
public:
	ChannelViewedEvent (const QJsonObject& object);
	virtual ~ChannelViewedEvent ();
public:
	QString channel_id;
};

} /* namespace Mattermost */


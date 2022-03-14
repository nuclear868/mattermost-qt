/**
 * @file NewDirectChannelEvent.h
 * @brief
 * @author Lyubomir Filipov
 * @date Mar 14, 2022
 */

#pragma once

#include <QJsonObject>

namespace Mattermost {

class NewDirectChannelEvent {
public:
	NewDirectChannelEvent (const QJsonObject& data, const QJsonObject& broadcast);
	virtual ~NewDirectChannelEvent ();
public:
	QString		channelId;
	QString		userId;
};

} /* namespace Mattermost */

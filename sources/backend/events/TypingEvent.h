/**
 * @file TypingEvent.h
 * @brief
 * @author Lyubomir Filipov
 * @date Jan 24, 2022
 */

#pragma once

#include <QJsonObject>

namespace Mattermost {

class TypingEvent {
public:
	TypingEvent (const QJsonObject& data, const QJsonObject& broadcast);
	virtual ~TypingEvent ();
public:
	QString		channel_id;
	QString		user_id;
};

} /* namespace Mattermost */

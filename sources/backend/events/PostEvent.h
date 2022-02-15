/**
 * @file PostEvent.h
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 31, 2021
 */

#pragma once

#include "backend/types/BackendPost.h"

namespace Mattermost {

class PostEvent {
public:
	PostEvent (const QJsonObject& data, const QJsonObject& broadcast);
	virtual ~PostEvent ();
public:
	QString		teamId;
	QString		channelId;
	QJsonObject	postObject;
	bool		set_online;
};

} /* namespace Mattermost */

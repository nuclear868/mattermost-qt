/**
 * @file PostDeletedEvent.h
 * @brief
 * @author Lyubomir Filipov
 * @date Mar 6, 2022
 */

#pragma once

#include <QJsonObject>

namespace Mattermost {

class PostDeletedEvent {
public:
	PostDeletedEvent (const QJsonObject& data, const QJsonObject& broadcast);
	virtual ~PostDeletedEvent ();
public:
	QString		channelId;
	QString		postId;
};

} /* namespace Mattermost */

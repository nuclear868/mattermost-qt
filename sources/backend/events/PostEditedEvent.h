/**
 * @file PostEditedEvent.h
 * @brief
 * @author Lyubomir Filipov
 * @date Mar 16, 2022
 */

#pragma once

#include <QString>
#include <QJsonObject>

namespace Mattermost {

class PostEditedEvent {
public:
	PostEditedEvent (const QJsonObject& data, const QJsonObject& broadcast);
	virtual ~PostEditedEvent ();
public:
	QString		teamId;
	QString		channelId;
	QJsonObject	postObject;
};

} /* namespace Mattermost */

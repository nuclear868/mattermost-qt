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
	PostEvent (const QJsonObject& object);
	virtual ~PostEvent ();
public:
	QString		team_id;
	bool		set_online;
	BackendPost post;
};

} /* namespace Mattermost */

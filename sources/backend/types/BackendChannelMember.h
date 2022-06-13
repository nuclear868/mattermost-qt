/**
 * @file BackendChannelMember.h
 * @brief
 * @author Lyubomir Filipov
 * @date Jun 13, 2022
 */

#pragma once

#include <QJsonObject>

namespace Mattermost {

class BackendUser;

class BackendChannelMember {
public:
	BackendChannelMember (const QJsonObject& jsonObject);
	virtual ~BackendChannelMember ();
public:
	BackendUser*	user;
	uint64_t		last_viewed_at;
	uint32_t		msg_count;
	uint32_t		mention_count;
	QString			user_id;
};

} /* namespace Mattermost */

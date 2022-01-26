/**
 * @file BackendChannel.h
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 1, 2021
 */

#pragma once

#include <QJsonObject>
#include <QVariant>
#include "BackendPost.h"

namespace Mattermost {

class BackendChannel: public QObject {
	Q_OBJECT
public:
	enum type {
		unknown,
		publicChannel,
		privateChannel,
		directChannel,
	};
	BackendChannel (const QJsonObject& jsonObject);
	virtual ~BackendChannel ();
signals:
	void onNewPost (BackendPost& post);
	void onUserTyping (const BackendUser& user);
public:
    QString			id;
    uint64_t		create_at;
    uint64_t		update_at;
    uint64_t		delete_at;
    QString			team_id;
    QString			display_name;
    QString			name;
    QString			header;
    QString			purpose;
    int				type;
    int				last_post_at;
    int				total_msg_count;
    int				extra_update_at;
    QString			creator_id;
    QVariant		scheme_id;
    QVariant		props;
    uint32_t		referenceCount;

    QList<BackendPost>	posts;
};

} /* namespace Mattermost */


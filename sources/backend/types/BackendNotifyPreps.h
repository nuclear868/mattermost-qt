/**
 * @file BackendNotifyPreps.h
 * @brief
 * @author Lyubomir Filipov
 * @date Nov 28, 2021
 */

#pragma once

#include <QObject>

namespace Mattermost {

class BackendNotifyPreps {
public:
	BackendNotifyPreps ();
	virtual ~BackendNotifyPreps ();
public:
	void deserialize (const QJsonObject& jsonObject);
public:
    bool 				channel;
    QString 			comments;
    QString 			desktop;
    bool 				desktop_sound;
    bool 				email;
    bool 				first_name;
    QStringList 		mention_keys;
    QString 			push;
    QString 			push_status;
};

} /* namespace Mattermost */

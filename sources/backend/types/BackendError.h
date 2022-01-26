/**
 * @file BackendError.h
 * @brief
 * @author Lyubomir Filipov
 * @date Nov 28, 2021
 */

#pragma once

#include <QJsonObject>

namespace Mattermost {

class BackendError {
public:
	BackendError ();
	virtual ~BackendError ();
public:
	void deserialize (const QJsonObject& jsonObject);
public:
    QString 			id;
    QString 			message;
    QString 			request_id;
    int 				status_code;
    bool 				is_oath;
};

} /* namespace Mattermost */

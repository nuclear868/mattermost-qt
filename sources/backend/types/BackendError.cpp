/**
 * @file BackendError.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Nov 28, 2021
 */

#include "BackendError.h"

#include <QJsonObject>

namespace Mattermost {

BackendError::BackendError ()
:status_code (0)
,is_oath (false)
{
}

BackendError::~BackendError () = default;

void BackendError::deserialize (const QJsonObject& jsonObject)
{
	id = jsonObject.value("id").toString();
	message = jsonObject.value("message").toString();
	request_id = jsonObject.value("request_id").toString();
	status_code = jsonObject.value("status_code").toInt();
	is_oath = jsonObject.value("is_oath").toBool();
}

} /* namespace Mattermost */

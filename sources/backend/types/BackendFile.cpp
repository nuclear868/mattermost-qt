/**
 * @file BackendFile.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Jan 2, 2022
 */

#include "BackendFile.h"

namespace Mattermost {

BackendFile::BackendFile (const QJsonObject& jsonObject)
{
	id = jsonObject.value ("id").toString();
	name = jsonObject.value ("name").toString();
	extension = jsonObject.value ("extension").toString();
	mini_preview = QByteArray::fromBase64 (jsonObject.value ("mini_preview").toString().toUtf8());
}

BackendFile::~BackendFile () = default;

} /* namespace Mattermost */

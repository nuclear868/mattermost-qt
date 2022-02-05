/**
 * @file BackendFile.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Jan 2, 2022
 */

#include <QVariant>
#include "BackendFile.h"

namespace Mattermost {

BackendFile::BackendFile (const QJsonObject& jsonObject)
{
	id = jsonObject.value ("id").toString();
	name = jsonObject.value ("name").toString();
	mimeType = jsonObject.value ("mime_type").toString();
	size = jsonObject.value ("size").toVariant().toULongLong ();
	extension = jsonObject.value ("extension").toString();
	mini_preview = QByteArray::fromBase64 (jsonObject.value ("mini_preview").toString().toUtf8());
}

BackendFile::~BackendFile () = default;

} /* namespace Mattermost */

/**
 * @file BackendFile.h
 * @brief
 * @author Lyubomir Filipov
 * @date Jan 2, 2022
 */

#pragma once

#include <QJsonObject>
#include <QObject>

namespace Mattermost {

class BackendFile: public QObject {
	Q_OBJECT
public:
	BackendFile (const QJsonObject& jsonObject);
	virtual ~BackendFile ();
signals:
	void onContentsAvailable (const QByteArray& data);
public:
	QString				id;
	QString				name;
	QString				mimeType;
	size_t				size;
	QString				extension;
	QByteArray			mini_preview;
	QByteArray			contents;
};

} /* namespace Mattermost */


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
	BackendFile (BackendFile&& other) = default;
	virtual ~BackendFile ();
signals:
	void onContentsAvailable ();
public:
	QString				id;
	QString				name;
	QString				extension;
	QByteArray			mini_preview;
	QByteArray			contents;
};

} /* namespace Mattermost */

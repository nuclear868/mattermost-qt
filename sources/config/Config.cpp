/**
 * @file Config.cpp
 * @brief Mattermost configuration class
 * @author Lyubomir Filipov
 * @date Feb 12, 2022
 */

#include <QDir>
#include "Config.h"

namespace Mattermost {

void Config::init ()
{
	QDir tempDir (tempDirectory());

	if (!tempDir.exists()) {
		tempDir.mkpath (".");
	}
}

QString Config::tempDirectory ()
{
	static QString dir (QDir::tempPath() + "/qmattermost/");
	return dir;
}

} /* namespace Mattermost */

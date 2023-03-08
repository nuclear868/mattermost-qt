/**
 * @file Config.cpp
 * @brief Mattermost configuration class
 * @author Lyubomir Filipov
 * @date Feb 12, 2022
 *
 * Copyright 2021, 2022 Lyubomir Filipov
 *
 * This file is part of Mattermost-QT.
 *
 * Mattermost-QT is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Mattermost-QT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Mattermost-QT. if not, see https://www.gnu.org/licenses/.
 */

#include <QStandardPaths>
#include <QDebug>
#include "Config.h"

namespace Mattermost {

#define PRINT_DIR(x) qDebug() << #x ": " << QStandardPaths::writableLocation(QStandardPaths::x)

void Config::init ()
{
#if 0
	PRINT_DIR (DesktopLocation);
	PRINT_DIR (DocumentsLocation);
	PRINT_DIR (FontsLocation);
	PRINT_DIR (ApplicationsLocation);
	PRINT_DIR (MusicLocation);
	PRINT_DIR (MoviesLocation);
	PRINT_DIR (PicturesLocation);
	PRINT_DIR (TempLocation);
	PRINT_DIR (HomeLocation);
	PRINT_DIR (DataLocation);
	PRINT_DIR (CacheLocation);
	PRINT_DIR (GenericDataLocation);
	PRINT_DIR (RuntimeLocation);
	PRINT_DIR (ConfigLocation);
	PRINT_DIR (DownloadLocation);
	PRINT_DIR (GenericCacheLocation);
	PRINT_DIR (GenericConfigLocation);
	PRINT_DIR (AppDataLocation);
	PRINT_DIR (AppConfigLocation);
#endif

	QDir tempDir (tempDirectory());

	if (!tempDir.exists()) {
		tempDir.mkpath (".");
	}
}

QDir Config::tempDirectory ()
{
	static QDir tempDir	(QStandardPaths::writableLocation(QStandardPaths::TempLocation));
	return tempDir.filePath("qmattermost");
}

} /* namespace Mattermost */

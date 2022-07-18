/**
 * @file BackendNotifyPreps.h
 * @brief
 * @author Lyubomir Filipov
 * @date Nov 28, 2021
 *
 * Copyright 2021, 2022 Lyubomir Filipov
 *
 * This file is part of Mattermost-QT.
 *
 * Mattermost-QT is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Mattermost-QT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Mattermost-QT; if not, see https://www.gnu.org/licenses/.
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

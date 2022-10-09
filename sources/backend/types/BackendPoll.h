/**
 * @file BackendPoll.h
 * @brief Holds all data for a poll for a post.
 * @author Lyubomir Filipov
 * @date Oct 6, 2022
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

#include <QJsonObject>
#include <QVector>
#include <QObject>

namespace Mattermost {

struct BackendPollOption {
	QString name;
	QString voters;
	QString	actionID;
};

/*
 * Poll metadata. It is received separately - only when requested, or when a vote is made
 */
struct BackendPollMetadata {
	bool						hasAdminPermissions;
	QVector<uint32_t>			ownVoteOptions;
};

class BackendPoll: public QObject {
	Q_OBJECT
public:
	BackendPoll (const QString& pollID, const QJsonObject& jsonObject);
	~BackendPoll ();
public:
	void fillMetadata (const QJsonObject& jsonObject);
signals:
	void onMetadataUpdated ();
private:
	void fillChoiceOptions (const QJsonArray& optionsJson);
	void fillPreviewOptions (const QJsonArray& optionsJson);
public:
	QString						id;
	QString						authorName;
	QString						title;
	QString						text;
	QVector<BackendPollOption>	options;
	bool						hasEnded;
	BackendPollMetadata			metadata;
};

} /* namespace Mattermost */

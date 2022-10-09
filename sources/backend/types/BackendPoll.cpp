/**
 * @file BackendPoll.cpp
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

#include "BackendPoll.h"

#include <QJsonArray>

namespace Mattermost {

BackendPoll::BackendPoll (const QString& pollID, const QJsonObject& jsonObject)
:id (pollID)
{
	authorName = jsonObject.value("author_name").toString();
	title = jsonObject.value("title").toString();
	text = jsonObject.value("text").toString();
	metadata.hasAdminPermissions = false;

	/**
	 * If the poll is open, there is 'actions' array.
	 * If the poll is closed, there is 'fields' array.
	 */

	const QJsonArray& actions = jsonObject.value("actions").toArray();

	if (!actions.isEmpty()) {
		fillChoiceOptions (actions);
		hasEnded = false;
	} else {
		const QJsonArray& fields = jsonObject.value("fields").toArray();
		fillPreviewOptions (fields);
		hasEnded = true;
	}
}

BackendPoll::~BackendPoll () = default;

void Mattermost::BackendPoll::fillMetadata (const QJsonObject& jsonObject)
{
	metadata.ownVoteOptions.clear();
	metadata.hasAdminPermissions = jsonObject.value("admin_permission").toBool (false);

	for (const auto& val: jsonObject.value("voted_answers").toArray()) {
		QString answerStr = val.toString();

		int optionIdx = 0;
		for (auto& option: options) {
			if (option.name == answerStr) {
				metadata.ownVoteOptions.push_back(optionIdx);
			}

			++optionIdx;
		}
	}

	emit onMetadataUpdated ();
}

void BackendPoll::fillChoiceOptions (const QJsonArray& optionsJson)
{
	for (const auto& jsonOption: optionsJson) {

		BackendPollOption option;
		option.name = jsonOption.toObject().value ("name").toString ();
		option.voters = jsonOption.toObject().value ("value").toString ();
		option.actionID = jsonOption.toObject().value ("id").toString ();

		options.push_back (option);
	}
}

void BackendPoll::fillPreviewOptions (const QJsonArray& optionsJson)
{
	for (const auto& jsonOption: optionsJson) {

		BackendPollOption option;
		option.name = jsonOption.toObject().value ("title").toString ();
		option.voters = jsonOption.toObject().value ("value").toString ();

		options.push_back (option);
	}
}

} /* namespace Mattermost */

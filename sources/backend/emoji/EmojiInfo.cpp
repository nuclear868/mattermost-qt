/**
 * @file EmojiInfo.cpp
 * @brief Contains functions for getting emoji by ID and adding custom emojis
 * @author Lyubomir Filipov
 * @date Dec 30, 2022
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

#include "EmojiInfo.h"
#include <QMap>
#include <QDebug>

namespace Mattermost {

extern uint32_t lastCategorySeq[EmojiCategory::COUNT];
extern QVector<Emoji> emojiVecNoSkinVariadic[EmojiCategory::COUNT];
extern QVector<SkinVariadicEmoji> emojiVecSkinVariadic;
extern QMap<QString, EmojiSeq>  emojiMap;
extern uint32_t nextEmojiSeq;

/**
 * Search for a skin tone string in the emoji name. Remove it, when performing lookup,
 * because emoji names are stored without the skin tone. All skin tone emojis are in an array and
 * the lookup is performed without the skin tone name.
 *
 * Also, the skin tone lookup order is changed, so that searching for 'light' will not find 'medium_light'
 */
static QString skinTonelookup[] {"", "medium_light", "medium_dark", "light", "medium", "dark"};
static const uint16_t skinToneLookupMap[] {
		EmojiSkinTone::none,
		EmojiSkinTone::mediumLight,
		EmojiSkinTone::mediumDark,
		EmojiSkinTone::light,
		EmojiSkinTone::medium,
		EmojiSkinTone::dark,
};

EmojiID EmojiInfo::findByName (const QString& emojiName)
{
	for (uint16_t i = 1; i < EmojiSkinTone::COUNT; ++i) {

		QString lookup ("_" + skinTonelookup[i] + "_skin_tone");

		int found = emojiName.indexOf (lookup);
		if (found != -1) {
			QString emojiNameReplaced (emojiName);
			emojiNameReplaced.remove (lookup);

			auto it = emojiMap.find (emojiNameReplaced);

			if (it == emojiMap.end ()) {
				return {0,0};
			}

			return {skinToneLookupMap[i], it.value()};
		}
	}

	auto it = emojiMap.find (emojiName);

	if (it == emojiMap.end ()) {
		return {0,0};
	}

	return {0, it.value()};
}

static int getEmojiCategory (uint16_t emojiSeq)
{
	for (int i = 0; i < EmojiCategory::COUNT; ++i) {
		if (emojiSeq <= lastCategorySeq[i]) {
			return i;
		}
	}

	return EmojiCategory::COUNT;
}

Emoji EmojiInfo::getEmoji (const EmojiID& emojiID)
{
	if (!emojiID) {
		qDebug () << "No emoji with seq " << emojiID.seq << " found";
		return Emoji {"",""};
	}

	int category = getEmojiCategory (emojiID.seq);

	if (category < EmojiCategory::COUNT) {
		int emojiIndex = emojiID.seq - 1 - (lastCategorySeq[category] - emojiVecNoSkinVariadic[category].size());
		return emojiVecNoSkinVariadic[category][emojiIndex];
	}

	if (emojiID.seq < SKINVARIADIC_START_INDEX) {
		qDebug () << "No emoji with seq " << emojiID.seq << " found";
		return Emoji {"",""};
	}

	int emojiIndex = emojiID.seq - SKINVARIADIC_START_INDEX;

	if (emojiIndex < emojiVecSkinVariadic.size()) {
		SkinVariadicEmoji variadicEmoji = emojiVecSkinVariadic[emojiIndex];

		QString emojiName (variadicEmoji.name);

		if (emojiID.skinTone) {
			emojiName += " (skin tone: " + skinTonelookup[emojiID.skinTone] + ")";
		}

		return Emoji {emojiName, variadicEmoji.unicodeString[emojiID.skinTone]};
	}

	qDebug () << "No emoji with seq " << emojiID.seq << " found";
	return {"",""};
}

QVector<Emoji> EmojiInfo::getAllEmojis (uint32_t category, uint32_t skinTone)
{
	QVector<Emoji> ret (emojiVecNoSkinVariadic[category]);

	if (category == EmojiCategory::people) {
		for (auto& it: emojiVecSkinVariadic) {
			ret.push_back (Emoji {it.name, it.unicodeString[skinTone]});
		}
	}

	return ret;
}

void EmojiInfo::addCustomEmoji (const QString& emojiName, const QString& emojiPath)
{
	emojiVecNoSkinVariadic[EmojiCategory::custom].push_back (Emoji {emojiName, " <img src=\"" + emojiPath + "\" width=32 height=32> "});
	emojiMap[emojiName] = nextEmojiSeq;
	++nextEmojiSeq;
	++lastCategorySeq[EmojiCategory::custom];
}

} /* namespace Mattermost */

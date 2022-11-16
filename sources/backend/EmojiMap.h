/**
 * @file EmojiMap.h
 * @brief Auto-generated file, containing emoji-name to emoji-string map
 * @author Lyubomir Filipov
 * @date Jul 28, 2022
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

#include <QMap>

namespace Mattermost {


/**
 * lookup for emoji value, given an emoji name
 */
class EmojiMap {
public:
	EmojiMap () = delete;
	~EmojiMap () = delete;
public:
	using iterator = QMap<QString, QString>::const_iterator;

	static iterator findByName (const QString& emojiName);
	static iterator missing ();

	/**
	 * Add a custom emoji.
	 * Custom emojis use image instead of unicode codepoints.
	 * However, images can be represented as <img> tags in Qt's QLabel rich text.
	 * This allows custom emojis also to use strings as values
	 * @param emojiName emoji name
	 * @param emojiID emoji id
	 */
	static void addCustomEmoji (const QString& emojiName, const QString& emojiID);
};

bool operator< (const EmojiMap::iterator lhs, const EmojiMap::iterator rhs);

} /* namespace Mattermost */

using Mattermost::operator<;


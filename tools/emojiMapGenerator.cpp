/**
 * @file emojiMapGenerator.cpp
 * @brief
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

#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

static const QString emojiSourceFileStart =
R"(/**
 * @file EmojiMap.cpp
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

#include "EmojiMap.h"

namespace Mattermost {

)";


static const QString emojiSourceFileEnd =
R"(};

const QString& EmojiMap::idToString (uint32_t id)
{
	return emojiStrings[id];
}

const QString& EmojiMap::nameToString (const QString& name)
{
	int id = emojiMap.value (name);
	return idToString (id);
}

uint32_t EmojiMap::nameToId (const QString& emojiName)
{
	return emojiMap.value (emojiName);
}

} /* namespace Mattermost */

)";

uint32_t emojiId = 0;
QMap<QString, QString> emojiNameToIdMap;
QVector<QString> emojiNames;
QVector<QString> emojiValues;

static void addEmoji (const QString& name, const QString& value)
{
	emojiNames.push_back (name);
	emojiValues.push_back (value);
	emojiNameToIdMap [name] = value;
	++emojiId;
}

int main (int argc, char** argv)
{
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <emoji json file> - generates emoji map from emoji json" << std::endl;
		return 1;
	}

	QFile file (argv[1]);
	file.open(QIODevice::ReadOnly);

//	if (!file) {
//		std::cout << "Error opening file '" << argv[1] << "'" << std::endl;
//		return 1;
//	}

	QFile outFile ("EmojiMap.cpp");
	outFile.open(QIODevice::ReadWrite | QIODevice::Truncate);

	QByteArray bytes = file.readAll();
	QJsonDocument doc = QJsonDocument::fromJson(bytes);

	QTextStream outStream (&outFile);
	outStream << emojiSourceFileStart;


	addEmoji ("", "");


	for (auto it: doc.array()) {
		const QJsonObject& jsonObject = it.toObject();

		QString unicode = jsonObject.value("unified").toString();
		QString name = jsonObject.value("short_name").toString();

		QVector<uint32_t> vec;

		for (QString& it: unicode.split("-")) {
			vec += it.toInt(0, 16);
		}

		QString result = QString::fromUcs4 (&vec[0], vec.size());

		if (result.size() > 0 && result[0] == '\0') {
			result = "";
		}

		addEmoji (name, result);

		for (auto shortName: jsonObject.value("short_names").toArray()) {
			if (shortName.toString() != name) {
				addEmoji (shortName.toString(), result);
			}
		}
	}

	outStream << "static const QString emojiStrings[] {\n";

	for (int i = 0; i < emojiValues.size(); ++i) {
		outStream << "\t\"" << emojiValues[i];

		if (emojiValues[i].size() <= 1) {
			outStream << "\",\t\t//";
		} else {
			outStream << "\",\t//";
		}

		if (i == 0) {
			outStream << "(placeholder for not found emoji)" << "\n";
		} else {
			outStream << emojiNames[i] << "\n";
		}
	}

	outStream << R"(};

static const QMap<QString, uint32_t> emojiMap {
)";

	for (int i = 0; i < emojiValues.size(); ++i) {
		outStream << "\t{\"" << emojiNames[i] << "\"," << i << "}," << "\n";
	}

	outStream << emojiSourceFileEnd;
	outFile.close();
	file.close();
	std::cout << "Done. Generated '" << "EmojiMap.cpp" << "'" << std::endl;
	return 0;
}

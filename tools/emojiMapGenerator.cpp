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

const QMap<QString, QString> EmojiMap {
)";


static const QString emojiSourceFileEnd =
R"(};

} /* namespace Mattermost */

)";


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

	for (auto it: doc.array()) {
		const QJsonObject& jsonObject = it.toObject();

		QString unicode = jsonObject.value("unified").toString();
		QString name = jsonObject.value("short_name").toString();

		QVector<uint32_t> vec;

		for (QString& it: unicode.split("-")) {

			//arr += QByteArray::fromHex(it.toLatin1());
			vec += it.toInt(0, 16);
			//arr+= i;
			//result += QChar::uc
		}
		QString result = QString::fromUcs4 (&vec[0], vec.size());


		outStream << "\t{\"" << name << "\",\"" << result << "\"}," << "\n";
	}

	outStream << emojiSourceFileEnd;
	outFile.close();
	file.close();
	std::cout << "Done. Generated '" << "EmojiMap.cpp" << "'" << std::endl;
	return 0;
}

/**
 * @file emojiMapGenerator.cpp
 * @brief Generate emoji map C++ source file
 * @author Lyubomir Filipov
 * @date Jul 28, 2022
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

#include <iostream>
#include <QFile>
#include <set>
#include <QVector>
#include <QDebug>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "backend/emoji/EmojiDefs.h"

namespace Mattermost {

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

#include <QMap>
#include <QVector>
#include "EmojiDefs.h"

namespace Mattermost {

)";

static const QString emojiSourceFileEnd =
R"(
} /* namespace Mattermost */

)";

using Mattermost::Emoji;
using Mattermost::SkinVariadicEmoji;
using Mattermost::SKINVARIADIC_START_INDEX;

static int emojiSeqNoSkinv = 1;
static int emojiSeqSkinv = 0;

static std::map<QString, uint16_t> emojiNameToIdMap;
static uint32_t lastCategorySeq[EmojiCategory::COUNT];
static QVector<Emoji> emojiVecNoSkinv[EmojiCategory::COUNT];
static QVector<SkinVariadicEmoji> emojiVecSkinv;

/**
 * Category names - as they are mentioned in the json file
 */
static QString categoryNames[] {
	"smileys-emotion",
	"people-body",
	"component",
	"animals-nature",
	"food-drink",
	"travel-places",
	"activities",
	"objects",
	"symbols",
	"flags",
	"custom",
};

static QMap<QString, uint32_t> categoryLookup {
	{categoryNames[EmojiCategory::smileys],		EmojiCategory::smileys},
	{categoryNames[EmojiCategory::people],		EmojiCategory::people},
	{categoryNames[EmojiCategory::component], 	EmojiCategory::component},
	{categoryNames[EmojiCategory::nature], 		EmojiCategory::nature},
	{categoryNames[EmojiCategory::food], 		EmojiCategory::food},
	{categoryNames[EmojiCategory::travel], 		EmojiCategory::travel},
	{categoryNames[EmojiCategory::activities], 	EmojiCategory::activities},
	{categoryNames[EmojiCategory::objects], 	EmojiCategory::objects},
	{categoryNames[EmojiCategory::symbols], 	EmojiCategory::symbols},
	{categoryNames[EmojiCategory::flags], 		EmojiCategory::flags},
	{categoryNames[EmojiCategory::custom], 		EmojiCategory::custom},
};


static void addNoSkinVariadicEmoji (const QVector<QString>& names, const QVector<QString>& values, QMap<QString, uint32_t>::iterator categoryIt)
{
	//validate values size
	if (values.size() != 1) {
		qDebug() << names.front() << ": expecting exacly one value for NoSkinVariadicEmoji";
		exit (1);
	}

//	if (emojiSeqNoSkinv != emojiVecNoSkinv.size() + 1) {
//		qDebug() << names.front() << ": emoji ID " << emojiSeqNoSkinv << ": unexpected emojiVecNoSkinv size " << emojiVecNoSkinv.size();
//		exit (1);
//	}

	//add all names to the map, so that the emoji can be found by it's name

	/**
	 * An emoji can have multiple names, associated with it.
	 * Add all names to the map, so that the emoji can be identified by any of them
	 */
	for (auto& name: names) {
		emojiNameToIdMap [name] = emojiSeqNoSkinv;
	}

	lastCategorySeq[categoryIt.value()] = emojiSeqNoSkinv;
	emojiVecNoSkinv[categoryIt.value()].push_back (Mattermost::Emoji {names.front(), values.front()});
	++emojiSeqNoSkinv;
}

static void addNoSkinVariadicEmoji (const QString& name, const QString& value)
{
	const QVector<QString> names ({name});
	const QVector<QString> values ({value});

	addNoSkinVariadicEmoji (names, values, categoryLookup.find("custom"));
}

static void addSkinVariadicEmoji (const QVector<QString>& names, const QVector<QString>& values)
{
	//validate values size
	if (values.size() != 6 && values.size() != 26) {
		qDebug() << names.front() << ": expecting 5 or 26 values for SkinVariadicEmoji, got " << values.size();
		exit (1);
	}

	if (emojiSeqSkinv != emojiVecSkinv.size()) {
		qDebug() << names.front() << ": emoji ID " << emojiSeqSkinv << ": unexpected emojiVecSkinv size " << emojiVecSkinv.size();
		exit (1);
	}

	/**
	 * An emoji can have multiple names, associated with it.
	 * Add all names to the map, so that the emoji can be identified by any of them
	 */
	for (auto& name: names) {
		emojiNameToIdMap [name] = emojiSeqSkinv + SKINVARIADIC_START_INDEX;
	}

	Mattermost::SkinVariadicEmoji skinVariadicEmoji;
	skinVariadicEmoji.name = names.front();
	skinVariadicEmoji.unicodeString = values;

	lastCategorySeq[EmojiCategory::people] = emojiSeqNoSkinv;
	emojiVecSkinv.push_back (skinVariadicEmoji);
	++emojiSeqSkinv;
}

static QString getUnicodeFromJson (QString unicodeText)
{
	QVector<uint32_t> vec;

	for (QString& it: unicodeText.split("-")) {
		vec += it.toInt(0, 16);
	}

	QString result = QString::fromUcs4 (&vec[0], vec.size());

	if (result.size() > 0 && result[0] == '\0') {
		result = "";
	}

	return result;
}

/**
 * Unicode codepoints for skin tones. They are appended to emojis, which have skin tone variation
 */
#define SKIN_LIGHT	"1F3FB"
#define SKIN_MLIGHT "1F3FC"
#define SKIN_MEDIUM "1F3FD"
#define SKIN_MDARK 	"1F3FE"
#define SKIN_DARK 	"1F3FF"


uint32_t getSkinIndex (QString skinName)
{
	/**
	 * Convert skin tone codepoint to skin tone index.
	 * Note, some emojis have all combinations of skin tone (for example, 'people holding hands')
	 * This results in 5 emojis for each such emoji, each of them having 5 variants for skin tone. It makes selection
	 * more complicated for the user, so that only emojis with the same skin tone in both positions will be stored
	 */
	static const std::map<QString, int> skinToIndex {
		{SKIN_LIGHT, 1},
		{SKIN_MLIGHT, 2},
		{SKIN_MEDIUM, 3},
		{SKIN_MDARK, 4},
		{SKIN_DARK, 5},

		{SKIN_LIGHT "-" SKIN_LIGHT, 1},
		{SKIN_MLIGHT "-" SKIN_MLIGHT, 2},
		{SKIN_MEDIUM "-" SKIN_MEDIUM, 3},
		{SKIN_MDARK "-" SKIN_MDARK, 4},
		{SKIN_DARK "-" SKIN_DARK, 5},
	};

	auto skinIndexIt = skinToIndex.find (skinName);

	if (skinIndexIt == skinToIndex.end()) {
		qDebug() << "no skin-tone name " << skinName << "found";
		//exit (1);
		return 0;
	}

	return skinIndexIt->second;
}

void addEmoji (const QJsonObject& jsonObject)
{
	/**
	 * Ignore emojis having 'skins' property, because they duplicate the emojis with
	 * 'skin-variations' property. The 'skin-variations' property will be used for
	 * emojis with skin variations
	 */
	if (jsonObject.contains("skins")) {
		return;
	}

	QString name = jsonObject.value("short_name").toString();

	/**
	 * The 'mattermost' emoji is special - it is not in custom emoji list.
	 * Maybe it is hardcoded in the official Mattermost client
	 */
	if (name == "mattermost") {
		addNoSkinVariadicEmoji (name, " <img src=\\\"qrc://img/mattermost-emoji.png\\\" width=32 height=32> ");
		return;
	}

	QString category = jsonObject.value("category").toString();
	QString unicode = jsonObject.value("unified").toString();


//		if (category == "people-body" && skinVariations ==!hasSkinVariations) {
//			qDebug() << "[" << category << "] emoji '" << name << "' has no skin_variations";
//			//exit (1);
//		}


	qDebug() << "[" << category << "] Add emoji '" << name << "'";


	const QJsonObject& skinVariations = jsonObject.value("skin_variations").toObject();

	/**
	 * Values (unicode strings) for emojis
	 */
	QVector<QString> emojiValues;
	emojiValues.resize (1 + skinVariations.keys().size());

	//The default skin tone (yellow) always has the first index
	emojiValues[0] = getUnicodeFromJson (unicode);

	for (auto skinName: skinVariations.keys()) {

		const QJsonObject& skinValue = skinVariations.value (skinName).toObject();

		QString unicode = skinValue.value("unified").toString();
		qDebug() << "[" << category << "] Add emoji '" << name << "'" << unicode;

		uint32_t skinIndex = getSkinIndex (skinName);

		if (skinIndex != 0) {
			emojiValues[skinIndex] = getUnicodeFromJson (unicode);
		}
	}

	/**
	 * Names which are used to identify the emoji.
	 * An emoji may have multiple names and should be able to be found by any of them
	 */
	QVector<QString> emojiNames;
	emojiNames.push_back (name);

	for (auto shortName: jsonObject.value("short_names").toArray()) {
		if (shortName.toString() != name) {
			emojiNames.push_back (shortName.toString());
		}
	}

	auto categoryIt = categoryLookup.find (category);
	if (categoryIt == categoryLookup.end()) {
		qDebug() << "category " << category << "not found";
		exit (1);
	}

	if (!skinVariations.isEmpty()) {
		addSkinVariadicEmoji (emojiNames, emojiValues);
	} else {
		addNoSkinVariadicEmoji (emojiNames, emojiValues, categoryIt);
	}
}

} /* namespace Mattermost */

using namespace Mattermost;

int main (int argc, char** argv)
{
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <emoji json file> - generates emoji map from emoji json" << std::endl;
		return 1;
	}

	QFile file (argv[1]);
	file.open(QIODevice::ReadOnly);


	QByteArray bytes = file.readAll();
	QJsonDocument doc = QJsonDocument::fromJson(bytes);

	/**
	 * Read all emoji data from the .json file
	 */
	for (auto jsonObjectIt: doc.array()) {
		addEmoji (jsonObjectIt.toObject());
	}

	/**
	 * Open the output .cpp file and write emoji definitions to it
	 */
	QFile outFile ("EmojiMap.cpp");
	outFile.open(QIODevice::ReadWrite | QIODevice::Truncate);
	QTextStream outStream (&outFile);
	outStream << emojiSourceFileStart;

	outStream << "uint32_t nextEmojiSeq = " << emojiSeqNoSkinv << ";\n\n";

	outStream << "uint32_t lastCategorySeq[EmojiCategory::COUNT] = {\n";
	for (int i = 0; i < EmojiCategory::COUNT; ++i) {
		outStream << "\t" << lastCategorySeq[i] << ", //" << categoryNames[i] << "\n";
	}
	outStream << "};\n\n";

	outStream << "QVector<Emoji> emojiVecNoSkinVariadic[EmojiCategory::COUNT] {\n";
	for (int i = 0; i < EmojiCategory::COUNT; ++i) {
		outStream << "{ //" << categoryNames[i] << "\n";
		for (auto& it: emojiVecNoSkinv[i]) {
			outStream << "\t{\"" << it.name << "\",\"" << it.unicodeString << "\"}," << "\n";
		}
		outStream << "\n},";
	}
	outStream << "};\n\n";

	outStream << "QVector<SkinVariadicEmoji> emojiVecSkinVariadic {\n";
	for (auto& it: emojiVecSkinv) {
		outStream << "\t{\"" << it.name << "\",";

		outStream << "{";
		for (auto& val: it.unicodeString) {
			outStream << "\"" << val << "\",";
		}
		outStream << "}},\n";
	}
	outStream << "};\n\n";

	outStream << "QMap<QString, EmojiSeq>  emojiMap {\n";
	for (auto& it: emojiNameToIdMap) {
		outStream << "\t{\"" << it.first << "\", " << it.second  << "}," << "\n";
	}
	outStream << "};\n";

	outStream << emojiSourceFileEnd;
	outFile.close();
	file.close();
	std::cout << "Done. Generated '" << "EmojiMap.cpp" << "'" << std::endl;
	return 0;
}

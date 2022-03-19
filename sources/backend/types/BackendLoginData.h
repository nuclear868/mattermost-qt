/**
 * @file BackendLoginData.h
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 5, 2021
 */

#pragma once

#include <QString>
#include <QSettings>

namespace Mattermost {

class BackendLoginData {
public:
	void loadFromSettings (const QSettings& settings);
	void saveToSettings (QSettings& settings)	const;
	bool areAllFieldsFilled () 					const;
public:
	QString 	domain;
	QString 	username;
	QString 	password;
	//QString 	alias;
};

} /* namespace Mattermost */

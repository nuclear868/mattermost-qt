/**
 * @file BackendLoginData.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 5, 2021
 */

#include "BackendLoginData.h"

namespace Mattermost {

void BackendLoginData::loadFromSettings (const QSettings& settings)
{
	domain = settings.value("domain").toString();
	username = settings.value("username").toString();
	password = settings.value("password").toString();
}

void BackendLoginData::saveToSettings (QSettings& settings) const
{
	settings.setValue("domain", domain);
	settings.setValue("username", username);
	settings.setValue("password", password);
}

bool BackendLoginData::areAllFieldsFilled () const
{
	return !domain.isEmpty()
			&& !username.isEmpty()
			&& !password.isEmpty();
}

} /* namespace Mattermost */


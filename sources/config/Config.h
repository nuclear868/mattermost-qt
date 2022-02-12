/**
 * @file Config.h
 * @brief Mattermost configuration class
 * @author Lyubomir Filipov
 * @date Feb 12, 2022
 */

#pragma once

#include <QString>

namespace Mattermost {

class Config {
public:
	Config () = delete;
	virtual ~Config () = delete;
public:
	static void init ();
	static QString tempDirectory ();
};

} /* namespace Mattermost */

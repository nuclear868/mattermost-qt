/**
 * @file RequestTracker.h
 * @brief Tracks requests in progress and does not allow duplicating them
 * @author Lyubomir Filipov
 * @date Apr 23, 2023
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


#pragma once

#include <QSet>

namespace Mattermost {

struct RequestTrackerEntry {

	RequestTrackerEntry (int type, const void* pointer1, const void* pointer2)
	:type (type)
	,pointer1 (pointer1)
	,pointer2 (pointer2)
	{}

	bool operator== (const RequestTrackerEntry& other) const
	{
		return type == other.type && pointer1 == other.pointer1 && pointer2 == other.pointer2;
	}

	int 		type;
	const void*	pointer1;
	const void*	pointer2;
};


/**
 * Prevents sending multiple requests for actions related to specified objects.
 * Callers can add an entry that was requested, and ignore next requests for the same data.
 * Callers delete entries when a response is received
 */
class RequestTracker {
public:
	RequestTracker ();
	virtual ~RequestTracker ();
public:
	void addEntry (const RequestTrackerEntry& entry);
	bool hasEntry (const RequestTrackerEntry& entry);
	void eraseEntry (const RequestTrackerEntry& entry);
	void reset ();
private:
	QSet<RequestTrackerEntry> entries;
};

} /* namespace Mattermost */

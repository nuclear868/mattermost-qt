/**
 * @file RequestTracker.cpp
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


#include "RequestTracker.h"
#include "log.h"

namespace Mattermost {

quint32 qHash(const RequestTrackerEntry& entry)
{
	return ::qHash (entry.type, 0) ^ ::qHash (entry.pointer1) ^ ::qHash (entry.pointer2);
}

RequestTracker::RequestTracker () = default;
RequestTracker::~RequestTracker () = default;

void RequestTracker::addEntry (const RequestTrackerEntry& entry)
{
	if (hasEntry (entry)) {
		LOG_DEBUG ("RequestTracker addEntry: Entry " << entry.type << " alreay exists");
		return;
	}

	entries.insert (entry);
}

bool RequestTracker::hasEntry (const RequestTrackerEntry& entry)
{
	return entries.contains (entry);
}

void RequestTracker::eraseEntry (const RequestTrackerEntry& entry)
{
	if (!hasEntry (entry)) {
		LOG_DEBUG ("RequestTracker eraseEntry: Entry " << entry.type << " not found");
		return;
	}

	entries.remove (entry);
}

void RequestTracker::reset ()
{
	entries.clear ();
}

} /* namespace Mattermost */

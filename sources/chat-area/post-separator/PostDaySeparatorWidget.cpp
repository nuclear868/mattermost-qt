/**
 * @file PostDaySeparatorWidget.cpp
 * @brief Separates posts from different days
 * @author Lyubomir Filipov
 * @date Nov 12, 2022
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

#include "PostDaySeparatorWidget.h"
#include <QDateTime>
#include <QDebug>

namespace Mattermost {

static QString getDayString (int daysAgo)
{
	switch (daysAgo) {
	case 0:
		return "Today";
	case 1:
		return "Yesterday";
	default:
		return QDateTime::currentDateTime().date().addDays(-daysAgo).toString("dd MMM yyyy");
	}

	return "";
}

PostDaySeparatorWidget::PostDaySeparatorWidget (uint32_t daysAgo)
:PostSeparatorWidget (getDayString (daysAgo))
,daysAgo (daysAgo)
{
	if (daysAgo > 1) {
		return;
	}

	/**
	 * If the text is 'Today' or 'Yesterday', it has to be shifted with one day,
	 * when the next day comes
	 */
	connect (&updateDayStringTimer, &QTimer::timeout, [this] {
		++this->daysAgo;
		setText (getDayString (this->daysAgo));

		updateDayStringTimer.stop ();

		if (this->daysAgo > 1) {
			return;
		}

		startUpdateDayStringTimer ();
	});

	startUpdateDayStringTimer ();
}

PostDaySeparatorWidget::~PostDaySeparatorWidget () = default;

//date.endOfDay() was introduced in QT 14
#if QT_VERSION_MAJOR == 5 && QT_VERSION_MINOR < 14
static QDateTime endOfDay (QDateTime now)
{
	QDateTime when (now.date(), QTime(23, 59, 59, 999));

    return when.isValid() ? when : QDateTime().addDays (1);
}
#endif


int PostDaySeparatorWidget::getMsToEndOfTheDay ()
{
	QDateTime now = QDateTime::currentDateTime();

//date.endOfDay() was introduced in QT 14
#if QT_VERSION_MAJOR == 5 && QT_VERSION_MINOR < 14
	QDateTime end = endOfDay ();
#else
	QDateTime end = now.date().endOfDay ();
#endif

	//add 2000, so that the calculation for the end of the next day will be correct
	return now.msecsTo(end) + 2000;
}

void PostDaySeparatorWidget::startUpdateDayStringTimer ()
{
	int diff = getMsToEndOfTheDay ();
	updateDayStringTimer.start (diff);
}

} /* namespace Mattermost */

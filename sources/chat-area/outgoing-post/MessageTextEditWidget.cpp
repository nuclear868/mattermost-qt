/**
 * @file MessageTextEditWidget.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Jan 7, 2022
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

#include "MessageTextEditWidget.h"
#include <QKeyEvent>
#include <QDebug>

namespace Mattermost {

MessageTextEditWidget::MessageTextEditWidget (QWidget *parent)
:QTextEdit (parent)
{
}

MessageTextEditWidget::~MessageTextEditWidget () = default;

void MessageTextEditWidget::keyPressEvent (QKeyEvent* event)
{
	switch (event->key()) {
	case Qt::Key_Up:
		emit upArrowPressed ();
		break;
	case Qt::Key_Escape:
		emit escapePressed ();
		break;
	case Qt::Key_Enter:
	case Qt::Key_Return:
		if (event->modifiers() & Qt::ShiftModifier) {
			//do nothing, new line will be added
		} else {
			emit enterPressed ();
			return;
		}
	}

	QTextEdit::keyPressEvent (event);
}

bool MessageTextEditWidget::hasNonEmptyText ()
{
	return document()->characterCount() > 1;
}

} /* namespace Mattermost */

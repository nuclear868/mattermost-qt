/**
 * @file MessageTextEditWidget.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Jan 7, 2022
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

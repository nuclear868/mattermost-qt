/**
 * @file MessageTextEditWidget.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Jan 7, 2022
 */

#include "MessageTextEditWidget.h"
#include <QKeyEvent>

namespace Mattermost {

MessageTextEditWidget::MessageTextEditWidget (QWidget *parent)
:QTextEdit (parent)
{
}

MessageTextEditWidget::~MessageTextEditWidget () = default;

void MessageTextEditWidget::keyPressEvent (QKeyEvent* event)
{
	if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
		if (event->modifiers() & Qt::ShiftModifier) {

		} else {
			emit enterPressed();
			return;
		}

	}

	QTextEdit::keyPressEvent (event);
}

} /* namespace Mattermost */

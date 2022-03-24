/**
 * @file MessageTextEditWidget.h
 * @brief
 * @author Lyubomir Filipov
 * @date Jan 7, 2022
 */

#pragma once

#include <qtextedit.h>

namespace Mattermost {

class MessageTextEditWidget: public QTextEdit {
	Q_OBJECT
public:
	MessageTextEditWidget (QWidget *parent = nullptr);
	virtual ~MessageTextEditWidget ();
public:
	void keyPressEvent (QKeyEvent* event) override;
	bool hasNonEmptyText ();
signals:
	void enterPressed ();
	void escapePressed ();
	void upArrowPressed ();
};

} /* namespace Mattermost */

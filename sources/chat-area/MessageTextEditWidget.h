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
signals:
	void enterPressed ();
};

} /* namespace Mattermost */

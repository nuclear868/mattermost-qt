/**
 * @file AttachmentListWidget.h
 * @brief
 * @author Lyubomir Filipov
 * @date Jan 21, 2022
 */

#pragma once

#include <qlistwidget.h>

namespace Mattermost {

class AttachmentListWidget: public QListWidget {
public:
	using QListWidget::QListWidget;
private:
	QSize sizeHint () const	override;
};

} /* namespace Mattermost */

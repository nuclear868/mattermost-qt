/**
 * @file PostAttachmentListWidget.h
 * @brief
 * @author Lyubomir Filipov
 * @date Jan 21, 2022
 */

#pragma once

#include <qlistwidget.h>

namespace Mattermost {

class PostAttachmentListWidget: public QListWidget {
public:
	using QListWidget::QListWidget;
private:
	QSize sizeHint () const	override;
};

} /* namespace Mattermost */

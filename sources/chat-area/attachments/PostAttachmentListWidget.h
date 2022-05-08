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
	QSize sizeHint () const	override;
private:
};

} /* namespace Mattermost */

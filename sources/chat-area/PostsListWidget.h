/**
 * @file PostsListWidget.h
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 27, 2021
 */

#pragma once

#include <QListWidget>

class PostsListWidget: public QListWidget {
public:
	using QListWidget::QListWidget;
private:
	void resizeEvent (QResizeEvent *event)	override;
};


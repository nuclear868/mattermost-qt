/**
 * @file ChannelItem.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Mar 30, 2022
 */

#include "ChannelItem.h"

#include <QDebug>
#include <QMenu>
#include "ChannelItemWidget.h"

namespace Mattermost {

ChannelItem::ChannelItem (QTreeWidgetItem* parent, ChannelItemWidget* widget)
:ChannelTreeItem (parent)
,widget (widget)
{
	QFont font1;
	font1.setBold (true);
	font1.setPixelSize(14);
	setFont (1, font1);
}

ChannelItem::~ChannelItem () = default;

void ChannelItem::setIcon (const QIcon& icon)
{
	if (widget) {
		widget->setIcon (icon);
	}
}

void ChannelItem::setLabel (const QString& label)
{
	if (widget) {
		widget->setLabel (label);
	}
}

void ChannelItem::showContextMenu (const QPoint& pos)
{
	// Create menu and insert some actions
	QMenu myMenu;

	myMenu.addAction ("ChannelItem", [] {
		qDebug() << "ChannelItem ";
	});

	myMenu.exec (pos);
}

} /* namespace Mattermost */

/**
 * @file ChannelItem.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Mar 30, 2022
 */

#include "ChannelItem.h"

#include "ChannelItemWidget.h"

namespace Mattermost {

ChannelItem::ChannelItem (Backend& backend, ChannelItemWidget* widget)
:ChannelTreeItem ()
,backend (backend)
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

} /* namespace Mattermost */

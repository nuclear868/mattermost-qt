/**
 * @file TeamChannelsListDialog.cpp
 * @brief
 * @author Lyubomir Filipov
 * @date Apr 16, 2022
 */

#include "TeamChannelsListDialog.h"

#include <set>
#include <QMenu>
#include "backend/Backend.h"
#include "backend/types/BackendChannel.h"
#include "info-dialogs/ChannelInfoDialog.h"
#include "ui_FilterListDialog.h"


namespace Mattermost {

namespace {

auto nameComparator = [] (const BackendChannel* const& lhs, const BackendChannel* const& rhs)
{
	return lhs->name < rhs->name;
};

}

TeamChannelsListDialog::TeamChannelsListDialog (Backend& backend, const QString& teamName, const std::list<BackendChannel>& channels, QWidget *parent)
:FilterListDialog (parent)
,backend (backend)
{
	std::set<const BackendChannel*, decltype (nameComparator)> set (nameComparator);

	for (auto& it: channels) {
		set.insert (&it);
	}

	uint32_t channelsCount = 0;
	for (auto& channel: set) {

		QTreeWidgetItem* item = new QTreeWidgetItem (ui->treeWidget, QStringList() << channel->display_name << channel->header);
//		QImage img = QImage::fromData (user->avatar);
//		item->setIcon (0, QIcon(QPixmap::fromImage(QImage::fromData (user->avatar)).scaled(32, 32)));
		item->setData (0, Qt::UserRole, QVariant::fromValue ((BackendChannel*)channel));
		ui->treeWidget->addTopLevelItem (item);
		++channelsCount;
	}

	setWindowTitle("Public Channels - Mattermost");
	ui->selectUserLabel->setText ("Public Channels in team '" + teamName + "':");
	ui->treeWidget->header()->setSectionResizeMode (0, QHeaderView::ResizeToContents);
	ui->treeWidget->header()->setSectionResizeMode (1, QHeaderView::Stretch);
	ui->usersCountLabel->setText(QString::number(channelsCount) + " channels");
	ui->filterUsersLabel->setText("Filter channels by name");

	ui->buttonBox->setStandardButtons(QDialogButtonBox::Close);
}

TeamChannelsListDialog::~TeamChannelsListDialog ()
{
	// TODO Auto-generated destructor stub
}

void TeamChannelsListDialog::showContextMenu (const QPoint& pos)
{
	// Create menu and insert some actions
	QMenu myMenu;

	// Handle global position
	QPoint globalPos = ui->treeWidget->mapToGlobal(pos);

	QTreeWidgetItem* pointedItem = ui->treeWidget->itemAt(pos);

	if (!pointedItem) {
		return;
	}

	BackendChannel *channel = pointedItem->data(0, Qt::UserRole).value<BackendChannel*>();

	//direct channel
	myMenu.addAction ("Join this channel", [this, channel] {
		backend.joinChannel (*channel);
	//	qDebug() << "View Profile for " << user->getDisplayName();
		//UserProfileDialog* dialog = new UserProfileDialog (*user, ui->treeWidget);
		//dialog->show ();
	});

	myMenu.addAction ("View channel details", [this, channel] {
		ChannelInfoDialog* dialog = new ChannelInfoDialog (*channel, this);
		dialog->show ();
	});

	myMenu.exec (globalPos + QPoint (15, 35));
}

} /* namespace Mattermost */

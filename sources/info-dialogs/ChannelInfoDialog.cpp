
#include "ChannelInfoDialog.h"
#include "ui_ChannelInfoDialog.h"

#include "backend/types/BackendChannel.h"
#include "backend/types/BackendTeam.h"

namespace Mattermost {

static QString getString (const QString& str)
{
	return str.isEmpty() ? "N/A" : str;
}


ChannelInfoDialog::ChannelInfoDialog (const BackendChannel& channel, QWidget *parent)
:QDialog(parent)
,ui(new Ui::ChannelInfoDialog)
{
    ui->setupUi(this);

    setWindowTitle ("Information for channel '" + channel.display_name + "' - Mattermost");

    ui->nameValue->setText (channel.name);
	ui->teamValue->setText (channel.team ? channel.team->display_name : "N/A");
    ui->headerValue->setText (getString (channel.header));
	ui->purposeValue->setText (getString (channel.purpose));
    ui->creatorValue->setText (channel.creator ? channel.creator->getDisplayName() : "N/A");
    ui->messageCountValue->setText (QString::number (channel.total_msg_count));
}

ChannelInfoDialog::~ChannelInfoDialog()
{
    delete ui;
}

} /* namespace Mattermost */

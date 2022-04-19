#include "ChannelInfoDialog.h"
#include "ui_ChannelInfoDialog.h"

ChannelInfoDialog::ChannelInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChannelInfoDialog)
{
    ui->setupUi(this);
}

ChannelInfoDialog::~ChannelInfoDialog()
{
    delete ui;
}

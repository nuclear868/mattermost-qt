#include "ChannelItemWidget.h"
#include "ui_ChannelItemWidget.h"

ChannelItemWidget::ChannelItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChannelItemWidget)
{
    ui->setupUi (this);
    ui->icon->setVisible (false);
}

ChannelItemWidget::~ChannelItemWidget()
{
    delete ui;
}

void ChannelItemWidget::setIcon (const QIcon& icon)
{
	ui->icon->setPixmap (icon.pixmap(24, 24));
	ui->icon->setVisible (true);
}

void ChannelItemWidget::setLabel (const QString& label)
{
	ui->label->setText (label);
}

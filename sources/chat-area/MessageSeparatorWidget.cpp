#include "MessageSeparatorWidget.h"
#include "ui_MessageSeparatorWidget.h"

MessageSeparatorWidget::MessageSeparatorWidget (const QString& text)
:QWidget(nullptr)
,ui(new Ui::MessageSeparatorWidget)
{
    ui->setupUi(this);
    ui->label->setText (text);
}

MessageSeparatorWidget::~MessageSeparatorWidget()
{
    delete ui;
}

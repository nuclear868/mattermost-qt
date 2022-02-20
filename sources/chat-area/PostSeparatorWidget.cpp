#include "PostSeparatorWidget.h"
#include "ui_PostSeparatorWidget.h"

PostSeparatorWidget::PostSeparatorWidget (const QString& text)
:QWidget(nullptr)
,ui(new Ui::PostSeparatorWidget)
{
    ui->setupUi(this);
    ui->label->setText (text);
}

PostSeparatorWidget::~PostSeparatorWidget()
{
    delete ui;
}

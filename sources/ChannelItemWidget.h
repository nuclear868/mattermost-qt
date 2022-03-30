#ifndef CHANNELITEMWIDGET_H
#define CHANNELITEMWIDGET_H

#include <QWidget>
#include <QIcon>

namespace Ui {
class ChannelItemWidget;
}

class ChannelItemWidget: public QWidget
{
    Q_OBJECT

public:
    explicit ChannelItemWidget(QWidget *parent = nullptr);
    ~ChannelItemWidget();

    void setIcon (const QIcon &icon);
    void setLabel (const QString& label);

private:
    Ui::ChannelItemWidget *ui;
};

#endif // CHANNELITEMWIDGET_H

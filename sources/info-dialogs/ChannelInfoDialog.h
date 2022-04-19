#ifndef CHANNELINFODIALOG_H
#define CHANNELINFODIALOG_H

#include <QDialog>

namespace Ui {
class ChannelInfoDialog;
}

class ChannelInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChannelInfoDialog(QWidget *parent = nullptr);
    ~ChannelInfoDialog();

private:
    Ui::ChannelInfoDialog *ui;
};

#endif // CHANNELINFODIALOG_H

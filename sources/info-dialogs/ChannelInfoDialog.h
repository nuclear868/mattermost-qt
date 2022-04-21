#ifndef CHANNELINFODIALOG_H
#define CHANNELINFODIALOG_H

#include <QDialog>
#include "fwd.h"

namespace Ui {
class ChannelInfoDialog;
}

namespace Mattermost {

class ChannelInfoDialog: public QDialog
{
    Q_OBJECT

public:
    explicit ChannelInfoDialog (const BackendChannel& channel, QWidget *parent = nullptr);
    ~ChannelInfoDialog();

private:
    Ui::ChannelInfoDialog *ui;
};

} /* namespace Mattermost */

#endif // CHANNELINFODIALOG_H

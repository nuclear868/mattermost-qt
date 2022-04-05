#ifndef NEWDIRECTCHANNELDIALOG_H
#define NEWDIRECTCHANNELDIALOG_H

#include <map>
#include <QDialog>
#include "fwd.h"

namespace Ui {
class NewDirectChannelDialog;
}

namespace Mattermost {

class NewDirectChannelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewDirectChannelDialog (const std::map<QString, BackendUser>& users, QWidget *parent = nullptr);
    ~NewDirectChannelDialog();
public:
    const BackendUser* getSelectedUser ();
private:
    void applyFilter (const QString& filter);
private:
    Ui::NewDirectChannelDialog *ui;
};

} /* namespace Mattermost */

#endif // NEWDIRECTCHANNELDIALOG_H

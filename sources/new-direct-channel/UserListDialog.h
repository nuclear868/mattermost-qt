#ifndef USERDIALOG_H
#define USERDIALOG_H

#include <map>
#include <QDialog>
#include "fwd.h"

namespace Ui {
class UserListDialog;
}

namespace Mattermost {

class UserListDialog : public QDialog
{
    Q_OBJECT

public:
    UserListDialog (const std::map<QString, BackendUser>& users, QWidget *parent);
    UserListDialog (const std::vector<BackendUser*>& users, QWidget *parent);
    ~UserListDialog();
public:
    const BackendUser* getSelectedUser ();
private:
    void applyFilter (const QString& filter);
protected:
    Ui::UserListDialog *ui;
};

} /* namespace Mattermost */

#endif // USERDIALOG_H

#ifndef USERPROFILEDIALOG_H
#define USERPROFILEDIALOG_H

#include <QDialog>
#include "fwd.h"

namespace Ui {
class UserProfileDialog;
}

namespace Mattermost {

class UserProfileDialog: public QDialog
{
    Q_OBJECT

public:
    explicit UserProfileDialog (const BackendUser& user, QWidget *parent = nullptr);
    ~UserProfileDialog();

private:
    Ui::UserProfileDialog *ui;
};

} /* namespace Mattermost */

#endif // USERPROFILEDIALOG_H

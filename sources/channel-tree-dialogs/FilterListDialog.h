#ifndef USERDIALOG_H
#define USERDIALOG_H

#include <map>
#include <QDialog>
#include "fwd.h"

namespace Ui {
class FilterListDialog;
}

namespace Mattermost {

class FilterListDialog : public QDialog
{
    Q_OBJECT

public:
    FilterListDialog (QWidget *parent);
    ~FilterListDialog();
private:
    void applyFilter (const QString& filter);
    virtual void showContextMenu (const QPoint& pos) = 0;
protected:
    Ui::FilterListDialog *ui;
};

} /* namespace Mattermost */

#endif // USERDIALOG_H

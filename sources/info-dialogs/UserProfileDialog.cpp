
#include "UserProfileDialog.h"
#include "ui_UserProfileDialog.h"

#include "backend/types/BackendUser.h"

namespace Mattermost {

UserProfileDialog::UserProfileDialog (const BackendUser& user, QWidget *parent)
:QDialog(parent)
,ui(new Ui::UserProfileDialog)
{
    ui->setupUi(this);

    setWindowTitle ("Profile for " + user.getDisplayName() + " - Mattermost");

	QImage img = QImage::fromData (user.avatar).scaled (128, 128, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->avatar->setPixmap (QPixmap::fromImage(img));
    ui->fullnameValue->setText (user.first_name + " " + user.last_name);
    ui->nicknameValue->setText (user.nickname.isEmpty() ? "N/A" : user.nickname);
    ui->usernameValue->setText (user.username);
    ui->emailValue->setText (user.email);
    ui->positionValue->setText (user.position.isEmpty() ? "N/A" : user.position);
    ui->statusValue->setText (user.status);
    ui->timezoneValue->setText (user.timezone.automaticTimezone);
}

UserProfileDialog::~UserProfileDialog()
{
    delete ui;
}

} /* namespace Mattermost */

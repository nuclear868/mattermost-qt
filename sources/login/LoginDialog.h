#pragma once

#include <QDialog>
#include "backend/types/BackendLoginData.h"

namespace Ui {
class LoginDialog;
}

namespace Mattermost {

class Backend;

class LoginDialog: public QDialog {
	Q_OBJECT
public:
	LoginDialog (QWidget *parent, Backend& backend, bool autoLogin);
	~LoginDialog ();
private slots:
	void on_login_pushButton_clicked();

	void onNetworkError (uint32_t errorNumber, const QString& errorText);
	void onHttpError (uint32_t errorNumber, const QString& errorText);

private:
	void setError (const QString& errorStr);
	void loginToServer (const BackendLoginData& loginData);

	Backend&			backend;
	Ui::LoginDialog*	ui;
};

} /* namespace Mattermost */

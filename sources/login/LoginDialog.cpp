
#include <iostream>
#include "LoginDialog.h"
#include "ui_LoginDialog.h"

#include <QSettings>
#include "backend/Backend.h"
#include "log.h"

namespace Mattermost {

LoginDialog::LoginDialog (QWidget *parent, Backend& backend, bool autoLogin)
:QDialog(parent)
,backend (backend)
,ui(new Ui::LoginDialog)
{
	setAttribute (Qt::WA_DeleteOnClose);
	QSettings settings;
	BackendLoginData loginData;
	loginData.loadFromSettings (settings);

	ui->setupUi(this);

	connect (&backend, &Backend::onNetworkError, this, &LoginDialog::onNetworkError);
	connect (&backend, &Backend::onHttpError, this, &LoginDialog::onHttpError);

	if (loginData.domain.isEmpty()) {
		loginData.domain = "https://";
	}

	ui->domain_lineEdit->setText (loginData.domain);
	ui->username_lineEdit->setText (loginData.username);
	ui->password_lineEdit->setText (loginData.password);
	ui->alias_lineEdit->setText (loginData.alias);

	//if all data is available in the settings, use it for the login
	if (autoLogin && loginData.areAllFieldsFilled()) {
		loginToServer (loginData);
	}
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_login_pushButton_clicked()
{
	QSettings settings;
	BackendLoginData loginData;

	loginData.domain = ui->domain_lineEdit->text();
	loginData.username = ui->username_lineEdit->text();
	loginData.password = ui->password_lineEdit->text();
	loginData.alias = ui->alias_lineEdit->text();

	loginData.saveToSettings (settings);
	loginToServer (loginData);
}

void LoginDialog::loginToServer (const BackendLoginData& loginData)
{
    ui->domain_lineEdit->setEnabled(false);
    ui->username_lineEdit->setEnabled(false);
    ui->password_lineEdit->setEnabled(false);
    ui->alias_lineEdit->setEnabled(false);
    ui->login_pushButton->setEnabled(false);
    ui->error_label->clear();

    LOG_DEBUG ("LoginDialog login");
    backend.login (loginData, [this]{
    	accept();
    });
}

void LoginDialog::onNetworkError (uint32_t errorNumber, const QString& errorText)
{
	qCritical() << "Net error: " << errorNumber << ": " << errorText;

    ui->domain_lineEdit->setEnabled(true);
    ui->username_lineEdit->setEnabled(true);
    ui->password_lineEdit->setEnabled(true);
    ui->alias_lineEdit->setEnabled(true);
    ui->login_pushButton->setEnabled(true);
    ui->error_label->setText ("Network Error: " + errorText);
}

void LoginDialog::onHttpError (uint32_t errorNumber, const QString& errorText)
{
    ui->domain_lineEdit->setEnabled(true);
    ui->username_lineEdit->setEnabled(true);
    ui->password_lineEdit->setEnabled(true);
    ui->alias_lineEdit->setEnabled(true);
    ui->login_pushButton->setEnabled(true);
    ui->error_label->setText ("HTTP Error " + QString::number(errorNumber) + ": "  + errorText);
}

} /* namespace Mattermost */


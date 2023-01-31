/**
 * Copyright 2021, 2022 Lyubomir Filipov
 *
 * This file is part of Mattermost-QT.
 *
 * Mattermost-QT is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Mattermost-QT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Mattermost-QT. if not, see https://www.gnu.org/licenses/.
 */

#include <iostream>
#include "LoginDialog.h"
#include "ui_LoginDialog.h"

#include <QSettings>
#include "backend/Backend.h"
#include "log.h"

namespace Mattermost {

LoginDialog::LoginDialog (QWidget *parent, Backend& backend)
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

	QIcon icon (":/icons/img/icon0.ico");
	ui->icon->setPixmap (icon.pixmap (QSize (64, 64)));

	//if all data is available in the settings, use it for the login
	if (backend.autoLoginEnabled() && loginData.areAllFieldsFilled()) {
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
	loginData.token = "";

	loginData.saveToSettings (settings);
	loginToServer (loginData);
}


void LoginDialog::loginToServer (const BackendLoginData& loginData)
{
    ui->domain_lineEdit->setEnabled(false);
    ui->username_lineEdit->setEnabled(false);
    ui->password_lineEdit->setEnabled(false);
    ui->login_pushButton->setEnabled(false);
    ui->error_label->clear();

    LOG_DEBUG ("LoginDialog login");
    backend.login (loginData, [this, loginData = loginData] (const QString& token) mutable {

		//token already saved. If the callback is called, the login is ok
		if (!loginData.token.isEmpty()) {
			accept ();
			return;
		}

		if (token.isEmpty()) {
			setError ("Unable to login using the saved token. Please enter your login credentials.");
			return;
		}

		loginData.token = token;
		QSettings settings;
		loginData.saveToSettings (settings);
		accept();
	});
}

void LoginDialog::onNetworkError (uint32_t errorNumber, const QString& errorText)
{
	qCritical() << "Net error: " << errorNumber << ": " << errorText;
    setError ("Network Error: " + errorText);
}

void LoginDialog::onHttpError (uint32_t errorNumber, const QString& errorText)
{
	if (errorText.isEmpty() && !ui->error_label->text().isEmpty()) {
		return;
	} else {
		setError ("HTTP Error " + QString::number(errorNumber) + ": "  + errorText);
	}
}

void LoginDialog::setError (const QString& errorStr)
{
    ui->domain_lineEdit->setEnabled(true);
    ui->username_lineEdit->setEnabled(true);
    ui->password_lineEdit->setEnabled(true);
    ui->login_pushButton->setEnabled(true);

    ui->error_label->setText (errorStr);
}

} /* namespace Mattermost */


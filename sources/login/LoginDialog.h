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
	LoginDialog (QWidget *parent, Backend& backend);
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

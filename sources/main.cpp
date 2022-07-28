/**
 * Copyright 2021, 2022 Lyubomir Filipov
 *
 * This file is part of Mattermost-QT.
 *
 * Mattermost-QT is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Mattermost-QT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Mattermost-QT; if not, see https://www.gnu.org/licenses/.
 */

#include <memory>
#include <QApplication>
#include <QMenu>
#include <QSystemTrayIcon>

#include "login/LoginDialog.h"
#include "mainwindow.h"
#include "backend/Backend.h"
#include "config/Config.h"

namespace Mattermost {

class MattermostApplication: public QApplication {
public:
	MattermostApplication (int& argc, char *argv[]);

	void openLoginWindow ();
	void showWindow ();
	void toggleShowWindow ();
	void quitAction ();
	void reopen ();
private:
	std::unique_ptr<MainWindow>			mainWindow;
	std::unique_ptr<QSystemTrayIcon> 	trayIcon;
	std::unique_ptr<QMenu>				trayIconMenu;
	Backend								backend;
	LoginDialog* 						loginDialog;
	bool								autologin;
};

inline MattermostApplication::MattermostApplication (int& argc, char *argv[])
:QApplication (argc, argv)
,trayIcon (std::make_unique<QSystemTrayIcon> (QIcon(":/icons/img/icon0.ico"), nullptr))
,trayIconMenu (std::make_unique<QMenu> (nullptr))
,loginDialog (nullptr)
,autologin (true)
{
    Config::init ();
	trayIcon->setToolTip(tr("Mattermost Qt"));
	trayIcon->setContextMenu (trayIconMenu.get());
	trayIcon->show();
	connect (this, &QGuiApplication::lastWindowClosed, this, &MattermostApplication::reopen);

	connect (trayIcon.get(), &QSystemTrayIcon::messageClicked, this, &MattermostApplication::showWindow);

	connect (trayIcon.get(), &QSystemTrayIcon::activated, [this] (QSystemTrayIcon::ActivationReason reason) {
		if (reason == QSystemTrayIcon::Trigger) {
			toggleShowWindow ();
		}
	});

	trayIconMenu->addAction ("Open Mattermost", this, &MattermostApplication::showWindow);
	trayIconMenu->addAction ("Quit", this, &MattermostApplication::quitAction);
}

void MattermostApplication::openLoginWindow ()
{
	loginDialog = new LoginDialog (nullptr, backend, autologin);
	loginDialog->open();

	connect (loginDialog, &LoginDialog::accepted, [this] {
		//create Main Window and open it, after successful login
		loginDialog = nullptr;
		mainWindow = std::make_unique<MainWindow> (nullptr, *trayIcon, backend);
		mainWindow->show();

		autologin = false;
	});
}

inline void MattermostApplication::showWindow ()
{
	QWidget* currentWindow = mainWindow.get();

	if (!currentWindow) {
		currentWindow = loginDialog;
	}

	if (!currentWindow) {
		return;
	}

	if (!currentWindow->isVisible()) {
		currentWindow->show ();
	}
}

inline void MattermostApplication::toggleShowWindow ()
{
	QWidget* currentWindow = mainWindow.get();

	if (!currentWindow) {
		currentWindow = loginDialog;
	}

	if (!currentWindow) {
		return;
	}

	if (currentWindow->isVisible()) {
		currentWindow->hide ();
	} else {
		currentWindow->show ();
	}
}

inline void MattermostApplication::quitAction ()
{
	if (mainWindow) {
		mainWindow->onQuit();
	} else {
		qApp->quit();
	}
}

inline void MattermostApplication::reopen ()
{
	qDebug () << "lastWindowClosed";

	if (!mainWindow) {
		return;
	}

	mainWindow.reset(nullptr);
	openLoginWindow ();
}

} /* namespace Mattermost */

int main( int argc, char *argv[])
{
	QCoreApplication::setOrganizationName("mattermost-native");
	QCoreApplication::setApplicationName("Mattermost");

	Mattermost::MattermostApplication app (argc, argv);
	app.openLoginWindow ();
	return app.exec();
}


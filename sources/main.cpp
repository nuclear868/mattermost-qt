
#include <memory>
#include <QApplication>
#include <QMenu>
#include <QSystemTrayIcon>

#include "login/LoginDialog.h"
#include "mainwindow.h"
#include "backend/Backend.h"

namespace Mattermost {

class Client: public QApplication {
public:
	Client (int& argc, char *argv[]);

	/*
	 * Opens login dialog and mainwindow, after a successful login
	 */
	void performLogin ();
	void openMainWindow ();
	void reopen ();
private:
	std::unique_ptr<MainWindow>			mainWindow;
	std::unique_ptr<QSystemTrayIcon> 	trayIcon;
	std::unique_ptr<QMenu>				trayIconMenu;
	Backend								backend;
	bool								autologin;
};

inline Client::Client (int& argc, char *argv[])
:QApplication (argc, argv)
,trayIcon (std::make_unique<QSystemTrayIcon> (QIcon(":/icons/img/icon0.ico"), nullptr))
,trayIconMenu (std::make_unique<QMenu> (nullptr))
,autologin (true)
{

	trayIcon->setToolTip(tr("Mattermost Qt"));
	trayIcon->setContextMenu (trayIconMenu.get());
	trayIcon->show();
	connect (this, &QGuiApplication::lastWindowClosed, this, &Client::reopen);
}

inline void Client::performLogin ()
{
	LoginDialog login (nullptr, backend, autologin);
	if (login.exec() != QDialog::Accepted) {
		::exit (0);
		return;
	}
}

inline void Client::openMainWindow ()
{
	mainWindow = std::make_unique<MainWindow> (nullptr, *trayIcon, backend);
	mainWindow->show();

	trayIconMenu->addAction ("Open Mattermost", mainWindow.get(), &MainWindow::show);
	trayIconMenu->addAction ("Quit", mainWindow.get(), &MainWindow::onQuit);
	autologin = false;
}

inline void Client::reopen ()
{
	qDebug () << "lastWindowClosed";

	if (!mainWindow) {
		return;
	}

	mainWindow.reset(nullptr);
	trayIconMenu->clear();

	performLogin ();
	openMainWindow ();
}

} /* namespace Mattermost */

int main( int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("mattermost-native");
    QCoreApplication::setApplicationName("Mattermost");

    Mattermost::Client client (argc, argv);
    client.performLogin ();
    client.openMainWindow ();
    return client.exec();
}


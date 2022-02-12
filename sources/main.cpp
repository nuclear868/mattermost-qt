
#include <memory>
#include <QApplication>
#include <QMenu>
#include <QSystemTrayIcon>

#include "login/LoginDialog.h"
#include "mainwindow.h"
#include "backend/Backend.h"
#include "config/Config.h"

namespace Mattermost {

class Client: public QApplication {
public:
	Client (int& argc, char *argv[]);

	void openLoginWindow ();
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
    Config::init ();
	trayIcon->setToolTip(tr("Mattermost Qt"));
	trayIcon->setContextMenu (trayIconMenu.get());
	trayIcon->show();
	connect (this, &QGuiApplication::lastWindowClosed, this, &Client::reopen);
}

void Client::openLoginWindow ()
{
	LoginDialog* login = new LoginDialog (nullptr, backend, autologin);
	login->open();

	connect (login, &LoginDialog::accepted, [this] {
		//create Main Window and open it, after successful login
		mainWindow = std::make_unique<MainWindow> (nullptr, *trayIcon, backend);
		mainWindow->show();

		trayIconMenu->addAction ("Open Mattermost", mainWindow.get(), &MainWindow::show);
		trayIconMenu->addAction ("Quit", mainWindow.get(), &MainWindow::onQuit);
		autologin = false;
	});
}

inline void Client::reopen ()
{
	qDebug () << "lastWindowClosed";

	if (!mainWindow) {
		return;
	}

	mainWindow.reset(nullptr);
	trayIconMenu->clear();

	openLoginWindow ();
}

} /* namespace Mattermost */

int main( int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("mattermost-native");
    QCoreApplication::setApplicationName("Mattermost");

    Mattermost::Client client (argc, argv);
    client.openLoginWindow ();
    return client.exec();
}



#include <memory>
#include <QApplication>

#include "login/LoginDialog.h"
#include "mainwindow.h"
#include "backend/Backend.h"

namespace Mattermost {

class Client: public QApplication {
public:
	Client (int& argc, char *argv[]);
private:
	std::unique_ptr<MainWindow>		mainWindow;
	Backend							backend;
};

inline Client::Client (int& argc, char *argv[])
:QApplication (argc, argv)
{
	LoginDialog login (nullptr, backend);
	if (login.exec() != QDialog::Accepted) {
		::exit (0);
		return;
	}

	mainWindow = std::make_unique<MainWindow> (nullptr, backend);
	mainWindow->show();
}

} /* namespace Mattermost */

int main( int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("mattermost-native");
    QCoreApplication::setApplicationName("Mattermost");

    Mattermost::Client mattermostClient (argc, argv);
    return mattermostClient.exec();
}


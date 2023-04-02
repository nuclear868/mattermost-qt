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

#include "mainwindow.h"

#include <QWindow>
#include <QCloseEvent>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include "./ui_mainwindow.h"
#include "chat-area/ChatArea.h"
#include "backend/Backend.h"
#include "SettingsWindow.h"
#include "build-config.h"
#include "log.h"

namespace Mattermost {

MainWindow::MainWindow (QWidget *parent, QSystemTrayIcon& trayIcon, Backend& _backend)
:QMainWindow(parent)
,ui (std::make_unique<Ui::MainWindow>())
,trayIcon (trayIcon)
,chooseEmojiDialog (this)
,backend (_backend)
,currentTeamRestoredFromSettings (false)
,doDeinit (false)
{
	LOG_DEBUG ("MainWindow create start");

	ui->setupUi(this);
	ui->channelList->setChatAreaStackedWidget (ui->chatAreaStackedWidget);
	ui->channelList->setFocus();

	createMenu ();

	const BackendUser& currentUser = backend.getLoginUser();

	if (currentUser.id.isEmpty()) {
		ui->usericon_label->clear();
		qCritical() << "Current User's ID is empty string";
		return;
	}

	connect (&currentUser, &BackendUser::onStatusChanged, [this, &currentUser] {
		ui->statusLabel->setText (currentUser.status);
	});

	ui->usernameLabel->setText (currentUser.username);

	connect (&currentUser, &BackendUser::onAvatarChanged, [this, &currentUser] {
		LOG_DEBUG ("Got User Image");
		QImage img = QImage::fromData (currentUser.avatar).scaled(42, 42, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
		ui->usericon_label->setPixmap (QPixmap::fromImage(img));
	});

	/*
	 * Gets the LoginUser's image for the user icon
	 */
	backend.retrieveUserAvatar (currentUser.id);

	backend.retrieveTotalUsersCount ([this] (uint32_t) {
		backend.retrieveAllUsers ();
	});

	/*
	 * Register for signals
	 */
	//connect (ui->channelList, &QTreeWidget::currentItemChanged, this, &MainWindow::channelListWidget_itemClicked);

	//getAllUsers is called from onShowEvent()
	connect (&backend, &Backend::onAllUsers, [this]() {
		/*
		 * Adds each team in which the LoginUser participates.
		 * The callback is called once for each team
		 */
		backend.retrieveOwnTeams ([this](BackendTeam& team) {
			ui->channelList->addTeam (backend, team);
		});
	});

	/*
	 * After all team channels are received from the server, create tree items for the direct channels.
	 * For some reason the server duplicates the direct channels in each team.
	 * Here they are in a single list (The official Mattermost client shows them in each team, which IMHO looks like a total mess).
	 * So, all team channels have to be received in order to know all (unique) direct channels
	 *
	 * The list of users needs to be obtained too, because direct channels' names consist of user IDs,
	 * which need to be displayer ad user names
	 */
	connect (&backend, &Backend::onAllTeamChannelsPopulated, [this] {
		ui->channelList->addGroupChannelsList (backend);
		ui->channelList->addDirectChannelsList (backend);

//		QSettings settings;
//		QString currentTeam (settings.value ("current_team", 0).toString());

		//Activate the same team that was active during the last session
//				if (teamChannelTree->team.id == currentTeam) {
//					LOG_DEBUG ("MainWindow activate team " << currentTeam);
//					//ui->teamComboBox->setCurrentIndex (teamSeq);
//					//channelList.activateTeam (teamSeq);
//					currentTeamRestoredFromSettings = true;
//				}

		initializationComplete ();
	});

	connect (&backend, &Backend::onNewPost, [this] (BackendChannel& channel, const BackendPost& post) {
		this->messageNotify (channel, post);
	});

	connect (&backend, &Backend::onChannelViewed, [this] (const BackendChannel& channel) {
		if (channelsWithNewPosts.remove (&channel)) {
			setNotificationsCountVisualization (channelsWithNewPosts.size());
		}
	});

	/*
	 * onAddedToTeam comes after a WebSocket event, when the user is added to (new) team
	 */
	connect (&backend, &Backend::onAddedToTeam, [this](BackendTeam& team) {
		ui->channelList->addTeam (backend, team);
	});

	/*
	 * On new post - set window and tray notifications
	 */
	connect (&backend, &Backend::onUnreadPostsAtStartup, this, &MainWindow::unreadMessagesNotify);

	LOG_DEBUG ("MainWindow signal register finish");

	//Restore saved window position and dimensions
	QSettings settings;
	restoreGeometry (settings.value( "geometry", saveGeometry()).toByteArray());

	connect (qApp, &QApplication::aboutToQuit, this, &MainWindow::saveState);
	LOG_DEBUG ("MainWindow create finish");
}

MainWindow::~MainWindow()
{
}

static QString infoText (QString ("Version " PROJECT_VER "<br/>"
"An unofficial Mattermost Client, using the QT framework<br/>") +
R"(
<br/>
More information:<br/> 
<a href='https://github.com/nuclear868/mattermost-qt'>https://github.com/nuclear868/mattermost-qt</a>
<br/>
<br/>
Mattermost QT Copyright 2021, 2022 Lyubomir Filipov<br/>
<br/>
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.<br/>
<br/>
You should have received a copy of the GNU Lesser General Public License
along with Mattermost-QT. if not, see <a href='https://www.gnu.org/licenses/'>https://www.gnu.org/licenses/</a>.<br/>
)");

void MainWindow::createMenu ()
{
	mainMenu = new QMenu (ui->toolButton);

	QMenu* fileMenu = mainMenu->addMenu ("File");
	fileMenu->addAction ("Logout", [this] {

		backend.logout ([this] {
			doDeinit = true;
			QMainWindow::close ();
			LOG_DEBUG ("Logout done");
		});
	});

	mainMenu->addAction ("Settings", [this] {
		settingsWindow = new SettingsWindow (this);

		connect (settingsWindow, &QDialog::accepted, [this] {

			if (QMessageBox::question (this, "Reload?", "In order to apply some settings, Mattermost has to be reloaded.\n"
					" Do you want to reload now? (If no, settings will be applied on the next startup)") == QMessageBox::Yes) {

				settingsWindow->applyNewSettings ();
			}
			reload ();
		});

		settingsWindow->show();
	});


	QMenu* helpMenu = mainMenu->addMenu ("Help");
	helpMenu->addAction ("About Mattermost", [this] {
		QMessageBox *msgBox = new QMessageBox (QMessageBox::Information,
				"About Mattermost", infoText);

		msgBox->setIconPixmap (windowIcon().pixmap (QSize (64, 64)));
		msgBox->setTextFormat(Qt::RichText);
		msgBox->setStandardButtons(QMessageBox::Ok);
		msgBox->setDefaultButton(QMessageBox::Ok);
		msgBox->open();
	});

	helpMenu->addAction ("About QT", [this] {
		QMessageBox::aboutQt (this, "About QT");
	});

	ui->toolButton->setMenu(mainMenu);
}

void MainWindow::moveEvent (QMoveEvent*)
{

	ChatArea* currentPage = ui->channelList->getCurrentPage();

	if (currentPage) {
		currentPage->onMove (pos());
	}
}

void MainWindow::dragMoveEvent (QDragMoveEvent*)
{
	qDebug() << "dragMove " << mapToGlobal(pos());
}

void MainWindow::reload ()
{
	QTimer::singleShot(0, [this] {
		backend.reset();
		doDeinit = true;
		QMainWindow::close ();
	});
}

void MainWindow::changeEvent (QEvent* event)
{
	QWidget::changeEvent(event);

	if (event->type() == QEvent::ActivationChange) {
		if (isActiveWindow()) {
			//qDebug() << "Activated";

			ChatArea* currentPage = ui->channelList->getCurrentPage();

			if (currentPage) {
				currentPage->onMainWindowActivate ();

				if (channelsWithNewPosts.remove (&currentPage->getChannel())) {
					setNotificationsCountVisualization (channelsWithNewPosts.size());
				}
			}

		} else {
			//qDebug() << "Deactivated";
		}
	} else {
		qDebug() << event->type();
	}
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	qDebug() << "closeEvent";

	if (doDeinit) {
		qDebug() << "QMainWindow closeEvent";
		saveState ();
		return QMainWindow::closeEvent (event);
	}

	if (trayIcon.isVisible()) {
		hide();
		event->ignore();
	}
}

void MainWindow::initializationComplete ()
{
	LOG_DEBUG ("MainWindow initialization comlete");

	/*
	 * No team was restored from settings. Either there was no team saved, or the saved team
	 * was deleted. In all cases, activate the first team
	 */
	if (!currentTeamRestoredFromSettings) {
	//	ui->teamComboBox->setCurrentIndex (0);
		//channelList.activateTeam (0);
	}
}

void MainWindow::messageNotify (const BackendChannel& channel, const BackendPost& post)
{
	//do not receive notifications for your own messages ;)
	if (post.author && post.author->id == backend.getLoginUser().id) {
		return;
	}

	/**
	 * If the Mattermost window is active (has focus) and the current channel is active,
	 * do not add notifications. We assume that the user is watching the chat window
	 */
	if (isActiveWindow() && ui->channelList->isChannelActive (channel)) {
		return;
	}

	//Add a desktop notification
	QString title;

	if (channel.type == BackendChannel::directChannel) {
		title = post.getDisplayAuthorName () + " messaged you";
	} else {
		title = post.getDisplayAuthorName () + " posted in '" + channel.display_name + "'";
	}

	trayIcon.showMessage (title, post.message, QSystemTrayIcon::Information);
	qApp->alert (nullptr, 0);

	//update the count of new channels in the taskbar and tray icon
	channelsWithNewPosts.insert(&channel);
	setNotificationsCountVisualization (channelsWithNewPosts.size());
}

void MainWindow::unreadMessagesNotify (const BackendChannel& channel)
{
	//update the count of new channels in the taskbar and tray icon
	channelsWithNewPosts.insert(&channel);
	setNotificationsCountVisualization (channelsWithNewPosts.size());
}

void MainWindow::setNotificationsCountVisualization (uint32_t notificationsCount)
{
	//set the count in the window's taskbar element
	if (notificationsCount == 0) {
		setWindowTitle (qApp->applicationName());
	} else {
		setWindowTitle ("(" + QString::number (channelsWithNewPosts.size()) + ") " + qApp->applicationName());
	}

	//set the count in the tray icon
	notificationsCount = std::min (notificationsCount, 6u);
	QString iconName (":/icons/img/icon" + QString::number(notificationsCount) + ".ico");
	trayIcon.setIcon(QIcon(iconName));
}

void MainWindow::saveState ()
{
	LOG_DEBUG ("MainWindow saveState");
	QSettings settings;
	settings.setValue ("geometry", saveGeometry());
//	settings.setValue ("current_team", channelList.getCurrentTeamId());
//	if (currentPage) {
//		settings.setValue ("current_channel", currentPage->getChannel().id);
//	}
}

} /* namespace Mattermost */





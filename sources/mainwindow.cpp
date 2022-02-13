
#include "mainwindow.h"

#include <QWindow>
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include "./ui_mainwindow.h"
#include "chat-area/ChatArea.h"
#include "ChannelListForTeam.h"
#include "backend/Backend.h"
#include "log.h"

namespace Mattermost {

MainWindow::MainWindow (QWidget *parent, QSystemTrayIcon& trayIcon, Backend& _backend)
:QMainWindow(parent)
,ui (std::make_unique<Ui::MainWindow>())
,trayIcon (trayIcon)
,backend (_backend)
,currentPage (nullptr)
,currentTeamRestoredFromSettings (false)
,doDeinit (false)
{
	LOG_DEBUG ("MainWindow create start");

	ui->setupUi(this);
	ui->channelList->setFocus();

	createMenu ();

	const BackendUser& currentUser = backend.getLoginUser();

	if (currentUser.id.isEmpty()) {
		ui->usericon_label->clear();
		qCritical() << "Current User's ID is empty string";
		return;
	}

	ui->username_label->setText (currentUser.username);

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

		/*
		 * Adds each team in which the LoginUser participates.
		 * The callback is called once for each team
		 */
		backend.retrieveOwnTeams ([this](BackendTeam& team) {

			//Add team here, so that they are added in the proper order
			ChannelListForTeam* teamChannelList = ui->channelList->addTeam (backend, team.display_name, team.id);

			/*
			 * Gets all channels of the team, where the user is member
			 */
			backend.retrieveOwnChannelMemberships (team, [this, teamChannelList] (BackendChannel& channel) {
				teamChannelList->addChannel (channel, ui->centralwidget);
			}); //on getOwnChannelMemberships()
		}); //on getOwnTeams()
	}); //on getTotalUsersCount()

	/*
	 * Register for signals
	 */
	connect (ui->channelList, &QTreeWidget::currentItemChanged, this, &MainWindow::channelListWidget_itemClicked);

	//getAllUsers is called from onShowEvent()
	connect (&backend, &Backend::onAllUsers, [this]() {
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
	connect (&backend, &Backend::onAllTeamChannelsPopulated, [this]() {
		LOG_DEBUG ("All Team Channels filled " << (void*) this);
		ChannelListForTeam* teamChannelList = ui->channelList->addTeam (backend, "Direct Messages", "");

		for (auto &channel: backend.getDirectChannels()) {
			teamChannelList->addChannel (*channel, ui->centralwidget);
		}

//		QSettings settings;
//		QString currentTeam (settings.value ("current_team", 0).toString());

		//Activate the same team that was active during the last session
//				if (teamChannelList->team.id == currentTeam) {
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

	/*
	 * onAddedToTeam comes after a WebSocket event, when the user is added to the team
	 */
	connect (&backend, &Backend::onAddedToTeam, [this](BackendTeam& team) {

		/**
		 * Adds each team in which the LoginUser participates
		 */
		ChannelListForTeam* teamChannelList = ui->channelList->addTeam (backend, team.display_name, team.id);

		/*
		 * Gets all channels of the team, where the user is member
		 */
		backend.retrieveOwnChannelMemberships (team, [this, teamChannelList] (BackendChannel& channel){
			teamChannelList->addChannel (channel, ui->centralwidget);
		});
	});

	connect (&backend, &Backend::onLeaveTeam, [this](BackendTeam& team) {

		ui->channelList->removeTeam (team);
	});

	/*
	 * On new post - set window and tray notifications
	 */
	connect (&backend, &Backend::onUnreadPostsAtStartup, this, &MainWindow::unreadMessagesNotify);

	LOG_DEBUG ("MainWindow signal register finish");

	//Restore saved window position and dimensions
	QSettings settings;
	restoreGeometry (settings.value( "geometry", saveGeometry()).toByteArray());

	LOG_DEBUG ("MainWindow create finish");
}

MainWindow::~MainWindow() = default;

void MainWindow::createMenu ()
{
	QMenu* mainMenu = new QMenu (ui->toolButton);

	QMenu* fileMenu = mainMenu->addMenu ("File");
	fileMenu->addAction ("Logout", [this] {
		backend.logout ([] {
			LOG_DEBUG ("Logout done");
		});

		QTimer::singleShot (100, [this] {
			backend.reset();
			doDeinit = true;
			QMainWindow::close ();
		});
	});

	QMenu* helpMenu = mainMenu->addMenu ("Help");
	helpMenu->addAction ("About");
	ui->toolButton->setMenu(mainMenu);
}


void MainWindow::changeEvent (QEvent* event)
{
	QWidget::changeEvent(event);

	if (event->type() == QEvent::ActivationChange) {
		if (isActiveWindow()) {
			qDebug() << "Activated";

			if (currentPage) {
				currentPage->onMainWindowActivate ();

				if (channelsWithNewPosts.remove (&currentPage->getChannel())) {
					setNotificationsCountVisualization (channelsWithNewPosts.size());
				}
			}

		} else {
			qDebug() << "Deactivated";
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

void MainWindow::channelListWidget_itemClicked (QTreeWidgetItem* item, QTreeWidgetItem*)
{
	ChatArea *chatArea = item->data(0, Qt::UserRole).value<ChatArea*>();

	if (!chatArea) {
		qCritical() << "chatArea is null";
		return;
	}

	if (currentPage == chatArea) {
		return;
	}

	if (currentPage) {
		ui->chatAreaStackedWidget->removeWidget (currentPage);
	}

	ui->chatAreaStackedWidget->addWidget(chatArea);
	currentPage = chatArea;
	currentPage->onActivate ();

	if (channelsWithNewPosts.remove (&currentPage->getChannel())) {
		setNotificationsCountVisualization (channelsWithNewPosts.size());
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
	if (isActiveWindow() && currentPage && &channel == &currentPage->getChannel()) {
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

void MainWindow::onQuit ()
{
	QSettings settings;
	settings.setValue ("geometry", saveGeometry());
//	settings.setValue ("current_team", channelList.getCurrentTeamId());
//	if (currentPage) {
//		settings.setValue ("current_channel", currentPage->getChannel().id);
//	}
	qApp->quit();
}


} /* namespace Mattermost */


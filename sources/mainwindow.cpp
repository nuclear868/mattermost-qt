
#include "mainwindow.h"

#include <QCloseEvent>
#include "./ui_mainwindow.h"
#include "chat-area/ChatArea.h"
#include "ChannelListForTeam.h"
#include "backend/Backend.h"
#include "log.h"

namespace Mattermost {

MainWindow::MainWindow (QWidget *parent, Backend& _backend)
:QMainWindow(parent)
,ui(std::make_unique<Ui::MainWindow>())
,trayIconMenu (std::make_unique<QMenu> (this))
,backend (_backend)
,currentPage (nullptr)
,teamsToLoad (0)
,currentTeamRestoredFromSettings (false)
{
	LOG_DEBUG ("MainWindow create start");

	ui->setupUi(this);

	trayIconMenu->addAction("Quit", this, &MainWindow::onQuit);

	trayIcon = std::make_unique<QSystemTrayIcon> (QIcon(":/icons/img/icon0.ico"),this);
	trayIcon->setToolTip(tr("Mattermost Qt"));
	trayIcon->setContextMenu (trayIconMenu.get());
	trayIcon->show();

	BackendUser currentUser = backend.getLoginUser();

	if (currentUser.id.isEmpty()) {
		ui->usericon_label->clear();
		qCritical() << "Current User's ID is empty string";
		return;
	}

	ui->username_label->setText (currentUser.username);

	/*
	 * Gets the LoginUser's information and gets it's image for the user icon
	 */
	backend.getUser ("me", [this] (BackendUser& user) {
		backend.getUserImage (user.id, [this](QByteArray& data) {
			LOG_DEBUG ("Got User Image");
			QImage img = QImage::fromData (data).scaled(42, 42, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
			ui->usericon_label->setPixmap (QPixmap::fromImage(img));
		});
	});

	backend.getTotalUsersCount ([this] (uint32_t) {
		backend.getAllUsers ();

		backend.getOwnTeams ([this](QMap<QString, BackendTeam>& teams) {

			teamsToLoad = teams.size();
			uint32_t teamSeq = 0;

			/*
			 * Adds each team in which the LoginUser participates
			 */
			for (auto& team: teams) {

				//Add team here, so that they are added in the proper order
				ChannelListForTeam* teamChannelList = ui->channelList->addTeam (backend, team.display_name);
				//backend.getTeamMembers (team);

				/*
				 * Gets all channels of the team, where the user is member
				 */
				backend.getOwnChannelMemberships (team, [this, teamChannelList, teamSeq] (QList<BackendChannel*>& channels){

					for (auto &channel: channels) {
						teamChannelList->addChannel (*channel, ui->centralwidget);
						connect (channel, &BackendChannel::onNewPost, [this, channel] (BackendPost& post) {
							this->messageNotify (*channel, post);
						});
					}


					QSettings settings;
					QString currentTeam (settings.value ("current_team", 0).toString());

					//Activate the same team that was active during the last session
	//				if (teamChannelList->team.id == currentTeam) {
	//					LOG_DEBUG ("MainWindow activate team " << currentTeam);
	//					//ui->teamComboBox->setCurrentIndex (teamSeq);
	//					//channelList.activateTeam (teamSeq);
	//					currentTeamRestoredFromSettings = true;
	//				}

					--teamsToLoad;

					if (teamsToLoad == 0) {

						ChannelListForTeam* teamChannelList = ui->channelList->addTeam (backend, "Direct Messages");

						for (auto &channel: backend.getDirectChannels()) {
							teamChannelList->addChannel (*channel, ui->centralwidget);
							connect (channel, &BackendChannel::onNewPost, [this, channel] (BackendPost& post) {
								this->messageNotify (*channel, post);
							});
						}

						initializationComplete ();
					}
				}); //on getOwnChannelMemberships()

				++teamSeq;
			}
		}); //on getOwnTeams()
	}); //on getTotalUsersCount()


	/*
	 * Register for signals
	 */

	connect (ui->channelList, &QTreeWidget::itemClicked, this, &MainWindow::channelListWidget_itemClicked);

	//getAllUsers is called from onShowEvent()
	connect (&backend, &Backend::onAllUsers, [this]() {
	});


	/*
	 * OnNewTeam comes after a WebSocket event, when the user is added to the team
	 */
	connect (&backend, &Backend::onNewTeam, [this](BackendTeam& team) {

		/**
		 * Adds each team in which the LoginUser participates
		 */
		ChannelListForTeam* teamChannelList = ui->channelList->addTeam (backend, team.display_name);
		//backend.getTeamMembers (team);

		/*
		 * Gets all channels of the team, where the user is member
		 */
		backend.getOwnChannelMemberships (team, [this, teamChannelList] (QList<BackendChannel*>& channels){

			for (auto &channel: channels) {
				teamChannelList->addChannel (*channel, ui->centralwidget);
			}
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

void MainWindow::changeEvent (QEvent* event)
{
	QWidget::changeEvent(event);

	if (event->type() == QEvent::ActivationChange) {
		if (isActiveWindow()) {
			qDebug() << "Activated";

			if (currentPage) {
				currentPage->onWindowActivate();

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
	if (trayIcon->isVisible()) {
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

void MainWindow::channelListWidget_itemClicked (QTreeWidgetItem* item, int)
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
	if (isActiveWindow() && &channel == &currentPage->getChannel()) {
		return;
	}

	//Add a desktop notification
	QString title;

	if (channel.type == BackendChannel::directChannel) {
		title = post.getDisplayAuthorName () + " messaged you";
	} else {
		title = post.getDisplayAuthorName () + " posted in '" + channel.display_name + "'";
	}

	trayIcon->showMessage (title, post.message, QSystemTrayIcon::Information);
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
	trayIcon->setIcon(QIcon(iconName));
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


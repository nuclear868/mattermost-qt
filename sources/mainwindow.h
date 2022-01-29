#pragma once

#include <memory>
#include <QSystemTrayIcon>
#include <QMainWindow>
#include <QSet>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QTreeWidgetItem;

namespace Mattermost {

class ChatArea;
class Backend;
class BackendChannel;
class BackendPost;
class BackendTeam;

class MainWindow: public QMainWindow {
	Q_OBJECT
public:
	MainWindow (QWidget *parent, Backend& backend);
	~MainWindow();
protected:
	void initializationComplete ();

	void changeEvent (QEvent* event) override;

	/**
	 * Called when the window's close buttons is clicked
	 * @param event event
	 */
	void closeEvent(QCloseEvent *event) override;

	/**
	 * Called when the quit action is chosen from the tray icon's menu
	 */
	void onQuit ();

	/**
	 * Called when a new post is received while the Mattermost client is on
	 * @param channel channel
	 * @param post post
	 */
	void messageNotify (const BackendChannel& channel, const BackendPost& post);

	/**
	 * Called on Mattermost client startup, when there were new posts, while the client was not open
	 * @param channel channel
	 */
	void unreadMessagesNotify (const BackendChannel& channel);
	void setNotificationsCountVisualization (uint32_t notificationsCount);
private slots:
	void channelListWidget_itemClicked(QTreeWidgetItem* item, QTreeWidgetItem*);
private:
	std::unique_ptr<Ui::MainWindow>		ui;
	std::unique_ptr<QSystemTrayIcon> 	trayIcon;
	std::unique_ptr<QMenu>				trayIconMenu;
	QSet<const BackendChannel*>			channelsWithNewPosts;
	Backend&							backend;
	ChatArea*							currentPage;
	bool								currentTeamRestoredFromSettings;
};

} /* namespace Mattermost */


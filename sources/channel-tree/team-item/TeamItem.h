/**
 * @file TeamItem.h
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 27, 2021
 */

#pragma once

#include <list>
#include <memory>
#include "channel-tree/ChannelTreeItem.h"
#include <QObject>

class QListWidget;
class QTreeWidgetItem;
class QTreeWidget;
class ChannelItemWidget;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace Mattermost {

class Backend;
class BackendTeam;
class BackendChannel;
class ChatArea;
class ChannelItem;

class TeamItem: public QObject, public ChannelTreeItem {
	Q_OBJECT
public:
	TeamItem (QTreeWidget& parent, Backend& backend, const QString& name, const QString& teamId);
	virtual ~TeamItem ();
public:
	void addChannel (BackendChannel& channel, QWidget *parent);
	virtual ChannelItem* createChannelItem (Backend& backend, ChannelItemWidget* itemWidget) = 0;
private:
	int getChannelIndex (const BackendChannel& channel);
public:
	Backend&							backend;
	QString								teamId;
	std::list<std::unique_ptr<ChatArea>>	chatAreas;
};

} /* namespace Mattermost */


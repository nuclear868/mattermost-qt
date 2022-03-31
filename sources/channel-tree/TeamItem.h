/**
 * @file TeamItem.h
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 27, 2021
 */

#pragma once

#include <list>
#include <memory>
#include "ChannelTreeItem.h"
#include <QObject>

class QListWidget;
class QTreeWidgetItem;
class QTreeWidget;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace Mattermost {

class Backend;
class BackendTeam;
class BackendChannel;
class ChatArea;

class TeamItem: public QObject, public ChannelTreeItem {
	Q_OBJECT
public:
	TeamItem (QTreeWidget& parent, Backend& backend, const QString& name, const QString& teamId);
	virtual ~TeamItem ();
public:
	void addChannel (BackendChannel& channel, QWidget *parent);
	void showContextMenu (const QPoint& pos) override;
public:
	Backend&							backend;
	QString								teamId;
	std::list<std::unique_ptr<ChatArea>>	chatAreas;
};

} /* namespace Mattermost */


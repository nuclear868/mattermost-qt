/**
 * @file ChannelListForTeam.h
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 27, 2021
 */

#pragma once

#include <QTreeWidgetItem>
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

class ChannelListForTeam: public QObject, public QTreeWidgetItem {
	Q_OBJECT
public:
	ChannelListForTeam (QTreeWidget& parent, Backend& backend, const QString& name, const QString& teamId);
	virtual ~ChannelListForTeam ();
public:
	void addChannel (BackendChannel& channel, QWidget *parent);
public:
	Backend&					backend;
	QString						teamId;
};

} /* namespace Mattermost */


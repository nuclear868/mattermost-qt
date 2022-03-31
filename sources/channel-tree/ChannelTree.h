/**
 * @file ChannelTree.h
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 18, 2021
 */

#pragma once

#include <QVector>
#include <QTreeWidget>


class QListWidget;
class QTreeWidgetItem;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace Mattermost {

class Backend;
class BackendTeam;
class TeamItem;

class ChannelTree: public QTreeWidget {
	Q_OBJECT
public:
	ChannelTree (QWidget* parent = nullptr);
	virtual ~ChannelTree ();
public:
	TeamItem* addTeam (Backend& backend, BackendTeam& team);
	void removeTeam (BackendTeam& team);
private:
	void showContextMenu (const QPoint& pos);
};

} /* namespace Mattermost */


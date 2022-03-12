/**
 * @file OutgoingAttachmentList.h
 * @brief
 * @author Lyubomir Filipov
 * @date Feb 20, 2022
 */

#pragma once

#include <qtreewidget.h>

namespace Mattermost {

class OutgoingAttachmentList: public QTreeWidget {
	Q_OBJECT
public:
	OutgoingAttachmentList (QWidget* parent);
public:
	void addFile (const QString& filename);

	QSize sizeHint () const override;

	QList<QString> getAllFiles ();
signals:
	void deleted ();
};

} /* namespace Mattermost */

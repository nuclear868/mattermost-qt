/**
 * Copyright 2021, 2022 Lyubomir Filipov
 *
 * This file is part of Mattermost-QT.
 *
 * Mattermost-QT is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Mattermost-QT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Mattermost-QT; if not, see https://www.gnu.org/licenses/.
 */

#ifndef FILEPREVIEW_H
#define FILEPREVIEW_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class FilePreview;
}

namespace Mattermost  {

struct FilePreviewData {
	const QByteArray 	fileContents;
	QString				fileName;
	QString				fileAuthor;
};

class FilePreview: public QDialog {
    Q_OBJECT
public:
    explicit FilePreview (const FilePreviewData& file, QWidget *parent = nullptr);
    ~FilePreview();
public:
    QSize getMinimumSize (const QPixmap& pixmap);

    void resizeEvent(QResizeEvent* event) override;

private:
    Ui::FilePreview*	ui;
    QPixmap				pixmap;
    QTimer				resizeTimer;
    QSize				newWindowSize;
};

} /* namespace Mattermost */

#endif // FILEPREVIEW_H

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

#ifndef MESSAGEATTACHMENTLIST_H
#define MESSAGEATTACHMENTLIST_H

#include <QWidget>
#include <map>

namespace Ui {
class PostAttachmentList;
}

class QListWidgetItem;

namespace Mattermost {

struct FilePreviewData;
class Backend;
class BackendFile;
class FilePreview;

class PostAttachmentList: public QWidget
{
    Q_OBJECT
public:
    explicit PostAttachmentList (Backend& backend, QWidget *parent = nullptr);
    ~PostAttachmentList();
public:
    void addFile (const BackendFile& file, const QString& authorName);
private:
    std::list<FilePreviewData>								filesPreviewData;
    static std::map <const FilePreviewData*, FilePreview*>	currentlyOpenFiles;
    Backend& 												backend;
    Ui::PostAttachmentList*								ui;
};

} /* namespace Mattermost */

#endif // MESSAGEATTACHMENTLIST_H



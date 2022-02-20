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

#endif // MESSAGEATTACHMENTLIST_H

} /* namespace Mattermost */


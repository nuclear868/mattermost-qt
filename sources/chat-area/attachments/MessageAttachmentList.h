#ifndef MESSAGEATTACHMENTLIST_H
#define MESSAGEATTACHMENTLIST_H

#include <QWidget>
#include <map>

namespace Ui {
class MessageAttachmentList;
}

class QListWidgetItem;

namespace Mattermost {

struct FilePreviewData;
class BackendFile;
class BackendUser;
class FilePreview;

class MessageAttachmentList: public QWidget
{
    Q_OBJECT
public:
    explicit MessageAttachmentList(QWidget *parent = nullptr);
    ~MessageAttachmentList();
public:
    void addFile (const BackendFile& file, const BackendUser& author);
private:
    std::list<FilePreviewData>								filesPreviewData;
    static std::map <const FilePreviewData*, FilePreview*>	currentlyOpenFiles;
    Ui::MessageAttachmentList*						ui;
};

#endif // MESSAGEATTACHMENTLIST_H

} /* namespace Mattermost */


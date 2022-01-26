#ifndef FILEPREVIEW_H
#define FILEPREVIEW_H

#include <QDialog>

namespace Ui {
class FilePreview;
}

namespace Mattermost  {

struct FilePreviewData {
	const QByteArray& 	fileContents;
	QString				fileName;
	QString				fileAuthor;
};

class FilePreview : public QDialog
{
    Q_OBJECT

public:
    explicit FilePreview (const FilePreviewData& file, QWidget *parent = nullptr);
    ~FilePreview();

private:
    Ui::FilePreview*	ui;
    QPixmap				pixmap;
};

} /* namespace Mattermost */

#endif // FILEPREVIEW_H

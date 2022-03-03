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

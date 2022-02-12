#ifndef ATTACHEDBINARYFILE_H
#define ATTACHEDBINARYFILE_H

#include <QWidget>
#include <QTemporaryFile>

namespace Ui {
class AttachedBinaryFile;
}

namespace Mattermost {

class Backend;
class BackendFile;

class AttachedBinaryFile: public QWidget {
    Q_OBJECT

public:
    explicit AttachedBinaryFile (Backend& backend, const BackendFile& file, QWidget *parent = nullptr);
    ~AttachedBinaryFile();
private:
    void setFileMimeIcon (const QString& filename);
private:
    Ui::AttachedBinaryFile 	*ui;
    QTemporaryFile			tempFile;
    QString					downloadedPath;
};

} /* namespace Mattermost */

#endif // ATTACHEDBINARYFILE_H

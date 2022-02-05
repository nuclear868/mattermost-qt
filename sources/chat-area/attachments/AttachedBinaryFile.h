#ifndef ATTACHEDBINARYFILE_H
#define ATTACHEDBINARYFILE_H

#include <QWidget>

namespace Ui {
class AttachedBinaryFile;
}

namespace Mattermost {

class BackendFile;

class AttachedBinaryFile: public QWidget {
    Q_OBJECT

public:
    explicit AttachedBinaryFile (const BackendFile& file, QWidget *parent = nullptr);
    ~AttachedBinaryFile();

private:
    Ui::AttachedBinaryFile *ui;
};

} /* namespace Mattermost */

#endif // ATTACHEDBINARYFILE_H

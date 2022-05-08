#ifndef ATTACHEDIMAGEFILE_H
#define ATTACHEDIMAGEFILE_H

#include <QWidget>

namespace Ui {
class AttachedImageFile;
}

namespace Mattermost {

class BackendFile;

class AttachedImageFile: public QWidget {
    Q_OBJECT

public:
    explicit AttachedImageFile (const BackendFile& file, QWidget *parent = nullptr);
    ~AttachedImageFile();

private:
    Ui::AttachedImageFile *ui;
};

} /* namespace Mattermost */

#endif // ATTACHEDIMAGEFILE_H

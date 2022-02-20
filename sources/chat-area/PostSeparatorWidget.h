#ifndef MESSAGESEPARATORWIDGET_H
#define MESSAGESEPARATORWIDGET_H

#include <QWidget>

namespace Ui {
class PostSeparatorWidget;
}

class PostSeparatorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PostSeparatorWidget (const QString& text);
    ~PostSeparatorWidget();

private:
    Ui::PostSeparatorWidget *ui;
};

#endif // MESSAGESEPARATORWIDGET_H

#ifndef MESSAGESEPARATORWIDGET_H
#define MESSAGESEPARATORWIDGET_H

#include <QWidget>

namespace Ui {
class MessageSeparatorWidget;
}

class MessageSeparatorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MessageSeparatorWidget (const QString& text);
    ~MessageSeparatorWidget();

private:
    Ui::MessageSeparatorWidget *ui;
};

#endif // MESSAGESEPARATORWIDGET_H

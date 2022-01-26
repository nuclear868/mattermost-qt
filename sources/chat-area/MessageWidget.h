
#pragma once

#include <QWidget>
#include <memory>

namespace Ui {
class MessageWidget;
}

namespace Mattermost {

class BackendPost;
class MessageAttachmentList;

class MessageWidget: public QWidget
{
    Q_OBJECT

public:
    explicit MessageWidget (const BackendPost &post, QWidget *parent = nullptr);
    ~MessageWidget();
public:
    void setOwnMessage ();
    QString getMessageTimeString (uint64_t timestamp);
    QString formatMessageText (const QString& str);

private:
    Ui::MessageWidget*						ui;
    std::unique_ptr<MessageAttachmentList>	attachments;
};

} /* namespace Mattermost */



#pragma once

#include <QWidget>
#include <memory>

namespace Ui {
class PostWidget;
}

namespace Mattermost {

class Backend;
class BackendPost;
class MessageAttachmentList;
class ChatArea;

class PostWidget: public QWidget
{
    Q_OBJECT

public:
    explicit PostWidget (Backend& backend, BackendPost &post, QWidget *parent, ChatArea* chatArea);
    ~PostWidget();
public:
    QString getMessageTimeString (uint64_t timestamp);
    QString formatMessageText (const QString& str);

    BackendPost&							post;
private:
    Ui::PostWidget*						ui;
    std::unique_ptr<MessageAttachmentList>	attachments;
};

} /* namespace Mattermost */


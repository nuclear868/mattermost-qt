
#pragma once

#include <QWidget>
#include <memory>

namespace Ui {
class PostWidget;
}

namespace Mattermost {

class Backend;
class BackendPost;
class PostAttachmentList;
class ChatArea;

class PostWidget: public QWidget
{
    Q_OBJECT

public:
    explicit PostWidget (Backend& backend, BackendPost &post, QWidget *parent, ChatArea* chatArea);
    ~PostWidget();
public:
    void markAsDeleted ();

    QString getMessageTimeString (uint64_t timestamp);
    QString formatMessageText (const QString& str);
    QString formatForClipboardSelection () const;

    BackendPost&						post;
    bool								isDeleted;
private:
    Ui::PostWidget*						ui;
    std::unique_ptr<PostAttachmentList>	attachments;
};

} /* namespace Mattermost */


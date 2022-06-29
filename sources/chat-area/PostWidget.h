
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

    enum FormatType {
		messageOnly,
		entirePost
    };

    void setEdited (const QString& message);

    void markAsDeleted ();


    QString getMessageTimeString (uint64_t timestamp);
    QString formatMessageText (const QString& str);
    QString formatForClipboardSelection (FormatType formatType) const;

    BackendPost&						post;
    QString								hoveredLink;
signals:
	void dimensionsChanged ();
private:
    Ui::PostWidget*						ui;
    std::unique_ptr<PostAttachmentList>	attachments;
};

} /* namespace Mattermost */


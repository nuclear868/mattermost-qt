
#include <iostream>
#include <QDebug>
#include <QDateTime>
#include <QResizeEvent>
#include "MessageWidget.h"
#include "ChatArea.h"
#include "attachments/MessageAttachmentList.h"
#include "ui_MessageWidget.h"
#include "backend/types/BackendPost.h"

namespace Mattermost {

MessageWidget::MessageWidget (BackendPost &post, QWidget *parent, ChatArea* chatArea)
:QWidget(parent)
,ui(new Ui::MessageWidget)
{
	ui->setupUi(this);

	ui->authorName->setText (post.getDisplayAuthorName ());

	ui->message->setText (formatMessageText (post.message));
	ui->time->setText (getMessageTimeString (post.create_at));

	if (!post.author || post.author->avatar.isEmpty()) {
		ui->authorAvatar->setText("");
		qDebug() << "Avatar for " << ui->authorName->text() << " is missing";
	} else {
		//load the author's avatar, with same size as the ui label
		QImage img = QImage::fromData (post.author->avatar).scaled (ui->authorAvatar->geometry().size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
		ui->authorAvatar->setPixmap (QPixmap::fromImage(img));
	}

	//Add previews for files, if any
	if (!post.files.empty()) {
		attachments = std::make_unique<MessageAttachmentList> (this);
		for (BackendFile& file: post.files) {

			if (!file.mini_preview.isEmpty()) {
				chatArea->addFileToload (&file);
			}

			attachments->addFile (file, *post.author);
		}
		ui->verticalLayout->addWidget (attachments.get(), 0, Qt::AlignLeft);
	}
}

MessageWidget::~MessageWidget()
{
    delete ui;
}

void MessageWidget::setOwnMessage ()
{
	ui->authorName->setStyleSheet("QLabel { color : blue; }");
}

QString MessageWidget::formatMessageText (const QString& str)
{
	QString ret (str.toHtmlEscaped ());

	ret.replace("\n", "<br>");

	int linkStart = 0;
	int linkEnd = 0;

	do {

		linkStart = ret.indexOf ("https://", linkEnd);

		if (linkStart == -1) {
			break;
		}

		//poor man's find_first_of - there is no such thing in QT, and std::string is not aware of multibyte characters
		for (linkEnd = linkStart + QString ("http://").size(); linkEnd < ret.size(); ++linkEnd) {
			if (ret.at (linkEnd) == ' ' || ret.at (linkEnd) == '<') {
				break;
			}
		}

		if (linkEnd == -1) {
			linkEnd = ret.size();
		}

		size_t size = linkEnd - linkStart;

		ret.insert (linkEnd, "\">" + QStringRef (&ret, linkStart,  size) + "</a>");
		ret.insert (linkStart, "<a href=\"");

		linkEnd += size + 15;
	} while (linkStart != -1);

	//std::cout << str.toStdString() << std::endl;
	//std::cout << ret.toStdString() << std::endl;
	//ret.repl
	return ret;
}

QString MessageWidget::getMessageTimeString (uint64_t timestamp)
{
	QDate currentDate = QDateTime::currentDateTime().date();
	QDateTime postTime = QDateTime::fromMSecsSinceEpoch (timestamp);
	QDate postDate = postTime.date();

	QString format;

	if (currentDate.year() != postDate.year()) {
		format = "dd MMM yyyy, hh:mm:ss";
	} else if (currentDate.day() != postDate.day()) {
		format = "dd MMM, hh:mm:ss";
	} else {
		format = "hh:mm:ss";
	}

	return postTime.toString (format);
}

} /* namespace Mattermost */


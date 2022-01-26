
#include "ChatArea.h"

#include <QFileDialog>
#include <QScrollBar>
#include "ui_ChatArea.h"
#include "MessageWidget.h"
#include "backend/Backend.h"
#include "log.h"

namespace Mattermost {

ChatArea::ChatArea (Backend& backend, BackendChannel& channel, QTreeWidgetItem* tree, QWidget *parent)
:QWidget(parent)
,ui(new Ui::ChatArea)
,backend (backend)
,channel (channel)
,treeItem (new QTreeWidgetItem (tree))
,unreadMessagesCount (0)
{
	ui->setupUi(this);
	ui->listWidget->verticalScrollBar()->setSingleStep (10);
	ui->title->setText (channel.display_name);
	treeItem->setText (0, channel.display_name);
	treeItem->setData(0, Qt::UserRole, QVariant::fromValue(this));

	QFont font1;
	font1.setPixelSize(14);
	font1.setBold (true);
	treeItem->setFont (1, font1);

	const Mattermost::BackendUser* user = backend.getStorage().getUserById (channel.name);

	if (user) {
		QImage img = QImage::fromData (user->avatar).scaled (64, 64, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
		ui->userAvatar->setPixmap (QPixmap::fromImage(img));

		if (channel.type == BackendChannel::directChannel) {
			treeItem->setIcon(0, QIcon(QPixmap::fromImage(QImage::fromData(user->avatar))));
		}
	} else {
		ui->userAvatar->clear();
		ui->userAvatar->hide();
	}

	connect (&channel, &BackendChannel::onNewPost, this, &ChatArea::appendChannelPost);

	connect (&channel, &BackendChannel::onUserTyping, this, &ChatArea::handleUserTyping);

	/*
	 * Send new post after pressing enter or clicking the 'Send' button
	 */
	connect (ui->sendButton, &QPushButton::clicked, this, &ChatArea::sendNewPost);
#if 0
	connect (ui->attachButton, &QPushButton::clicked, [this] {
		for (auto& filename: QFileDialog::getOpenFileNames (this, "Select File(s) to attach")) {
			qDebug() << filename;
			this->backend.uploadFile (this->channel, filename, [] (QString fileID) {

			});
		}
	});
#endif
	connect (ui->textEdit, &MessageTextEditWidget::enterPressed, this, &ChatArea::sendNewPost);
}

ChatArea::~ChatArea()
{
    delete ui;
}

BackendChannel& ChatArea::getChannel ()
{
	return channel;
}

void ChatArea::fillChannelPosts ()
{
	for (auto& post: channel.posts) {
		MessageWidget* message = new MessageWidget (post);

		if (post.isOwnPost()) {
			message->setOwnMessage ();
		}

		QListWidgetItem* newItem = new QListWidgetItem();

		ui->listWidget->addItem (newItem);
		ui->listWidget->setItemWidget (newItem, message);
	}

	backend.getChannelUnreadPost (channel, [this] (const QString& postId){
		qDebug () << "Last Read post for " << channel.display_name << ": " << postId;
		++unreadMessagesCount;
		treeItem->setText(1, QString::number(unreadMessagesCount));
	});
}

void ChatArea::appendChannelPost (const BackendPost& post)
{
	MessageWidget* message = new MessageWidget (post);

	if (post.isOwnPost()) {
		message->setOwnMessage ();
	}

	QListWidgetItem* newItem = new QListWidgetItem();

	ui->listWidget->addItem (newItem);
	ui->listWidget->setItemWidget (newItem, message);

	newItem->setSizeHint(QSize (message->width(), message->heightForWidth(ui->listWidget->size().width())));
	ui->listWidget->scrollToBottom();

	//do not add unread messages count if the item is selected
	if (treeItem->isSelected() && isActiveWindow ()) {
		return;
	}

	++unreadMessagesCount;
	treeItem->setText(1, QString::number(unreadMessagesCount));
}

void ChatArea::sendNewPost ()
{
	QString message = ui->textEdit->toPlainText ();

	//do not send empty messages
	if (message.isEmpty()) {
		return;
	}

	ui->textEdit->clear();
	backend.addPost (channel, message);
}

void ChatArea::onActivate ()
{
	unreadMessagesCount = 0;
	treeItem->setText(1, "");
	ui->listWidget->scrollToBottom();

	//hack to resize chat area which was inactive
	ui->listWidget->resize(200, 299);
}

void ChatArea::handleUserTyping (const BackendUser& user)
{
	LOG_DEBUG (channel.display_name << ": " << user.getDisplayName() << " is typing");
}

void ChatArea::onWindowActivate ()
{
	unreadMessagesCount = 0;
	treeItem->setText(1, "");
}

} /* namespace Mattermost */

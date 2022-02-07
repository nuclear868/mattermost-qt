
#include "ChatArea.h"

#include <QFileDialog>
#include <QScrollBar>
#include "ui_ChatArea.h"
#include "MessageWidget.h"
#include "MessageSeparatorWidget.h"
#include "backend/Backend.h"
#include "log.h"

namespace Mattermost {

ChatArea::ChatArea (Backend& backend, BackendChannel& channel, QTreeWidgetItem* tree, QWidget *parent)
:QWidget(parent)
,ui(new Ui::ChatArea)
,backend (backend)
,channel (channel)
,treeItem (new QTreeWidgetItem (tree))
,newMessagesSeparator (nullptr)
,unreadMessagesCount (0)
{
	ui->setupUi(this);
	ui->listWidget->verticalScrollBar()->setSingleStep (10);
	ui->title->setText (channel.display_name);
	treeItem->setText (0, channel.display_name);
	treeItem->setData(0, Qt::UserRole, QVariant::fromValue(this));

	removeNewMessagesSeparatorTimer.setSingleShot (true);
	connect (&removeNewMessagesSeparatorTimer, &QTimer::timeout, this, &ChatArea::removeNewMessagesSeparator);

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

	/*
	 * First, get the first unread post (if any). So that a separator can be inserted before it
	 */
	backend.getChannelUnreadPost (channel, [this, &backend, &channel] (const QString& postId){
		qDebug () << "Last Read post for " << channel.display_name << ": " << postId;

		backend.getChannelPosts (channel, 0, 200, [this, postId]() {
			fillChannelPosts (postId);
		});
	});

	connect (&channel, &BackendChannel::onViewed, [this] {
		LOG_DEBUG ("Channel viewed: " << this->channel.name);
		setUnreadMessagesCount (0);
		if (newMessagesSeparator) {
			removeNewMessagesSeparatorTimer.start (1000);
		}
	});

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

void ChatArea::fillChannelPosts (const QString& lastReadPostID)
{
	for (auto& post: channel.posts) {
		MessageWidget* message = new MessageWidget (post, ui->listWidget, this);

		if (post.isOwnPost()) {
			message->setOwnMessage ();
		}

		QListWidgetItem* newItem = new QListWidgetItem();

		ui->listWidget->addItem (newItem);
		ui->listWidget->setItemWidget (newItem, message);

		if (post.id == lastReadPostID) {
			addNewMessagesSeparator ();
			++unreadMessagesCount;
		}
	}

	setUnreadMessagesCount (unreadMessagesCount);
}

void ChatArea::appendChannelPost (BackendPost& post)
{
	MessageWidget* message = new MessageWidget (post, ui->listWidget, this);

	if (post.isOwnPost()) {
		message->setOwnMessage ();
	}

	bool chatAreaHasFocus = treeItem->isSelected() && isActiveWindow ();

	if (!chatAreaHasFocus) {
		addNewMessagesSeparator ();
	}

	QListWidgetItem* newItem = new QListWidgetItem();

	ui->listWidget->addItem (newItem);
	ui->listWidget->setItemWidget (newItem, message);

	newItem->setSizeHint(QSize (message->width(), message->heightForWidth(ui->listWidget->size().width())));
	ui->listWidget->scrollToBottom();

	//do not add unread messages count if the Chat Area is on focus
	if (chatAreaHasFocus) {
		return;
	}

	++unreadMessagesCount;
	setUnreadMessagesCount (unreadMessagesCount);
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

	removeNewMessagesSeparator ();
}

void ChatArea::handleUserTyping (const BackendUser& user)
{
	LOG_DEBUG (channel.display_name << ": " << user.getDisplayName() << " is typing");
}

void ChatArea::onActivate ()
{
	if (newMessagesSeparator) {
		ui->listWidget->scrollToItem (newMessagesSeparator, QAbstractItemView::PositionAtCenter);
	} else {
		ui->listWidget->scrollToBottom();
	}

	ui->listWidget->adjustSize();

	backend.markChannelAsViewed (channel);

	for (auto& file: filesToLoad) {

		if (!file->contents.isEmpty()) {
			continue;
		}

		backend.getFile (file->id, [file] (QByteArray& data) {
			file->contents = data;
			emit file->onContentsAvailable();
		});
	}
}

void ChatArea::onMainWindowActivate ()
{
	setUnreadMessagesCount (0);
	backend.markChannelAsViewed (channel);
}

void ChatArea::addNewMessagesSeparator ()
{
	if (newMessagesSeparator) {
		return;
	}

	MessageSeparatorWidget* separator = new MessageSeparatorWidget ("New messages");
	newMessagesSeparator = new QListWidgetItem();
	ui->listWidget->addItem (newMessagesSeparator);
	ui->listWidget->setItemWidget (newMessagesSeparator, separator);
}

void ChatArea::removeNewMessagesSeparator ()
{
	if (!newMessagesSeparator) {
		return;
	}

	delete newMessagesSeparator;
	newMessagesSeparator = nullptr;
}

void ChatArea::addFileToload (BackendFile* file)
{
	filesToLoad.push_back (file);
}

void ChatArea::setUnreadMessagesCount (uint32_t count)
{
	unreadMessagesCount = count;

	if (count == 0) {
		treeItem->setText(1, "");
	} else {
		treeItem->setText(1, QString::number(count));
	}
}

} /* namespace Mattermost */

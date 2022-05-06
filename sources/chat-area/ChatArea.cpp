
#include "ChatArea.h"

#include "channel-tree/ChannelItem.h"
#include "ui_ChatArea.h"
#include "PostWidget.h"
#include "backend/Backend.h"
#include "log.h"

namespace Mattermost {

ChatArea::ChatArea (Backend& backend, BackendChannel& channel, ChannelItem* treeItem, QWidget *parent)
:QWidget(parent)
,ui(new Ui::ChatArea)
,backend (backend)
,channel (channel)
,treeItem (treeItem)
,outgoingPostCreator (*this)
,unreadMessagesCount (0)
,texteditDefaultHeight (80)
,gettingOlderPosts (false)
{
	//accept drag&drop attachments
	setAcceptDrops(true);

	ui->setupUi(this);
	ui->listWidget->backend = &backend;

	ui->titleLabel->setText (channel.display_name);
	ui->statusLabel->setText (channel.getChannelDescription ());

	setTextEditWidgetHeight (texteditDefaultHeight);

	const Mattermost::BackendUser* user = backend.getStorage().getUserById (channel.name);

	if (user) {

		connect (user, &BackendUser::onAvatarChanged, [this, user] {
			setUserAvatar (*user);
		});

		if (!user->avatar.isEmpty()) {
			setUserAvatar (*user);
		}
	} else {
		ui->userAvatar->clear();
		ui->userAvatar->hide();
	}

	/*
	 * First, get the first unread post (if any). So that a separator can be inserted before it
	 */
	backend.retrieveChannelUnreadPost (channel, [this, &backend, &channel] (const QString& postId){
		lastReadPostId = postId;

		if (!postId.isEmpty()) {
			qDebug () << "Last Read post for " << channel.display_name << ": " << postId;
		}

		backend.retrieveChannelPosts (channel, 0, 25);
	});

	connect (&channel, &BackendChannel::onViewed, [this] {
		LOG_DEBUG ("Channel viewed: " << this->channel.name);
		setUnreadMessagesCount (0);
		ui->listWidget->removeNewMessagesSeparatorAfterTimeout (1000);
	});

	connect (&channel, &BackendChannel::onNewPosts, this,  &ChatArea::fillChannelPosts);

	connect (&channel, &BackendChannel::onNewPost, this, &ChatArea::appendChannelPost);

	//let the post creator know that the last sent / edited post has appeared so that the input box can be cleared
	connect (&channel, &BackendChannel::onNewPost, &outgoingPostCreator, &OutgoingPostCreator::onPostReceived);
	connect (&channel, &BackendChannel::onPostEdited, &outgoingPostCreator, &OutgoingPostCreator::onPostReceived);

	connect (&channel, &BackendChannel::onUserTyping, this, &ChatArea::handleUserTyping);

	connect (&channel, &BackendChannel::onPostEdited, [this] (BackendPost& post) {
		PostWidget* postWidget = ui->listWidget->findPost (post.id);

		if (postWidget) {
			postWidget->setEdited (post.message);
			ui->listWidget->adjustSize();
		}
	});

	//initiate editing of last post, after an up arrow is pressed
	connect (ui->textEdit, &MessageTextEditWidget::upArrowPressed, [this] {
		QListWidgetItem* post = ui->listWidget->getLastOwnPost ();

		if (post) {
			ui->listWidget->initiatePostEdit (*post);
		}
	});

	//initiate editing of post, when edit is selected from the context menu
	connect (ui->listWidget, &PostsListWidget::postEditInitiated, &outgoingPostCreator, &OutgoingPostCreator::postEditInitiated);

	connect (&outgoingPostCreator, &OutgoingPostCreator::postEditFinished, ui->listWidget, &PostsListWidget::postEditFinished);

	connect (&channel, &BackendChannel::onPostDeleted, [this] (const QString& postId) {
		PostWidget* postWidget = ui->listWidget->findPost (postId);

		if (postWidget) {
			postWidget->markAsDeleted ();
			ui->listWidget->adjustSize();
		}
	});

	connect (ui->splitter, &QSplitter::splitterMoved, [this] {
		texteditDefaultHeight = ui->splitter->sizes()[1];
	});

	connect (ui->textEdit, &MessageTextEditWidget::textChanged, [this] {
		QSize size = ui->textEdit->document()->size().toSize();

		int height = size.height() + 10;

		if (height < texteditDefaultHeight) {
			height = texteditDefaultHeight;
		}

		if (height > ui->textEdit->maximumHeight()) {
			height = ui->textEdit->maximumHeight();
		}

		setTextEditWidgetHeight (height);
	});

	//when scrolling to top, get older posts
	connect (ui->listWidget, &PostsListWidget::scrolledToTop, [this, &backend, &channel] {
		if (!gettingOlderPosts) {
			//do not spam requests
			gettingOlderPosts = true;
			backend.retrieveChannelOlderPosts (channel, 40);
		}
	});
}

ChatArea::~ChatArea()
{
    delete ui;
}

void ChatArea::setUserAvatar (const BackendUser& user)
{
	QImage img = QImage::fromData (user.avatar).scaled (64, 64, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	ui->userAvatar->setPixmap (QPixmap::fromImage(img));

	if (channel.type == BackendChannel::directChannel) {
		treeItem->setIcon (QIcon(QPixmap::fromImage(QImage::fromData(user.avatar))));
	}
}

Ui::ChatArea* ChatArea::getUi ()
{
	return ui;
}

Backend& ChatArea::getBackend ()
{
	return backend;
}

BackendChannel& ChatArea::getChannel ()
{
	return channel;
}

void ChatArea::fillChannelPosts (const ChannelNewPosts& newPosts)
{
	QDate currentDate = QDateTime::currentDateTime().date();
	int insertPos = 0;
	int startPos = 0;
	int currentElapsedDays = INT32_MAX;

	//save the first post (before insertion), so that the list will be scrolled to it after the insertion
	QListWidgetItem* firstPost = nullptr;
	if (gettingOlderPosts) {

		firstPost = ui->listWidget->item(0);

		if (firstPost->data(Qt::UserRole) != ItemType::post) {
			firstPost = ui->listWidget->item(1);
		}

		PostWidget* firstPostWidget = static_cast<PostWidget*> (ui->listWidget->itemWidget (firstPost));
		currentElapsedDays = firstPostWidget->post.getCreationTime().date().daysTo(currentDate);
	}

	for (const ChannelNewPostsChunk& chunk: newPosts.postsToAdd) {

		if (!chunk.previousPostId.isEmpty()) {
			qDebug() << "Add posts after" << chunk.previousPostId;
		}

		insertPos = ui->listWidget->findPostByIndex (chunk.previousPostId, startPos);
		++insertPos;
		startPos = insertPos;

		for (auto& post: chunk.postsToAdd) {

			if (!chunk.previousPostId.isEmpty()) {
				qDebug() << "\tAdd post " << post->id;
			}

			lastPostDate = post->getCreationTime ().date();

			int postElapsedDays = (lastPostDate.daysTo (currentDate));

			if (postElapsedDays != currentElapsedDays) {
				currentElapsedDays = postElapsedDays;

				ui->listWidget->addDaySeparator (insertPos, postElapsedDays);
				++insertPos;
			}

			ui->listWidget->insertPost (insertPos, new PostWidget (backend, *post, ui->listWidget, this));
			++insertPos;

			if (post->id == lastReadPostId) {
				ui->listWidget->addNewMessagesSeparator ();
				++insertPos;
				++unreadMessagesCount;
			}
		}
	}

	gettingOlderPosts = false;

	if (firstPost) {
		ui->listWidget->scrollToItem(firstPost, QAbstractItemView::PositionAtTop);
	}

	//ui->listWidget->adjustSize();
	setUnreadMessagesCount (unreadMessagesCount);

}

void ChatArea::appendChannelPost (BackendPost& post)
{
	QDate currentDate = QDateTime::currentDateTime().date();

	if (lastPostDate.daysTo (currentDate) >= 1) {
		ui->listWidget->addDaySeparator (0);
		QDateTime postTime = QDateTime::fromMSecsSinceEpoch (post.create_at);
		lastPostDate = postTime.date();
	}

	bool chatAreaHasFocus = treeItem->isSelected() && isActiveWindow ();

	if (!chatAreaHasFocus) {
		ui->listWidget->addNewMessagesSeparator ();
	}

	ui->listWidget->insertPost (new PostWidget (backend, post, ui->listWidget, this));

	ui->listWidget->adjustSize();
	ui->listWidget->scrollToBottom();

	//do not add unread messages count if the Chat Area is on focus
	if (chatAreaHasFocus) {
		return;
	}

	++unreadMessagesCount;
	setUnreadMessagesCount (unreadMessagesCount);
}

void ChatArea::handleUserTyping (const BackendUser& user)
{
	LOG_DEBUG (channel.display_name << ": " << user.getDisplayName() << " is typing");
}

void ChatArea::onActivate ()
{
	ui->listWidget->scrollToUnreadPostsOrBottom ();
	//ui->listWidget->adjustSize();

	backend.markChannelAsViewed (channel);

	for (BackendFile* file: filesToLoad) {

		if (!file->contents.isEmpty()) {
			continue;
		}

		backend.retrieveFile (file->id, [file] (const QByteArray& data) {
			file->contents = data;
			emit file->onContentsAvailable (data);
		});
	}
}

void ChatArea::onMainWindowActivate ()
{
	setUnreadMessagesCount (0);
	backend.markChannelAsViewed (channel);
}

void ChatArea::addFileToload (BackendFile* file)
{
	if (!treeItem->isSelected()) {
		filesToLoad.push_back (file);
		return;
	}

	//if the chat area is active, load files immediately"

	if (!file->contents.isEmpty()) {
		return;
	}

	backend.retrieveFile (file->id, [file] (const QByteArray& data) {
		file->contents = data;
		emit file->onContentsAvailable (data);
	});
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

void ChatArea::dragEnterEvent (QDragEnterEvent* event)
{
	outgoingPostCreator.onDragEnterEvent (event);
}

void ChatArea::dragMoveEvent (QDragMoveEvent* event)
{
	outgoingPostCreator.onDragMoveEvent (event);
}

void ChatArea::dropEvent (QDropEvent* event)
{
	outgoingPostCreator.onDropEvent (event);
}

QVBoxLayout& ChatArea::getAttachmentListParentWidget ()
{
	return *ui->verticalLayout;
}

void ChatArea::setTextEditWidgetHeight (int height)
{
	//set the size of the text input area only. The chat area will take the whole remaining part, because it has higher stretch factor
	ui->splitter->setSizes({1, height});
}

} /* namespace Mattermost */

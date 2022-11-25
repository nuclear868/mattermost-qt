/**
 * Copyright 2021, 2022 Lyubomir Filipov
 *
 * This file is part of Mattermost-QT.
 *
 * Mattermost-QT is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Mattermost-QT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Mattermost-QT; if not, see https://www.gnu.org/licenses/.
 */

#include "ChatArea.h"

#include "channel-tree/ChannelItem.h"
#include "ui_ChatArea.h"
#include "post/PostWidget.h"
#include "backend/Backend.h"
#include "channel-tree/ChannelItemWidget.h"
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

		if (ui->statusLabel->text().isEmpty()) {
			ui->statusLabel->setText (user->status);
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

	connect (&channel, &BackendChannel::onUpdated, [this] {
		ui->titleLabel->setText (this->channel.display_name);
		this->treeItem->setLabel (this->channel.display_name);
		ui->statusLabel->setText (this->channel.getChannelDescription ());
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

	connect (&channel, &BackendChannel::onPostReactionUpdated, [this] (BackendPost& post) {
		PostWidget* postWidget = ui->listWidget->findPost (post.id);

		if (postWidget) {
			postWidget->updateReactions ();
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

	BackendPost* lastRootPost = nullptr;

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

			ui->listWidget->insertPost (insertPos, new PostWidget (backend, *post, ui->listWidget, this, lastRootPost));
			lastRootPost = post->rootPost;
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
	//moveOnListTop ();
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

	ui->listWidget->insertPost (new PostWidget (backend, post, ui->listWidget, this, nullptr));

	ui->listWidget->adjustSize();
	ui->listWidget->scrollToBottom();

	moveOnListTop ();

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

	backend.setCurrentChannel (channel);
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

void ChatArea::moveOnListTop ()
{
	QTreeWidgetItem* parent = treeItem->parent();
	QTreeWidget* tree = treeItem->treeWidget();

	//item already on top, nothing to do
	if (parent->indexOfChild (treeItem) == 0) {
		return;
	}

	bool isCurrent = (tree->currentItem() == treeItem);

	ChannelItemWidget* thisItemWidget = static_cast<ChannelItemWidget*> (tree->itemWidget(treeItem, 0));


	/**
	 * takeChild will delete the widget because the tree owns the widget.
	 * Therefore, create a new widget and set it as ItemWidget
	 */
	ChannelItemWidget* newItemWidget = new ChannelItemWidget (thisItemWidget->parentWidget());
	newItemWidget->setLabel (channel.display_name);

	if (thisItemWidget->getPixmap()) {
		newItemWidget->setIcon (QIcon(*thisItemWidget->getPixmap()));
	}

	qDebug() << "Move on top (" << parent->indexOfChild(treeItem) << ") -> 0";

	//block signals, so that itemActivated is not called

	tree->blockSignals (true);
	QTreeWidgetItem* child = parent->takeChild (parent->indexOfChild(treeItem));
	parent->insertChild(0, child);
	tree->blockSignals (false);

	if (child != treeItem) {
		exit (1);
	}

	tree->setItemWidget (child, 0, newItemWidget);
	treeItem->setWidget (newItemWidget);

	if (isCurrent) {
		tree->setCurrentItem (child);
	}

	qDebug() << "Move on top done";
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

void ChatArea::goToPost (const BackendPost& post)
{
	int pos = ui->listWidget->findPostByIndex (post.id, 0);

	ui->listWidget->scrollToItem(ui->listWidget->item(pos), QAbstractItemView::PositionAtTop);
}

void ChatArea::setTextEditWidgetHeight (int height)
{
	//set the size of the text input area only. The chat area will take the whole remaining part, because it has higher stretch factor
	ui->splitter->setSizes({1, height});
}

} /* namespace Mattermost */

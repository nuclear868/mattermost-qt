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

#include "PostWidget.h"

#include <iostream>
#include <QDebug>
#include <QDateTime>
#include <QResizeEvent>
#include "backend/Backend.h"
#include "backend/types/BackendPost.h"
#include "backend/EmojiMap.h"
#include "chat-area/ChatArea.h"
#include "PostQuoteFrame.h"
#include "attachments/PostAttachmentList.h"
#include "attachments/PostPoll.h"
#include "reactions/PostReactionList.h"
#include "ui_PostWidget.h"

namespace Mattermost {

PostWidget::PostWidget (Backend& backend, BackendPost &post, QWidget *parent, ChatArea* chatArea, BackendPost* lastRootPost)
:QWidget(parent)
,post (post)
,ui(new Ui::PostWidget)
{
	ui->setupUi(this);
	ui->authorName->setText (post.getDisplayAuthorName ());

	if (post.isOwnPost()) {
		ui->authorName->setStyleSheet("QLabel { color : blue; }");
	}

	ui->message->setText (formatMessageText (post.message));
	ui->time->setText (getMessageTimeString (post.create_at));

	if (!post.author || post.author->avatar.isEmpty()) {
		ui->authorAvatar->setText("");
		//qDebug() << "Avatar for " << ui->authorName->text() << " is missing";
	} else {
		//load the author's avatar, with same size as the ui label
		QImage img = QImage::fromData (post.author->avatar).scaled (ui->authorAvatar->geometry().size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
		ui->authorAvatar->setPixmap (QPixmap::fromImage(img));
	}

	/**
	 * Add root post as a quote box.
	 * Multiple consecutive posts, quoting the same post will have the quote added only to the first of them.
	 */
	if (post.rootPost && post.rootPost != lastRootPost) {

		quoteFrame = std::make_unique<PostQuoteFrame> (post, *post.rootPost, backend.getStorage(), this);

		//insert the frame after the post author line
		ui->verticalLayout->insertWidget (1, quoteFrame.get(), 0, Qt::AlignLeft);

		connect (quoteFrame.get(), &PostQuoteFrame::postClicked, [&post, chatArea] {
			chatArea->goToPost (*post.rootPost);
		});
	}

	//Add previews for files, if any
	if (!post.files.empty()) {
		attachments = std::make_unique<PostAttachmentList> (backend, this);
		for (BackendFile& file: post.files) {

			if (!file.mini_preview.isEmpty()) {
				chatArea->addFileToload (&file);
			}

			attachments->addFile (file, post.getDisplayAuthorName());
		}
		ui->verticalLayout->addWidget (attachments.get(), 0, Qt::AlignLeft);
	}

	//Add reactions, if any
	if (!post.reactions.empty()) {
		reactions = std::make_unique<PostReactionList> (this);

		for (auto& it: post.reactions) {
			auto emojiIterator = it.first;
			reactions->addReaction (emojiIterator.key(), emojiIterator.value(), it.second);
		}

		ui->verticalLayout->addWidget (reactions.get(), 0, Qt::AlignLeft);
	}

	if (post.poll) {
		//clear message text, because poll messages do not contain free text (outside the poll itself)
		clearMessageText ();
		poll = std::make_unique<PostPoll> (backend, post, *post.poll, this);
		ui->verticalLayout->addWidget (poll.get(), 0, Qt::AlignLeft);
	}

	connect (ui->message, &QLabel::linkHovered, [this] (const QString& link) {
		qDebug() << "Link hovered: " << link;
		hoveredLink = link;
	});
}

PostWidget::~PostWidget()
{
    delete ui;
}

void PostWidget::setEdited (const QString& message)
{
	ui->message->setText (formatMessageText (message));

	/**
	 * if (there is a poll in the post, just recreate the poll instance
	 */
	if (post.poll) {
		//clear message text, because poll messages do not contain free text (outside the poll itself)
		clearMessageText ();
		std::unique_ptr<PostPoll> newPoll = std::make_unique<PostPoll> (poll->backend, post, *post.poll, this);
		ui->verticalLayout->replaceWidget (poll.get(), newPoll.get());
		poll = std::move (newPoll);
	}
}

void PostWidget::updateReactions ()
{
	if (reactions) {
		reactions.reset ();
	}

	//Add reactions, if any
	if (!post.reactions.empty()) {
		reactions = std::make_unique<PostReactionList> (this);

		for (auto& it: post.reactions) {
			auto emojiIterator = it.first;
			reactions->addReaction (emojiIterator.key(), emojiIterator.value(), it.second);
		}

		ui->verticalLayout->addWidget (reactions.get(), 0, Qt::AlignLeft);
	}
}

void PostWidget::markAsDeleted ()
{
	attachments.reset (nullptr);
	post.isDeleted = true;
	if (poll) {
		ui->verticalLayout->removeWidget (poll.get());
		poll.reset (nullptr);

		ui->message->setText ("(Poll deleted)");
		ui->message->setMaximumHeight (100);
	} else {
		ui->message->setText ("(Message deleted)");
	}
}


QString PostWidget::getSelectedText ()
{
	return ui->message->selectedText();
}

void replaceEmojis (QString& str)
{
	int emojiStart = 0;
	int emojiEnd = 0;

	do {

		//find a substring enclosed in ':' - for example - :wave:
		emojiStart = str.indexOf (':', emojiEnd);
		if (emojiStart == -1) {
			break;
		}

		emojiEnd = str.indexOf (':', emojiStart + 1);
		if (emojiEnd == -1) {
			break;
		}

		if (emojiEnd - emojiStart == 1) {
			++emojiEnd;
			continue;
		}

		int emojiNameSize = emojiEnd - emojiStart - 1;

		//get the substring enclosed in ':' (without the ':'). This is the emoji name
		QString emojiName = str.mid (emojiStart + 1, emojiNameSize);

		auto it = EmojiMap::findByName (emojiName);

		if (it == EmojiMap::missing ()) {
			continue;
		}

		//replace the emoji name (together with ':') with it's corresponding value
		str.replace (emojiStart, emojiNameSize + 2, it.value());

		emojiEnd -= emojiName.size() + 2 - it.value().size();
		++emojiEnd;

	} while (emojiStart != -1);

}

QString PostWidget::formatMessageText (const QString& str)
{
	QString ret (str.toHtmlEscaped ());
	ret.replace("\n", "<br>");

	int linkStart = 0;
	int linkEnd = 0;

	replaceEmojis (ret);

	do {

		QLatin1String lookups[2] = { QLatin1String ("http://"), QLatin1String ("https://") };
		QLatin1String* useLookup = nullptr;

		for (auto& lookup: lookups) {
			linkStart = ret.indexOf (lookup, linkEnd);

			if (linkStart != -1) {
				useLookup = &lookup;
				break;
			}
		}

		if (!useLookup) {
			break;
		}

		//poor man's find_first_of - there is no such thing in QT, and std::string is not aware of multibyte characters
		for (linkEnd = linkStart + useLookup->size(); linkEnd < ret.size(); ++linkEnd) {
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
	return ret;
}

QString PostWidget::getMessageTimeString (uint64_t timestamp)
{
	QDate currentDate = QDateTime::currentDateTime().date();
	QDateTime postTime = QDateTime::fromMSecsSinceEpoch (timestamp);
	QDate postDate = postTime.date();

	QString format;

	if (currentDate.year() != postDate.year()) {
		format = "dd MMM yyyy, hh:mm:ss";
	} else if (currentDate.day() != postDate.day() || currentDate.month() != postDate.month()) {
		format = "dd MMM, hh:mm:ss";
	} else {
		format = "hh:mm:ss";
	}

	return postTime.toString (format);
}

QString PostWidget::formatForClipboardSelection (FormatType formatType) const
{
	if (formatType == messageOnly) {
		return post.message;
	}

	QString ret (post.getDisplayAuthorName() + "\t[" + ui->time->text() + "]\n");
	ret += " " + post.message + "\n\n";
	return ret;
}

void PostWidget::clearMessageText ()
{
	ui->message->setText ("");
	ui->message->setMaximumHeight (0);
}

} /* namespace Mattermost */


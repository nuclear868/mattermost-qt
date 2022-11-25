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

#include "PostQuoteFrame.h"

#include <QDebug>
#include "ui_PostQuoteFrame.h"
#include "backend/types/BackendPost.h"
#include "backend/types/BackendPoll.h"
#include "backend/Storage.h"
#include "PostWidget.h"

namespace Mattermost {

PostQuoteFrame::PostQuoteFrame (BackendPost& containingPost, const BackendPost& quotedPost, const Storage& storage, PostWidget* containingPostWidget)
:QFrame (containingPostWidget)
,ui (new Ui::PostQuoteFrame)
{
	ui->setupUi(this);

	QString headerText;

	bool isMatterpollQuote = quotedPost.author == storage.matterpollUser && containingPost.author == storage.matterpollUser;
	if (isMatterpollQuote) {

		if (!quotedPost.poll) {
			qDebug() << "Matterpoll quoted post contains no poll";
		} else {
			QString pollTitle = quotedPost.poll->title;

			/**
			 * When a poll ends, there is auto-generated message with the following text, from the Matterpoll user.
			 * The message is too annoying. Replace it with shorter message and a button, which links to the ended poll
			 */
			QString expectedText = "The poll **" + pollTitle + "** has ended and the original post has been updated. You can jump to it by pressing";

			if (containingPost.message.startsWith (expectedText)) {
				ui->header->setText ("The poll '" + pollTitle + "' has ended.");
				ui->message->setText("");
				ui->message->setMaximumHeight (0);
				containingPostWidget->clearMessageText ();
			}
		}
	} else {

		ui->header->setText ("Originally posted by " + quotedPost.author->getDisplayName ());
	}

	setContentsMargins (20, 4, 4, 4);
	connect (ui->postArrow, &QPushButton::clicked, this, &PostQuoteFrame::postClicked);
}

PostQuoteFrame::~PostQuoteFrame()
{
    delete ui;
}

void PostQuoteFrame::setHeaderText (const QString& headerText)
{
	ui->header->setText (headerText);
}


} /* namespace Mattermost */

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

#include "PostPoll.h"
#include "ui_PostPoll.h"

#include <QPushButton>
#include "backend/Backend.h"
#include "backend/types/BackendPoll.h"

namespace Mattermost {

PostPoll::PostPoll (Backend& backend, const QString& postID, BackendPoll& poll, QWidget *parent)
:QFrame(parent)
,ui(new Ui::PostPoll)
,backend (backend)
,postID (postID)
{
	ui->setupUi(this);

	if (!poll.id.isEmpty()) {
		backend.retrievePollMetadata (poll);
	}

	ui->titleLabel->setText (poll.title);

	QString text (poll.text.toHtmlEscaped ());
	text.replace("---\n", "");
	text.replace("\n", "<br>");

	//replace stars with bold tags
	QString replacements[2] = { "<b>", "</b>" };
	int replacementIdx = 0;

	int start = 0;
	int pos = text.indexOf("**", start);

	while (pos != -1) {
		text.replace (pos, 2, replacements[(replacementIdx++) % 2]);
		start = pos + 2;
		pos = text.indexOf("**", start);
	}

	ui->textLabel->setText (text);

	for (auto& option: poll.options) {

		QPushButton* optionButton = new QPushButton (option.name, this);
		optionButton->setMinimumSize (QSize(200, 30));
		optionButton->setMaximumSize (QSize(200, 30));

		optionButton->setToolTip (option.voters);

		if (poll.hasEnded) {
			optionButton->setDisabled (true);
		}

		connect (optionButton, &QPushButton::released, [this, &option] {
			this->backend.sendPostAction (this->postID, option.actionID);
		});

		ui->verticalLayout->addWidget (optionButton, 0, Qt::AlignLeft|Qt::AlignTop);
	}
}

PostPoll::~PostPoll()
{
    delete ui;
}

} /* namespace Mattermost */

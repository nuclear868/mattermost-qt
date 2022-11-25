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
#include <QMessageBox>
#include "backend/Backend.h"
#include "backend/types/BackendPoll.h"

namespace Mattermost {

PostPoll::PostPoll (Backend& backend, const BackendPost& post, BackendPoll& poll, QWidget *parent)
:QFrame(parent)
,ui(new Ui::PostPoll)
,backend (backend)
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

		QPushButton* pushButton = new QPushButton (option.name, this);
		pushButton->setMinimumSize (QSize(200, 30));
		pushButton->setMaximumSize (QSize(200, 30));

		pushButton->setToolTip (option.voters);

		if (poll.hasEnded) {
			pushButton->setDisabled (true);
		}


		ui->verticalLayout->addWidget (pushButton, 0, Qt::AlignLeft|Qt::AlignTop);

		if (option.actionID.isEmpty() || option.actionID.startsWith ("vote")) {
			optionButtons.push_back (pushButton);
			connect (pushButton, &QPushButton::released, [this, &post, &option] {
				this->backend.sendPostAction (post, option.actionID);
			});
		} else {
			adminButtons.push_back (pushButton);
			connect (pushButton, &QPushButton::released, [this, &post, &option, pushButton] {

				if (QMessageBox::question (this, "Are you sure?", "Are you sure that you want to " + pushButton->text() + "?") == QMessageBox::Yes) {
					this->backend.sendPostAction (post, option.actionID);
				}

			});

			QPalette pal = pushButton->palette();
			pal.setColor (QPalette::Button, QColor(Qt::darkGray));
			pushButton->setPalette (pal);

			pushButton->setVisible (poll.metadata.hasAdminPermissions);
		}
	}

	connect (&poll, &BackendPoll::onMetadataUpdated, [this, &poll] {
		for (auto& adminButton: adminButtons) {
			if (!adminButton->isVisible()) {
				adminButton->setVisible (poll.metadata.hasAdminPermissions);
			}
		}

		for (auto& idx: poll.metadata.ownVoteOptions) {
			QFont font (optionButtons[idx]->font());
			font.setBold (true);
			optionButtons[idx]->setFont (font);
		}
	});
}

PostPoll::~PostPoll()
{
    delete ui;
}

} /* namespace Mattermost */

/**
 * @file ChooseEmojiDialogWrapper.cpp
 * @brief Shows the ChooseEmojiDialog with given callback for chosen emoji
 * @author Lyubomir Filipov
 * @date Jan 2, 2023
 *
 * Copyright 2021, 2022 Lyubomir Filipov
 *
 * This file is part of Mattermost-QT.
 *
 * Mattermost-QT is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Mattermost-QT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Mattermost-QT. if not, see https://www.gnu.org/licenses/.
 */

#include "ChooseEmojiDialogWrapper.h"
#include <QDebug>

namespace Mattermost {

static ChooseEmojiDialog* gChooseEmojiDialog;
static std::function<void (Emoji)> chooseEmojiCallback;

ChooseEmojiDialogWrapper::ChooseEmojiDialogWrapper (QWidget* parent)
:dialog (parent)
{
	gChooseEmojiDialog = &dialog;

	QObject::connect (gChooseEmojiDialog, &QDialog::accepted, [] {
		if (!chooseEmojiCallback) {
			qCritical() << "ChooseEmojiDialog::accepted() called without active chooseEmojiCallback";
			return;
		}
		chooseEmojiCallback (gChooseEmojiDialog->getSelectedEmoji ());
	});

}

ChooseEmojiDialogWrapper::~ChooseEmojiDialogWrapper () = default;

void showEmojiDialog (std::function<void (Emoji)> chooseCallback)
{
	chooseEmojiCallback = chooseCallback;
	gChooseEmojiDialog->show ();
}

} /* namespace Mattermost */

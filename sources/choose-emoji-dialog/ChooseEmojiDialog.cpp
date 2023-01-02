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

#include "ChooseEmojiDialog.h"

#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QComboBox>
#include "backend/emoji/EmojiInfo.h"
#include "ui_ChooseEmojiDialog.h"

namespace Mattermost {

static constexpr int itemsPerRow = 28;

/**
 * Index of the emoji to be shown before the tab name for the current category.
 * The index is set to specify the emoji which most cleary describles the meaning of the category
 */
static const uint32_t indexForCategoryTab[EmojiCategory::COUNT] = {
	0, 	//smileys-emotion
	98, //people-body
	0, 	//component
	1, 	//animals-nature
	2, 	//food-drink
	0, 	//travel-places
	30, //activities
	1,	//objects
	120,//symbols
	0,	//flags
	0,	//custom
};

ChooseEmojiDialog::ChooseEmojiDialog(QWidget *parent)
:QDialog(parent)
,ui(new Ui::ChooseEmojiDialog)
{
	ui->setupUi(this);

}

void ChooseEmojiDialog::createEmojiTabs ()
{
	//tabs already created
	if (ui->tabWidget->count() >= 1) {
		return;
	}

	for (uint32_t categoryIdx = 0, tabIndex = 0; categoryIdx < EmojiCategory::COUNT; ++categoryIdx) {

		int row = 0;
		int column = 0;

		/**
		 * The component category contains only the skin tone images, it is not useful alone
		 */
		if (categoryIdx == EmojiCategory::component) {
			continue;
		}

		QVector<Emoji> emojis = EmojiInfo::getAllEmojis (categoryIdx, 0);

		QWidget *tab = new QWidget ();
		tab->setObjectName(QString::fromUtf8("tab") + QString::number(categoryIdx));
		QGridLayout *gridLayout = new QGridLayout(tab);
		gridLayout->setSpacing(0);
		gridLayout->setContentsMargins(0, 0, 0, 0);
		ui->tabWidget->addTab(tab, QString());

		/**
		 * For the 'people' category, add a combobox for settings skin tone
		 */
		if (categoryIdx == EmojiCategory::people) {
			addSkinToneComboBox (tab, gridLayout, categoryIdx);
			peopleEmojiButtons.reserve (emojis.size());
			row = 1;
		}

		QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
		sizePolicy.setHorizontalStretch(0);
		sizePolicy.setVerticalStretch(0);

		QFont font;
		font.setPointSize(16);
		QPushButton* customIconButton = nullptr;

		for (auto& emoji: emojis) {
			QPushButton* pushButton = new QPushButton (this);

			pushButton->setSizePolicy(sizePolicy);
			pushButton->setMinimumSize(QSize(32, 32));
			pushButton->setMaximumSize(QSize(32, 32));
			pushButton->setText (emoji.unicodeString);
			pushButton->setToolTip (emoji.name);
			pushButton->setFont(font);
			pushButton->setFlat(true);

			if (categoryIdx == EmojiCategory::custom) {
				QString str (emoji.unicodeString);
				int found1 = str.indexOf ('"');

				if (found1 != -1) {
					++found1;
					int found2 = str.indexOf ('"', found1);
					if (found2 != -1) {
						QString path (str.mid (found1, found2-found1));
						path.replace("qrc://",":/");
						qDebug() << "Use path " << path;
						QIcon icon (QPixmap::fromImage(QImage(path)));
						pushButton->setText ("");
						pushButton->setIcon (icon);
						pushButton->setIconSize(QSize(24,24));

						if (!customIconButton) {
							customIconButton = pushButton;
						}
					}
				}
			}

			connect (pushButton, &QPushButton::clicked, [this, pushButton] {
				selectedEmoji.name = pushButton->toolTip() + EmojiSkinTone::nameString[skinToneComboBox->currentIndex()];
				selectedEmoji.unicodeString = pushButton->text();
				accept ();
			});

			gridLayout->addWidget(pushButton, row, column, 1, 1);

			if (categoryIdx == EmojiCategory::people) {
				peopleEmojiButtons.push_back(pushButton);
			}

			++column;

			if (column == itemsPerRow) {
				column = 0;
				++row;
			}
		}

		/**
		 * Set tab text and icon
		 */
		if (categoryIdx == EmojiCategory::custom) {
			ui->tabWidget->setTabText (tabIndex, categoryDisplayNames[categoryIdx]);
			ui->tabWidget->setTabIcon (tabIndex, customIconButton->icon());
		} else {
			ui->tabWidget->setTabText (tabIndex, emojis[indexForCategoryTab[categoryIdx]].unicodeString + categoryDisplayNames[categoryIdx]);
		}

		++tabIndex;

		/**
		 * If there are less emojis than a complete row in the current tab, add a horizontal spacer
		 * to the end of the row, so that emojis are aligned to the left
		 */
		if (row == 0 && column < itemsPerRow) {
			QSpacerItem* horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	        gridLayout->addItem(horizontalSpacer, 0, column, 1, itemsPerRow - column);
		}

		/**
		 * Add vertical spacer, so that there is empty space, when the tab occupies less area than other tabs.
		 */
		QSpacerItem* verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
        gridLayout->addItem(verticalSpacer, row+1, 0, 1, 1);
	}
}

ChooseEmojiDialog::~ChooseEmojiDialog()
{
    delete ui;
}

Emoji ChooseEmojiDialog::getSelectedEmoji ()
{
	return selectedEmoji;
}

void ChooseEmojiDialog::show ()
{
	createEmojiTabs ();
	QDialog::show ();
}

void ChooseEmojiDialog::addSkinToneComboBox (QWidget *tab, QGridLayout *gridLayout, uint32_t categoryIdx)
{
	QLabel *label = new QLabel(tab);
	label->setText ("Skin Tone:");
	gridLayout->addWidget(label, 0, 0, 1, 2);

	skinToneComboBox = new QComboBox(tab);
	skinToneComboBox->setToolTip ("Emojis from this category have a 'Skin Tone' property,\nwhich can modify the skin color, making it different from the classic one (yellow)");

	for (int i = 0; i < EmojiSkinTone::COUNT; ++i) {
		skinToneComboBox->addItem (EmojiSkinTone::descriptionString[i], i);
	}

	connect (skinToneComboBox, qOverload<int>(&QComboBox::currentIndexChanged), [this, categoryIdx] (int index) {
		qDebug () << "Set skin tone " << index;
		QVector<Emoji> emojis = EmojiInfo::getAllEmojis (categoryIdx, index);

		for (int i = 0; i < emojis.size(); ++i) {
			if (i >= peopleEmojiButtons.size()) {
				qDebug() << "Emoji index " << i << " exceeds peopleEmojiButtons count" << peopleEmojiButtons.size();
				return;
			}

			peopleEmojiButtons[i]->setText (emojis[i].unicodeString);
		}
	});

	gridLayout->addWidget (skinToneComboBox, 0, 3, 1, 4);
}

} /* namespace Mattermost */


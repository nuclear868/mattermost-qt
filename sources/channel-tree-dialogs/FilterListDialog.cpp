/**
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

#include "FilterListDialog.h"

#include <QDebug>
#include <QMenu>
#include "ui_FilterListDialog.h"

namespace Mattermost {

FilterListDialog::FilterListDialog (QWidget* parent)
:QDialog(parent)
,ui(new Ui::FilterListDialog)
{
	ui->setupUi(this);

	connect (ui->tableWidget, &QWidget::customContextMenuRequested, [this] (const QPoint& pos) {

		QTableWidgetItem* pointedItem = ui->tableWidget->itemAt (pos);

		if (!pointedItem) {
			qDebug() << "No pointed item at " << pos;
			return;
		}

		//only the first item from the row contains a pointer to the item-specific data
		QTableWidgetItem* pointedFirstItem = ui->tableWidget->item (pointedItem->row(), 0);

		if (!pointedFirstItem) {
			qDebug() << "No pointed name item at " << pos;
			return;
		}

		// Create menu and insert some actions
		QMenu menu;

		addContextMenuActions (menu, pointedFirstItem->data (Qt::UserRole));

		if (!menu.isEmpty()) {
			// Handle global position
			QPoint globalPos = ui->tableWidget->mapToGlobal (pos);
			menu.exec (globalPos + QPoint (15, 35));
		}
	});

connect (ui->filterLineEdit, &QLineEdit::textEdited, this, &FilterListDialog::applyFilter);
}

FilterListDialog::~FilterListDialog()
{
    delete ui;
}

void FilterListDialog::create (const FilterListDialogConfig& cfg)
{
	setWindowTitle (cfg.title);
	ui->selectUserLabel->setText(QCoreApplication::translate("FilterListDialog", cfg.description.toStdString().c_str(), nullptr));
	ui->filterUsersLabel->setText (cfg.filterLabelText);

	if (cfg.buttons != 0) {
		ui->buttonBox->setStandardButtons (cfg.buttons);
	}
}

void FilterListDialog::applyFilter (const QString& text)
{
	uint32_t count = 0;

	for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
		QTableWidgetItem* item = ui->tableWidget->item (row, 0);

		if (item->text ().contains(text, Qt::CaseInsensitive)) {
			ui->tableWidget->showRow (row);
			++count;
		} else {
			ui->tableWidget->hideRow (row);
		}
	}

	setItemCountLabel (count);
}


} /* namespace Mattermost */

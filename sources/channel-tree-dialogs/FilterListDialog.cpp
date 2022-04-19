
#include "FilterListDialog.h"
#include "ui_FilterListDialog.h"

namespace Mattermost {

FilterListDialog::FilterListDialog (QWidget* parent)
:QDialog(parent)
,ui(new Ui::FilterListDialog)
{
    ui->setupUi(this);

    connect (ui->treeWidget, &QTreeWidget::customContextMenuRequested, this, &FilterListDialog::showContextMenu);
    connect (ui->filterLineEdit, &QLineEdit::textEdited, this, &FilterListDialog::applyFilter);
}

FilterListDialog::~FilterListDialog()
{
    delete ui;
}

void FilterListDialog::applyFilter (const QString& text)
{
	uint32_t usersCount = 0;

	for (int row = 0; row < ui->treeWidget->topLevelItemCount(); ++row) {
		QTreeWidgetItem* item = ui->treeWidget->topLevelItem (row);

		if (item->text(0).contains(text, Qt::CaseInsensitive)) {
			item->setHidden(false);
			++usersCount;
		} else {
			item->setHidden(true);
		}
	}

	ui->usersCountLabel->setText(QString::number(usersCount) + " users");
}

} /* namespace Mattermost */


#include "NewDirectChannelDialog.h"
#include "ui_NewDirectChannelDialog.h"

#include <set>
#include "backend/types/BackendUser.h"

namespace Mattermost {

auto nameComparator = [] (const BackendUser* const& lhs, const BackendUser* const& rhs)
{
	return lhs->username < rhs->username;
};

NewDirectChannelDialog::NewDirectChannelDialog (const std::map<QString, BackendUser>& users, QWidget *parent)
:QDialog(parent)
,ui(new Ui::NewDirectChannelDialog)
{
    ui->setupUi(this);

    std::set<const BackendUser*, decltype (nameComparator)> set (nameComparator);

    for (auto& it: users) {
    	set.insert (&it.second);
    }

    uint32_t usersCount = 0;
    for (auto& user: set) {
    	QString displayName (user->getDisplayName());

    	if (!user->nickname.isEmpty()) {
    		displayName += " (" + user->nickname + ")";
    	}

    	QListWidgetItem* item = new QListWidgetItem (displayName);
    	QImage img = QImage::fromData (user->avatar);
    	item->setIcon (QIcon(QPixmap::fromImage(QImage::fromData (user->avatar)).scaled(32, 32)));
    	item->setData (Qt::UserRole, QVariant::fromValue ((BackendUser*)user));
    	ui->listWidget->addItem (item);
    	++usersCount;
    }

    ui->usersCountLabel->setText(QString::number(usersCount) + " users");
    connect (ui->filterLineEdit, &QLineEdit::textEdited, this, &NewDirectChannelDialog::applyFilter);
}

NewDirectChannelDialog::~NewDirectChannelDialog()
{
    delete ui;
}

void NewDirectChannelDialog::applyFilter (const QString& text)
{
	uint32_t usersCount = 0;

	for (int row = 0; row < ui->listWidget->count(); ++row) {
		QListWidgetItem* item = ui->listWidget->item(row);

		if (item->text().contains(text, Qt::CaseInsensitive)) {
			item->setHidden(false);
			++usersCount;
		} else {
			item->setHidden(true);
		}
	}

	ui->usersCountLabel->setText(QString::number(usersCount) + " users");
}

const BackendUser* NewDirectChannelDialog::getSelectedUser ()
{
	auto selection = ui->listWidget->selectedItems();

	if (selection.size() == 0) {
		return nullptr;
	}

	return selection.first()->data(Qt::UserRole).value<BackendUser*>();
}

} /* namespace Mattermost */

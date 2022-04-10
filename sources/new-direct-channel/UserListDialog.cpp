
#include "UserListDialog.h"
#include "ui_UserListDialog.h"

#include <set>
#include "backend/types/BackendUser.h"

namespace Mattermost {

auto nameComparator = [] (const BackendUser* const& lhs, const BackendUser* const& rhs)
{
	return lhs->username < rhs->username;
};

UserListDialog::UserListDialog (const std::map<QString, BackendUser>& users, QWidget* parent)
:QDialog(parent)
,ui(new Ui::UserListDialog)
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

    	QTreeWidgetItem* item = new QTreeWidgetItem (ui->treeWidget, QStringList() << displayName << user->status);
    	QImage img = QImage::fromData (user->avatar);
    	item->setIcon (0, QIcon(QPixmap::fromImage(QImage::fromData (user->avatar)).scaled(32, 32)));
    	item->setData (0, Qt::UserRole, QVariant::fromValue ((BackendUser*)user));
    	ui->treeWidget->addTopLevelItem (item);
    	++usersCount;
    }

    ui->treeWidget->header()->setSectionResizeMode (0, QHeaderView::Stretch);
    ui->treeWidget->header()->setSectionResizeMode (1, QHeaderView::ResizeToContents);
    ui->usersCountLabel->setText(QString::number(usersCount) + " users");
    connect (ui->filterLineEdit, &QLineEdit::textEdited, this, &UserListDialog::applyFilter);
}

UserListDialog::UserListDialog (const std::vector<BackendUser*>& users, QWidget *parent)
:QDialog(parent)
,ui(new Ui::UserListDialog)
{
    ui->setupUi(this);

    std::set<const BackendUser*, decltype (nameComparator)> set (nameComparator);

    for (auto& it: users) {
    	set.insert (it);
    }

    uint32_t usersCount = 0;
    for (auto& user: set) {
    	QString displayName (user->getDisplayName());

    	if (!user->nickname.isEmpty()) {
    		displayName += " (" + user->nickname + ")";
    	}

    	QTreeWidgetItem* item = new QTreeWidgetItem (ui->treeWidget, QStringList() << displayName << user->status);
    	QImage img = QImage::fromData (user->avatar);
    	item->setIcon (0, QIcon(QPixmap::fromImage(QImage::fromData (user->avatar)).scaled(32, 32)));
    	item->setData (0, Qt::UserRole, QVariant::fromValue ((BackendUser*)user));
    	ui->treeWidget->addTopLevelItem (item);
    	++usersCount;
    }

    ui->treeWidget->header()->setSectionResizeMode (0, QHeaderView::Stretch);
    ui->treeWidget->header()->setSectionResizeMode (1, QHeaderView::ResizeToContents);
    ui->usersCountLabel->setText(QString::number(usersCount) + " users");
    connect (ui->filterLineEdit, &QLineEdit::textEdited, this, &UserListDialog::applyFilter);
}

UserListDialog::~UserListDialog()
{
    delete ui;
}

void UserListDialog::applyFilter (const QString& text)
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

const BackendUser* UserListDialog::getSelectedUser ()
{
	auto selection = ui->treeWidget->selectedItems();

	if (selection.size() == 0) {
		return nullptr;
	}

	return selection.first()->data(0, Qt::UserRole).value<BackendUser*>();
}

} /* namespace Mattermost */

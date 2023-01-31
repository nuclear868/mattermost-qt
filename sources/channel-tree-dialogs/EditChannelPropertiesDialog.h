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

#ifndef EDITCHANNELPROPERTIESDIALOG_H
#define EDITCHANNELPROPERTIESDIALOG_H

#include <QDialog>
#include "backend/types/BackendChannelProperties.h"
#include "fwd.h"

namespace Ui {
class EditChannelPropertiesDialog;
}

namespace Mattermost {

class EditChannelPropertiesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditChannelPropertiesDialog (const BackendChannel& channel, QWidget *parent = nullptr);
    ~EditChannelPropertiesDialog();
public:
    BackendChannelProperties getNewProperties ();

private:
    Ui::EditChannelPropertiesDialog *ui;
};

} /* namespace Mattermost */

#endif // EDITCHANNELPROPERTIESDIALOG_H

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

#ifndef POSTPOLL_H
#define POSTPOLL_H

#include <QFrame>
#include "fwd.h"

class QPushButton;

namespace Ui {
class PostPoll;
}

namespace Mattermost {

class BackendPoll;

class PostPoll: public QFrame {
    Q_OBJECT
public:
    explicit PostPoll (Backend& backend, const QString& postID, BackendPoll& poll, QWidget *parent = nullptr);
    ~PostPoll();
private:
    Ui::PostPoll*			ui;
public:
    Backend& 				backend;
    const QString&			postID;
    QVector<QPushButton*> 	optionButtons;
    QVector<QPushButton*> 	adminButtons;
};

} /* namespace Mattermost */

#endif // POSTPOLL_H

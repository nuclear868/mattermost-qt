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

#pragma once

#include <QFrame>

namespace Ui {
class PostQuoteFrame;
}

namespace Mattermost {

class BackendPost;
class Storage;
class PostWidget;

class PostQuoteFrame: public QFrame
{
    Q_OBJECT

public:
    explicit PostQuoteFrame (BackendPost& containingPost, const BackendPost& quotedPost, const Storage& storage, PostWidget* parent);
    ~PostQuoteFrame();
public:
    void setHeaderText (const QString& headerText);
signals:
	void postClicked ();
private:
    Ui::PostQuoteFrame *ui;
};

} /* namespace Mattermost */

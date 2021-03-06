/***************************************************************************
 *   Copyright (C) 2011 by Nicolae Ghimbovschi                             *
 *     nicolae.ghimbovschi@gmail.com                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 3 of the License.               *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef PROGBARANDICON_H
#define PROGBARANDICON_H

#include <QTimer>
#include <QMainWindow>
#include "../../src/TaskbarButton.h"

namespace Ui {
    class ProgBarAndIcon;
}

class ProgBarAndIcon : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProgBarAndIcon(QWidget *parent = 0);
    ~ProgBarAndIcon();

protected:
    bool winEvent(MSG * message, long * result);

private:
    int mProgressValue;
    QTimer mTimer;
    Ui::ProgBarAndIcon *ui;
    QW7::TaskbarButton* mTaskbarButton;

private slots:
    void OnTaskbarReady();
    void OnOverlayIconChanged();
    void OnProgressTypeChanged();
    void OnUpdateProgressValue();
};

#endif // PROGBARANDICON_H

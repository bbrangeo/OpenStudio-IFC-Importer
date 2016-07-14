/**********************************************************************
*  Copyright (c) 2008-2015, Alliance for Sustainable Energy.
*  All rights reserved.
*
*  This library is free software; you can redistribute it and/or
*  modify it under the terms of the GNU Lesser General Public
*  License as published by the Free Software Foundation; either
*  version 2.1 of the License, or (at your option) any later version.
*
*  This library is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*  Lesser General Public License for more details.
*
*  You should have received a copy of the GNU Lesser General Public
*  License along with this library; if not, write to the Free Software
*  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**********************************************************************/

#ifndef BIMSERVER_SETTINGSWIDGET_HPP
#define BIMSERVER_SETTINGSWIDGET_HPP

#include "../model/Model.hpp"
#include "../shared_gui_components/OSDialog.hpp"
#include "../openstudio_lib/MainTabView.hpp"
#include "../openstudio_lib/MainTabController.hpp"

#include <QDialog>
#include <QListWidget>
#include <QStatusBar>
#include <QSettings>
#include <QEventLoop>
#include <QCloseEvent>
#include <QKeyEvent>

namespace openstudio {
namespace bimserver {   
    
class SettingsWidget : public QWidget
{
    Q_OBJECT

    public:
    
    SettingsWidget( QWidget * parent = nullptr );

    virtual ~SettingsWidget() {}

    QLineEdit *set_baddEdit;
    QLineEdit *set_bportEdit;
    QLineEdit *set_unameEdit;
    QLineEdit *set_upassEdit;

    QLabel *set_sevStatus;

    signals:

    void reset();
    void finished();
    void updated(QSettings * new_settings);
    void nextTab(int index);

    public slots:

    void okButton_clicked();
    void nextButton_clicked();
    void logoButton_clicked();
    void successStatus();
    void failedStatus();

    private:
    
    QLabel *set_introLabel;
    QLabel *set_baddLabel;
    QLabel *set_bportLabel;
    QLabel *set_unameLabel;
    QLabel *set_upassLabel;
    QLabel *set_logoLabel;

    QSettings   *m_settings;
    QPushButton *set_okButton;
    QPushButton *set_nextButton;   
    QPushButton *set_logoButton;
    //QPushButton *set_cancelButton;
};

} // bimserver
} // openstudio

#endif 
//BIMSERVER_SETTINGSWIDGET_HPP

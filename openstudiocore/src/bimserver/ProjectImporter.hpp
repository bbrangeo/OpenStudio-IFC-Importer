/**********************************************************************
*  Copyright (c) 2008-2016, Alliance for Sustainable Energy.
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

#ifndef BIMSERVER_PROJECTIMPORTER_HPP
#define BIMSERVER_PROJECTIMPORTER_HPP

#include "BIMserverAPI.hpp"
#include "BIMserverConnection.hpp"
#include "IFCTabController.hpp"

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

  class BIMSERVER_API ProjectImporter: public OSDialog
  {
    Q_OBJECT

    public:

    /// Default constructor
    ProjectImporter(QWidget *parent);
    /// Virtual destructor
    ~ProjectImporter();
    /// Start importing IFC workflow
    boost::optional<model::Model> run();
    /// Reimplemented the close event and guide it to the run() function
    void closeEvent(QCloseEvent *event) override;
    /// Reimplemented the key press event of ESC and guide it to the run() function
    void keyPressEvent(QKeyEvent *event) override;

    /// process success cases for createProject, checkInIFC, and login
    void processSucessCases(QString sucessCase);
    /// process all failure cases if BIMserver outputs an exception. Print it 
    void processFailureCases(QString failureCase);
    /// process if BIMserver is not connected.
    void processBIMserverErrors();

    signals:
    /// OSM String is retrieved.
    void finished();

    private:

      QString     m_OSM;
      QString     m_proID;
      QString     m_ifcID;
      QListWidget *m_proList;
      QListWidget *m_ifcList;
      QStatusBar  *m_statusBar;
      QEventLoop  *m_waitForOSM;
      
      QSettings *m_settings;

      QPushButton *m_okButton;
      QPushButton *m_loadButton;
      QPushButton *m_selectButton;

      FilesWidget * m_filesWidget;
      ImportWidget * m_importWidget;
      SettingsWidget * m_settingsWidget;
      ProjectsWidget * m_projectsWidget;
      IFCTabController *m_IFCTabController;  
      BIMserverConnection *m_bimserverConnection;

    private slots:

      void app_ended();
      void okButton_clicked();
      void newButton_clicked();
      void loadButton_clicked();
      void selectButton_clicked();
      void settingButton_clicked(); 
  };

} // bimserver
} // openstudio

#endif 
// BIMSERVER_PROJECTIMPORTER_HPP 

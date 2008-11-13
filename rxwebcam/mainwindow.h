
/**********************************************************                    #
# This program is free software; you can redistribute it and/or modify         #
# it under the terms of the GNU General Public License as published by         #
 # the Free Software Foundation; Licence Version 2 .                           #
#                                                                              #
# This program is distributed in the hope that it will be useful,              #
# but WITHOUT ANY WARRANTY; without even the implied warranty of               #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                #
# GNU General Public License for more details.                                 #
#                                                                              #
# You should have received a copy of the GNU General Public License            #
# along with this program; if not, write to the Free Software                  #
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA    #
#                                                                              #
*******************************************************************************/
#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QWidget>
#include <QStringList>
#include <QMenuBar>
#include <QFileDialog>
#include <QStatusBar>
#include <QDir>
#include <QFileInfo>

#define VERSION "0.1beta"

#include "RxPluginManager.h"
#include "OpenDeviceImp.h"
#include "FormStreamingImp.h"
#include "ConfigPluginsImp.h"


class RxWebcamMain : public QMainWindow
{
   Q_OBJECT
 public:

   RxWebcamMain(QWidget *parent=0);
   
   void createPluginsMenu();
   void createMenus();
   void createStatusBar();
   void buildModes( const QString maxMode );
    
 protected slots:
   void openDevice();
   void setSize(QAction *ob);
   void newSize( QSize);
   void setStatus( const QString &msg );
   void pmenuSlot( QAction *act );
   void configPlugins();
   void setSafeMode();
   void showFps();
   void about();
   void aboutQt();
 private:
   FormStreamingImp *FSI;
   QStringList modes;
   QMenu *modos;
   QMenu *plugins;

};

#endif

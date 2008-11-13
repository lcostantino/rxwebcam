
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
#include "mainwindow.h"

RxWebcamMain::RxWebcamMain(QWidget *parent): QMainWindow(parent)
{
   FSI = NULL;
   FSI = new FormStreamingImp();
   setCentralWidget(FSI);
   connect( FSI, SIGNAL(newSize(QSize )),SLOT( newSize(QSize )));
   connect( FSI, SIGNAL(setStatus(QString )),SLOT( setStatus( QString )));
   modes << "160x120" << "320x240" << "640x480";
   setWindowTitle("RxWebcam");
   createMenus();
   createStatusBar();

   PluginManager->setDir("/usr/share/rxwebcam/plugins/binary/");
   if( !PluginManager->loadPlugins())
     QMessageBox::information(0,tr("Atencion"),tr("El directorio de plugins no fue encontrado"));

   createPluginsMenu();
}

void RxWebcamMain::createPluginsMenu()
{

   plugins->addAction(tr("Configuracion"), this, SLOT( configPlugins()));
   plugins->addSeparator();
   
   #ifdef MANT
   QAction *safe = new QAction(tr("Modo \"Seguro\" ( mas lento )"),this);
   connect(safe, SIGNAL( triggered() ), SLOT( setSafeMode()));
   safe->setCheckable(true);
   plugins->addAction(safe);
   #endif
   foreach( QString pname, PluginManager->pluginNames())
     {
	QMenu *pmenu =  plugins->addMenu(pname);
	QAction *enableAction = new QAction(tr("Habilitar"),this);
	enableAction->setCheckable(true);
	enableAction->setData( pname );
	pmenu->addAction(enableAction);
	QAction *configAction = new QAction(tr("Configurar"),this);
	configAction->setData(pname);
	pmenu->addAction( configAction );
	connect( pmenu, SIGNAL( triggered( QAction *)), SLOT( pmenuSlot( QAction *)));
     }
}

void RxWebcamMain::createMenus()
{
   QAction *openDev = new QAction(tr("Abrir dispositivo"),this);
   connect(openDev,SIGNAL(triggered()),SLOT(openDevice()));

   QMenu *fileMenu = menuBar()->addMenu(tr("&Archivo"));
   fileMenu->addAction(openDev);
   QAction *showFps = new QAction(tr("Mostrar FPS"),this);
   showFps->setCheckable(true);
   connect( showFps, SIGNAL( triggered() ), this,SLOT( showFps() ) );
   fileMenu->addAction(showFps);
   fileMenu->addAction( tr("Configuracion Webcam"), FSI, SLOT( showWebcamController())  );
   fileMenu->addAction( tr("Salir"), this, SLOT(close()));
   modos = menuBar()->addMenu(tr("Modos"));
   modos->addSeparator();
   connect(modos, SIGNAL( triggered(QAction *)), SLOT( setSize( QAction *)));
   plugins = menuBar()->addMenu(tr("Plugins"));
   QMenu *about = menuBar()->addMenu(tr("A&yuda"));
   about->addAction(tr("&Acerca de"),this,SLOT( about()));
   about->addAction(tr("QT Libs"),this,SLOT( aboutQt()));
}
void RxWebcamMain::createStatusBar()
{
   statusBar()->showMessage(tr("Listo"));
}

void RxWebcamMain::buildModes( const QString maxMode )
{
   modos->clear();
   foreach( QString size, modes)
     {
	modos->addAction(size);
	if( maxMode == size )
	  return;
     }
}

void RxWebcamMain::openDevice()
{
   QDir devices_dir("/dev/","video[0-9]*");
   QString last_device;
   OpenDeviceImp ODI;
   FSI->closeDevice();
   Webcam *current_dev = FSI->getWebcam();
   V4L2WebcamInfo *ptr=NULL;

   last_device = current_dev->devName();

   devices_dir.setFilter(QDir::System);

   if( !devices_dir.exists() )
     {
	QMessageBox::information(0,"Error",tr("El directorio /dev no existe"));
	return;
     }

   QFileInfoList list_files = devices_dir.entryInfoList();
   foreach( QFileInfo dev_name, list_files )
     {
	if( current_dev)
	  {
	     ptr = current_dev->openAndGatherInfoFrom(dev_name.absoluteFilePath());
	     if( ptr ) ODI.addDeviceInfo(dev_name.absoluteFilePath(),ptr->dump(),ptr->getSize());
	     current_dev->close_device(); //no stream at all, go direct
	  }
     }
   if( ODI.numDevices() <= 0 )
     {
	QMessageBox::information(0,"Error","No se ha encontrado ningun dispositivo de captura compatible\nLa aplicacion sera finalizada");
	exit(0);
     }
   if( ODI.exec() == QDialog::Accepted )
     {
	//recrear el menu de sizes aca
	FSI->setWebcamDevice( ODI.selectedDevice(),ODI.selectedSize() );
	buildModes( QString("%1x%2").arg(ODI.selectedSize().width()).arg(ODI.selectedSize().height()));
     }
   else
     {
	if( last_device.isEmpty() )
	  {
	     QMessageBox::information(0,"Error",tr("NO ha seleccionado ninguna webcam") );
	     current_dev->setDevice("");
	     FSI->setEnabled(false);
	     return;

	  }
	else
	  {
	     FSI->setWebcamDevice( ODI.selectedDevice(),ODI.selectedSize() );
	     buildModes( QString("%1x%2").arg(ODI.selectedSize().width()).arg(ODI.selectedSize().height()));
	  }

     }

   FSI->setEnabled(true);
}

void RxWebcamMain::setSize(QAction *ob)
{
   QStringList size = ob->text().split("x");

   if( !FSI->switchResolution( size[0].toInt(),size[1].toInt()))
     {
	QMessageBox::information(0,tr("Error"),tr("Error cambian la resolucion"));
	return;
     }
   qDebug("Resolution Switched to %s\n",qPrintable(ob->text()));

}

void RxWebcamMain::newSize( QSize ss)
{
   updateGeometry();
   adjustSize();
   setFixedSize( size() );
}
void RxWebcamMain::setStatus( const QString &msg )
{
   statusBar()->showMessage(msg);
}

void RxWebcamMain::pmenuSlot( QAction *act )
{
   Q_ASSERT( act != NULL );
   QMenu *parent = act->menu();
   
   /* Be aware that the name of the plugin should be already translated here. Else, implement some kind of id here */
   if( act->isCheckable() )
     {
	if( ! PluginManager->setPluginState(act->data().toString(),act->isChecked()) )
	  {
	     QMessageBox::information(this,tr("Error"),QString(tr("El plugin reporto un error: %1").arg(PluginManager->getLastError())));
	     act->setChecked(false);
	  }

     }
   else
     PluginManager->showConfig( act->data().toString(),this);
}

void RxWebcamMain::configPlugins()
{
   ConfigPluginsImp *CPI = new ConfigPluginsImp(PluginManager->pluginNames(),this);
   Q_ASSERT(CPI != NULL);
   CPI->exec();
   delete CPI;

}

void RxWebcamMain::setSafeMode()
{
   FSI->toggleSafeMode();
}
void RxWebcamMain::showFps()
{
   FSI->toggleShowFps();
}
void RxWebcamMain::about()
{
   QMessageBox::about( this, "About", QString("<b>RxWebcam %1</b>. Test application for v4l2 webcam drivers. \
					       Some plugins provided as example. \
                                               Work based on svv , luvcview and others from linuxtv.org. \
					       Pixart SRL ").arg(VERSION));
}


void RxWebcamMain::aboutQt()
{
   QMessageBox::aboutQt(this,"QT Lib");
}



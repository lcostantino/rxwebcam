
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
#include "plugin_photo_server.h"
#include "ui_interfaces/ConfigPluginImp.h"
#include <QTcpServer>
#include <QDataStream>

PhotoServer::PhotoServer()
{
	_author = " Costantino Leandro <le_costantino<at>pixartargentina.com.ar>";
	_version = 1.0;
	_name = "Photo Server";
        _description = QObject::tr("Plugin de Ejemplo: Muestra snapshots mediante un simple servidor");
	_datadir = "photo_server"; //internal dir
	_msec_update = 2000;
}

/* This example plugin, do not do "anything" on the qimage , just copy the data */
void PhotoServer::processImage( QImage *s, QWidget *parent)
{
   if( _update_timer.elapsed() >=  _msec_update )
     {
         _server.shareData(s);
	_update_timer.restart();
     }
}

QImage PhotoServer::processImage( QImage &img )
{
   if( _update_timer.elapsed() >=  _msec_update )
     {
         _server.shareData(&img);
	_update_timer.restart();
     }
   return img;
} 


QWidget * PhotoServer::configPlugin(QWidget *parent)
{

   ConfigPluginImp *CPI = new ConfigPluginImp(QString("%1/%2/").arg(PLUGIN_DIR).arg(_datadir),parent);
   
   if( CPI == NULL )
      return NULL;
   CPI->setCurrentValues( _server.getIp(),_server.getPort(),_msec_update );   
   if( CPI->exec() == QDialog::Accepted )
     {
	/* a msg box shouldn't be here, but lets reuse the CPI before deletion */
	 if( _server.setConfig( CPI->getIp(), CPI->getPort()) == false )
	   QMessageBox::information(CPI,tr("Server Error. Verifique la configuracion"), _server.getError());
	 else	
	  _msec_update = CPI->getSeconds() * 1000;
     }

   delete CPI;
   
   return NULL;
   
}

const bool PhotoServer::start()
{
   _update_timer.start();
   if( ! _server.start() )
    {
       _error = _server.getError();
       return false;
    }
   
   return true;
}

const bool PhotoServer::stop()
{
  return _server.stop();
}


Q_EXPORT_PLUGIN2(plugin_photo_server,PhotoServer);


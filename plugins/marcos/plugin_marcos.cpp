
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
#include "plugin_marcos.h"
#include <QPainter>
#include "ui_interfaces/ConfigPluginImp.h"

Marcos::Marcos()
{
   _author = "Costantino Leandro <le_costantino<at>pixartargentina.com.ar>";
   _version = 1.0;
   _name = "Marcos";
   _description = QObject::tr("Permite poner borders a la imagen");
   _datadir = "marcos"; //internal dir
   current_frame_file = NULL;
}

/* current_frame_file should be checked by caller */
void Marcos::checkSize( const QSize &source )
{
   /* this could be done once, and be notified when size change.
    *  should me moved later */
   if( source != current_frame_file->size() )
     {
	QImage copy = current_frame_file->scaled(  source, Qt::IgnoreAspectRatio );
	delete current_frame_file;
	current_frame_file = new QImage(copy);
     }
}

void Marcos::processImage( QImage *source, QWidget *parent)
{
   QPainter p(source);
  
   if( current_frame_file == NULL || source == NULL )
     return;
   
     checkSize( source->size() );
   /* Composition modes , is not really needed since we are using alpha c on the frames */
     p.drawImage(0,0 ,*current_frame_file);
}

QImage Marcos::processImage( QImage &set )
{
  qDebug("Not supported in safe mode");
  return set;
}

QWidget * Marcos::configPlugin(QWidget *parent)
{
   ConfigPluginImp *CPI = new ConfigPluginImp(QString("%1/%2/images/").arg(PLUGIN_DIR).arg(_datadir),parent);
   if( CPI->exec() == QDialog::Accepted )
     {
	if( NULL != current_frame_file )
	  {
	     delete current_frame_file;
	     current_frame_file = NULL;
	  }
	if( !CPI->selectedFile().isEmpty() )
	  {
	     /* should we check if was really loaded? */
	     current_frame_file = new QImage( CPI->selectedFile() ); 
	  }
     }
   delete CPI;
   return NULL;
}

Marcos::~Marcos()
{
   if( NULL != current_frame_file )
     delete current_frame_file;
}

Q_EXPORT_PLUGIN2(pnp_marcos,Marcos);


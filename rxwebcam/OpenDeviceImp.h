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
#include "ui_opendevice.h"
#include <QListWidget>
#include <QListWidgetItem>

/* Simple dialog to open a webcam device and pass info to WebcamDevice */
class OpenDeviceImp : public QDialog, private Ui::OpenDevice
{
 public:
   OpenDeviceImp( QWidget * parent = 0 ) : QDialog( parent)
     {
	setupUi( this);

     }

   void addDeviceInfo( const QString &device , const QString  &data, const QSize &maxResolution )
     {
	QListWidgetItem *ndevice =  new QListWidgetItem( QIcon(":/proyect/qt4/iconos/webcam.png"),data, lw_devices);
	Q_ASSERT( ndevice != NULL );
	ndevice->setData( Qt::UserRole, device );
	lw_devices->setCurrentItem(ndevice);
	ndevice->setData( Qt::UserRole + 1, maxResolution);
     }

   const int numDevices()
     {
	return lw_devices->count();
     }
   const QSize selectedSize()
     {
	QListWidgetItem * actual = lw_devices->currentItem();
	if( actual == NULL )
	  return QSize();

	return actual->data( Qt::UserRole + 1 ).toSize();
     }

   const QString selectedDevice()
     {
	QListWidgetItem * actual = lw_devices->currentItem();
	if( actual == NULL )
	  return QString();

	return actual->data( Qt::UserRole ).toString();
     }

};

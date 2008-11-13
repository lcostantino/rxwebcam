
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
#include "ConfigPluginImp.h"
#include <QWidget>
#include <QListWidget>
#include <QDir>
#include <QFileInfo>
#include <QDialog>
#include <QStringList>
#include <QIcon>
#include <QMessageBox>
#include <QInputDialog>

#include "effect.h"

ConfigPluginImp::ConfigPluginImp(const QString & imagesDir,QWidget *parent):QDialog(parent)
{
   setupUi(this);
   lw_effects->setIconSize(QSize(100,100));
   connect( lw_effects,SIGNAL( itemClicked( QListWidgetItem *)), SLOT( effectActivated( QListWidgetItem *)));
   _working_dir = imagesDir;
}

void ConfigPluginImp::fillEffects()
{
   lw_effects->clear();

   foreach( Effect *xeffect, *_effect_list )
     {
	/* search the icon/image based on effect id, and data_dir */
	QListWidgetItem *xitem = new QListWidgetItem( QIcon(QPixmap(_working_dir+QString("/%1").arg(xeffect->id()))),
						      xeffect->name(),lw_effects);
	if( NULL != xitem)
	{ 
	   xitem->setData(Qt::UserRole, xeffect->id());
	   if( xeffect->enabled() )
	      xitem->setSelected(true);
	}
     }
}

const QString  ConfigPluginImp::selectedFile()
{
   if( lw_effects->currentItem() != NULL )
     {
	/* this could go inside a variant data too, instead of using the "name"
	 * "Ninguno" = "None" */
	return ( lw_effects->currentItem()->text() == tr("Ninguno")) ?
	  QString() :  QString("%1/%2").arg(_working_dir).arg(lw_effects->currentItem()->text());
     }

   return QString();
}

void ConfigPluginImp::setEffectList( QList< Effect *> *effects )
{
   _effect_list = effects;
   Q_ASSERT( _effect_list != NULL );

   fillEffects();
}

void ConfigPluginImp::findAndSetEffect( int id, bool enabled )
{
   qDebug("Item: %d  enabled -> (%d)\n",id,enabled);
   foreach( Effect *xeffect, *_effect_list)
     {
	if( xeffect->id() == id )
	  {
	     xeffect->setEnabled(enabled);
	     if( enabled )
	       {
		  xeffect->showInputDialog(this);
	       }
	  }
     }
}

void ConfigPluginImp::effectActivated( QListWidgetItem *item )
{

   if( !item || ( item && !lw_effects->isItemSelected(item)) )
     return;

   findAndSetEffect( item->data(Qt::UserRole).toInt(), true );
}

void ConfigPluginImp::accept()
{
   int i;
   QListWidgetItem *xitem;

   for( i =0; i < lw_effects->count();i++)
     {
	xitem = lw_effects->item(i);
	if( xitem &&  !lw_effects->isItemSelected(xitem))
	  {
	     findAndSetEffect( xitem->data(Qt::UserRole).toInt(),false);

	  }
     }

   QDialog::accept();
}


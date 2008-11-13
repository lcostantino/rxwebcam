
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

ConfigPluginImp::ConfigPluginImp(const QString & imagesDir,QWidget *parent)
  :QDialog(parent)
{
   setupUi(this);
   lw_frames->setIconSize(QSize(100,100));
   _working_dir = imagesDir;
   fillFrameFiles();
}

void ConfigPluginImp::fillFrameFiles()
{
   QDir dir(_working_dir);
   lw_frames->clear();
   if( !dir.exists())
     {
	QMessageBox::information(0,tr("Error"),tr("Directorio inexistente"));
	reject();
     }
   new QListWidgetItem( QIcon(QPixmap()), tr("Ninguno"),lw_frames);
   QFileInfoList list_files = dir.entryInfoList(QStringList()<< "*.jpg" << "*.png" );

   foreach( QFileInfo file_info, list_files )
	new QListWidgetItem( QIcon(file_info.absoluteFilePath()), file_info.fileName(),lw_frames);
}

const QString  ConfigPluginImp::selectedFile()
{
   if( lw_frames->currentItem() != NULL )
     {
	/* this could go inside a variant data too, instead of using the "name" */
	return ( lw_frames->currentItem()->text() == tr("Ninguno")) ?
	  QString() :  QString("%1/%2").arg(_working_dir).arg(lw_frames->currentItem()->text());
     }

   return QString();
}

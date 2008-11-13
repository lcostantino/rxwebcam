
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
#include "ui_configplugin.h"
class QWidget;
class QListWidget;
class QListWidgetItem;

class QString;
class QDialog;

#include <QList>



class ConfigPluginImp : public QDialog , private Ui::ConfigPlugin
{
   Q_OBJECT
   
 public:
   ConfigPluginImp(const QString & imagesDir,QWidget *parent=0);

   const QString  selectedFile();
   
 
   const int getPort(){ return sb_port->value(); }
   const QString getIp(){ return ( le_ip->isEnabled() == true ) ? le_ip->text() : "000.000.000.000"; };
   const int getSeconds(){ return sb_seconds->value(); }	
   void setCurrentValues( const QString &ip, const int port, const int msecs );
   
	
 protected slots:
    void accept();
    void stateIpChanged( int );
 private:
   QString _working_dir;
 
}
;



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

#include "ui_configplugins.h"
#include <QDialog>
#include <QMessageBox>
#include "RxPluginManager.h"

/* Dialog for plugin configuration */
class ConfigPluginsImp : public QDialog , private Ui::ConfigPlugins
{
   Q_OBJECT
 public:
   ConfigPluginsImp( const QStringList &names, QWidget *parent=0);
   void clear();

 protected slots:
   void pluginChange( const QString &pname);
   void enablePlugin(int state );
   void configPlugin();
   
 private:
   RxWebcamInterface *xplugin;

};

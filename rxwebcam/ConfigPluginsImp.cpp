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

#include "ConfigPluginsImp.h"

ConfigPluginsImp::ConfigPluginsImp( const QStringList &names, QWidget *parent):QDialog(parent)
{
   setupUi(this);
   xplugin = NULL;
   lb_pluginList->addItems(names);
   connect(lb_pluginList, SIGNAL( highlighted(const QString &)), SLOT( pluginChange( const QString & )));
   connect(lb_pluginList, SIGNAL( currentIndexChanged(const QString &)), SLOT( pluginChange( const QString & )));
   
   connect(cb_enablePlugin, SIGNAL (stateChanged(int ) ), SLOT( enablePlugin(int ) ) );
   connect(pb_configurePlugin, SIGNAL( clicked() ), SLOT( configPlugin()));
   pluginChange( lb_pluginList->currentText());
  
   
}
void ConfigPluginsImp::clear()
{
   te_infoPlugin->clear();
   tl_pluginPreview->clear();
   fr_actions->setEnabled(false);
}

void ConfigPluginsImp::pluginChange( const QString &pname)
{

   clear();
   //just to avoid wrapping all the data..
   xplugin = PluginManager->getPlugin(pname);
   if( NULL == xplugin )
     {
	QMessageBox::information(0,tr("Error"),tr("El plugin no pudo ser adquirido"));
	return;
     }

   QString infoPluginHtml = QString("<html><body><table border=1>");
   infoPluginHtml += "<tr><td>" + tr("Author") + ":</td><td>" + xplugin->author() + "</td></tr>";
   infoPluginHtml += "<tr><td>" + tr("Version") + "</td><td>" + QString::number(xplugin->version()) + "</td></tr>";
   infoPluginHtml += "<tr><td>" + tr("Descripcion:") + "</td><td>" + xplugin->description() + "</td></tr>";
   infoPluginHtml += "</table></body></html>";

   cb_enablePlugin->setChecked( xplugin->enabled());
   te_infoPlugin->setHtml(infoPluginHtml);
   tl_pluginPreview->setPixmap( QString("%1/%2/preview.png").arg( PLUGIN_DIR).arg( xplugin->dataDir()));
   fr_actions->setEnabled(true);

}

void ConfigPluginsImp::enablePlugin(int state )
{
   if( NULL != xplugin )
	PluginManager->setPluginState( xplugin, state);
}

void ConfigPluginsImp::configPlugin()
{
   if( NULL != xplugin )
     xplugin->configPlugin(this);
}


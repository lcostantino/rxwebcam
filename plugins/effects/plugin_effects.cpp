
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
#include "plugin_effects.h"
#include <QPainter>
#include "ui_interfaces/ConfigPluginImp.h"

Effects::Effects()
{
   _author = " Costantino Leandro <le_costantino<at>pixartargentina.com.ar>";
   _version = 1.0;
   _name = "Effects";
   _description = QObject::tr("Algunos efectos de imagen");
   _datadir = "effects"; /* internal data dir name, keep images, data, etc in /usr/share/..*/

   effects_list.append( new BlackAndWhite);
   effects_list.append( new HMirror);
   effects_list.append( new VMirror);
   effects_list.append( new Rotate );
}

void Effects::processImage( QImage *s, QWidget *parent)
{
   if( !s )
     return;

   foreach( Effect *xeffect, effects_list)
     {
	if( xeffect->enabled() )
	  xeffect->applyEffect(s);
     }
}

QImage Effects::processImage( QImage &img ) 
{
   foreach( Effect *xeffect, effects_list)
     {
	if( xeffect->enabled() )
	  img = xeffect->applyEffect(img);
     }

   return img;
}

QWidget * Effects::configPlugin(QWidget *parent)
{

   ConfigPluginImp *CPI = new ConfigPluginImp(QString("%1/%2/").arg(PLUGIN_DIR).arg(_datadir),parent);
   
   if( CPI == 0 )
      return NULL;
   
   CPI->setEffectList(&effects_list);
   CPI->exec();
     
   delete CPI;

   return NULL;
}

Q_EXPORT_PLUGIN2(plugin_effects,Effects);


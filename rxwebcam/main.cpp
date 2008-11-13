
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
#include <QApplication>
#include <QTranslator>
#include "mainwindow.h"

void loadLocales( QString locale_name)
{
   
   QDir locale_dir("/usr/share/rxwebcam/locales/" + locale_name );

/* Just in case, to allow in some future utf-8 and not on the same dir.
   Currently use only the available ones  */
   if( !locale_dir.exists() )
   {
        locale_dir = QDir("/usr/share/rxwebcam/locales/" + ( locale_name.contains("UTF-8") ?
                                                             locale_name.remove(".UTF-8") :
                                                                locale_name + ".UTF-8" ) );

      qDebug("Alternative Locale: %s\n",qPrintable( locale_dir.dirName() ) );
   }
   if( !locale_dir.exists() )
     {
	
	fprintf(stderr,"Locale dir not found /usr/share/rxwebcam/locales/%s\n",qPrintable(locale_name));
     	return;
     }
   locale_dir.setNameFilters( QStringList() << "*.qm");
   QFileInfoList list_files = locale_dir.entryInfoList();
   foreach( QFileInfo ts_name, list_files ) {
	
	QTranslator *appTrans = new QTranslator;
	
   	if( appTrans->load(ts_name.absoluteFilePath())) {
	   qDebug("Loading: %s\n",qPrintable(ts_name.absoluteFilePath()));
	   qApp->installTranslator(appTrans);	
	}
   }
}

int main(int argc, char *argv[])
{
   QApplication qa(argc,argv);
  
   QObject::connect( &qa, SIGNAL( lastWindowClosed() ), &qa, SLOT(quit()));
   if( argc > 1 && strlen(argv[1]) < 20)
     loadLocales(argv[1]);
   else  
     loadLocales(QLocale::system().name());

   RxWebcamMain rxm;
   rxm.show();
   return qa.exec();
   
}

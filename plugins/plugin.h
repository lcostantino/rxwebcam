
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
#ifndef PLUGIN_H
# define PLUGIN_H

# include <QImage>
# include <QObject>
# include <QWidget>
# include <QString>
# include <QtCore/qplugin.h>

# ifdef QT_NO_DEBUG
#  define DBG( fmt, args... ) while(0){}
# else
#  define DBG( fmt , args... ) fprintf(stderr, fmt, ## args )
# endif

# define PLUGIN_DIR "/usr/share/rxwebcam/plugins/"

class RxWebcamInterface
{
 public:

   virtual    ~RxWebcamInterface(){}
   /* Process image, called from Plugin Manager */
   virtual void processImage( QImage *, QWidget *parent=0)=0;
   virtual QImage processImage( QImage & )=0;
   /* QWidget for configure plugin settings */
   virtual QWidget * configPlugin(QWidget *parent=0)=0;

   const QString & name(){ return _name; }
   const float version() { return _version; }
   void setEnabled(bool state){ _enable = state;}
   const bool enabled(){ return _enable;}
   /* Called on enable / disable plugin */
   virtual const bool start()=0;
   virtual const bool stop()=0;

   const QString & author(){ return _author;}
   const QString & description(){ return _description;}
   const QString & dataDir() { return _datadir;}
   const QString error(){ return _error;}

 protected:
   QString _name,_author,_description,_datadir;
   float _version;
   bool _enable;
   QString _error;
}
;

Q_DECLARE_INTERFACE(RxWebcamInterface,"com.trolltech.RxWebcamInterface/1.0");
#endif

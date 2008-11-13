

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
#include "plugin.h"
#include <QByteArray>
#include <QTime>
#include <QMessageBox>
#include "simple_server.h"

/* This is just a simple server model for plugin example.*/

class PhotoServer :  public QObject, public RxWebcamInterface
{
   Q_OBJECT
   Q_INTERFACES( RxWebcamInterface);

 public:
   PhotoServer();
   QImage processImage( QImage & );
   void processImage( QImage *s, QWidget *parent=0);

   QWidget * configPlugin(QWidget *parent=0);

   const bool start();
   const bool stop();

   ~PhotoServer(){}

 private:
   SimpleServer _server;
   QTime _update_timer;
   int _msec_update;
   QByteArray data;

}
;

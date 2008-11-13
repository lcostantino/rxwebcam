
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
#ifndef THREAD_SERVER_H
# define THREAD_SERVER_H
# include <QThread>
# include <QTcpSocket>
# include <QBuffer>
# include <QByteArray>
# include <QHttpResponseHeader>
# include <QDateTime>
#include <QImage>

/* Actually, Keep-Alive is not being used.
 * Could be implemented later, is easy and its almost there.. */

class PhotoClient : public QThread
{
 public:
   PhotoClient(int socketDesc, QImage ptrBlock,const QString & last_update ,QObject *parent);

   const QByteArray header( const QString &type="image/png", bool close=true);
   void run();
   
 private:
   int socket_fd;
   QImage temp_data; //image data
   QString _last_update;
   QByteArray image_data; //array data
}
;
#endif

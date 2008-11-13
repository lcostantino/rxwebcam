
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
#ifndef SIMPLE_SERVER
# define SIMPLE_SERVER
# include <QtNetwork>
# include <QMutex>

# include <QImage>
# include "thread_server.h"

class QTcpSocket;

/* Simple server, taken from  Fortune Server From Qt4 docs , for example purpose
   This should be recoded for a real application */

class SimpleServer : public QTcpServer
{
 public:

   SimpleServer(const QString server_ip="000.000.000.000",const int server_port = 6050);
   bool setConfig( const QString &server_ip, const int server_port );

   const QString getIp();
   const int getPort();

   const QString getError() ;
   const bool start();
   const bool stop();
   void shareData( QImage *img);

 protected:
   void incomingConnection( int sockfd );

 private:
   QMutex locked;
   QByteArray send_data;
   QString last_update;
   QString ip;
   int port;
   QImage current_data;
};
#endif

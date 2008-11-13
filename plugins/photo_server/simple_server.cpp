
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
#include "simple_server.h"

SimpleServer::SimpleServer(const QString server_ip,const int server_port):QTcpServer(),
ip(server_ip),port(server_port)
{
}

bool SimpleServer::setConfig( const QString &server_ip, const int server_port )
{
   ip = server_ip;
   port = server_port;

   if( isListening() )
     {
	stop();
	return start();
     }
   return true;
}
const QString SimpleServer::getError() { return errorString();}

const QString SimpleServer::getIp(){ return ip;  }
const int SimpleServer::getPort() { return port; }

const bool SimpleServer::start()
{
   return 	listen(QHostAddress(ip),port);
}

const bool SimpleServer::stop()
{
   close();
   return true;
}

   /* The "mutex" is just for testing purpose, wont hurt..., since the qbytearray could be cloned (is not..)
      and destroyed on each thread, dont care rigth now. */

void SimpleServer::shareData( QImage *img)
{
   qDebug("Sharing Data. Lock\n");
   locked.lock();
   current_data = QImage(*img);
   last_update = QDateTime::currentDateTime().toString(); 
   locked.unlock();
}

void SimpleServer::incomingConnection( int sockfd )
{

   qDebug("Go on.\n");
//warn lock?
   PhotoClient *thread =  new PhotoClient( sockfd, current_data,last_update,this);
   connect(thread, SIGNAL( finished() ), thread, SLOT( deleteLater()));
   thread->start();
}


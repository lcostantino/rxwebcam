
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
#include "thread_server.h"

PhotoClient::PhotoClient(int socketDesc, QImage ptrBlock,const QString & last_update ,QObject *parent):QThread(parent)
{
   socket_fd = socketDesc;
   temp_data = ptrBlock;
   _last_update = last_update;
}

const QByteArray PhotoClient::header( const QString &type, bool close)
{
   QHttpResponseHeader header(200,"OK");
   header.setValue("Last Modified", QDateTime::currentDateTime().toString() );
   header.setContentType(type);

   if( close == true )
     header.setValue("Connection","closed");
   else {
	header.setValue("Keep-Alive","timeout=5, max=100");
	header.setValue("Connection","keep-alive");
    }

   if( type == "image/png" )
   {
      header.setContentLength( image_data.size() );
   }
   
   return  header.toString().toAscii();
}

void PhotoClient::run()
{
   QTcpSocket sock;
   
   if( sock.setSocketDescriptor( socket_fd ) )
     {
	/* the if could be removed later on keep alive */
	sock.waitForReadyRead(1000);
	if( sock.read(40).contains("/rand.png"))
	  {
	     /* Save the buffer as png for network transfer on this place. 
	      * This is needed on this example, because doing it on the server will slow a lot the streaming
	      * on picture update since its running on the same thread */
             QBuffer bf(&image_data);
             bf.open( QIODevice::WriteOnly);
             temp_data.save(&bf,"PNG");
	     sock.write( header("image/png",true) );
	     sock.write(image_data);
	  }
	else
	  {
	     sock.write( header("text/html",true));
	     sock.write(QString("<html><title>RxWebcam</title> \
                                 <meta http-equiv=\"refresh\" content=\"2\" \
				 <body> \
				 <table align=center><tr><td><img src=rand.png></td></tr> \
                                 <tr><td>Last Update: %1</td></tr></table></body></html>\n").arg(_last_update).toAscii());
	  }

	sock.disconnectFromHost();
	sock.waitForDisconnected();
     }
}



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

#include <v4l2wrap/grabinputmanager.h>

V4L2GrabImageManager::V4L2GrabImageManager( V4L2Cmd &refControl)
{
	current_io="mmap";
	grabbers["read"]=new ReadInputMode( refControl );
	grabbers["mmap"]=new MmapInputMode( refControl );
	grabbers["iouser"]=new UserPointerInputMode( refControl );

}


V4L2GrabImageManager::~V4L2GrabImageManager()
{
   delete grabbers["read"];
   delete grabbers["mmap"];
   delete grabbers["iouser"];
   
}

void V4L2GrabImageManager::setIO( const QString &cio)
     {
	if( grabbers.contains(cio) )
	  current_io = cio;
	else
	  current_io = "read";
	qDebug("Current IO: %s\n",qPrintable(current_io));
     }

bool V4L2GrabImageManager::initMode(quint32 sizeImage)
     {
	Q_ASSERT( grabbers[current_io] != NULL );
	return grabbers[current_io]->init(sizeImage);
     }
bool V4L2GrabImageManager::cleanup()
     {
	Q_ASSERT( grabbers[current_io] != NULL );
	return grabbers[current_io]->cleanup();

     }

bool V4L2GrabImageManager::startCapture()
     {
	Q_ASSERT( grabbers[current_io] != NULL );
	return grabbers[current_io]->start();
     }

bool V4L2GrabImageManager::stopCapture()
     {
	Q_ASSERT( grabbers[current_io] != NULL );
	return grabbers[current_io]->stop();
     }

int V4L2GrabImageManager::readFrame()
     {
	Q_ASSERT( grabbers[current_io] != NULL );
	return grabbers[current_io]->readFrame();
     }


int V4L2GrabImageManager::frameSize(){ 	return grabbers[current_io]->current_frame_len;}
unsigned char * V4L2GrabImageManager::frameData(){ 	return grabbers[current_io]->current_frame;}
const QString & V4L2GrabImageManager::currentIO(){ return current_io;}

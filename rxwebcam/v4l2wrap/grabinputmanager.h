/* Most of this coded is based on the Simple Viewer by
 * Moine Jeaf Francois ( gspca2 mantainer )
 *									       */  
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

#ifndef GRAB_INPUT_MANAGER_H
#define GRAB_INPUT_MANAGER_H
class V4L2Cmd;

#include <QMap>
#include <QString>
#include <v4l2wrap/grabinputmodes.h> //class GrabInputMode; let it be for inclusion

/* This class handle the grab methods 
 * Read / MMAP / UserPointer */
class V4L2GrabImageManager
{
 public:
   V4L2GrabImageManager( V4L2Cmd &refControl);
   void setIO( const QString &cio);

   bool initMode(unsigned int sizeImage);
   bool cleanup();
   bool startCapture();
   bool stopCapture();
   int readFrame();

   int frameSize();
   unsigned char * frameData();
   const QString & currentIO();

   ~V4L2GrabImageManager();
 private:
   QMap< QString , GrabInputMode *> grabbers;
   QString current_io;

};


#endif

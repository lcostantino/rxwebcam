/* 
 *  This code is purely based on C code from LUVCVIEW and may be obsolete.
    take a look at v4l2ctrl app from LinuxTv.org for a better approach
 * 
 *  (c) 2008 Costantino Leandro 
 *  (c) 2005 2006 Laurent Pinchar && Michel Xhaard (gspca)
 * */

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

/* This is just C code in a C++ class for fast use. I repeat, C in C++, not C++.
 *
 * Made Qobject to emit signals for easy control creation, (and to avoid another class, and list<..> to return,etc)
 */
#ifndef V4L2UVC_H
#define V4L2UVC_H

/* from svv.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <fcntl.h>              /* low-level i/o */
#include <unistd.h>
#include <errno.h>
#include <malloc.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <asm/types.h>          /* for videodev2.h */
#include "libv4lconvert.h"

#include <QObject>
#include <QString>
#include <QByteArray>
# include  "Error.h"

#define uint unsigned int 
#define errno_exit( MSG ) return 

#define CLEAR(x) memset(&(x), 0, sizeof(x))


class V4L2Cmd : public QObject
{

   Q_OBJECT

 public:
   typedef enum CTRLTYPE
     {
          INTEGER=0,
	  BOOLEAN=1,
	  BUTTON=2,
	  MENU=3,
     }
   CTRLTYPE;

   V4L2Cmd():fd(-1){}
   /* Set / Copy file descriptor from webcam device */
   void copyFileDescriptor ( int current_fd ){	fd = current_fd;}

   int build_control( struct v4l2_queryctrl query );
   int enum_controls();
   int isv4l2Control( int control,struct v4l2_queryctrl *queryctrl);

   int v4l2GetControl(int control);
   int v4l2SetControl(int control,int value);
   int v4l2UpControl(int control);
   int v4l2DownControl(int control);
   int v4l2ToggleControl(int control);
   int v4l2ResetControl(int control);
   int v4l2ResetPanTilt(int pantilt);
   int v4L2UpDownPan(short inc);
   int v4L2UpDownTilt(short inc);
   int v4L2UpDownPanTilt(short inc_p, short inc_t);
   int v4l2SelectMenu(int id, short option);
   int xioctl(int fd, int request, void *arg);
   int sioctl( int request, void *args)
     {
	return xioctl(fd,request,args);
     }
   const int getFd(){ return fd;}
   
public slots:
     void changeValue( const QString &, int , int );
   
 protected:
   void enumerate_menu(struct v4l2_queryctrl q,int v);

signals:
   void new_control( const QString &, int min, int max, int current, int type,int step, int def_value, unsigned long int id );

 private:
   int  fd;
}
;
#endif




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
#ifndef WEBCAM_DEVICE_H
#define WEBCAM_DEVICE_H

#include <QSize>
# include <QMessageBox>
# include <QMap>
# include <QImage>
# include <QTime>
# include <v4l2wrap/v4l2wrap.h>

/* Webcam Device  (qt)
 * All int functions return 1 on success */

class Webcam : public QObject
{
   Q_OBJECT
 public:
   Webcam(const QString & dev_name  );
   /* read_frame, called by get_frame */
   int read_frame(void);
   int get_frame();
 
   int open_device(void);
   int reopen_device(void);
   const int nframes();
   const bool start_capturing(void);
   const bool init_device(int w=640, int h=480);
   const bool isStreaming();

   void close_device();

   void stop_capturing(void);
   void setDevice( const QString &dev);
   void setDrawSurface ( QImage *drawPtr );

   V4L2WebcamInfo * openAndGatherInfoFrom(const QString &fname);
   V4L2WebcamInfo * deviceInfo();
   V4L2Cmd *controlWebcam();
   
   const QString devName();
   const QSize  getSize();
   const QSize  getSourceSize();
   
   const int setResolution( int w,int h );
   
   /* Pass a widget to receive and send ioctls for control the webcam
    * if any available. V4L2UVC is wrapper around V4L2Wrap.
      This will break any design pattern. :P */
   void setControllerWidget( QWidget *ifAny=0);
   
   ~Webcam();

 private:
   int fd;
   int grab;
   int n_frames;
   QString dev_name;
   QTime timer;
   QImage *_draw_surface;
   bool streaming;
   V4L2Wrap v4l2wrap;
   V4L2WebcamInfo *webcam_info;
   
}
;

#endif

/**********************************************************                    #
# This program is free software; you can redistribute it and/or modify         #
# it under the terms of the GNU General Public License as published by         #
# the Free Software Foundation; Licence Version 2 .                            #
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
#include "webcamdevice.h"

Webcam::Webcam(const QString & dev_name  ):QObject()
{
   fd=-1;
   setDevice(dev_name);
   v4l2wrap.setIO("read");

   webcam_info = new V4L2WebcamInfo;
   streaming = false;
}

void Webcam::setDevice( const QString &dev)
{
   dev_name = dev;
}

void Webcam::close_device()
{
   if( isStreaming() )
     stop_capturing();

   if( fd != -1 )
     close(fd);
   //assure
    fd=-1;
}

const bool Webcam::isStreaming(){ return streaming; }

V4L2WebcamInfo * Webcam::openAndGatherInfoFrom(const QString &fname)
{
   setDevice(fname);
   if( !open_device() )
     return NULL;
   return deviceInfo();
}

V4L2WebcamInfo * Webcam::deviceInfo()
{
   if(v4l2wrap.gatherInfoAboutDevice(webcam_info))
     return webcam_info;

   return NULL;
}

const QString Webcam::devName()
{
   return dev_name;
}
/* converted */
const QSize  Webcam::getSize()
{
   return v4l2wrap.getSourceSize(); //src size ( v4lconvert)
}
/* from webcam */
const QSize  Webcam::getSourceSize()
{
   return v4l2wrap.getSize();//fmt size ( original )
}

void Webcam::setDrawSurface ( QImage *drawPtr )
{
   Q_ASSERT( drawPtr != NULL);
   _draw_surface = drawPtr;
}

const int Webcam::nframes(){ return n_frames;}

Webcam::~Webcam()
{
   close_device();
   delete webcam_info;
}

int Webcam::read_frame(void)
{

   n_frames =1000/timer.elapsed();
   timer.restart();
   return v4l2wrap.readFrameQtConvert(_draw_surface);
}

int Webcam::get_frame()
{
   fd_set fds;
   struct timeval tv;
   int r;

   /* just in case */
   if( fd == -1 )
     return -1;
   
   FD_ZERO(&fds);
   FD_SET(fd, &fds);

   tv.tv_sec = 5;
   tv.tv_usec = 0;

   r = select(fd + 1, &fds, NULL, NULL, &tv);
   if (r < 0)
     {
	if (EINTR == errno)
	  return 0;
		
        ExceptError::fatal("Select Error.");
	return -1;
     }

   if (0 == r)
     {
        ExceptError::warn(QT_TR_NOOP("Timeout en espera de datos"));
	return 0;
     }
  
   return read_frame();

}

void Webcam::stop_capturing(void)
{
   v4l2wrap.stopStream();
   streaming = false;
}

const bool Webcam::start_capturing(void)
{
   streaming = false;
   if(  v4l2wrap.startStream() )
     streaming = true;

   return streaming;
}

const bool Webcam::init_device(int w, int h)
{
  return v4l2wrap.init(w,h);
}

int Webcam::open_device()
{
   struct stat st;
   fd=-1;
   if (stat(dev_name.toLatin1(), &st) < 0)
     {
	ExceptError::warn(QT_TR_NOOP(QString("El dispositivo %1 es inexistente").arg(dev_name)));
	return -1;
     }

   if (!S_ISCHR(st.st_mode))
     {
	ExceptError::warn(QT_TR_NOOP(QString("El dispositivo %1 no es un dispositivo CHAR").arg(dev_name)));
	return -1;
     }

   fd = open(dev_name.toLatin1(), O_RDWR | O_NONBLOCK, 0);
   if (fd < 0)
     {
	ExceptError::warn(QT_TR_NOOP(QString("Imposible abrir el dispositivo %1 ").arg(dev_name)));
	return -1;
     }

   v4l2wrap.setFileDescriptor(fd);
   
   return fd;
}

const int Webcam::setResolution( int w,int h)
{
   if(   reopen_device())
     return init_device( w,h);
   return 0;
}

int Webcam::reopen_device()
{
   close_device();
   return  open_device();
}

V4L2Cmd * Webcam::controlWebcam()
{
  v4l2wrap.getControlWebcam();
}

/* Note the slotName for the widget, if any */
void Webcam::setControllerWidget( QWidget *ifAny)
{
  if( 0 == ifAny )
     return;
  connect( v4l2wrap.getControlWebcam(), SIGNAL(new_control( const QString &,  int, int, int , int ,int,int,unsigned long int)),ifAny,
   	    SLOT(new_control( const QString &, int, int, int, int,int,int,unsigned long int  )));
//do real method call when the controller widget updates
  connect( ifAny, SIGNAL( changeValue(const QString & ,int , int ) ), v4l2wrap.getControlWebcam(),
	   SLOT( changeValue(const QString & , int, int ) ) );

}



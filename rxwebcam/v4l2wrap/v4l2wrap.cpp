\
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

#include <v4l2wrap/v4l2wrap.h>
V4L2Wrap::V4L2Wrap (QString io_mode):QObject ()
{
   Grabber = new V4L2GrabImageManager (control_webcam);
   Q_ASSERT (Grabber != NULL);
   Grabber->setIO (io_mode);
   raw = false;
}

bool V4L2Wrap::gatherInfoAboutDevice (V4L2WebcamInfo * info)
{
   struct v4l2_capability cap;
   struct v4l2_format afmt;
   afmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

   Q_ASSERT (info != NULL);
   info->clear ();

   if (!info)
     return false;;
   
   if (control_webcam.sioctl (VIDIOC_QUERYCAP, &cap) < 0)
     return false;;
   if (!(cap.capabilities & V4L2_CAP_VIDEO_CAPTURE))
     return false;;

   if (control_webcam.sioctl (VIDIOC_G_FMT, &afmt) < 0)
     return false;

   info->setInfo ((char *) cap.driver, (char *) cap.card, afmt.fmt.pix.width,
		  afmt.fmt.pix.height, "unknown");
   return true;
}

bool V4L2Wrap::checkAndInit ()
{
   struct v4l2_capability cap;

   if (control_webcam.sioctl (VIDIOC_QUERYCAP, &cap) < 0)
     {
	if (EINVAL == errno)
	  ExceptError::warn (QT_TR_NOOP ("El dispositivo no es del tipo V4L2"));
        else
	  ExceptError:: warn (QT_TR_NOOP("Error en ioctl VIDIOC_QUERYCAP"));

	return false;
     }

   if (!(cap.capabilities & V4L2_CAP_VIDEO_CAPTURE))
     {
ExceptError::warn (QT_TR_NOOP("El dispositivo no es de captura"));
        return false;
     }
   
   
   if (cap.capabilities & V4L2_CAP_STREAMING)
	Grabber->setIO ("mmap");
   else if (cap.capabilities & V4L2_CAP_READWRITE)
	Grabber->setIO ("read");
   else
     {
	ExceptError::warn (QT_TR_NOOP("El dispositivo no soportap ningun I/O ( read, mmap )"));
	return false;
     }

   return true;
}

bool V4L2Wrap::startStream ()
{
   return Grabber->startCapture ();
}

bool V4L2Wrap::stopStream ()
{
   return Grabber->stopCapture ();
}

int V4L2Wrap::readFrameQtConvert (QImage *current_frame)
{
   int length;
   if (NULL == current_frame)
     return -1;

   
   if (Grabber->readFrame ())
     {
	if (!raw)
	  {
	
	     int ret=0;
	     if ((ret=V4LConvert.convert (Grabber->frameData (), Grabber->frameSize ())))
	       {
		  unsigned char *so = current_frame->bits();
		  
		  /* Qt do not allow to loadFromData in this case, ( no format), and deleting and allocating
		   * a qimage every time dont fit my needs. LEts do it this way.
		   * This, must be really tested... */
		  //memset(so,0x00,current_frame->numBytes());
		
// pac7311
		  if( ret == -1 ) 
			 return 1;
		    
		  
		  if( so != 0 && ret > 0 && current_frame->numBytes() >= ret )
		    {
		      memcpy(so,V4LConvert.dstBuf(),ret);
		    }
		  

/*		  This was needed for Convert from rgb24 to rgb32. Now i use RGB_..888 (24bits), so 
 *                lest remove it, but keep it commented for future tests.
 *                
                  fprintf(stderr,"FrameSize: %d ImageCurrentSize %d\n",ret,current_frame->numBytes());
 * 
		  const unsigned char *ptr = V4LConvert.dstBuf (); 
		  int step = 0;
		  unsigned long *bt;
		  //rgb24 to rgb32 x qimage..
		  fprintf(stderr,"RET: %d\n",ret);
		  bt = (unsigned long *) current_frame->bits ();
		  
		  for (int loop = 0; loop <  current_frame->numBytes () && ptr[step+2] != 0; loop += 4)
		    {
		       bt[loop / 4] = qRgb (ptr[step], ptr[step + 1], ptr[step + 2]);
		       		       step += 3;
		    }
*/
		     
	       }
	  }
        else //UNTESTED, this shouldn't work..
	current_frame->loadFromData (Grabber->frameData(),Grabber->frameSize());

	return 1;
     }

   return -1;
}



//ese h y w pasarlo no, segun el format size?
bool V4L2Wrap::init (int w, int h)
{
   int sizeimage = 0;

   if (!checkAndInit ())
     return false;
  
   Grabber->cleanup ();
   qDebug("Check and Init\n");
   if (!V4LConvert.init (control_webcam.getFd (), w, h))
     return false;
   if(control_webcam.sioctl (VIDIOC_S_FMT, V4LConvert.srcFmt ()) <  0)
   {
      exit(0);
      return false;
   }
   if ((sizeimage = V4LConvert.createDestBuffer ()) == 0)
     return false;
   
   if (Grabber->initMode (sizeimage) == false)
     {
	/* Try 1 alternative ( UserPointerMode is avoided because some drivers do not support it yet */
	Grabber->cleanup();
        if( Grabber->currentIO() == "read" )
	  Grabber->setIO("mmap");
	else
	  Grabber->setIO("read");

	return Grabber->initMode(sizeimage);
	
     }
   qDebug("End of Init\n");

return true;
}

void V4L2Wrap::setFileDescriptor(int fd )
{
   control_webcam.copyFileDescriptor( fd); 
   //if any control widget was associated, signals will be emited from there
   control_webcam.enum_controls(); 
}

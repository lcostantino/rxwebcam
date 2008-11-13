
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

#ifndef V4L2_WRAP_H
#define V4L2_WRAP_H


#include <string.h>
#include <QSize>

#include <QMap>
#include <QImage>
#include <QTime>
#include <v4l2wrap/formatv4l2convert.h>
#include <v4l2wrap/grabinputmanager.h>

class V4L2WebcamInfo
{
 public:
   V4L2WebcamInfo(){ _capture = false; }
   const QString & driver(){return _driver;}
   const QString & name(){return _name;}
   const QSize & size(){return _size;}
   const QString & format(){return _format;}

   void clear()
     {
	_driver=_name=_format="";
	_size = QSize(0,0) ;
	_capture = false;
     }

   void setInfo(  const QString driv,const QString name,
		  const int width,const int height,const QString &format)
     {
	_driver = driv;
	_name = name;
	_size = QSize(width,height);
	_format = format;
	_capture = true;
     }
   const QSize getSize()
     {
	return _size;
     }
   
   const QString dump()
     {
	return QString("Name: [%1]\nDriver: %2\nSize: %3x%4\n").arg(_name).arg(_driver) \
                                               .arg(_size.width()).arg(_size.height());
     }

 private:
   QString _driver,_name,_format;
   QSize _size;
   bool _capture;
};


class V4L2Wrap  :public QObject
{
   Q_OBJECT
 public:
   V4L2Wrap(QString io_mode="read");

   void setIO(const QString & io_mode){Grabber->setIO(io_mode);}
   //wrappers for classes ( ugl..)
   
   void setFileDescriptor(int fd );
   const QSize  getSize(){ return V4LConvert.getSourceSize();} //src size ( original format)
   const QSize  getSourceSize(){ return V4LConvert.getSize();} //fmt size ( dest format )
   const int sioctl(int req, void *args){ return control_webcam.sioctl(req,args); }
   V4L2Cmd & controlWebcam() { return control_webcam;}
   FormatV4L2Convert & v4lConvert() { return V4LConvert;}
   	
   bool gatherInfoAboutDevice(V4L2WebcamInfo * info);
   bool  checkAndInit();
   bool  startStream();
   bool stopStream();
   int readFrameQtConvert( QImage *current_frame);
   bool init(int w, int h );
   
   ~V4L2Wrap(){ delete Grabber;}
   V4L2Cmd * getControlWebcam(){ return &control_webcam; }
	
 private:
   V4L2Cmd control_webcam;//xioctl, fd, control panel.
   FormatV4L2Convert V4LConvert; //converter
   V4L2GrabImageManager *Grabber;
   int _last_error;
   bool raw;

signals:
   void newFrame(const unsigned char *, int len, const QSize &);

};

#endif

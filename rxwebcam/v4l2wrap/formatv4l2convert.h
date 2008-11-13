/* Code here wrappers the liblconver from Heode (libv4lconvert
*/
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

#ifndef FORMAT_V4L2_CONVERT_H
#define FORMAT_V4L2_CONVERT_H
#include <v4l2wrap/v4l2uvc.h>

#include <QString>
#include <QSize>

//i'm too lazy for coding it inside the class
#define PIXEL_FORMAT( sv4l2_format ) sv4l2_format.fmt.pix.pixelformat

class FormatV4L2
{
   /* somethings belong to C world.... wrappers get ugly on this case's :( */
   /* This is just a "makeup" for C++...All this could be simplified and written in simple c for simplicity and optimi.*/
 public:
   FormatV4L2( v4l2_buf_type type=V4L2_BUF_TYPE_VIDEO_CAPTURE,
	       quint32 width=640, quint32 height=480, quint32 pformat = V4L2_PIX_FMT_RGB24,
	       v4l2_field field = V4L2_FIELD_INTERLACED )
     {

	clear();
	
	_fmt.type = type;
	_fmt.fmt.pix.width = width;
	_fmt.fmt.pix.height = height;
	_fmt.fmt.pix.pixelformat = pformat;
	_fmt.fmt.pix.field = field;
     }

   void clear(){ CLEAR(_fmt);}
   void setSize(int w, int h) { 
      _fmt.fmt.pix.width = w;
      _fmt.fmt.pix.height = h;
   }
   
      
	
   void setType( v4l2_buf_type type ) { _fmt.type = type; }
   void setPixelFormat( qint32 pformat ) { PIXEL_FORMAT(_fmt)  = pformat ; }
   void setField( v4l2_field field ) { _fmt.fmt.pix.field = field; }
   const quint32 getPixelFormat() { return PIXEL_FORMAT(_fmt); }
   const QSize getSize() { return QSize( _fmt.fmt.pix.width,_fmt.fmt.pix.height); }
   const qint32 sizeImage() { return _fmt.fmt.pix.sizeimage; }
   struct v4l2_format * fmt(){ return (v4l2_format *)&_fmt;}
   const QString  infoFormat()
     {
	QString info;
        return info.sprintf("Info Format %c%c%c%c (%dx%d)\n",PIXEL_FORMAT(_fmt) & 0xff,
			    (PIXEL_FORMAT(_fmt) >> 8) & 0xff,
			    (PIXEL_FORMAT(_fmt) >> 16) & 0xff,
			    (PIXEL_FORMAT(_fmt) >> 24) & 0xff,
			    _fmt.fmt.pix.width,_fmt.fmt.pix.height);
     }

	
 private:
   struct v4l2_format _fmt;
}
;

class FormatV4L2Convert
{

 public:
   FormatV4L2Convert();

   bool init(int fd,int w, int h);
   quint32 createDestBuffer();
   int convert(unsigned char *p, int len);
   unsigned char const * dstBuf();
   struct v4l2_format * dstFmt();
   struct v4l2_format * srcFmt();
   const QSize  getSourceSize();
   const QSize  getSize() ;
   
 private:
   FormatV4L2 fmt, src_fmt;
   struct v4lconvert_data *v4lconvert_data;
   unsigned char *dst_buf;

}
;
#endif


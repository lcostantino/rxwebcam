
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

#include <v4l2wrap/formatv4l2convert.h>

FormatV4L2Convert::FormatV4L2Convert(){ v4lconvert_data = NULL;}

bool FormatV4L2Convert::init(int fd, int width, int height)
{

   fmt.setSize(width,height);
   
   if( v4lconvert_data != NULL )
      v4lconvert_destroy(v4lconvert_data);
   
   if( ( v4lconvert_data = v4lconvert_create(fd)) == NULL )
   {
      ExceptError::fatal(QT_TR_NOOP("V4lConvert: Error en buffer"));
      return false;
   }
   
   if (v4lconvert_try_format(v4lconvert_data, dstFmt(),srcFmt()  ) != 0)
   {
      ExceptError::warn(QT_TR_NOOP("V4lConvert: Error en formatos"));
      return false;
   }
   /* CHECK FMT SIZE, if its not the same as width x height, then 
    * format is not available */
   qDebug("Dest: %s\n Source: %s\n",qPrintable(fmt.infoFormat()),qPrintable(src_fmt.infoFormat()));
   return true;
}

quint32 FormatV4L2Convert::createDestBuffer()
{
   dst_buf = new unsigned char[fmt.sizeImage()];
   Q_ASSERT( dst_buf != NULL );
   return src_fmt.sizeImage();
}

int FormatV4L2Convert::convert(unsigned char *p, int len)
{
   int res=0;
   if ( v4lconvert_convert(v4lconvert_data,srcFmt(),dstFmt(), p, len, dst_buf,fmt.sizeImage()) < 0)
     {
	if( errno != -EAGAIN ) //pac73xx
	  return -1;

	ExceptError::warn(QT_TR_NOOP("V4lConvert: Error en conversion de formatos"));
	return 0;
     }
   
   return fmt.sizeImage();
}

unsigned char const * FormatV4L2Convert::dstBuf()
{
   return dst_buf;
}

/* Converted Format */
struct v4l2_format * FormatV4L2Convert::dstFmt()
{
   return fmt.fmt();
}
/* Webcam Device Format */
struct v4l2_format * FormatV4L2Convert::srcFmt()
{
   return src_fmt.fmt();
}
/* Webcam Device Format Size */
const QSize  FormatV4L2Convert::getSourceSize()
{
   return src_fmt.getSize();
}
/* Convert Format Size */
const QSize  FormatV4L2Convert::getSize()
{
   return fmt.getSize() ;
}


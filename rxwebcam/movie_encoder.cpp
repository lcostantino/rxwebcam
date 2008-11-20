
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
#include "movie_encoder.h"
#include "v4l2wrap/Error.h"
#ifdef WITH_XVID_RECORD
RevelEncoder::RevelEncoder()
{

}

void RevelEncoder::setParameters( const QString &filename, const QSize &size,
				  float frate, float quality )
{
   _fname = filename;
   Revel_InitializeParams(&_rparams);
   _rparams.width = size.width();
   _rparams.height = size.height();
   _rparams.frameRate = frate;
   _rparams.quality = quality;
   _rparams.codec = REVEL_CD_XVID;
   _rparams.hasAudio = 0;
   
   frame.width = size.width();
   frame.height = size.height();
   frame.bytesPerPixel = 3;
   //we are getting RGB24 from v4lconvert,
   //this may not be well suited, but allow me to keep using any revel lib around without
   //touching lib source code. 
   frame.pixelFormat = REVEL_PF_BGR;
   frame.pixels = NULL;
}

/* disabled */
void RevelEncoder::freePixels()
{
   return; 
   if( (int *)frame.pixels != NULL )
     {
	delete [] (int *)frame.pixels;
	frame.pixels = NULL;
     }

}

const bool RevelEncoder::start()
{
   int res;
   if( (res = Revel_CreateEncoder( &_encoder_handler )) != REVEL_ERR_NONE )
     {
	ExceptError::fatal(QT_TR_NOOP("Revel_CreateEncoder Error."));
	return false;
     }

   if( (res = Revel_EncodeStart( _encoder_handler, _fname.toLatin1(), &_rparams ) ) != REVEL_ERR_NONE )
     {
	ExceptError::warn(QT_TR_NOOP("Revel_EncodeStart Error."));
	return false;
     }

   freePixels();
/* if you want to put this inside a thread or anywhere, and dont want to share the qimage ptr, then
 * allocate memory here, and copy the image later when needed. Remember to call
   and enable free_pixels() , that is currently disabled. 
   This would lead to a better implementation in a future, if someone cares */
   frame.pixels = NULL;
    
   return true;

}

const bool RevelEncoder::addVideoFrame( QImage * ptImage )
{
   int frameSize=0;
   if( NULL == ptImage )
     return false;

   frame.pixels = (int *) ptImage->bits();
//   memcpy(frame.pixels, (int *)ptImage->bits(), ptImage->width() * ptImage->height() * 3 );
   if( Revel_EncodeFrame(_encoder_handler, &frame,&frameSize) != REVEL_ERR_NONE )
     {
	qDebug("EncodeFrame Error\n");
	return false;
     }

   return true;
}

const bool RevelEncoder::stop()
{
   int total_size;
   if( Revel_EncodeEnd(_encoder_handler, &total_size) != REVEL_ERR_NONE )
     {
	qDebug(" Error while ending decode\n");
	ExceptError::fatal(QT_TR_NOOP("Error finalizando el decoder"));
	return false;
     }
   qDebug("Video Total Written: %d\n",total_size);
   Revel_DestroyEncoder(_encoder_handler);
   /* Should be called when streamwidget is destroyed */
   /* its sharing the same ptr */
   freePixels();

   return true;
}

RevelEncoder::~RevelEncoder()
{
}
#endif

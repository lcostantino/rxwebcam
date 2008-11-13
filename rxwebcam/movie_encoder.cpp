
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
   frame.bytesPerPixel = 4;
   frame.pixelFormat = REVEL_PF_RGBA;
   frame.pixels = NULL;
}

void RevelEncoder::freePixels()
{
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
   frame.pixels = new int[ frame.width * frame.height ];
   if( (int *)frame.pixels == 0 )
     return false;

   memset(frame.pixels,0x00,frame.width * frame.height * 4 );
   return true;

}

const bool RevelEncoder::addVideoFrame( QImage * ptImage )
{
   int frameSize=0;
   if( NULL == ptImage )
     return false;
   frame.pixels = (int *) ptImage->bits();
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
   freePixels();

   return true;
}

RevelEncoder::~RevelEncoder()
{
}
#endif

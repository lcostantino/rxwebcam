
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

#ifndef MOVIE_ENCODER_H
# define MOVIE_ENCODER_H
# include <QString>
#include <QImage>

# ifdef WITH_XVID_RECORD
#  include <revel.h>


class RevelEncoder
{
 public:
   RevelEncoder();
     /* Actually, frame rate and quality on vide are fixed... */
   void setParameters( const QString &filename, const QSize &size,
		       float frate=20.0f, float quality=1.0f );
   void freePixels();
   const bool start();
   //pasar a un thread?
   const bool addVideoFrame( QImage * ptImage );
   const bool stop();
   ~RevelEncoder();

 private:
   int _encoder_handler;
   int nframes;
   QString _fname;
   Revel_Params _rparams;
   Revel_VideoFrame frame;

}
;
# endif

#endif

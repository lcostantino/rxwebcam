
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
#ifndef FORM_STREAMINGIMP_H
# define FORM_STREAMINGIMP_H
# include "ui_streaming.h"
/* Some includes could be replaced by Class and included on each unit code for speed up compilation */
# include <QLabel>
# include <QImage>
# include <QPainter>
# include <QWidget>
# include <QFrame>
# include <QTimer>
# include <QResizeEvent>
#include "WebcamControlImp.h"
# include "webcamdevice.h"
# include "plugin.h"
# include "movie_encoder.h"

 
/* Widget that show the current image */
class RealStreamWidget : public QLabel
{
   Q_OBJECT
 public:
   RealStreamWidget(QWidget *parent=0);
   
   QImage  * shareImage();
   QImage *getDrawSurface();
/* The size of the image has changed */
   void updateFrameSize( QSize new_size );
   void setImage( QImage *image );

   ~RealStreamWidget()
     {
	if( current_frame )
	  delete current_frame;
     }
   
 protected:
   void paintEvent( QPaintEvent *ev);

 private:
   QImage *current_frame;
   QPolygon pol;
}
;

/* Central Widget */
class FormStreamingImp : public QWidget, private Ui::FormStreaming
{
   Q_OBJECT
 public:

   FormStreamingImp(const QString & video_device = "", QWidget *parent=0 ) ;
   /* Change webcam resolution */
   int switchResolution(int w,int h );
   /* Notify everyone about the size change */
   void updateFrameSize( int w, int h );
   void enableButtons(bool state=true);
   void make_connections();
   void closeDevice();
   void toggleShowFps();
   /* Plugins parameters for the image, are not passed as pointer */
   void toggleSafeMode();
   
   bool setWebcamDevice( const QString &fname, const QSize &max_width=QSize() );
   bool initialize(const QSize &max_width=QSize());
   /* Current webcam device, only one right now */
   Webcam *getWebcam();

   ~FormStreamingImp();

 protected:
   void resizeEvent( QResizeEvent *e)
     {
		emit newSize(e->size());
     }
 public slots:
   void showWebcamController();
 protected slots:
   void grabPicture();
   void updateTimer();
   void startStream();
   void stopStream();
   void grabMovie();
   
 signals:
   void newSize( QSize );
   void setStatus(const QString  &);

 private:
   QString video_dev;
   Webcam *current_webcam; /* only one ... */
   RealStreamWidget *RSW;
   QTimer *tet;
   QImage *webcam_frame;
   bool webcam_opened;
   bool show_fps;
   bool safe_image_plugin;
   bool on_movie_record;
   WebcamControlImp WebcamController;
# ifdef WITH_XVID_RECORD
   RevelEncoder movie_grabber;
 #endif
}
;
#endif

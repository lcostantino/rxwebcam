
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
#include "FormStreamingImp.h"
#include <QPluginLoader>
#include <QHBoxLayout>
#include <QResizeEvent>
#include <QFileDialog>
#include <QMessageBox>
#include "RxPluginManager.h"

/* Simple Error Handler 
 * Mostly for v4l2wrap errors */
static inline void handleError()
{
   if( ExceptError::isFatal() )
     {
        QMessageBox::information(0,"Error Fatal", ExceptError::error() );
	exit(0); // o llamar a close
     }
   QMessageBox::information(0,"Error", ExceptError::error() );
}

/*==================*/
/* RealStreamWidget , a simple qlabel */
RealStreamWidget::RealStreamWidget(QWidget *parent /*frame*/ ):QLabel(parent)
{
   setAttribute(Qt::WA_OpaquePaintEvent,true);
   current_frame = new QImage(640,480,QImage::Format_RGB888);
   current_frame->fill(0);
}

QImage * RealStreamWidget::shareImage()
{
   return current_frame;
}

void RealStreamWidget::updateFrameSize( QSize new_size )
{
   delete current_frame;
   current_frame = new QImage( new_size,QImage::Format_RGB888);
   Q_ASSERT( current_frame != NULL);
   setFixedSize(new_size);
   current_frame->fill(0);

}
QImage * RealStreamWidget::getDrawSurface(){ return current_frame;}

void RealStreamWidget::setImage( QImage *image )
{
    current_frame = image;
   
}

void RealStreamWidget::paintEvent( QPaintEvent *ev)
{
   
   QPainter p(this);
   
   if( NULL != current_frame)
      p.drawImage(0,0,*current_frame);

   ev->accept();
}

/*==================*/
/* FormStreamingImp */

FormStreamingImp::FormStreamingImp(const QString & video_device , QWidget *parent ) : QWidget(parent)
{
   setupUi(this);
   current_webcam =  new Webcam( video_device );
   Q_ASSERT( current_webcam != NULL );
   current_webcam->setControllerWidget(&WebcamController);
   enableButtons(false);
   RSW = new RealStreamWidget(frame_stream);
   webcam_frame = new QImage(640,480,QImage::Format_RGB888);
  
   Q_ASSERT( RSW != NULL);
   QHBoxLayout *ns = new QHBoxLayout;
   ns->addWidget(RSW);
   frame_stream->setLayout(ns);
 
   current_webcam->setDrawSurface( webcam_frame);
   tet = new QTimer(this);//easy way.
   make_connections();
   webcam_opened = false;
   show_fps = false;
   safe_image_plugin = false; //Just for test purposes, True, go by copy/ref. False: go by pointer
   on_movie_record = false;

#ifndef WITH_XVID_RECORD
   pb_movie->hide();
#endif
}

int FormStreamingImp::switchResolution(int w,int h )
{
      
   if( webcam_frame->size() == QSize(w,h) )
          return 1;
    
   WebcamController.clear();  
   if( current_webcam->setResolution(w,h) )
     {
	/* Resolution Switch was ok, but not with our requested values.
	 * This is needed because of the qimage processing....
	 * gdk_rgb.. (gtk) wouldn't need this */
	if( QSize(w,h) != current_webcam->getSize() )
	  {
	     QMessageBox::information(this,tr("Informacion"),tr("La resolucion solicitada no esta disponible\nSe ajustaran los valores adquiridos"));
	     w = current_webcam->getSize().width();
	     h = current_webcam->getSize().height();
	     qDebug("Trying: %dx%d Got: %dx%d\n",w,h,current_webcam->getSize().width(),current_webcam->getSize().height());
	  }
	
	updateFrameSize(w,h);
	current_webcam->setDrawSurface( webcam_frame);
       	return 1;
     }
   else
     handleError();

   return 0;

}

void FormStreamingImp::updateFrameSize( int w, int h )
{

   delete webcam_frame;
   webcam_frame = new QImage(w,h,QImage::Format_RGB888);
   Q_ASSERT(webcam_frame != NULL);
   RSW->updateFrameSize( QSize(w,h));

  /* since its inside a layout, this is needed to "manually" update all from mainwindow  */
  /* obs: widgets inside layout shoulnd't be resized manually, but here i do */
   frame_stream->updateGeometry();
   frame_stream->adjustSize();
   updateGeometry();
   adjustSize();
}

bool FormStreamingImp::setWebcamDevice( const QString &fname, const QSize &max_size )
{
   if( fname.isEmpty() )
     return false;
   qDebug("SETTING WEBCAM DEVICE\n");
   
   current_webcam->setDevice(fname);
   WebcamController.clear();
   if( !initialize(max_size) )
     {
	
	qDebug("Initialize Error\n");
	handleError(); //no se pudo inicializar
	enableButtons(false);
	return false;
     }
   updateFrameSize(max_size.width(),max_size.height());
   current_webcam->setDrawSurface( webcam_frame);
  	qDebug("Initialize OK\n"); 
   enableButtons();
   webcam_opened = true;
   return true;

}

void FormStreamingImp::enableButtons(bool state)
{
   pb_start->setEnabled(state);
   pb_stop->setEnabled(state);
#ifdef WITH_XVID_CAPTURE
   pb_capture->setEnabled(state);
#endif
}

void FormStreamingImp::make_connections()
{
   connect( pb_start, SIGNAL( clicked(bool) ), SLOT(startStream() ));
   connect( pb_stop, SIGNAL( clicked(bool) ), SLOT(stopStream() ));
   connect( pb_capture, SIGNAL( clicked(bool)),SLOT(grabPicture()));
   connect( pb_movie, SIGNAL( clicked(bool)), SLOT(grabMovie()));
   /*Qtimer Actually this is better that putting getFrame on on a "Real" (qtimer works inside a thread too)
     QThread and polling, because some locking method must be done for that thread while using the same image pointer.
    If you want to use a thread, you sould change the pass by pointer/ref. also take care of the plugins work. */
   connect(tet,SIGNAL(timeout()), this, SLOT(updateTimer()));
}

bool FormStreamingImp::initialize(const QSize &max_size)
{
   int w=640;
   int h=480;

   if( current_webcam->open_device() < 0 )
     return false;
   if( max_size.isValid() )
     {
	w = max_size.width();
	h = max_size.height();
     }
   qDebug("Inititating with %dx%d\n",w,h);
   if( current_webcam->init_device(w,h) == false )
     return false;

   return true;
}

void FormStreamingImp::closeDevice()
{
   current_webcam->close_device();
   webcam_opened=false;
   enableButtons(false);
   
}

Webcam *FormStreamingImp::getWebcam(){return current_webcam;}

void FormStreamingImp::grabPicture()
{
   QString saveTo = QFileDialog::getSaveFileName(this,tr("Guardar foto en..."),getenv("HOME"),tr("Images (*.png *.jpg )"));
   QString format = "jpeg";
   if( !saveTo.isEmpty() )
     {
	//yes, photoxx.png.jpg could not work as expected...
	if( saveTo.contains(".png"))
	  format="png";

	QImage *toSave = new QImage(*webcam_frame); /* just in case it's get updated. We surely are streaming... */
	Q_ASSERT( toSave != NULL);
	if(toSave->save(saveTo,format.toLatin1()) )
          QMessageBox::information(0,tr("Capturar Imagen"),tr("La imagen ha sido guardada"));
	else
	  QMessageBox::information(0,tr("Capturar Imagen"),tr("La imagen no pudo ser guardada\n"));

	delete toSave;
     }
   return;

}

void FormStreamingImp::updateTimer()
{
   
   
   if( !webcam_opened || !current_webcam->isStreaming() )
     return;
   
   if( current_webcam->get_frame() < 0 )
     {
	tet->stop();
	handleError();
	return;
     }
   	/* Image Processing could be done inside a thread, but since its streaming, but the time the new frame arrived is must be shown as soon
	 * as possible, so , would have the same impact if its sequential here.
	 * Plugins will decrease  fps when processing;
	 * Currently, some plugins don't do anything on safe mode
         * PluginManager->processPlugins use a separate list for plugins already enabled */
   #ifdef MANT //for internal tests 
   if( safe_image_plugin)
     {
	QImage safe ( *webcam_frame);
	safe = PluginManager->processPlugins(safe);
	RSW->setImage(&safe);
	return;
     }
   else
     {
   #endif 
        PluginManager->processPlugins( webcam_frame,this);
	RSW->setImage( webcam_frame);
   #ifdef MANT   
     }
   #endif 
   RSW->repaint();
  
   if( show_fps )
     emit setStatus(QString(" FPS: %1").arg( current_webcam->nframes()));
#ifdef WITH_XVID_RECORD
   if( on_movie_record == true )
     {
	qDebug("Recording\n");
	movie_grabber.addVideoFrame( webcam_frame);
     }
#endif
}

void FormStreamingImp::startStream()
{

   if( !current_webcam->start_capturing() )
     {
	handleError();
	return;
     }

   pb_start->setEnabled(false);
   pb_stop->setEnabled(true);

   emit setStatus("Streaming....");
   tet->start(10);
}

void FormStreamingImp::stopStream()
{
   tet->stop();
   current_webcam->stop_capturing();
  
   emit setStatus("Stream Off");

   pb_stop->setEnabled(false);
   pb_start->setEnabled(true);
   if( on_movie_record )
     grabMovie();
}

void FormStreamingImp::toggleShowFps()
{
   show_fps = !show_fps;
}

void FormStreamingImp::toggleSafeMode()
{
  #ifdef MANT
  if( webcam_opened ) 
     stopStream();
   safe_image_plugin = !safe_image_plugin;
  #endif
}
/* start / stop movie */
void FormStreamingImp::grabMovie()
{
#ifdef WITH_XVID_RECORD
   if( on_movie_record == true )
     {
	on_movie_record = false;
	if( !movie_grabber.stop() )
	  {
	     handleError();
	     return;
	  }
	emit setStatus(QString(tr("Grabacion Finalizada")));
     }
   QString saveTo = QFileDialog::getSaveFileName(this,tr("Guardar video en..."),getenv("HOME"),tr("Video (*.avi)"));
   //no permitir cambio de size mientras graba!
   if( saveTo.isEmpty() )
     return;

   movie_grabber.setParameters(saveTo,current_webcam->getSourceSize()); //size or sourcesize?
   if( !movie_grabber.start() )
     {
	handleError();
	return;
     }

   emit setStatus(QString(tr("El video sera guarduado en %1").arg(saveTo)));

   on_movie_record = true;
#endif
}

void FormStreamingImp::showWebcamController()
{
  if( webcam_opened )
     WebcamController.show();
  else
     QMessageBox::information(this,tr("Informacion"),QString(tr("Seleccione una webcam primero!")));
}

/* On exit this should be deallocated. ( we use this form just 1 time ).
 * Anyway, this is here for debug purposes */

FormStreamingImp::~FormStreamingImp()
{
   if( RSW)
     delete RSW;
   if( tet )
     delete tet;
   if( current_webcam)
     delete current_webcam;
   qDebug("FSI Deleted\n");
}

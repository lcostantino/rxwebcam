#include <v4l2wrap/grabinputmodes.h>

/*=== ReadInput Mode ( grab by read sysc )  purely C code*/

ReadInputMode::ReadInputMode( V4L2Cmd & control_webcam )
  :GrabInputMode(control_webcam)
{
   buffers = NULL;

}

bool ReadInputMode::init(uint buffer_size)
{
   buffers = (struct buffer *)calloc(1, sizeof(*buffers));

   if (NULL == buffers)
     {
	ExceptError::fatal(QObject::tr("No hay memoria suficiente / Fallo la asignacion"));
	return false; //no mem
     }
   buffers[0].length = buffer_size;
   buffers[0].start = malloc(buffer_size);
   if (NULL == buffers[0].start)
     {
	ExceptError::fatal(QObject::tr("No hay memoria suficiente / Fallo la asignacion"));
	return false;
     }

   return true;
}

bool ReadInputMode::cleanup()
{
   if( buffers != NULL )
     {
	free(buffers[0].start); // delete? check if null?
	free(buffers);
     }
   buffers=NULL;
   current_frame = NULL;
   return true;
}

bool ReadInputMode::start(){return true;}
bool ReadInputMode::stop(){return true;}

int  ReadInputMode::readFrame()
{
   int i=0;

   if( buffers == NULL )
     return false;

   if( (i = read(refControl.getFd(), buffers[0].start, buffers[0].length)) < 0 )
     {
	if( errno == EAGAIN )
	  return 0;

	ExceptError::warn(QObject::tr("Error de lectura en el dispositivo"));
	return -1;
     }

   current_frame = (unsigned char *)buffers[0].start;
   current_frame_len = i;

   return 1;
}

ReadInputMode::~ReadInputMode()
{

   if( buffers != NULL )
     cleanup();
}

UserPointerInputMode::UserPointerInputMode(V4L2Cmd & control_webcam ):GrabInputMode(control_webcam)
{
   buffers = NULL;
}

bool UserPointerInputMode::init(uint buffer_size)
{
   struct v4l2_requestbuffers req;
   unsigned int page_size;

   page_size = getpagesize();
   buffer_size = (buffer_size + page_size - 1) & ~(page_size - 1);

   CLEAR(req);

   req.count = 4;
   req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
   req.memory = V4L2_MEMORY_USERPTR;

   if (refControl.sioctl( VIDIOC_REQBUFS, &req) < 0)
     {
	if( errno == EINVAL)
	  _available = false;

	return false;
     }

   //si es EINVAL no lo soporta, intentar cambiar

   buffers = (struct buffer *)calloc(4, sizeof(*buffers));
   if (!buffers)
     {
	ExceptError::fatal(QObject::tr("No hay memoria suficiente / Fallo la asignacion"));
	return false;
     }

   for (n_buffers = 0; n_buffers < 4; ++n_buffers)
     {
	buffers[n_buffers].length = buffer_size;
	buffers[n_buffers].start = memalign(  page_size,buffer_size);
	if (!buffers[n_buffers].start)
	  {
	     ExceptError::fatal(QObject::tr("No hay memoria suficiente / Fallo la asignacion"));
	     return false; // should clean the rest? , exit here
	  }

     }
   return true;
}

bool UserPointerInputMode::cleanup()
{
   int i;

   if (last_buf.memory == V4L2_MEMORY_USERPTR )
     if( refControl.sioctl( VIDIOC_QBUF, &last_buf) < 0)
       return -1;

   if( NULL != buffers )
     {
	for (i = 0; i < n_buffers; ++i)
	  free(buffers[i].start);

	free(buffers);
     }

   current_frame = NULL;
   n_buffers=0;

   return true;
}

bool UserPointerInputMode::start()
{
   int i=0;
   enum v4l2_buf_type type;
   for (i = 0; i < n_buffers; ++i)
     {

	struct v4l2_buffer buffer;
	CLEAR(buffer);
	buffer.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	buffer.memory = V4L2_MEMORY_USERPTR;
	buffer.index = i;
	buffer.m.userptr = (unsigned long) buffers[i].start;
	buffer.length = buffers[i].length;

	if (refControl.sioctl( VIDIOC_QBUF, &buffer) < 0)
	  {
	     ExceptError::fatal(QObject::tr("Error IOCTL(VIDIOC_QBUF) ")); 
	 /* IOCTL Errors could be setted on  sioctl/xioctl in one single line */
	     return false;
	  }

     }

   type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
   if (refControl.sioctl( VIDIOC_STREAMON, &type) < 0)
     {
	ExceptError::warn(QObject::tr("Error activando el streaming"));
        return false;
     }

   CLEAR(last_buf);
   return true;
}

bool UserPointerInputMode::stop()
{
   enum v4l2_buf_type type;
   type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

   if (refControl.sioctl( VIDIOC_STREAMOFF, &type) < 0)
     {
	ExceptError::warn(QObject::tr("Error IOCTL(VIDIOC_STREAMOFF) "));
	return false; //errno_exit("VIDIOC_STREAMOFF");
     }

   return true;
}
int UserPointerInputMode::readFrame()
{

   int i=0;
   if (last_buf.memory == V4L2_MEMORY_USERPTR )
     if( refControl.sioctl( VIDIOC_QBUF, &last_buf) < 0)
       return -1;

   last_buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
   last_buf.memory = V4L2_MEMORY_USERPTR;

   if (refControl.sioctl( VIDIOC_DQBUF, &last_buf) < 0)
     {
	if( errno == EAGAIN )
	  return 0;

	ExceptError::warn(QObject::tr("Error IOCTL(VIDIOC_DQBUF) "));
	return -1;
     }

   for (i = 0; i < n_buffers; ++i)
     if (last_buf.m.userptr == (unsigned long) buffers[i].start
	 && last_buf.length == buffers[i].length)
       break;
   Q_ASSERT(i < n_buffers);

   current_frame  = (unsigned char *)last_buf.m.userptr;
   current_frame_len = last_buf.bytesused;

   return 1;
}

UserPointerInputMode::~UserPointerInputMode()
{
   if( NULL != buffers )
     cleanup();
}

MmapInputMode::MmapInputMode(V4L2Cmd & control_webcam ):GrabInputMode(control_webcam)
{
   buffers = NULL;
}

bool MmapInputMode::init(uint par1)
{
   Q_UNUSED(par1);
   struct v4l2_requestbuffers req;
   
   CLEAR(req);
   req.count = 4;
   req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
   req.memory = V4L2_MEMORY_MMAP;
   
  
   if (refControl.sioctl( VIDIOC_REQBUFS, &req) < 0)
     {
	if( errno == EINVAL)
	  _available = false;
	
        ExceptError::warn(QObject::tr("[MmapInputMode] Error IOCTL(VIDIOC_REBUFS) "));
	return false;
     }

   if (req.count < 2)
     return false;

   buffers = (struct buffer *)calloc(req.count, sizeof(*buffers));

   if (!buffers)
     {
	ExceptError::fatal(QObject::tr("No hay memoria suficiente / Fallo la asignacion"));
	return false;
     }

   for (n_buffers = 0; n_buffers < req.count; ++n_buffers)
     {
	struct v4l2_buffer buf;
	CLEAR(buf);
	buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	buf.memory = V4L2_MEMORY_MMAP;
	buf.index = n_buffers;
	if (refControl.sioctl( VIDIOC_QUERYBUF, &buf) < 0)
	  {
	     ExceptError::fatal(QObject::tr("Error en IOCTL(VIDIOC_QUERYBUF) "));
	     return false;
	  }
	buffers[n_buffers].length = buf.length;
	buffers[n_buffers].start = mmap(NULL  ,
					buf.length,
					PROT_READ | PROT_WRITE,
					MAP_SHARED,
					refControl.getFd(), buf.m.offset);
	if (MAP_FAILED == buffers[n_buffers].start)
	  {
	     ExceptError::fatal(QObject::tr("Error mapeando memoria "));
	     return false;
	  }

     }
   return true;

}

bool MmapInputMode::cleanup()
{

   unsigned int i=0;
/* LAST BUFFER MUST BE REMOVED IF A FORMAT SIZE CHANGE IS NEEDED ( it the newer size is higher )
 * If there are buffers still allocated, we cannot switch from 320x240 to 640x480, but we can switch
 * to 170x... ( anyway, the buffer will still allocate more data, so we must clean this */
   
   if (last_buf.memory == V4L2_MEMORY_MMAP )
     refControl.sioctl( VIDIOC_QBUF, &last_buf); /* ignore errors for now..*/
   
   if( NULL != buffers )
     {

	for (i = 0; i < n_buffers; ++i)
	  if (  -1 ==munmap(buffers[i].start, buffers[i].length))
	    {
	       ExceptError::fatal(QObject::tr("Error liberando area de memoria "));
	       return false; //error critico
	    }

	free(buffers);
     }
  
   current_frame = NULL;
   n_buffers=0;
   return true;

}

bool MmapInputMode::start()
{
   unsigned int i=0;
   enum v4l2_buf_type type;

   for (i = 0; i < n_buffers; ++i)
     {
	struct v4l2_buffer buffer;
	CLEAR(buffer);
	buffer.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	buffer.memory = V4L2_MEMORY_MMAP;
	buffer.index = i;

	if (refControl.sioctl( VIDIOC_QBUF, &buffer) < 0)
	  {
	     ExceptError::fatal(QObject::tr("Error en IOCTL (VIDIOC_QBUF)"));
	     return false;
	  }
     }

   type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
   if (refControl.sioctl( VIDIOC_STREAMON, &type) < 0)
     {
	ExceptError::warn(QObject::tr("Error activando el streaming"));
	return false;
     }

   CLEAR(last_buf);
   return true;
}

bool MmapInputMode::stop()
{

   enum v4l2_buf_type type;
   type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

   if (refControl.sioctl( VIDIOC_STREAMOFF, &type) < 0)
     {
	ExceptError::warn(QObject::tr("Error desactivando el streaming"));
	return false;
     }

   return true;
}

int MmapInputMode::readFrame()
{
   //maybe last buffer keep on queue, should check that when stream is off
   if (last_buf.memory == V4L2_MEMORY_MMAP )
     if( refControl.sioctl( VIDIOC_QBUF, &last_buf) < 0)
       return -1;

   CLEAR(last_buf);
   last_buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
   last_buf.memory = V4L2_MEMORY_MMAP;

   if (refControl.sioctl( VIDIOC_DQBUF, &last_buf) < 0)
     {
	if( errno == EAGAIN )
	  return 0;

	ExceptError::warn(QObject::tr("Error IOCTL(VIDIOC_DQBUF) "));

	return -1;

     }

   Q_ASSERT(last_buf.index < n_buffers);

   current_frame = ( unsigned char *)buffers[last_buf.index].start;
   current_frame_len = last_buf.bytesused;
   return 1;
}

MmapInputMode::~MmapInputMode()
{
   if( NULL != buffers )
     cleanup();
}


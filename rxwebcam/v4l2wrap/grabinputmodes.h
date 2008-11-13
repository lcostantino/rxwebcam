/* this is really really ugly. This should be keeped without any class, 
 * and could be made in a few code lines for 3 modes */
#ifndef GRAB_INPUT_MODES_H
#define GRAB_INPUT_MODES_H

#include <v4l2wrap/v4l2uvc.h>


struct buffer {
	void *start;
	size_t length;
};

class GrabInputMode
{
   /*i really dont like the control_webcam for ioctls... but, just leave it as is it right now... 
    *some1 should clean this mess; since only 1 webcam is supported... there are others alternatives 
    *(and better ones!) */
 public:
   GrabInputMode( V4L2Cmd & control_webcam ):refControl(control_webcam)
     {
	_available=true;
	current_frame = NULL;
	current_frame_len = 0;
     }

   virtual ~GrabInputMode(){};
   virtual bool init(uint )=0;
   virtual bool cleanup()=0;
   virtual bool start()=0;
   virtual bool stop()=0;
   virtual int readFrame()=0;
   const bool available(){ return _available;}
   //public member
   unsigned char *current_frame;
   uint current_frame_len;

 protected:
   V4L2Cmd &refControl ;
   struct buffer *buffers;
   bool _available;

}
;

class ReadInputMode : public GrabInputMode
{
 public:
   ReadInputMode( V4L2Cmd & control_webcam );
   bool init(uint buffer_size);
   bool cleanup();
   bool start();
   bool stop();
   int  readFrame();
   ~ReadInputMode();

};

class UserPointerInputMode : public GrabInputMode
{

 public:
   UserPointerInputMode(V4L2Cmd & control_webcam );
   bool init(uint buffer_size);
   bool cleanup();
   bool start();
   bool stop();
   int readFrame();

   ~UserPointerInputMode();

 private:
   int n_buffers;
   struct v4l2_buffer last_buf;
}
;
class MmapInputMode : public GrabInputMode
{
 public:

   MmapInputMode(V4L2Cmd & control_webcam );
   bool init(uint par1=0);
   bool cleanup();
   bool start();
   bool stop();
   int readFrame();
   ~MmapInputMode();

 private:
   uint n_buffers;
   struct v4l2_buffer last_buf;

};

#endif

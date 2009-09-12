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

#include <stdlib.h>
#include <qstringlist.h>
#include "v4l2uvc.h"

int V4L2Cmd::xioctl(int fd, int request, void *arg)
{
   int r;
   do
     {
	r = ioctl(fd, request, arg);
     }
   while (r < 0 && (EINTR == errno) );
   if( r < 0 )
   	     ExceptError::warn(QT_TR_NOOP("Error IOCTL "));  /* IOCTL Errors could be setted on sioctl/xioctl in one single line */
   
   
   return r;
}

//subroutine to read menu items of controls with type 3
void V4L2Cmd::enumerate_menu (struct v4l2_queryctrl queryctrl, int value)
{
   struct v4l2_querymenu querymenu;

   QStringList menu_items;
   menu_items <<QString().sprintf("%s#", queryctrl.name);
   memset (&querymenu, 0, sizeof (querymenu));
   querymenu.id = queryctrl.id;
   for (querymenu.index = queryctrl.minimum;
	querymenu.index <= queryctrl.maximum;
	querymenu.index++)
     {
	if (0 == xioctl (fd, VIDIOC_QUERYMENU, &querymenu))
	  {
	     QString menu_entry = QString().sprintf("%d:%s#",querymenu.index,querymenu.name);
	     menu_items << menu_entry;
	  }
	else
	  {
	     //error menu
	     break;
	  }
     }
   emit new_control(menu_items.join("#"), queryctrl.minimum, queryctrl.maximum, value, queryctrl.type, queryctrl.step , queryctrl.default_value,queryctrl.id);
}
int V4L2Cmd::build_control( struct v4l2_queryctrl queryctrl )
{
   struct v4l2_control   control_s;
   QString base_name;
   control_s.id=queryctrl.id;

   xioctl(fd, VIDIOC_G_CTRL, &control_s);
   usleep(10);
   qDebug("index:%-10d name:%-32s type:%d min:%-5d max:%-5d step:%-5d def:%-5d now:%d \n",
	  queryctrl.id, queryctrl.name, queryctrl.type, queryctrl.minimum,
	  queryctrl.maximum, queryctrl.step, queryctrl.default_value, control_s.value);
   base_name = QString().sprintf("%-32s",queryctrl.name);
   if (queryctrl.type == V4L2_CTRL_TYPE_MENU)
     enumerate_menu (queryctrl,control_s.value);
   else
     emit new_control(base_name, queryctrl.minimum, queryctrl.maximum, control_s.value, queryctrl.type, queryctrl.step , queryctrl.default_value,queryctrl.id);

   return 0;
}

int V4L2Cmd::enum_controls()
{
/* all this structs could be members of this class, but need to be cleaned each time */
   struct v4l2_queryctrl queryctrl;
   struct v4l2_input*    getinput;
  
   getinput=(struct v4l2_input *) calloc(1, sizeof(struct v4l2_input));
   memset(getinput, 0, sizeof(struct v4l2_input));
   getinput->index=0;
   xioctl(fd,VIDIOC_ENUMINPUT , getinput);
   qDebug("Available controls of device '%s' (Type 1=Integer 2=Boolean 3=Menu 4=Button)\n", getinput->name);
   //predefined controls
   qDebug ("V4L2_USER_CID_BASE         (predefined controls):\n");
   queryctrl.id = V4L2_CTRL_FLAG_NEXT_CTRL;
   while( xioctl(fd,VIDIOC_QUERYCTRL,&queryctrl) == 0 )
     {
	build_control( queryctrl );
	queryctrl.id |= V4L2_CTRL_FLAG_NEXT_CTRL;
     }

   if( queryctrl.id != V4L2_CTRL_FLAG_NEXT_CTRL )
     return 0;
   for (queryctrl.id = V4L2_CID_USER_BASE;
	queryctrl.id < V4L2_CID_LASTP1;
	queryctrl.id++)
     {
	if (0 == xioctl (fd, VIDIOC_QUERYCTRL, &queryctrl))
	  {
	     if (queryctrl.flags & V4L2_CTRL_FLAG_DISABLED)
	       continue;
	     build_control( queryctrl );
	  }
	else
	  {
	     if (errno == EINVAL)
	       continue;
	     return -1;
	  }
     }
   //driver specific controls
   qDebug("V4L2_CID_PRIVATE_BASE (driver specific controls):\n");

   for (queryctrl.id = V4L2_CID_PRIVATE_BASE; xioctl(fd, VIDIOC_QUERYCTRL, &queryctrl) == 0 ;
	queryctrl.id++)
     {
	if (queryctrl.flags & V4L2_CTRL_FLAG_DISABLED)
	  continue;
	build_control( queryctrl );

     }
}

int V4L2Cmd::isv4l2Control( int control,
			    struct v4l2_queryctrl *queryctrl)
{
   int err =0;
   queryctrl->id = control;
   if ((err= xioctl(fd, VIDIOC_QUERYCTRL, queryctrl)) < 0)
     {
	qDebug("xioctl querycontrol error %d \n",errno);
     }
   else if (queryctrl->flags & V4L2_CTRL_FLAG_DISABLED)
     {
	qDebug("control %s disabled \n", (char *) queryctrl->name);
     }

   return err;
}

int  V4L2Cmd::v4l2GetControl( int control)
{
   struct v4l2_queryctrl queryctrl;
   struct v4l2_control control_s;
   int err;
   if (isv4l2Control( control, &queryctrl) < 0)
     return -1;
   control_s.id = control;
   if ((err = xioctl(fd, VIDIOC_G_CTRL, &control_s)) < 0)
     {
	qDebug("xioctl get control error\n");
	return -1;
     }
   return control_s.value;
}

int  V4L2Cmd::v4l2SetControl( int control, int value)
{
   struct v4l2_control control_s;
   struct v4l2_queryctrl queryctrl;
   int min, max, step, val_def;
   int err;
   if (isv4l2Control( control, &queryctrl) < 0)
     return -1;
   min = queryctrl.minimum;
   max = queryctrl.maximum;
   step = queryctrl.step;
   val_def = queryctrl.default_value;
   if ((value >= min) && (value <= max))
     {
	control_s.id = control;
	control_s.value = value;
	if ((err = xioctl(fd, VIDIOC_S_CTRL, &control_s)) < 0)
	  {
	     qDebug("xioctl set control error\n");
	     return -1;
	  }
     }
   return 0;
}
int  V4L2Cmd::v4l2UpControl( int control)
{
   struct v4l2_control control_s;
   struct v4l2_queryctrl queryctrl;
   int min, max, current, step, val_def;
   int err;

   if (isv4l2Control( control, &queryctrl) < 0)
     return -1;
   min = queryctrl.minimum;
   max = queryctrl.maximum;
   step = queryctrl.step;
   val_def = queryctrl.default_value;
   current = v4l2GetControl(control);
   current += step;

   if (current <= max)
     {
	control_s.id = control;
	control_s.value = current;
	if ((err = xioctl(fd, VIDIOC_S_CTRL, &control_s)) < 0)
	  {
	     qDebug("xioctl set control error\n");
	     return -1;
	  }
     }

   return control_s.value;
}
int V4L2Cmd::v4l2DownControl( int control)
{
   struct v4l2_control control_s;
   struct v4l2_queryctrl queryctrl;
   int min, max, current, step, val_def;
   int err;
   if (isv4l2Control( control, &queryctrl) < 0)
     return -1;
   min = queryctrl.minimum;
   max = queryctrl.maximum;
   step = queryctrl.step;
   val_def = queryctrl.default_value;
   current = v4l2GetControl( control);
   current -= step;
   if (current >= min)
     {
	control_s.id = control;
	control_s.value = current;
	if ((err = xioctl(fd, VIDIOC_S_CTRL, &control_s)) < 0)
	  {
	     return -1;
	  }
     }
   return control_s.value;
}

int  V4L2Cmd::v4l2ToggleControl( int control)
{
   struct v4l2_control control_s;
   struct v4l2_queryctrl queryctrl;
   int current;
   int err;
   if (isv4l2Control( control, &queryctrl) != 1)
     return -1;
   current = v4l2GetControl( control);
   control_s.id = control;
   control_s.value = !current;
   if ((err = xioctl(fd, VIDIOC_S_CTRL, &control_s)) < 0)
     {
	qDebug("xioctl toggle control error\n");
	return -1;
     }
   return control_s.value;
}

int  V4L2Cmd::v4l2ResetControl( int control)
{
   struct v4l2_control control_s;
   struct v4l2_queryctrl queryctrl;
   int val_def;
   int err;
   if (isv4l2Control( control, &queryctrl) < 0)
     return -1;
   val_def = queryctrl.default_value;
   control_s.id = control;
   control_s.value = val_def;
   if ((err = xioctl(fd, VIDIOC_S_CTRL, &control_s)) < 0)
     {
	qDebug("xioctl reset control error\n");
	return -1;
     }

   return 0;
}

int  V4L2Cmd::v4l2SelectMenu(int id, short option)
{

   struct v4l2_control control_s;
   struct v4l2_queryctrl queryctrl;
   int err;

   control_s.id = id;
   if (isv4l2Control( id, &queryctrl) < 0)
     return -1;

   control_s.value = option;
   if ((err = xioctl(fd, VIDIOC_S_CTRL, &control_s)) < 0)
     {
	qDebug("xioctl  error\n");
	return -1;
     }
   return 0;
}
/* connection with widgets. Ignore control errors */
void V4L2Cmd::changeValue( const QString &callBack, int val1 , int val2)
{
   if( callBack == "UpControl" )
     v4l2UpControl( val1 );
   else if( callBack == "DownControl")
     v4l2DownControl( val1 );
   else if( callBack == "ToggleControl")
     v4l2ToggleControl( val1 );
   else
     v4l2SelectMenu( val1, val2);

}


#include "WebcamControlImp.h"

WebcamControlImp::WebcamControlImp(QWidget *parent)
  :QDialog(parent)
{
   setupUi(this);
}

/* controls will be created on each open. A resize of the webcam may require a reopen, so 
 * we need to clear old controllers, or implement a better way to detect if there was already
 * there, and if we are managing the same webcam */
void WebcamControlImp::clear()
{
   
   QLayoutItem *child=NULL;
   QLayoutItem *child2=NULL;

   while( (child = bg_commonLayout->takeAt(0)) != 0 )
     {
	if( child->layout() != 0 )
	  {
	      while( ( child2 = child->layout()->takeAt(0) )  != 0 )
	      {
		 
		 if( child2->widget() ) delete child2->widget();
		 delete child2;
	      }
	  }
	delete child;
     }
}

void WebcamControlImp::addControlSlider( QString name, int min, int max, int current, int step, int default_value , qulonglong id )
{
   QHBoxLayout *layout_ctrl = new QHBoxLayout;
   QSliderT *slider = new QSliderT(min,max,step,current,Qt::Horizontal,bg_common, QString("%1Slider").arg(name));
   slider->setAddedValues(id,default_value);

   layout_ctrl->addWidget( new QLabel(name,bg_common));
   layout_ctrl->addWidget( slider );

   QLCDNumber *lcd = new QLCDNumber( bg_common);
   lcd->setObjectName(QString("%1LCD").arg(name));
   lcd->setSegmentStyle( QLCDNumber::Filled);
   lcd->setFrameShape( QFrame::Box);
   lcd->display( slider->value());
   
   layout_ctrl->addWidget(lcd);
   bg_commonLayout->addLayout(layout_ctrl,bg_commonLayout->rowCount(),0);

   connect( slider, SIGNAL( valueChanged(int)),
	    lcd, SLOT( display( int ) ) );

   connect( slider, SIGNAL( updateDataController(qulonglong,int,int,int )),
	    this, SLOT( updateDataController(qulonglong,int,int,int ) ) );

}

void WebcamControlImp::addControlMenu( QString name, int min, int max, int current, int step, int default_value , qulonglong id )
{
   Q_UNUSED(min);
   Q_UNUSED(max);
   Q_UNUSED(default_value);
   Q_UNUSED(step);

   QHBoxLayout *layout_ctrl = new QHBoxLayout;
   QStringList list = name.split("#",QString::SkipEmptyParts);
   QComboBoxT *cb = new QComboBoxT(id,bg_common);
   layout_ctrl->addWidget( new QLabel(list[0], bg_common ));
   list.removeAt( 0 );
   cb->addItems( list );
   cb->setCurrentIndex(  current );
   connect( cb, SIGNAL( updateDataController(qulonglong,int,int,int )),
	    this, SLOT( updateDataController(qulonglong,int,int,int ) ) );

   layout_ctrl->addWidget(cb);
   bg_commonLayout->addLayout(layout_ctrl,bg_commonLayout->rowCount(),0);

}

void WebcamControlImp::addControlBoolean( QString name, int min, int max, int current,  int step, int default_value ,qulonglong id )
{
   Q_UNUSED(min);
   Q_UNUSED(max);
   Q_UNUSED(default_value);
   Q_UNUSED(step);

   QHBoxLayout *layout_ctrl = new QHBoxLayout;
   QCheckBoxT *cbox = new QCheckBoxT( name,id,bg_common);
   if( current )
     cbox->setChecked(true);

   connect( cbox, SIGNAL( updateDataController(qulonglong,int,int,int )),
	    this, SLOT( updateDataController(qulonglong,int,int,int ) ) );

   layout_ctrl->addWidget(cbox);
   bg_commonLayout->addLayout(layout_ctrl,bg_commonLayout->rowCount(),0);

}
/* NOT TESTED YET */
void WebcamControlImp::addControlButton( QString name, int min, int max, int current, int step, int default_value , qulonglong id )
{
   Q_UNUSED(min);
   Q_UNUSED(max);
   Q_UNUSED(default_value);
   Q_UNUSED(step);

   QHBoxLayout *layout_ctrl = new QHBoxLayout;
   layout_ctrl->addWidget( new QLabel(name, bg_common ));
   QPushButtonT *btn = new QPushButtonT(id,bg_common);

   connect( btn, SIGNAL( updateDataController(qulonglong,int,int,int )),
	    this, SLOT( updateDataController(qulonglong,int,int,int ) ) );
   layout_ctrl->addWidget(btn);
   bg_commonLayout->addLayout(layout_ctrl, bg_commonLayout->rowCount(),0);
}

/* find by control name, Keeping the objects in a map o list will be faster, 
 but this is just a webcam test controller so i dont really care...*/
QObject *WebcamControlImp::findByName(const QString &name,const QString &obj)
{
   return findChild<QObject *>( QString("%1%2").arg(name).arg(obj));
}

/* slots */
void WebcamControlImp::new_control( const QString &name, int min, int max, int current,int type, int step,int default_value , unsigned long int id )
{
   
   if( type == V4L2_CTRL_TYPE_INTEGER &&  (max-min) == 1 )//integer with 1 option
     type = V4L2_CTRL_TYPE_BOOLEAN;
   switch( type)
     {
      case V4L2_CTRL_TYPE_INTEGER:
	addControlSlider(name,min,max,current,step,default_value,id);
	break;;
      case V4L2_CTRL_TYPE_BOOLEAN:
	addControlBoolean(name,min,max,current,step,default_value,id);
	break;;
      case V4L2_CTRL_TYPE_MENU:
	addControlMenu(name,min,max,current,step,default_value,id);
      default:
	break;
     }

}
void WebcamControlImp::updateDataController(qulonglong id ,int old_value,int new_value,int type )
{
   switch(type)
     {
      case V4L2_CTRL_TYPE_INTEGER:
	if( new_value > old_value )
	  emit changeValue("UpControl",id,id);
	else
	  emit changeValue("DownControl",id,id);
	break;;
      case V4L2_CTRL_TYPE_BOOLEAN:
      case V4L2_CTRL_TYPE_BUTTON:
	emit changeValue("ToggleControl",id,id);
	break;;
      case V4L2_CTRL_TYPE_MENU:
	emit changeValue("MenuControl",id,old_value);
	break;;
      default:
	QMessageBox::information(this,tr("Error"),QString(tr("Ctrl Type %1 (id: %2) no soportado")).arg(type).arg(id));
	break;;
     }

}

/*
   Test app for private commands (menu, and others ). v4l2.
   Based on luvcview. Ported from qt3 , some features may be missed.
   For a real command interface app, look at v4l qt control app on LinuxTv.org code.
 
   Costantino Leandro <le_costantino@gmail.com>

 */
    /*******************************************************************************
    # This program is free software; you can redistribute it and/or modify         #
    # it under the terms of the GNU General Public License as published by         #
    # the Free Software Foundation; Version 2.					   #
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




#ifndef WEBCAM_CONTROL_IMP_H
# define WEBCAM_CONTROL_IMP_H
#include "ui_webcamcontrol.h"
#include <QSlider>
#include <QLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QButtonGroup>
#include <QComboBox>
#include <QMessageBox>
#include <QPushButton>
#include <QString>
#include <QCheckBox>
#include "v4l2wrap/v4l2uvc.h"

   
class QPushButtonT : public QPushButton
{
   Q_OBJECT
 public:
   QPushButtonT( qulonglong idc, QWidget *parent=0):QPushButton(parent),_control_id(idc)
     {
	connect( this, SIGNAL(clicked() ), SLOT( click()));
     }
 protected slots:
   void click()
     {
	emit updateDataController( _control_id, 0 ,0,  V4L2_CTRL_TYPE_BUTTON );
     }

signals:
   void updateDataController( qulonglong , int , int , int);

 private:
   qulonglong _control_id;
};

class QComboBoxT : public QComboBox
{
   Q_OBJECT
 public:
   QComboBoxT( qulonglong idc, QWidget *parent=0):QComboBox(parent),_control_id(idc)
     {
	connect( this, SIGNAL(currentIndexChanged(int) ), SLOT( selectedItem(int)));
     }
 protected slots:
   void selectedItem(int current)
     {
	emit updateDataController( _control_id, currentText().left( currentText().indexOf(":")).toInt() ,0,  V4L2_CTRL_TYPE_MENU );
     }

signals:
   void updateDataController( qulonglong , int , int , int);

 private:
   qulonglong _control_id;
};

class QCheckBoxT : public QCheckBox
{
   Q_OBJECT
 public:
   QCheckBoxT( QString name, qulonglong idc,  QWidget *parent=0):QCheckBox(name,parent),_control_id(idc)
     {
	setObjectName(name);
	connect( this, SIGNAL(clicked() ), SLOT( clickedBox()));
     }
 protected slots:
   void clickedBox()
     {
	emit updateDataController( _control_id, this->isChecked(),0,  V4L2_CTRL_TYPE_BOOLEAN );
     }

signals:
   void updateDataController( qulonglong , int , int , int);

 private:
   qulonglong _control_id;
};

class QSliderT : public QSlider
{
   Q_OBJECT
 public:
   QSliderT(int min, int max, int step, int current, Qt::Orientation layout, QWidget *parent, QString name)
      :QSlider(layout,parent)
       {
	  
	  setMinimum(min);
	  setMaximum(max);
	  setSingleStep( step );
	  setValue(current);
	  setObjectName(name);
	  setTracking(true);
	  setTickPosition(QSlider::TicksAbove);
//	  setTickInterval(step);
	  _old_value = current;
	  connect( this,SIGNAL( valueChanged( int ) ),this, SLOT( changedvalue(int )));
       }

   void setAddedValues(qulonglong id, int default_value)
     {
	_default_value = default_value;
	_control_id = id;
     }

 protected slots:

   void changedvalue(int newVal)
     {
	emit( updateDataController( _control_id,_old_value,newVal, V4L2_CTRL_TYPE_INTEGER ));
	_old_value = newVal; //prevValue() not anymore in qt4 :(
     }
signals:
   void updateDataController( qulonglong , int , int , int);

 private:
   qulonglong _control_id;
   int _default_value;
   int _old_value;
};

class WebcamControlImp : public QDialog, private Ui::WebcamControl
{
   Q_OBJECT
 public:
   WebcamControlImp (QWidget *parent=0);
   //el default verlo despues como reinicia..
   void addControlSlider( QString name, int min, int max, int current, int step, int default_value , qulonglong id );

   void addControlMenu( QString name, int min, int max, int current, int step, int default_value , qulonglong id );
   void addControlBoolean( QString name, int min, int max, int current,  int step, int default_value ,qulonglong id );
   void addControlButton( QString name, int min, int max, int current, int step, int default_value , qulonglong id );
             /* find by control name, Keeping the objects in a map o list will be faster, but this is just a webcam test controller so i dont really care...*/
   QObject *findByName(const QString &name,const QString &obj);
   void clear();
 protected slots:
   //could recieve a class "Control" too, if someone made it :)
   void new_control( const QString &name, int min, int max, int current,int type, int step,int default_value , unsigned long int id );
   void updateDataController(qulonglong id ,int old_value,int new_value,int type );

 signals:
      void changeValue( const QString &, int, int );
   


}
;
#endif


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
#include "effect.h"
#include <QInputDialog>
#include <QPainter>
#include <QMessageBox>

/* This plugins are not checking the QImage pointer, so bad things can happens 
   if the streamform do not handle it well */

BlackAndWhite::BlackAndWhite():Effect(1,QObject::tr(("Black And White")))
{
}

BlackAndWhite::~BlackAndWhite()
{
}

/* This function could be really optimized. Was taken from a filter qt example */
QImage BlackAndWhite::applyEffect( QImage &s)
{
   int x,y;
   for( y = 0; y < s.height(); ++y)
     {
	for( x =0; x < s.width(); ++x )
	  {
	     int pixel = s.pixel(x,y);
	     int gray = qGray(pixel);
	     s.setPixel(x,y, qRgb(gray,gray,gray));
	  }

     }

   return s;
}

void BlackAndWhite::applyEffect( QImage *img )
{
   int x,y;
   for( y = 0; y < img->height(); ++y)
     {
	for( x =0; x < img->width(); ++x )
	  {
	     int pixel = img->pixel(x,y);
	     int gray = qGray(pixel);
	     img->setPixel(x,y, qRgb(gray,gray,gray));
	  }

     }
}

void BlackAndWhite::showInputDialog( QWidget *parent)
{
}

HMirror::HMirror():Effect(2,QObject::tr(("HMirror")))
{
}

HMirror::~HMirror()
{
}

QImage HMirror::applyEffect( QImage &s)
{
   qDebug("Apply Effect!\n");
   return s.mirrored(true,false);
}

void HMirror::applyEffect( QImage *img )
{
   //must copy an image on this effect..
   *img = img->mirrored(true,false);
}

void HMirror::showInputDialog( QWidget *parent )
{
}

VMirror::VMirror():Effect(3,QObject::tr(("VMirror")))
{
}

VMirror::~VMirror()
{
}

QImage VMirror::applyEffect( QImage &s)
{
   return s.mirrored(false,true);
}

void VMirror::applyEffect( QImage *img )
{
   *img = img->mirrored(false,true);
}

void VMirror::showInputDialog( QWidget *parent )
{
}

Rotate::Rotate():Effect(4,QObject::tr(("Rotate")))
{

   setDataValue(90); //rotate degree
}

Rotate::~Rotate()
{
}

QImage Rotate::applyEffect( QImage &s)
{

     QMatrix nmatrix;
     QImage copy;
   
     nmatrix.rotate(dataValue());
     copy = s.transformed(nmatrix);
   
     if( s.width() != copy.width() )
       return  copy.scaled(s.width(),s.height());

    return copy;
}

void Rotate::applyEffect( QImage *img )
{
     QMatrix nmatrix;
     int original_width = img->width();
     nmatrix.rotate(dataValue());
   /* Scale the image to fit in. If we dont do this, then we should translate the matrix on the qpainter or using another
    * method, and we dont have access from here, and i dont want to do it  neither.
      Actually rotating on 90/180/270/0 could be accomplished by mixing H/V mirror.
      Its here, only as an example*/
     *img = img->transformed(  nmatrix);
     if( img->width() != original_width )
       *img = img->scaled(img->height(),img->width());
}

void Rotate::showInputDialog( QWidget *parent )
{
   bool ok;
   int value;
   value = QInputDialog::getInteger(parent,QObject::tr(("Valor de Rotacion")),QObject::tr(("Grados de Rotacion de la Imagen (0,90,180,270)")),dataValue(),0,360,30,&ok);
   if( ok )
     {
	/* If you want 45 degrees, for example, you should recode some places, 
	 *  or you will end up crashing the app */
	if( ( value % 90 ) != 0 )
	  { 
	     QMessageBox::information(parent,QObject::tr(("Error")),QObject::tr(("Valor invalido. ( 0, 90 , 180, 270 )")));
	     return showInputDialog(parent);
	  }
	
	qDebug("Setting Value %d\n",value);
	setDataValue(value);
     }
}


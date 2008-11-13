
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
#ifndef EFFECT_H
#define EFFECT_H

# include <QString>
# include <QImage>

/* Effect Class
 * Each effect must have different id's, the preview img is based on that id */

class Effect
{
 public:
   Effect(const int id,  const QString &name )
     {
	_name = name;
	_id = id;
	_internal_parameter = -1; //not used = -1
	_enabled = false;
     }

   virtual ~Effect(){};
   
   /* Apply effect to Image, get's called from the Plugin Effects
    * "Secure Plugin" will call ( QImage &).
    * (QImage *) gets called by default */
   virtual QImage  applyEffect( QImage &)=0;
   virtual void applyEffect( QImage * )=0;
   /* If the effect need some value parameter, reimplement 
    * with your requirements */
   virtual void showInputDialog( QWidget *parent=0 )=0;
   /* Effect States */
   const bool enabled(){ return _enabled;}
   void setEnabled(bool state){_enabled = state;}
     
   void setDataValue( int p )  { _internal_parameter = p;}
   const int dataValue(){ return _internal_parameter;}
   
   const QString name(){ return _name;}
   const int id(){ return _id;}

 private:
   QString _name;
   int _id;
   bool _enabled;
   int _internal_parameter;
};

class BlackAndWhite : public Effect
{

 public:
   BlackAndWhite();
   ~BlackAndWhite();
   QImage applyEffect( QImage &s);
   void applyEffect( QImage *img );
   void showInputDialog( QWidget *parent=0 );
};

class HMirror : public Effect
{

 public:
   HMirror();
   ~HMirror();
   QImage applyEffect( QImage &s);
   void applyEffect( QImage *img );
   void showInputDialog( QWidget *parent=0 );
   
};

class VMirror : public Effect
{

 public:
   VMirror();
   ~VMirror();
   QImage applyEffect( QImage &s);
   void applyEffect( QImage *img );
   void showInputDialog( QWidget *parent=0 );
};

class Rotate : public Effect
{

 public:
   Rotate();
   ~Rotate();
   QImage applyEffect( QImage &s);
   void applyEffect( QImage *img );
   void showInputDialog( QWidget *parent=0 );
};
#endif

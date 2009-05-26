
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
#ifndef ERROR_H
# define ERROR_H

# include <errno.h>
# include <string.h>
# include <QString>
# include <QMap>

/* Simple error interface to reach the gui from the wrappers.*/

class ExceptError
{

 public:
   typedef enum CritGrade { NONE,INFO, WARNING, FATAL } CritGrade;
   /* To avoid translations duplicates, a qmap with ErrorsTypes could be defined too. idctm */
   static ExceptError * Instance()
     {
	static ExceptError ins;
	return &ins;
     }
   static void setMessageError(const QString &err, ExceptError::CritGrade crit_grade=INFO);
   static CritGrade criticalGrade();
   static void fatal( const QString &err ) { setMessageError(err, ExceptError::FATAL ); }
   static void warn( const QString &err ) { setMessageError(err, ExceptError::WARNING ); }
   static void info( const QString &err ) { setMessageError(err, ExceptError::INFO ); }
   static int isFatal() { return ( _crit_grade == ExceptError::FATAL ); }
   static int isWarning() { return ( _crit_grade == ExceptError::WARNING ); }
   static int isInfo() { return ( _crit_grade == ExceptError::INFO ); }
   /* getting the error string will clear the last error and CritGrade, to avoid calling a clear every time */
   /* It must be called only one time per error*/
   static const QString error()
     {
	QString old_error ( _error );
        _error= "";
        _crit_grade = NONE;
	return old_error;
     }

 private:
   ExceptError()
     {
     }

   static  QString _error;
   static CritGrade   _crit_grade;

};

# define GlobalError ExceptError::Instance()
#endif

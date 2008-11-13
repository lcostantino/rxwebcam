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

#include <v4l2wrap/Error.h>
void ExceptError::setMessageError(const QString &err, ExceptError::CritGrade crit_grade){ 
     _error = QString("Error Str: %1\nPerror Report:%2\n").arg(err).arg(strerror(errno)); 
     _crit_grade = crit_grade;
 
}

ExceptError::CritGrade ExceptError::criticalGrade(){ return _crit_grade;}

ExceptError::CritGrade ExceptError::_crit_grade = ExceptError::INFO ;
QString ExceptError::_error = "";

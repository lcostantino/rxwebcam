
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
#include "ValidateIp.h"

ValidateIp::ValidateIp(QObject *parent) : QValidator(parent)
{
}
/* Note that this is valid if the mask is using 0 as "spaces" */
QValidator::State ValidateIp::validate( QString &input, int & pos ) const
     {
	QStringList octect = input.split(".");
	bool ok;
	
	
	if( octect.size() != 4 )
	   return Invalid;
	
	foreach( QString oct, octect )
	  {
		     
	        int num = oct.toInt(&ok);
	       
	        if( !ok || num > 255 || num < 0 ) 
	          return Invalid;
	       
	  }
	
	return Acceptable;
     }
void ValidateIp::fixup( QString &i) const {}



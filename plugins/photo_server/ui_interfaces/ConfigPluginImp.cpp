
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

#include "ConfigPluginImp.h"
#include <QWidget>
#include <QDialog>
#include <QIcon>
#include <QMessageBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QNetworkInterface>
#include <QNetworkAddressEntry>
#include "ValidateIp.h"


ConfigPluginImp::ConfigPluginImp(const QString & imagesDir,QWidget *parent):QDialog(parent)
{
   QNetworkInterface ifaces;
   QString current_address = "IP: ";
   
   setupUi(this);
   le_ip->setInputMask("000.000.000.000;0");
   le_ip->setValidator( new ValidateIp);
   connect(cb_allips, SIGNAL( stateChanged(int)), SLOT( stateIpChanged(int ) ) );
   cb_allips->setChecked(true);
   _working_dir = imagesDir;
   foreach( QHostAddress ips,ifaces.allAddresses() )
   	if( ips.protocol() == QAbstractSocket::IPv4Protocol )
 		current_address +=  ips.toString() += " - ";

   tl_currentip->setText( current_address );
}



void ConfigPluginImp::stateIpChanged(int current_state ) 
{
   le_ip->setEnabled( !current_state );
   
}
void ConfigPluginImp::setCurrentValues( const QString &ip, const int port, const int msecs )
{
    le_ip->setText(ip);
    
   if( ip.contains("000.000.000.000"))
      cb_allips->setChecked(true);
    else
      cb_allips->setChecked(false);
    
    sb_port->setValue(port);
    sb_seconds->setValue( msecs / 1000 );
}


void ConfigPluginImp::accept()
{
   if( getuid() != 0 && ( sb_port->value() >= 1  && sb_port->value() <= 1024 ) )
     {
	QMessageBox::information(0,tr("Error"),tr("Debe seleccionar un puerto mayor a 1024"));
	return;
     }
    if( sb_seconds->value() == 1 )
     	QMessageBox::information(0,tr("Informacion"),tr("Un tiempo muy bajo puede reducir los frames de visualizacion"));
     
   QDialog::accept();
}


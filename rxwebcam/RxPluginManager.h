#ifndef RX_PLUGIN_MANAGER_H
# define RX_PLUGIN_MANAGER_H

# include "plugin.h"
# include <QDir>
# include <QFileInfo>
# include <QString>
# include <QStringList>
# include <QMap>
# include <QList>
# include <QPluginLoader>

/* Just make it static singleton, to avoid passing more and more ptrs to the stream interface */
/* This class relay on plugin names, no with id, etc, etc. Translation should become from plugin to work as expected */

class RxPluginManager
{

 public:
   static RxPluginManager * Instance()
     {
	static RxPluginManager ins;
	return &ins;
     }

   void setDir( const QString &dn )
     {
	_dname = dn;
     }

   bool loadPlugins()
     {
	QDir pdir(_dname);
	QFileInfoList plist;

	if( !pdir.exists())
	  return false;

	plist = pdir.entryInfoList(QStringList() << "*.so");
	foreach( QFileInfo pname, plist )
	  addPlugin( pname.absoluteFilePath());

	return true;

     }
   const QString getLastError()
     {
	return _last_error;
     }

   bool addPlugin(const QString fname)
     {
	QPluginLoader plug(fname);
	if( plug.load() )
	  {
	     QObject *xplugin = plug.instance();
	     if( xplugin != NULL )
	       {
		  RxWebcamInterface *iface = qobject_cast< RxWebcamInterface *>(xplugin);
		  if( iface )
		    {
		       /* duplicated name, only allow newer versions.. */
		       if( plugin_map.contains(iface->name() ) &&
			   plugin_map[iface->name()]->version() > iface->version() )
		         {
			    plug.unload(); //just in case.
			    return  false;
			 }

		       plugin_map[iface->name()]=iface;
		       return true;
		    }
	       }
	  }
	qDebug("Plugin %s couldn't be loaded\n",qPrintable(fname));
	return false;
     }

   bool setPluginState(  RxWebcamInterface  *ptrPlugin, int state )
     {
	_last_error = "";
	DBG("SetPluginState: %p\n",ptrPlugin);
	ptrPlugin->setEnabled(state);
	if( state )
	  {
	     if(  ptrPlugin->start() )
	       plugins_enabled.append( ptrPlugin );
	     else
	       {
		  _last_error = ptrPlugin->error();
		  return false;
	       }
	  }
	else
	  {
	     int index = plugins_enabled.indexOf(ptrPlugin);
	     if( index != -1 )
	       {
		  ptrPlugin->stop();
		  plugins_enabled.removeAt(index);
	       }
	     else
	       return false;
	  }
	return true;
     }

   bool setPluginState( const QString &pname, int state )
     {
	RxWebcamInterface *xplugin = getPlugin(pname);
	if( xplugin != 0  )
	  return  setPluginState( xplugin,state);

	return false;

     }

   RxWebcamInterface * getPlugin( const QString &name )
     {
	if( plugin_map.contains(name))
	  return plugin_map[name];

	return NULL;
     }

   void showConfig( const QString &name, QWidget *parent=0 )
     {
	RxWebcamInterface *xplugin = getPlugin(name);
	if( xplugin )
	  xplugin->configPlugin(parent );
     }

   const QStringList pluginNames()
     {
	return QStringList( plugin_map.keys());
     }

   void processPlugins(  QImage *img, QWidget *parent=0)
     {

	foreach( RxWebcamInterface *cplugin, plugins_enabled )
	  {
	     DBG("Processing %s\n",qPrintable(cplugin->name()));
	     cplugin->processImage(img,parent);
	  }
     }
 #ifdef MANT
   QImage processPlugins ( QImage &img )
     {
	QImage lastest = img;
	foreach( RxWebcamInterface *cplugin, plugins_enabled )
	  {
	     fprintf(stderr,"Processing SafeMode: %s\n",qPrintable(cplugin->name()));
             lastest = cplugin->processImage(lastest);
	  }
	return lastest;
     }
 #endif 
 private:

   RxPluginManager(){}

   ~RxPluginManager(){}

   QString _dname;
   //plugin map by name
   QMap< QString, RxWebcamInterface *> plugin_map;
   //plugins currently enabled
   QList< RxWebcamInterface *> plugins_enabled;
   QString _last_error;
};

# define PluginManager RxPluginManager::Instance()

#endif


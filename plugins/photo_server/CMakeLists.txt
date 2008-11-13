include(${QT_USE_FILE})

set(pluginphotoserver_SRCS
    thread_server.cpp
    plugin_photo_server.cpp
    simple_server.cpp
   ./ui_interfaces/ConfigPluginImp.cpp    
   ./ui_interfaces/ValidateIp.cpp  
)


SET(pluginphotoserver_UIS
./ui_interfaces/configplugin.ui
)

QT4_WRAP_UI(pluginphotoserver_UIS_H ${pluginphotoserver_UIS} )

include_directories(${CMAKE_CURRENT_BINARY_DIR}
                    ${QT_INCLUDE_DIR}
		    ${QT_QTNETWORK_INCLUDE_DIR}
)


set(pluginphotoserver_MOCS_HDRS
	plugin_photo_server.h
	simple_server.h
	ui_interfaces/ConfigPluginImp.h
)

QT4_WRAP_CPP(pluginphotoserver_MOC_SRCS ${pluginphotoserver_MOCS_HDRS} )

ADD_DEFINITIONS(${QT_DEFINITIONS})
ADD_DEFINITIONS(-DQT_PLUGIN)

ADD_LIBRARY( pluginphotoserver SHARED ${pluginphotoserver_SRCS}
             ${pluginphotoserver_MOC_SRCS} ${pluginphotoserver_UIS_H} 
)
target_link_libraries(pluginphotoserver ${QT_LIBRARIES} ${QT_QTNETWORK_LIBRARIES}  )

install( TARGETS pluginphotoserver DESTINATION /usr/share/rxwebcam/plugins/binary/ )
install( DIRECTORY share_data/photo_server DESTINATION /usr/share/rxwebcam/plugins/
         USE_SOURCE_PERMISSIONS )

install( DIRECTORY share_data/locales DESTINATION /usr/share/rxwebcam/
         USE_SOURCE_PERMISSIONS )


include(${QT_USE_FILE})

SET(pluginmarcos_UIS
./ui_interfaces/configplugin.ui

)

QT4_WRAP_UI(pluginmarcos_UIS_H ${pluginmarcos_UIS} )

set(pluginmarcos_SRCS
    plugin_marcos.cpp
   ./ui_interfaces/ConfigPluginImp.cpp    
)

include_directories(${CMAKE_CURRENT_BINARY_DIR}
                    ${QT_INCLUDE_DIR}
)


set(pluginmarcos_MOCS_HDRS
./plugin_marcos.h
./ui_interfaces/ConfigPluginImp.h
)

QT4_WRAP_CPP(pluginmarcos_MOC_SRCS ${pluginmarcos_MOCS_HDRS} )

ADD_DEFINITIONS(${QT_DEFINITIONS})
ADD_DEFINITIONS(-DQT_PLUGIN)

ADD_LIBRARY( pluginmarcos SHARED ${pluginmarcos_SRCS} ${pluginmarcos_MOC_SRCS}  ${pluginmarcos_UIS_H})

target_link_libraries(pluginmarcos ${QT_LIBRARIES}  )


install( TARGETS pluginmarcos DESTINATION /usr/share/rxwebcam/plugins/binary/ )

install( DIRECTORY share_data/marcos DESTINATION /usr/share/rxwebcam/plugins/
         USE_SOURCE_PERMISSIONS )

install( DIRECTORY share_data/locales DESTINATION /usr/share/rxwebcam/
         USE_SOURCE_PERMISSIONS )



include(${QT_USE_FILE})

set(plugineffect_SRCS
    effect.cpp
    plugin_effects.cpp
   ./ui_interfaces/ConfigPluginImp.cpp    
)


SET(plugineffect_UIS
./ui_interfaces/configplugin.ui
)

QT4_WRAP_UI(plugineffect_UIS_H ${plugineffect_UIS} )

include_directories(${CMAKE_CURRENT_BINARY_DIR}
                    ${QT_INCLUDE_DIR}
)


set(plugineffect_MOCS_HDRS
plugin_effects.h
ui_interfaces/ConfigPluginImp.h
)

QT4_WRAP_CPP(plugineffect_MOC_SRCS ${plugineffect_MOCS_HDRS} )


ADD_DEFINITIONS(${QT_DEFINITIONS})
ADD_DEFINITIONS(-DQT_PLUGIN)


ADD_LIBRARY( plugineffect SHARED ${plugineffect_SRCS} ${plugineffect_MOC_SRCS} ${plugineffect_UIS_H})

target_link_libraries(plugineffect ${QT_LIBRARIES}  )

install( TARGETS plugineffect DESTINATION /usr/share/rxwebcam/plugins/binary/ )
install( DIRECTORY share_data/effects DESTINATION /usr/share/rxwebcam/plugins/ 
	 USE_SOURCE_PERMISSIONS )
	 
install( DIRECTORY share_data/locales DESTINATION /usr/share/rxwebcam/
	 USE_SOURCE_PERMISSIONS )



#Template taken from http://www.bineteri.com/qtwithcmake

FIND_PATH(V4LCONVERT_INCLUDE_DIR libv4lconvert.h /usr/include /usr/local/include )

FIND_LIBRARY(V4LCONVERT_LIB NAMES v4lconvert PATH /usr/lib /usr/local/lib /lib )
FIND_LIBRARY(XVIDCORE_LIB  NAMES xvidcore  PATH /usr/lib /usr/local/lib /lib )
FIND_LIBRARY(REVEL_LIB NAMES revel PATH /usr/lib /usr/local/lib /lib )
SET(OPTIONAL_LIBS "")



include(${QT_USE_FILE})


set(rxwebcam_SRCS
     webcamdevice.cpp
    ./v4l2wrap/grabinputmodes.cpp
    ./v4l2wrap/v4l2uvc.cpp
    ./v4l2wrap/formatv4l2convert.cpp
    ./v4l2wrap/v4l2wrap.cpp
    ./v4l2wrap/Error.cpp
    ./v4l2wrap/grabinputmanager.cpp
    ./ConfigPluginsImp.cpp
    ./movie_encoder.cpp
    ./FormStreamingImp.cpp
    ./WebcamControlImp.cpp
    ./mainwindow.cpp
    ./main.cpp
)



IF ( V4LCONVERT_INCLUDE_DIR AND V4LCONVERT_LIB )
   SET(V4LCONVERT_FOUND TRUE )
ENDIF ( V4LCONVERT_INCLUDE_DIR AND V4LCONVERT_LIB )
   
IF ( V4LCONVERT_FOUND )
   MESSAGE(STATUS "V4LConvert Found: ${V4LCONVERT_LIB} ")
ELSE ( V4LCONVERT_FOUND )
   MESSAGE(FATAL_ERROR "V4LConvert not found!. Get it from xxxx")
ENDIF (V4LCONVERT_FOUND)

IF (XVIDCORE_LIB AND REVEL_LIB )
  
  MESSAGE(STATUS "-> Video Record Enabled: ${XVIDCORE_LIB} && ${REVEL_LIB} Found")
  MESSAGE(STATUS "* inside 3rd_libs, its shared librevel. Also check that its not founding libxvidcore.a.
                    if it's, then remove it and check that libxvidcore.so exists (this would make cmake happy)")
  MESSAGE(STATUS "-> (testing ) Static Video Record Libs  may increase binary in 700kb plus")
   SET(OPTIONAL_LIBS ${REVEL_LIB} ${XVIDCORE_LIB} )  
   ADD_DEFINITIONS(-DWITH_XVID_RECORD  )

ELSE (XVIDCORE_LIB AND REVEL_LIB )
    MESSAGE(WARNING "-> Video Record Disabled. XVidCore Or Revel Lib not found.")
ENDIF (XVIDCORE_LIB AND REVEL_LIB )



SET(rxwebcam_UIS
./ui_interface/opendevice.ui
./ui_interface/configplugins.ui
./ui_interface/streaming.ui
./ui_interface/webcamcontrol.ui
)

QT4_WRAP_UI(rxwebcam_UIS_H ${rxwebcam_UIS} )

QT4_ADD_RESOURCES( rxwebcam_RC_SRCS rxwebcam.qrc )


include_directories(${CMAKE_CURRENT_BINARY_DIR}
                    ${QT_INCLUDE_DIR}
		    )


set(rxwebcam_MOCS_HDRS
./v4l2wrap/v4l2uvc.h
./webcamdevice.h
./mainwindow.h
./v4l2wrap/v4l2wrap.h
./ConfigPluginsImp.h
./FormStreamingImp.h
./WebcamControlImp.h
)

QT4_WRAP_CPP(rxwebcam_MOC_SRCS ${rxwebcam_MOCS_HDRS} )
if(COMMAND cmake_policy)
       cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)
	   
add_executable( rxwebcam
		${rxwebcam_SRCS}
		${rxwebcam_UIS_H}
		${rxwebcam_MOC_SRCS} 
		${rxwebcam_RC_SRCS}
)



#just to remember..
#INCLUDE_DIRECTORIES (
#	       ${QT_INCLUDE_DIR}
#	       ${QT_QTNETWORK_INCLUDE_DIR}
#)

#TARGET_LINK_LIBRARIES (
#		${QT_LIBRARIES}
#		$(QT_QTNETWORK_LIBRARIES)
#)

ADD_DEFINITIONS(${QT_DEFINITIONS})
#ADD_DEFINITIONS(-DQT_PLUGIN)
#...

#ADD_LIBRARY( foo SHARED $(foo_SRCS) )

#ADD_DEFINITIONS(-DQT_NO_DEBUG)

target_link_libraries(rxwebcam ${QT_LIBRARIES} ${V4LCONVERT_LIB} ${OPTIONAL_LIBS} )


install( TARGETS rxwebcam DESTINATION /usr/local/bin )

install( DIRECTORY locales DESTINATION /usr/share/rxwebcam/
         USE_SOURCE_PERMISSIONS )






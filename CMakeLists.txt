project (rxwebcam)
cmake_minimum_required(VERSION 2.4.0)
find_package(Qt4 REQUIRED)

#set( CMAKE_BUILD_TYPE "Debug")

IF ( CMAKE_BUILD_TYPE STREQUAL "Debug" )
   ADD_DEFINITIONS("-DQT_DEBUG -g -DMANT ")
   SET( CMAKE_SHARED_LINKER_FLAGS "-Wl,--warn-unresolved-symbols") 
   MESSAGE(FATAL "ERROR")
ELSE ( CMAKE_BUILD_TYPE STREQUAL "Debug" ) 
   ADD_DEFINITIONS("-DQT_NO_DEBUG_OUTPUT")
   ADD_DEFINITIONS("-DQT_NO_DEBUG")
ENDIF ( CMAKE_BUILD_TYPE STREQUAL "Debug" )

#SET(BUILD_SHARED_LIBS "TRUE")

add_subdirectory(rxwebcam)
add_subdirectory(plugins/effects)
add_subdirectory(plugins/marcos)
add_subdirectory(plugins/photo_server)


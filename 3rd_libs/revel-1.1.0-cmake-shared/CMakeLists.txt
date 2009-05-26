FIND_LIBRARY(XVIDCORE_LIB  NAMES xvidcore  PATH /usr/lib /usr/local/lib /lib )

set(revel_SRCS
	src/BaseEncoder.cpp  
	src/XvidEncoder.cpp  
	src/revelcore.cpp
	src/avilib.c
)

include_directories(${CMAKE_CURRENT_BINARY_DIR}
                    "include/"

)


ADD_LIBRARY( revel SHARED ${revel_SRCS} )

target_link_libraries(revel  ${XVIDCORE_LIB} )

install( TARGETS revel  DESTINATION /usr/local/lib/ )
install( FILES include/revel.h DESTINATION /usr/include/ )


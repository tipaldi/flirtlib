SET(geometry_SRCS 
    point.cpp 
) 

SET(geometry_HDRS 
    point.h
) 

ADD_LIBRARY(geometry SHARED ${geometry_SRCS})
TARGET_LINK_LIBRARIES(geometry boost_serialization-mt)

install(TARGETS geometry
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib/flirtlib
    ARCHIVE DESTINATION lib/flirtlib)

install(FILES ${geometry_HDRS} DESTINATION include/flirtlib/geometry)


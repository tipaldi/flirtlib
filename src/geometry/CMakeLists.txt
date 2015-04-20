SET(geometry_SRCS 
    point.cpp 
) 

SET(geometry_HDRS 
    point.h
) 

ADD_LIBRARY(geometry SHARED ${geometry_SRCS})
TARGET_LINK_LIBRARIES(geometry ${Boost_SERIALIZATION_LIBRARY})

install(TARGETS geometry
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib/flirtlib
    ARCHIVE DESTINATION lib/flirtlib)

install(FILES ${geometry_HDRS} DESTINATION include/flirtlib/geometry)


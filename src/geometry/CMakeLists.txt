SET(geometry_SRCS
    point.cpp
)

SET(geometry_HDRS
    point.h
)

ADD_LIBRARY(flirtlib_geometry SHARED ${geometry_SRCS})
TARGET_LINK_LIBRARIES(flirtlib_geometry ${Boost_SERIALIZATION_LIBRARY})

install(TARGETS flirtlib_geometry
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)

install(FILES ${geometry_HDRS} DESTINATION include/flirtlib/geometry)


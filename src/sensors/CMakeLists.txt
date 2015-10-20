SET(sensors_SRCS
    AbstractReading.cpp
    LaserReading.cpp
)

SET(sensors_HDRS
    AbstractReading.h
    LaserReading.h
)

ADD_LIBRARY(flirtlib_sensors SHARED ${sensors_SRCS})
TARGET_LINK_LIBRARIES(flirtlib_sensors flirtlib_geometry)

install(TARGETS flirtlib_sensors
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)

install(FILES ${sensors_HDRS} DESTINATION include/flirtlib/sensors)

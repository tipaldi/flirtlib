SET(sensors_SRCS 
    AbstractReading.cpp 
    LaserReading.cpp
) 

ADD_LIBRARY(sensors SHARED ${sensors_SRCS})
TARGET_LINK_LIBRARIES(sensors geometry)

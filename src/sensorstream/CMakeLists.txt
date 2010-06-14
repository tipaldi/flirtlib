SET(sensorstream_SRCS 
    CarmenLog.cpp 
    LogSensorStream.cpp
) 

SET(sensorstream_LIBS
    sensors
)

ADD_LIBRARY(sensorstream SHARED ${sensorstream_SRCS})
TARGET_LINK_LIBRARIES(sensorstream ${sensorstream_LIBS})

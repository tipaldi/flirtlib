SET(sensorstream_SRCS
    CarmenLog.cpp
    LogSensorStream.cpp
)

SET(sensorstream_HDRS
    LogReader.h
    LogWriter.h
    SensorStream.h
    CarmenLog.h
    LogSensorStream.h
)

SET(sensorstream_LIBS
    flirtlib_sensors
)

ADD_LIBRARY(flirtlib_sensorstream SHARED ${sensorstream_SRCS})
TARGET_LINK_LIBRARIES(flirtlib_sensorstream ${sensorstream_LIBS})

install(TARGETS flirtlib_sensorstream
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)

install(FILES ${sensorstream_HDRS} DESTINATION include/flirtlib/sensorstream)

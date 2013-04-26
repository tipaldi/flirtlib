ADD_EXECUTABLE(ransacLoopClosureTest RansacLoopClosureTest.cpp)
TARGET_LINK_LIBRARIES(ransacLoopClosureTest feature sensorstream sensors utils)

IF(CAIRO_FOUND)
    ADD_EXECUTABLE(ransacLoopClosureDraw RansacLoopClosureDrawMovie.cpp)
    TARGET_LINK_LIBRARIES(ransacLoopClosureDraw feature sensorstream sensors utils ${CAIRO_LIBRARIES})
ENDIF(CAIRO_FOUND)

QT4_AUTOMOC(
    FLIRTDemo.cpp
)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

ADD_EXECUTABLE(flirtDemo FLIRTDemo.cpp)
TARGET_LINK_LIBRARIES(flirtDemo gui )


ADD_EXECUTABLE(ransacLoopClosureTest RansacLoopClosureTest.cpp)
TARGET_LINK_LIBRARIES(ransacLoopClosureTest flirtlib_feature flirtlib_sensorstream flirtlib_sensors flirtlib_utils)

install(TARGETS ransacLoopClosureTest
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib/flirtlib
    ARCHIVE DESTINATION lib/flirtlib)

IF(CAIRO_FOUND)
    ADD_EXECUTABLE(ransacLoopClosureDraw RansacLoopClosureDrawMovie.cpp)
    TARGET_LINK_LIBRARIES(ransacLoopClosureDraw flirtlib_feature flirtlib_sensorstream flirtlib_sensors flirtlib_utils ${CAIRO_LIBRARIES})
    install(TARGETS ransacLoopClosureDraw
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib/flirtlib
	ARCHIVE DESTINATION lib/flirtlib)
ENDIF(CAIRO_FOUND)

if(BUILD_GUI)
  QT4_AUTOMOC(
      FLIRTDemo.cpp
  )
  INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
  ADD_EXECUTABLE(flirtDemo FLIRTDemo.cpp)
  TARGET_LINK_LIBRARIES(flirtDemo flirtlib_gui)
  install(TARGETS flirtDemo
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib/flirtlib
    ARCHIVE DESTINATION lib/flirtlib)
endif()


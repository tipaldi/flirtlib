SET(feature_SRCS 
    InterestPoint.cpp 
    MultiScaleDetector.cpp
    RangeDetector.cpp
    NormalDetector.cpp
    NormalEdgeDetector.cpp
    NormalBlobDetector.cpp
    CurvatureDetector.cpp
    ShapeContext.cpp
    BetaGrid.cpp
    AbstractFeatureSetMatcher.cpp
    RansacFeatureSetMatcher.cpp
    RansacMultiFeatureSetMatcher.cpp
) 

ADD_LIBRARY(feature SHARED ${feature_SRCS})

ADD_EXECUTABLE(ransacLoopClosureTest RansacLoopClosureTest.cpp)
TARGET_LINK_LIBRARIES(ransacLoopClosureTest feature sensorstream sensors utils)

IF(CAIRO_FOUND)
    ADD_EXECUTABLE(ransacLoopClosureDraw RansacLoopClosureDrawMovie.cpp)
    TARGET_LINK_LIBRARIES(ransacLoopClosureDraw feature sensorstream sensors utils ${CAIRO_LIBRARIES})
ENDIF(CAIRO_FOUND)


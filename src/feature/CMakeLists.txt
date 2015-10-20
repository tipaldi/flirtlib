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

SET(feature_HDRS
    Detector.h
    Descriptor.h
    InterestPoint.h
    MultiScaleDetector.h
    RangeDetector.h
    NormalDetector.h
    NormalEdgeDetector.h
    NormalBlobDetector.h
    CurvatureDetector.h
    ShapeContext.h
    BetaGrid.h
    AbstractFeatureSetMatcher.h
    RansacFeatureSetMatcher.h
    RansacMultiFeatureSetMatcher.h
)

ADD_LIBRARY(flirtlib_feature SHARED ${feature_SRCS})
TARGET_LINK_LIBRARIES(flirtlib_feature ${Boost_SERIALIZATION_LIBRARY})

install(TARGETS flirtlib_feature
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)

install(FILES ${feature_HDRS} DESTINATION include/flirtlib/feature)

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


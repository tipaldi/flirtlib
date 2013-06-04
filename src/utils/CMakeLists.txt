SET(utils_SRCS
    Regression.cpp
    SimplePeakFinder.cpp
    SimpleMinMaxPeakFinder.cpp
    PoseEstimation.cpp
)

SET(utils_HDRS
    Regression.h
    Convolution.h
    Convolution.hpp
    HistogramDistances.h
    HistogramDistances.hpp
    SimplePeakFinder.h
    SimpleMinMaxPeakFinder.h
    PoseEstimation.h
)

ADD_LIBRARY(utils SHARED ${utils_SRCS})

install(TARGETS utils 
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib/flirtlib
    ARCHIVE DESTINATION lib/flirtlib)

install(FILES ${utils_HDRS} DESTINATION include/flirtlib/utils)

SET(gui_SRCS
    Color.cpp
    LaserReadingRenderer.cpp
    InterestPointRenderer.cpp
    PolarGridRenderer.cpp
    SensorStreamWidget.cpp
    RendererWidget.cpp
    MultiScaleDetectorPlotWidget.cpp
    SimplePeakFinderPresenter.cpp
    MultiScaleDetectorPresenter.cpp
    MultiScaleCurvatureDetectorPresenter.cpp
    MultiScaleNormalDetectorPresenter.cpp
    DetectorChooserPresenter.cpp
    DescriptorChooserPresenter.cpp
    ParameterWidget.cpp
    TabbedParameterWidget.cpp
    BoxParameterWidget.cpp
    ShapeContextPresenter.cpp
    BetaGridPresenter.cpp
    DescriptorWidget.cpp
    PolarGridGraphicsItem.cpp
    CorrespondenceRenderer.cpp
    FeatureSetMatcherPresenter.cpp
    RansacPresenter.cpp
)

SET(gui_HDRS
    AbstractRenderer.h
    Color.h
    LaserReadingRenderer.h
    InterestPointRenderer.h
    PolarGridRenderer.h
    SensorStreamWidget.h
    RendererWidget.h
    MultiScaleDetectorPlotWidget.h
    PeakFinderPresenter.h
    SimplePeakFinderPresenter.h
    DetectorPresenter.h
    MultiScaleDetectorPresenter.h
    MultiScaleCurvatureDetectorPresenter.h
    MultiScaleNormalDetectorPresenter.h
    DetectorChooserPresenter.h
    DescriptorChooserPresenter.h
    ParameterWidget.h
    TabbedParameterWidget.h
    BoxParameterWidget.h
    DescriptorPresenter.h
    ShapeContextPresenter.h
    BetaGridPresenter.h
    DescriptorWidget.h
    PolarGridGraphicsItem.h
    CorrespondenceRenderer.h
    FeatureSetMatcherPresenter.h
    RansacPresenter.h
)

SET(gui_LIBS
    flirtlib_sensors
    flirtlib_sensorstream
    flirtlib_feature
    flirtlib_geometry
    ${QT_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${QWT_LIBRARIES}
    flirtlib_utils
)

QT4_AUTOMOC(${gui_SRCS})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

ADD_LIBRARY(flirtlib_gui SHARED ${gui_SRCS})
TARGET_LINK_LIBRARIES(flirtlib_gui ${gui_LIBS})

install(TARGETS flirtlib_gui
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)

install(FILES ${gui_HDRS} DESTINATION include/flirtlib/gui)


include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${QT_INCLUDE_DIR}
)

add_definitions(-DQSL_COMPILE_LIB)

set( qsl_HDRS_NO_MOC
    QSLGlobal.h
    QSLMath.h
    QSLPhysics.h
    QSLComplex.h
    QSLArray1D.h
    QSLArray2D.h
)

set( qsl_HDRS
    QSLFitEngine.h
    QSLFitLine.h
    QSLGraph.h
    QSLPlot.h
    QSLPlotable.h
    QSLPlotArea.h
    QSLPlotCartesian.h
    QSLPlotCartesianSet.h
    QSLPlotLegend.h
    QSLPlotScale.h
)

set( qsl_SRCS
    QSLFitEngine.cpp
    QSLFitLine.cpp
    QSLGraph.cpp
    QSLPlot.cpp
    QSLPlotable.cpp
    QSLPlotArea.cpp
    QSLPlotCartesian.cpp
    QSLPlotCartesianSet.cpp
    QSLPlotLegend.cpp
    QSLPlotScale.cpp
)

QT4_WRAP_CPP(qsl_HDRS_MOC ${qsl_HDRS})

add_library( qsl SHARED
    ${qsl_HDRS}
    ${qsl_HDRS_NO_MOC}
    ${qsl_HDRS_MOC}
    ${qsl_SRCS}
)

target_link_libraries( qsl ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})

install(TARGETS qsl DESTINATION /usr/lib )
install(FILES ${qsl_HDRS_NO_MOC} ${qsl_HDRS} DESTINATION /usr/include/QSL )

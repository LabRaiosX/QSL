# Install script for directory: /home/elvis/dev/CXX/qsl-1.0/src

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}/usr/lib/libqsl.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/lib/libqsl.so")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/lib/libqsl.so"
         RPATH "")
  ENDIF()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/lib/libqsl.so")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/usr/lib" TYPE SHARED_LIBRARY FILES "/home/elvis/dev/CXX/qsl-1.0/build/src/libqsl.so")
  IF(EXISTS "$ENV{DESTDIR}/usr/lib/libqsl.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/lib/libqsl.so")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/lib/libqsl.so")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/QSL/QSLGlobal.h;/usr/include/QSL/QSLMath.h;/usr/include/QSL/QSLPhysics.h;/usr/include/QSL/QSLComplex.h;/usr/include/QSL/QSLArray1D.h;/usr/include/QSL/QSLArray2D.h;/usr/include/QSL/QSLFitEngine.h;/usr/include/QSL/QSLFitLine.h;/usr/include/QSL/QSLGraph.h;/usr/include/QSL/QSLPlot.h;/usr/include/QSL/QSLPlotable.h;/usr/include/QSL/QSLPlotArea.h;/usr/include/QSL/QSLPlotCartesian.h;/usr/include/QSL/QSLPlotCartesianSet.h;/usr/include/QSL/QSLPlotLegend.h;/usr/include/QSL/QSLPlotScale.h")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/usr/include/QSL" TYPE FILE FILES
    "/home/elvis/dev/CXX/qsl-1.0/src/QSLGlobal.h"
    "/home/elvis/dev/CXX/qsl-1.0/src/QSLMath.h"
    "/home/elvis/dev/CXX/qsl-1.0/src/QSLPhysics.h"
    "/home/elvis/dev/CXX/qsl-1.0/src/QSLComplex.h"
    "/home/elvis/dev/CXX/qsl-1.0/src/QSLArray1D.h"
    "/home/elvis/dev/CXX/qsl-1.0/src/QSLArray2D.h"
    "/home/elvis/dev/CXX/qsl-1.0/src/QSLFitEngine.h"
    "/home/elvis/dev/CXX/qsl-1.0/src/QSLFitLine.h"
    "/home/elvis/dev/CXX/qsl-1.0/src/QSLGraph.h"
    "/home/elvis/dev/CXX/qsl-1.0/src/QSLPlot.h"
    "/home/elvis/dev/CXX/qsl-1.0/src/QSLPlotable.h"
    "/home/elvis/dev/CXX/qsl-1.0/src/QSLPlotArea.h"
    "/home/elvis/dev/CXX/qsl-1.0/src/QSLPlotCartesian.h"
    "/home/elvis/dev/CXX/qsl-1.0/src/QSLPlotCartesianSet.h"
    "/home/elvis/dev/CXX/qsl-1.0/src/QSLPlotLegend.h"
    "/home/elvis/dev/CXX/qsl-1.0/src/QSLPlotScale.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")


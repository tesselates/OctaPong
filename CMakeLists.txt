cmake_minimum_required(VERSION 3.1)
if(${CMAKE_VERSION} VERSION_LESS 3.15)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
    cmake_policy(VERSION 3.15)
endif()

project(Pong VERSION 1.0
DESCRIPTION "Sparks in the horizon"
LANGUAGES CXX)

# Qt instructions
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(CMAKE_CXX_STANDARD 11)

# Find components, for these to be found please set Qt5_DIR to the cmake directory of Qt5 ".../qtbase/lib/cmake/Qt5/"
#  This can be done through exporting Qt5_DIR or adding -DQt5_DIR in the cmake command
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)

# set the include dir to "include"
include_directories(include)

add_executable(pong
    main.cpp

    # source
    src/BallModel.cpp
    src/GraphicsManager.cpp
    src/KeyFilter.cpp
    src/LifeLine.cpp
    src/MainWindow.cpp
    src/PaddleModel.cpp
    src/PongApp.cpp
    src/PongModel.cpp
    src/PongView.cpp

    # include
    include/config.hpp
    include/BallModel.hpp
    include/GraphicsManager.hpp
    include/KeyFilter.hpp
    include/KeyListener.hpp
    include/MainWindow.hpp
    include/PaddleModel.hpp
    include/PongApp.hpp
    include/PongModel.hpp
    include/PongView.hpp
    include/utility.hpp

    # ui
    src/ui/mainwindow.ui
    )

target_link_libraries(pong Qt5::Widgets)
target_link_libraries(pong Qt5::Core)


# Documentation
option(BUILD_DOC "Build documentation" ON)
# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
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

# Find components, for these to be found please set Qt5_DIR to the cmake directory of Qt5 ".../qtbase/lib/cmake/Qt5/"
#  This can be done through exporting Qt5_DIR or adding -DQt5_DIR in the cmake command
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)

# set the include dir to "include"
include_directories(include)

add_executable(pong
    main.cpp

    # source
    src/mainwindow.cpp
    src/PaddleFactory.cpp

    # include
    include/config.hpp
    include/mainwindow.hpp
    include/PaddleFactory.hpp
    include/PongApp.hpp

    # ui
    src/ui/mainwindow.ui
    )

target_link_libraries(pong Qt5::Widgets)
target_link_libraries(pong Qt5::Core)

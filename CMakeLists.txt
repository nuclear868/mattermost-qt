cmake_minimum_required(VERSION 3.5)

file(READ .version version)
project(qmattermost VERSION ${version} LANGUAGES CXX)
configure_file(build-config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/sources/build-config.h)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -g -ggdb")

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

option(BUILD_MULTIMEDIA "Enable Multimedia" OFF)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Network REQUIRED)
find_package(Qt5 COMPONENTS WebSockets REQUIRED)

if(BUILD_MULTIMEDIA)
	find_package(Qt5 COMPONENTS Multimedia REQUIRED)
	find_package(Qt5 COMPONENTS MultimediaWidgets REQUIRED)
endif()

include_directories(${Qt5Network_INCLUDE_DIRS} sources/)


if(ANDROID)
  add_library(mattermost-client SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    logindialog.cpp
    logindialog.h
    logindialog.ui
    qmattermostbackend.cpp
    qmattermostbackend.h
    resource.qrc
  )
else()
  file(GLOB_RECURSE SOURCES sources/*.cpp)
  add_executable(qmattermost
    ${SOURCES}
    resource.qrc
  )
  
  if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
	set_property(TARGET qmattermost PROPERTY WIN32_EXECUTABLE true)
  endif()
  
endif()

add_subdirectory (tools)

target_link_libraries(qmattermost PRIVATE Qt5::Widgets Qt5::Network Qt5::WebSockets)

if(BUILD_MULTIMEDIA)
	target_link_libraries(qmattermost PRIVATE Qt5::Multimedia Qt5::MultimediaWidgets)
endif()

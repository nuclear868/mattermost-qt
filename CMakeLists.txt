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

set(APPID "mattermost-qt")

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

find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6 COMPONENTS Network REQUIRED)
find_package(Qt6 COMPONENTS WebSockets REQUIRED)

if(BUILD_MULTIMEDIA)
	find_package(Qt6 COMPONENTS Multimedia REQUIRED)
	find_package(Qt6 COMPONENTS MultimediaWidgets REQUIRED)
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
  add_executable(${APPID}
    ${SOURCES}
    resource.qrc
  )

  if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
	set_property(TARGET ${APPID} PROPERTY WIN32_EXECUTABLE true)
  endif()

endif()

add_subdirectory (tools)

target_link_libraries (${APPID} PRIVATE Qt6::Widgets Qt6::Network Qt6::WebSockets)

if(UNIX)
	include(GNUInstallDirs)
	set(SRC_ICONS_DIR "resources/icons/application-dark")
	set(SRC_ICON_PREFIX "${APPID}-dark")
	set(DST_ICONS_DIR "${CMAKE_INSTALL_DATAROOTDIR}/icons")

	install (TARGETS "${APPID}" RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}")
	install (FILES "${SRC_ICONS_DIR}/${SRC_ICON_PREFIX}-16.png" DESTINATION "${DST_ICONS_DIR}/hicolor/16x16/apps" RENAME "${APPID}.png")
	install (FILES "${SRC_ICONS_DIR}/${SRC_ICON_PREFIX}-32.png" DESTINATION "${DST_ICONS_DIR}/hicolor/32x32/apps" RENAME "${APPID}.png")
	install (FILES "${SRC_ICONS_DIR}/${SRC_ICON_PREFIX}-64.png" DESTINATION "${DST_ICONS_DIR}/hicolor/64x64/apps" RENAME "${APPID}.png")
	install (FILES "${SRC_ICONS_DIR}/${SRC_ICON_PREFIX}-128.png" DESTINATION "${DST_ICONS_DIR}/hicolor/128x128/apps" RENAME "${APPID}.png")
	install (FILES "${SRC_ICONS_DIR}/${SRC_ICON_PREFIX}-256.png" DESTINATION "${DST_ICONS_DIR}/hicolor/256x256/apps" RENAME "${APPID}.png")
	install (FILES "${SRC_ICONS_DIR}/${SRC_ICON_PREFIX}-512.png" DESTINATION "${DST_ICONS_DIR}/hicolor/512x512/apps" RENAME "${APPID}.png")
	install (FILES "${SRC_ICONS_DIR}/${SRC_ICON_PREFIX}-1024.png" DESTINATION "${DST_ICONS_DIR}/hicolor/1024x1024/apps" RENAME "${APPID}.png")
	install (FILES "resources/svg/${SRC_ICON_PREFIX}.svg" DESTINATION "${DST_ICONS_DIR}/hicolor/scalable/apps" RENAME "${APPID}.svg")

	configure_file("resources/mattermost-qt.desktop.in" "resources/mattermost-qt.desktop" @ONLY)
	install (FILES "${CMAKE_CURRENT_BINARY_DIR}/resources/mattermost-qt.desktop" DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/applications" RENAME "${APPID}.desktop")
	configure_file("resources/mattermost-qt.appdata.xml.in" "resources/mattermost-qt.appdata.xml" @ONLY)
	install (FILES "${CMAKE_CURRENT_BINARY_DIR}/resources/mattermost-qt.appdata.xml" DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/metainfo" RENAME "${APPID}.appdata.xml")
endif()

if(BUILD_MULTIMEDIA)
	target_link_libraries(qmattermost PRIVATE Qt6::Multimedia Qt6::MultimediaWidgets)
endif()

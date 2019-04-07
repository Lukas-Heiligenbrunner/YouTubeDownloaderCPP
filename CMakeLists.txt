cmake_minimum_required(VERSION 2.8.11)

project(qt5project)

#set(CMAKE_AUTOMOC ON)
#set(CMAKE_INCLUDE_CURRENT_DIR ON)
#
#find_package(Qt5Widgets)
#
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
#
#set(SOURCE_FILES main.cpp mainwindow.cpp)
#
#add_executable(qt5project ${SOURCE_FILES})
#target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5PrintSupport REQUIRED)
find_package(Qt5Sql REQUIRED)

set(QT5_LIBRARIES Qt5::Widgets Qt5::PrintSupport Qt5::Sql)
add_compile_options(-lcurl)

#
# project main
#
set(TARGET ${CMAKE_PROJECT_NAME})

set(SOURCES
        main.cpp
        gui/mainwindow.cpp api/API.cpp api/API.h datatypes/Hashmap.h api/YouTube.cpp api/YouTube.h datatypes/json.h api/YouTubeToLink.cpp api/YouTubeToLink.h download/DownloadManager.cpp download/DownloadManager.h)

set(UI_SOURCES
        gui/mainwindow.ui
        )

#
# Generate necessary headers from .ui files. (qmake lets `uic` do this job.)
# hint from [Cross-platform Qt5 project using cmake](http://stackoverflow.com/questions/21174586/cross-platform-qt5-project-using-cmake)
#
qt5_wrap_ui(UI_GENERATED_HEADERS ${UI_SOURCES})

#
# IMPORTANT: Adding generated headers to target as dependencies
# hint from [unable to include a ui_form header of QT5 in cmake](http://stackoverflow.com/questions/16245147/unable-to-include-a-ui-form-header-of-qt5-in-cmake)
#
add_executable(${TARGET} ${SOURCES} ${UI_GENERATED_HEADERS})

#
# `target_link_libraries()` rather than `qt5_use_modules()` for CMake 2.8.11 or later
# hint from [CMake & QT5 - QT5_WRAP_UI not generating ui header files](http://stackoverflow.com/questions/25875255/cmake-qt5-qt5-wrap-ui-not-generating-ui-header-files)
#
target_link_libraries(${TARGET} ${QT5_LIBRARIES} curl)

project(parseHttp)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)
find_package(KDE4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})
include_directories(${KDE4_INCLUDES} .)

set(parseHttp_SRCS parseHttp.cpp main.cpp)
qt4_automoc(${parseHttp_SRCS})
kde4_add_executable(parseHttp ${showHttp_SRCS})
target_link_libraries(parseHttp ${QT_QTCORE_LIBRARY} ${KDE4_KPARTS_LIBS})

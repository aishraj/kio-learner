project(metalinkHttp)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)
find_package(KDE4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})
include_directories(${KDE4_INCLUDES} .)

set(metalinkHttp_SRCS metalinkHttp.cpp main.cpp)
qt4_automoc(${metalinkHttp_SRCS})
kde4_add_executable(metalinkHttp ${metalinkHttp_SRCS})
target_link_libraries(metalinkHttp ${QT_QTCORE_LIBRARY} ${KDE4_KPARTS_LIBS})

cmake_minimum_required(VERSION 3.7.2)
project (cppTraining)

# debug configurations
# set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

find_package(PkgConfig REQUIRED)
find_package(CURL REQUIRED)

pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

include_directories(include)
include_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${CURL_INCLUDE_DIR})
include_directories(${GTKMM_INCLUDE_DIRS})

link_directories(${GTKMM_LIBRARY_DIRS})

file(GLOB SOURCES "src/*.cpp")

add_definitions(${GTKMM_CFLAGS_OTHER})

add_executable(cppTraining ${SOURCES})

target_link_libraries(cppTraining ${GTKMM_LIBRARIES} ${CURL_LIBRARIES})
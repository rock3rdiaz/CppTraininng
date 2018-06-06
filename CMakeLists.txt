cmake_minimum_required(VERSION 3.7.2)
project (cppTraining)

# debug configurations
# set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

find_package(libmongoc-1.0 REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(CURL REQUIRED)
find_package(Poco REQUIRED Foundation Net)

pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
pkg_check_modules(libmongoc REQUIRED libmongoc-1.0)

include_directories(include)
include_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${CURL_INCLUDE_DIR})
include_directories(${GTKMM_INCLUDE_DIRS})
include_directories(${LIBMONGOC_INCLUDE_DIR})
include_directories(${Poco_INCLUDE_DIR})

link_directories(${GTKMM_LIBRARY_DIRS})
link_directories(${LIBMONGOC_INCLUDE_DIR})

file(GLOB SOURCES "src/*.cpp")

add_definitions(${GTKMM_CFLAGS_OTHER})

add_executable(cppTraining ${SOURCES})

target_link_libraries(cppTraining ${GTKMM_LIBRARIES} ${CURL_LIBRARIES} ${LIBMONGOC_LIBRARIES} ${Poco_LIBRARIES})
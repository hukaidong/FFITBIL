cmake_minimum_required(VERSION 3.10)

project(tiff)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_BUILD_TYPE DEBUG)
add_definitions(-std=c++17 -ggdb)

add_executable(${PROJECT_NAME} main)

find_package(TIFF REQUIRED)
include_directories(${PROJECT_NAME} ${TIFF_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${TIFF_LIBRARIES})



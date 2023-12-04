cmake_minimum_required(VERSION 3.8)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -ggdb")

message("** include: ${CMAKE_SOURCE_DIR}/common")

include_directories("${CMAKE_SOURCE_DIR}/common")

add_subdirectory("day1")
add_subdirectory("day2")
cmake_minimum_required (VERSION 3.3)
# set (CMAKE_CXX_STANDARD 17)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS_RELEASE "-O3")

project (haneul)
add_definitions("-Wall" "-std=c++1z")
include_directories(include)
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(haneul-exe ${SOURCES})

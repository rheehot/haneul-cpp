cmake_minimum_required (VERSION 3.3)
# set (CMAKE_CXX_STANDARD 17)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

project (haneul)
add_definitions("-Wall" "-std=c++1z" "-O3")
include_directories(include)
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(haneul-exe ${SOURCES})

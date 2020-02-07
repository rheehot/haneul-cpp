cmake_minimum_required (VERSION 2.8.11)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

project (haneul)


include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(haneul-exe ${SOURCES})

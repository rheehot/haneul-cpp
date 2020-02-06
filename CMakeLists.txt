cmake_minimum_required (VERSION 2.8.11)
set (CMAKE_CXX_STANDARD 17)
project (haneul)


include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(haneul-exe ${SOURCES})

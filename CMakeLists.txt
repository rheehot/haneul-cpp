cmake_minimum_required (VERSION 2.8.11)
project (haneul)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(haneul-exe ${SOURCES})

cmake_minimum_required (VERSION 3.8)

find_package(Boost 1.72 REQUIRED)

project (haneul)

set (CMAKE_EXPORT_COMPILE_COMMANDS ON)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -O3")
set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")
set (CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS}")

add_compile_options("-Wall")

include_directories(include)
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(haneul-exe ${SOURCES})

target_link_libraries(haneul-exe LINK_PUBLIC Boost::headers)


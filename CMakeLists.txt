cmake_minimum_required(VERSION 3.20)

project(Mantel)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/)

file(GLOB_RECURSE SOURCES "src/*.cpp")

include_directories({CMAKE_SOURCE_DIR}/src/)
include_directories({CMAKE_SOURCE_DIR}/src/utils)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_executable(Mantel_Test ${SOURCES})

target_link_libraries(Mantel_Test SDL2 SDL2_image SDL2_ttf)
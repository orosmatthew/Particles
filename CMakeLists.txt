cmake_minimum_required(VERSION 3.0)
project(particles)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

file(GLOB_RECURSE SRC "src/*.c src/*.cpp src/*.h src/*.hpp")

add_subdirectory("lib/raylib-4.0.0")

add_executable(particles)
target_sources(particles PRIVATE src/main.cpp)
target_link_libraries(particles PRIVATE raylib)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

target_compile_definitions(particles PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/")
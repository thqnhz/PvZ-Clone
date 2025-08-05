cmake_minimum_required(VERSION 3.10)
project(PvZCloneRaylib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(raylib)

add_executable(PvZCloneRaylib src/main.cpp)

# Copy assets to the build directory
file(COPY src/assets DESTINATION ${CMAKE_BINARY_DIR})

target_link_libraries(PvZCloneRaylib PRIVATE raylib)

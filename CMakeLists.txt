cmake_minimum_required(VERSION 3.10)
project(PvZCloneRaylib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(raylib)

add_executable(PvZCloneRaylib src/main.cpp src/Game/Game.cpp src/Scene/MainMenu.cpp)

target_link_libraries(PvZCloneRaylib PRIVATE raylib)

cmake_minimum_required(VERSION 3.0)

project(game-opengl)

add_executable(game-opengl src/main.cpp src/engine/shader.cpp src/engine/render.cpp src/engine/texture.cpp src/engine/element.cpp src/engine/sprite.cpp src/engine/parallax.cpp)

add_library(glad src/glad/glad.c)

include_directories(include/ include/engine include/stb)

target_include_directories(game-opengl PUBLIC include/*)

target_link_libraries(game-opengl glfw glad GL dl)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
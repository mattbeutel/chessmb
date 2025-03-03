cmake_minimum_required(VERSION 3.29)
project(chessmb)

set(CMAKE_CXX_STANDARD 14)

add_executable(chessmb
        chess.cpp
        chess.h
        definitions.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(chessmb sfml-system sfml-window sfml-graphics sfml-audio)



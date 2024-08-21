cmake_minimum_required(VERSION 3.10)

project(COSC345)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    src/dungeon_dreams/main.cpp
    src/dungeon_dreams/StartScreen.cpp
    src/dungeon_dreams/AsciiArt.cpp
    src/dungeon_dreams/EndScreen.cpp
    src/dungeon_dreams/interactions.cpp
    src/dungeon_dreams/item.cpp
    src/dungeon_dreams/movement.cpp
    src/dungeon_dreams/player.cpp
    src/dungeon_dreams/utils.cpp
)


add_executable(COSC345 ${SOURCES})

include_directories(include)



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

# this should hopefully enable code cov!
if(CMAKE_BUILD_TYPE STREQUAL "Coverage")
    message("Building with code coverage")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-instr-generate -fcoverage-mapping")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-instr-generate -fcoverage-mapping")
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
# this is for windows, in order 2 prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(runTests
    Test/AsciiArtTest.cpp
    Test/EndScreenTest.cpp
    Test/InteractionsTest.cpp
    Test/ItemTest.cpp
    Test/PlayerTest.cpp
    Test/MainTest.cpp
    Test/MovementTest.cpp
    Test/StartScreen.cpp
    Test/UtilsTest.cpp
)

target_link_libraries(runTests gtest_main)

include(GoogleTest)
gtest_discover_tests(runTests)

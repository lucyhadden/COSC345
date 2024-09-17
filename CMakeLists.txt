cmake_minimum_required(VERSION 3.10)

project(COSC345)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    include/AsciiArt.h
    include/EndScreen.h
    include/interactions.h
    include/item.h
    include/miniGames.h
    include/movement.h
    include/player.h
    include/StartScreen.h
    include/utils.h
    include/Equipment.h
    include/Status.h
    include/SafeZone.h
    src/dungeon_dreams/main.cpp
    src/dungeon_dreams/StartScreen.cpp
    src/dungeon_dreams/AsciiArt.cpp
    src/dungeon_dreams/EndScreen.cpp
    src/dungeon_dreams/interactions.cpp
    src/dungeon_dreams/item.cpp
    src/dungeon_dreams/miniGames.cpp
    src/dungeon_dreams/movement.cpp
    src/dungeon_dreams/player.cpp
    src/dungeon_dreams/utils.cpp
    src/dungeon_dreams/Equipment.cpp
    src/dungeon_dreams/Status.cpp
    src/dungeon_dreams/SafeZone.cpp
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

add_executable(DungeonGameTest
    Test/AsciiArtTest.cpp
    Test/EndScreenTest.cpp
    Test/StartScreenTest.cpp
    Test/InteractionsTest.cpp
    Test/ItemTest.cpp
    Test/PlayerTest.cpp
    Test/MainTest.cpp
    Test/MovementTest.cpp
    Test/UtilsTest.cpp
    Test/MiniGamesTest.cpp

    
    src/dungeon_dreams/AsciiArt.cpp
    src/dungeon_dreams/TestUtils.cpp
    src/dungeon_dreams/StartScreen.cpp
    src/dungeon_dreams/EndScreen.cpp
    src/dungeon_dreams/miniGames.cpp
    src/dungeon_dreams/player.cpp
    src/dungeon_dreams/utils.cpp
)

# target_include_directories(runTests PRIVATE include)
# target_include_directories(runTests PRIVATE Test)

# target_compile_definitions(runTests PRIVATE TESTING)

# target_link_libraries(runTests gtest_main)

# include(GoogleTest)
# gtest_discover_tests(runTests)

target_link_libraries(DungeonGameTest gtest gtest_main)
target_link_libraries(DungeonGameTest ${CMAKE_THREAD_LIBS_INIT})

# Enable testing
enable_testing()
add_test(NAME DungeonGameTest COMMAND DungeonGameTest)
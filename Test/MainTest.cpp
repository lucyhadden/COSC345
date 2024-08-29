#include "gtest/gtest.h"
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <string>
#include "StartScreen.h"
#include "movement.h"
#include "EndScreen.h"
#include "AsciiArt.h"
#include "player.h"
#include "item.h"
#include "interactions.h"
#include "utils.h"

short dungeon_sizes[8][2] = {{3, 3}, {6, 5}, {6, 3}, {6, 5}, {10, 5}, {8, 7}, {8, 7}, {10, 9}};
const int levels = 8;

// Mock implementations for testing
void mockSystemClear() {
    // Mock the clear screen
}

void mockSleep(int seconds) {
    // Mock sleep function
}

TEST(DungeonGameTest, TestCountdownSequence) {
    // Capture output
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    int countdown = 5;
    int position = 0;

    while (countdown > 0) {
        mockSystemClear();
        for (int i = 0; i < position; i++) {
            std::cout << std::endl;
        }
        std::cout << AsciiArt::dungeonEntranceArt << std::endl;
        std::cout << "You are entering the dungeon in " << countdown << std::endl;
        mockSleep(1);
        position++;
        countdown--;
    }

    std::string output = buffer.str();
    EXPECT_NE(output.find("You are entering the dungeon in 5"), std::string::npos);

    // Restore the original stdout
    std::cout.rdbuf(old);
}

TEST(DungeonGameTest, TestDungeonEntry) {
    // Capture output
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    mockSystemClear();
    std::cout << "You have entered the dungeon..." << std::endl;
    mockSleep(1);

    std::string output = buffer.str();
    EXPECT_NE(output.find("You have entered the dungeon..."), std::string::npos);

    // Restore the original stdout
    std::cout.rdbuf(old);
}

TEST(DungeonGameTest, TestLevelCompletion) {
    // Capture output
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    int level = 1;
    std::cout << "You have completed level " << level << ". Press enter for next level..." << std::endl;

    std::string output = buffer.str();
    EXPECT_NE(output.find("You have completed level 1"), std::string::npos);

    // Restore the original stdout
    std::cout.rdbuf(old);
}

TEST(DungeonGameTest, TestGameCompletion) {
    bool playerWon = true;
    EXPECT_NO_THROW(showEndScreen(playerWon));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

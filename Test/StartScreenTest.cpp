#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <cstdlib>  
#include "MockAsciiArt.h"
#include <StartScreen.h>
#include "TestUtils.h"
#include "utils.h"


// Testing displayMenu()
TEST(DungeonDreamsTest, TestDisplayMenu) {
    // Redirect stdout to a stringstream to capture output
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    displayMenu();

    std::string output = buffer.str();

    EXPECT_NE(output.find("Welcome to Dungeon Dreams"), std::string::npos);
    EXPECT_NE(output.find("1. View Character Classes"), std::string::npos);
    EXPECT_NE(output.find("2. Start Game"), std::string::npos);
    EXPECT_NE(output.find("3. Exit"), std::string::npos);

    // Restore the original stdout
    std::cout.rdbuf(old);
}

// Testing startingStory()
TEST(DungeonDreamsTest, TestStartingStory) {
    // Expect the function to run without errors
    EXPECT_NO_THROW(startingStory());
}
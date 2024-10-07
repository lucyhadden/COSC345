#include "gtest/gtest.h"
#include <sstream>
#include <iostream>
#include <SafeZone.h>

TEST(DungeonDreamsTest, TestDisplayOptions) {
    // Redirect std::cout to a stringstream
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    // Call the function that prints the options
    displayOptions();

    // Restore std::cout to its original state
    std::cout.rdbuf(old);

    // Define expected output
    std::string expected_output = 
        "Welcome to the safe zone\n"
        "1. Play a minigame to earn more gold!\n"
        "2. Visit the store\n"
        "3. Continue to next level\n"
        "Please enter your choice (1-4): ";

    // Compare the captured output with the expected output
    EXPECT_EQ(buffer.str(), expected_output);
}
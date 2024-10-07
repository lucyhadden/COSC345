#include "gtest/gtest.h"
#include <sstream>
#include <iostream>
#include <SafeZone.h>
#include <Status.h>

TEST(SafeZoneTest, TestDisplayOptions) {
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

TEST(SafeZoneTest, TestInvalidChoice) {
    // Set up mock input and output
    std::stringstream input("4\n3\n");  // Mock input: invalid choice 4, then valid choice 3
    std::stringstream output;

    // Redirect cin and cout to our stringstreams
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    // Set up player stats
    CharacterStats playerStats(KNIGHT);

    // Call the function
    handleChoice(playerStats);

    // Check the output
    std::string outputStr = output.str();
    
    // Expect the correct message for invalid choice (4)
    EXPECT_NE(outputStr.find("Invalid choice. Please try again."), std::string::npos);

    // Check if the menu was re-displayed after invalid choice
    EXPECT_NE(outputStr.find("Welcome to the safe zone"), std::string::npos);
    EXPECT_NE(outputStr.find("1. Play a minigame to earn more gold!"), std::string::npos);
    EXPECT_NE(outputStr.find("2. Visit the store"), std::string::npos);
    EXPECT_NE(outputStr.find("3. Continue to next level"), std::string::npos);
    EXPECT_NE(outputStr.find("Please enter your choice (1-4):"), std::string::npos);

    // Restore cin and cout to their original state
    std::cin.rdbuf(oldCin);
    std::cout.rdbuf(oldCout);
}
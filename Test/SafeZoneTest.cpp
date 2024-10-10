#include "gtest/gtest.h"
#include <sstream>
#include <iostream>
#include <SafeZone.h>
#include <Status.h>

TEST(SafeZoneTest, TestDisplayOptions) {
    std::ostringstream outputBuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputBuffer.rdbuf()); 

    // Call the function that prints the options
    displayOptions();

    // Capture the output
    std::string outputStr = outputBuffer.str();

    // Validate parts of the output
    EXPECT_NE(outputStr.find("Welcome to the safe zone"), std::string::npos);
    EXPECT_NE(outputStr.find("1. Play a minigame to earn more gold!"), std::string::npos);
    EXPECT_NE(outputStr.find("2. Visit the store"), std::string::npos);
    EXPECT_NE(outputStr.find("Please enter your choice (1-3): "), std::string::npos);

    std::cout.rdbuf(oldCout);
}

TEST(SafeZoneTest, TestInvalidChoice) {

    std::ostringstream outputBuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputBuffer.rdbuf()); 

    std::istringstream inputBuffer("4\n3\n"); 
    std::streambuf* oldCin = std::cin.rdbuf(inputBuffer.rdbuf());

    // Set up player stats
    CharacterStats playerStats(KNIGHT);

    // Call the function
    displaySafeZone(playerStats);

    // Capture the output
    std::string outputStr = outputBuffer.str();
    
    // Expect the correct message for invalid choice (4)
    EXPECT_NE(outputStr.find("Invalid choice. Please try again."), std::string::npos);

    // Check if the menu was re-displayed after invalid choice
    EXPECT_NE(outputStr.find("Welcome to the safe zone"), std::string::npos);
    EXPECT_NE(outputStr.find("1. Play a minigame to earn more gold!"), std::string::npos);
    EXPECT_NE(outputStr.find("2. Visit the store"), std::string::npos);
    EXPECT_NE(outputStr.find("3. Continue to next level"), std::string::npos);
    EXPECT_NE(outputStr.find("Please enter your choice (1-3):"), std::string::npos);

    // Restore cin and cout to their original state
    std::cout.rdbuf(oldCout);
    std::cin.rdbuf(oldCin);
}

TEST(SafeZoneTest, TestValidChoiceEndsLoop) {
    // Set up mock input and output
    std::stringstream input("3\n");  // Mock input: valid choice 3
    std::stringstream output;

    // Redirect cin and cout to our stringstreams
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    // Set up player stats
    CharacterStats playerStats(KNIGHT);  // Example player stats

    // Call the function
    handleChoice(playerStats);

    // Check the output
    std::string outputStr = output.str();

    // Since 3 is a valid choice to end the loop, check for no further output
    EXPECT_EQ(outputStr.find("Invalid choice"), std::string::npos);  // No invalid choice message


    // Restore cin and cout to their original state
    std::cin.rdbuf(oldCin);
    std::cout.rdbuf(oldCout);
}

TEST(SafeZoneTest, TestMinigameAlreadyPlayed) {
    // Set up mock input and output
    std::ostringstream outputBuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputBuffer.rdbuf()); 

    std::istringstream inputBuffer("1\n3\n"); 
    std::streambuf* oldCin = std::cin.rdbuf(inputBuffer.rdbuf());

    // Set up player stats and doneMinigame
    CharacterStats playerStats(KNIGHT);  // Example player stats
    
    setDoneMinigame(true);  // Set up condition for already played

    // Call the function
    handleChoice(playerStats);

    // Capture the output
    std::string outputStr = outputBuffer.str();
    
    // Expect to see the message for already played minigame
    EXPECT_NE(outputStr.find("You have already played a minigame"), std::string::npos);
    
    // Check if the menu was re-displayed after invalid choice
    EXPECT_NE(outputStr.find("Welcome to the safe zone"), std::string::npos);
    EXPECT_NE(outputStr.find("1. Play a minigame to earn more gold!"), std::string::npos);
    EXPECT_NE(outputStr.find("2. Visit the store"), std::string::npos);
    EXPECT_NE(outputStr.find("3. Continue to next level"), std::string::npos);
    EXPECT_NE(outputStr.find("Please enter your choice (1-3):"), std::string::npos);

    // Restore cin and cout to their original state
    std::cout.rdbuf(oldCout);
    std::cin.rdbuf(oldCin);
}

TEST(SafeZoneTest, TestStore) {
    // Set up mock input and output
    std::stringstream input("2\n5\n3\n");  // Mock input: 2 to enter the store, 5 to exit the store, 3 to end safezone
    std::stringstream output;

    // Redirect cin and cout to our stringstreams
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    // Set up player stats
    CharacterStats playerStats(KNIGHT);  // Example player stats

    // Call the function (entering the store with option 3)
    handleChoice(playerStats);

    // Capture the output
    std::string outputStr = output.str();

    // Restore cin and cout to their original state
    std::cin.rdbuf(oldCin);
    std::cout.rdbuf(oldCout);

    // Validate that the store introduction appeared
    EXPECT_NE(outputStr.find("Welcome to"), std::string::npos);
    EXPECT_NE(outputStr.find("Please enter your choice (1-5):"), std::string::npos);

    // Validate that the player exited the store by selecting option 5
    EXPECT_NE(outputStr.find("5. Exit Shop"), std::string::npos);
}



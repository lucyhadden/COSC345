#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include <Store.h>
#include <Status.h>

TEST(StoreTest, FirstTimeVisit) {
    // Redirect output to a stringstream
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    // Create a dummy player stats
    CharacterStats playerStats(KNIGHT);  // Adjust depending on your setup

    // Test for first-time visit
    // isFirstTime = true;
    IntroductionToStore(playerStats);

    // Capture the output
    std::string outputStr = output.str();

    // Restore cout
    std::cout.rdbuf(oldCout);

    // Assertions for first time visit
    EXPECT_NE(outputStr.find("Oh a new face? Hello friend, my name is [...]. I am a skeleton"), std::string::npos);
    EXPECT_NE(outputStr.find("This is my shop. Please buy something."), std::string::npos);
}


TEST(StoreTest, SecondTimeVisitOutput) {
    // Redirect output to a stringstream
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    // Create a dummy player stats
    CharacterStats playerStats(KNIGHT);  // Adjust based on your setup

    // // Ensure it's the first-time visit
    // isFirstTime = true;

    // Call the function twice
    IntroductionToStore(playerStats);  // First call - should print first-time messages
    IntroductionToStore(playerStats);  // Second call - should print second-time messages

    // Capture the output
    std::string outputStr = output.str();

    // Restore cout to its original state
    std::cout.rdbuf(oldCout);

    // Assertions for second-time visit
    EXPECT_NE(outputStr.find("Oh a new face? Hello friend, my name is [...]. I am a skeleton"), std::string::npos); // Check first call output
    EXPECT_NE(outputStr.find("This is my shop. Please buy something."), std::string::npos); // Check first call output

    // Check for the second call output
    EXPECT_NE(outputStr.find("Hello again friend! Welcome back to my store."), std::string::npos);
    EXPECT_NE(outputStr.find("Please buy something."), std::string::npos);
}
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include <Store.h>
#include <Status.h>

// Test suite
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

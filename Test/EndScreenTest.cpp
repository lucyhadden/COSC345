#include "gtest/gtest.h"
#include "EndScreen.h"  

TEST(EndScreenTest, TestWinScreen) {
    // Ignore the TERM environment variable warning
    std::string output = showWinScreen();
    EXPECT_THAT(output, ::testing::HasSubstr("Inside, something glimmers — a crown of dark emeralds and gold"));
}

TEST(EndScreenTest, TestLoseScreen) {
    std::string output = showLoseScreen();
    EXPECT_THAT(output, ::testing::HasSubstr("You have failed to retrieve the treasure"));
}
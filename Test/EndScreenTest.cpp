#include "gtest/gtest.h"
#include "EndScreen.h"  

TEST(EndScreenTest, TestWinScreen) {
    // Redirect stdout to a stringstream to capture output
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    winScreen();

    std::string output = buffer.str();
    EXPECT_NE(output.find("You enter a dark room"), std::string::npos);
    EXPECT_NE(output.find("Inside, something glimmers — a crown of dark emeralds and gold"), std::string::npos);
    EXPECT_NE(output.find("You completed the game"), std::string::npos);
    EXPECT_NE(output.find("What would you like to do?"), std::string::npos);
    EXPECT_NE(output.find("1. Restart"), std::string::npos);
    EXPECT_NE(output.find("2. Go to main menu"), std::string::npos);
    EXPECT_NE(output.find("3. Exit"), std::string::npos);

    // Restore the original stdout
    std::cout.rdbuf(old);
}

TEST(EndScreenTest, TestLoseScreen) {
    // Redirect stdout to a stringstream to capture output
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    loseScreen();

    std::string output = buffer.str();
    EXPECT_NE(output.find("Oh no"), std::string::npos);
    EXPECT_NE(output.find("You failed to protect Grizzle and clear the dungeon"), std::string::npos);
    EXPECT_NE(output.find("What would you like to do?"), std::string::npos);
    EXPECT_NE(output.find("1. Restart"), std::string::npos);
    EXPECT_NE(output.find("2. Go to main menu"), std::string::npos);
    EXPECT_NE(output.find("3. Exit"), std::string::npos);

    // Restore the original stdout
    std::cout.rdbuf(old);
}

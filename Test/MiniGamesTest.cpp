#include "gtest/gtest.h"
#include "miniGames.h"  

TEST(MiniGamesTest, TestGame1) {
    // Redirect stdout to a stringstream to capture output
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    game1();

    std::string output = buffer.str();
    EXPECT_NE(output.find("Welcome to the Word Unscramble Game!"), std::string::npos);
    EXPECT_NE(output.find("Unscramble the word:"), std::string::npos);
    EXPECT_NE(output.find("Enter your answer:"), std::string::npos);
    EXPECT_NE(output.find("Correct! The unscrambled word is indeed"), std::string::npos);
    EXPECT_NE(output.find("Game over! Your final score is"), std::string::npos);

    // Restore the original stdout
    std::cout.rdbuf(old);
}


TEST(MiniGamesTest, TestSpinWheel) {
    // Redirect stdout to a stringstream to capture output
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    int gameSelection = spinWheel();

    std::string output = buffer.str();
    EXPECT_NE(output.find("Spinning the wheel..."), std::string::npos);
    EXPECT_NE(output.find("The wheel stops at:"), std::string::npos);

    // Verify that the game selection is between 1 and 4
    EXPECT_GE(gameSelection, 1);
    EXPECT_LE(gameSelection, 4);

    // Restore the original stdout
    std::cout.rdbuf(old);
}

TEST(MiniGamesTest, TestMiniGames) {
    // Redirect stdout to a stringstream to capture output
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    miniGames();

    std::string output = buffer.str();
    EXPECT_NE(output.find("You Have Entered The MiniGames!"), std::string::npos);
    EXPECT_NE(output.find("Spinning the wheel..."), std::string::npos);
    EXPECT_NE(output.find("The wheel stops at:"), std::string::npos);

    // Restore the original stdout
    std::cout.rdbuf(old);
}
#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <cstdlib>  
#include "MockAsciiArt.h"
#include <StartScreen.h>
#include "TestUtils.h"
#include "utils.h"

// Testing displayMenu()
TEST(StartScreenTest, TestDisplayMenu) {
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

TEST(StartScreenTest, MenuChooseOption) {
    std::ostringstream outputBuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputBuffer.rdbuf()); 

    std::istringstream inputBuffer("0\n2\n"); // Simulate choosing the Knight class
    std::streambuf* oldCin = std::cin.rdbuf(inputBuffer.rdbuf());

    handleMenuChoice();

    // Capture the output
    std::string outputStr = outputBuffer.str();

    EXPECT_NE(outputStr.find("Invalid choice. Please try again."), std::string::npos);
    EXPECT_NE(outputStr.find("Starting the game..."), std::string::npos);

    // Restore cout and cin
    std::cout.rdbuf(oldCout);
    std::cin.rdbuf(oldCin);
}

// Test the displayCharacterClasses function
TEST(DisplayCharacterClassesTest, DisplayCharacterClassesOutput) {
    std::string expectedKnight = R"(
              /
       ,~~   /
   _  <=)  _/_
  /I\.="==.{>
  \I/-\T/-'
      /_\
     // \\_
    _I    /
)";
    std::string expectedMage = R"(
            ,    _
           /|   | |
         _/_\_  >_<
        .-\-/.   |
       /  | | \_ |
       \ \| |\__(/
       /(`---')  |
      / /     \  |
   _.'  \'-'  /  |
   `----'`=-='   '
)";
    std::string expectedThief = R"(
   .-.
  (o o) 
   | O \
  /  .  \
 /_'---'_\
  |     |
 /       \
)";
    std::string expectedTank = R"(
    ___
 __(   )====::
/~~~~~~~~~\
\O.O.O.O.O/
)";
    std::string expectedCleric = R"(
  /\_/\ 
 / o o \
(   "   )
 \~(*)~/
  \~_~/
   | |
  /   \
 /_____\
 )";

    std::ostringstream outputBuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputBuffer.rdbuf()); 

    std::istringstream inputBuffer("0\n1\n"); // Simulate choosing the Knight class
    std::streambuf* oldCin = std::cin.rdbuf(inputBuffer.rdbuf());

    // Call the function to test
    displayCharacterClasses();

    // Capture the output
    std::string output = outputBuffer.str();

    // Verify the output contains the expected text
    EXPECT_NE(output.find("Character Classes in Dungeon Dreams: The Goblin Guide"), std::string::npos);
    EXPECT_NE(output.find("1. Knight"), std::string::npos);
    EXPECT_NE(output.find(expectedKnight), std::string::npos);
    EXPECT_NE(output.find("2. Mage"), std::string::npos);
    EXPECT_NE(output.find(expectedMage), std::string::npos);
    EXPECT_NE(output.find("3. Thief"), std::string::npos);
    EXPECT_NE(output.find(expectedThief), std::string::npos);
    EXPECT_NE(output.find("4. Tank"), std::string::npos);
    EXPECT_NE(output.find(expectedTank), std::string::npos);
    EXPECT_NE(output.find("5. Cleric"), std::string::npos);
    EXPECT_NE(output.find(expectedCleric), std::string::npos);
    EXPECT_NE(output.find("Press any key to return to the main menu..."), std::string::npos);

    // Restore cout and cin
    std::cout.rdbuf(oldCout);
    std::cin.rdbuf(oldCin);
}

TEST(StartScreenTest, StartingStory) {
    std::string expectedStoryStart = R"(
    _________________________________________________________
    |                                                       |
    |                                                       |
    |   ^  ^  ^   ^      ___I_      ^  ^   ^  ^  ^   ^  ^   |
    |  /|\/|\/|\ /|\    /\-_--\    /|\/|\ /|\/|\/|\ /|\/|\  |
    |  /|\/|\/|\ /|\   /  \_-__\   /|\/|\ /|\/|\/|\ /|\/|\  |
    |  /|\/|\/|\ /|\   |[]| [] |   /|\/|\ /|\/|\/|\ /|\/|\  |   
    |                                                       |
    |_______________________________________________________|
)";

    std::ostringstream outputBuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputBuffer.rdbuf()); 

    std::istringstream inputBuffer("\n"); // Simulate choosing the Knight class
    std::streambuf* oldCin = std::cin.rdbuf(inputBuffer.rdbuf());

    handleMenuChoice();

    // Capture the output
    std::string outputStr = outputBuffer.str();

    EXPECT_NE(outputStr.find(expectedStoryStart), std::string::npos);
    EXPECT_NE(outputStr.find("In a world filled with dungeons and monsters, adventure awaits at every corner. You are an aspiring adventurer, whose dreams have always been filled with epic quests and heroic deeds."), std::string::npos);
    EXPECT_NE(outputStr.find("One fateful morning, you set off for the capital, leaving behind your village and mundane life. The grand walls of the capital greet you with an air of opportunity and excitement."), std::string::npos);
    EXPECT_NE(outputStr.find("Are you ready to face the challenges ahead?"), std::string::npos);
    EXPECT_NE(outputStr.find("With a heart full of hope and a spirit ready for adventure, you march straight to the Adventurers' Guild..."), std::string::npos);
    EXPECT_NE(outputStr.find("Press enter to continue..."), std::string::npos);

    // Restore cout and cin
    std::cout.rdbuf(oldCout);
    std::cin.rdbuf(oldCin);
}

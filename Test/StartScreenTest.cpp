#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <cstdlib>  
#include "MockAsciiArt.h"
#include <StartScreen.h>
#include "TestUtils.h"
#include "utils.h"

/*TEST(DungeonDreamsTest, TestFunction) {
    // Redirect stdout to a stringstream to capture output
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    function();

    std::string output = buffer.str();
    EXPECT_NE(output.find("Welcome to Dungeon Dreams"), std::string::npos);
    EXPECT_NE(output.find("1. View Character Classes"), std::string::npos);
    EXPECT_NE(output.find("2. Start Game"), std::string::npos);
    EXPECT_NE(output.find("3. Exit"), std::string::npos);
    EXPECT_NE(output.find("Starting story..."), std::string::npos);

    // Restore the original stdout
    std::cout.rdbuf(old);
}
**/

// Testing displayWelcome()
TEST(DungeonDreamsTest, TestDisplayWelcome) {
    // Redirect stdout to a stringstream to capture output
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    // Call the display welcome method
    displayWelcome();

    //Verify that the dragon ASCII art is displayed
    std::string output = buffer.str();
    EXPECT_NE(output.find("Dragon Art"), std::string::npos);

    // Verify that the menu options are displayed
    EXPECT_NE(output.find("1. View Character Classes"), std::string::npos);
    EXPECT_NE(output.find("2. Start Game"), std::string::npos);
    EXPECT_NE(output.find("3. Exit"), std::string::npos);

    // Verify that the starting story is displayed
    EXPECT_NE(output.find("Starting story..."), std::string::npos);

    // Restore the original stdout
    std::cout.rdbuf(old);

}

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

// Testing handleMenuChoice()
 TEST(DungeonDreamsTest, TestHandleMenuChoice) {
        // Redirect stdin to a stringstream to simulate user input
    std::stringstream input;
    std::streambuf* old = std::cin.rdbuf(input.rdbuf());

    // Redirect stdout to a stringstream to capture output
    std::stringstream output;
    std::streambuf* oldOut = std::cout.rdbuf(output.rdbuf());

    // Test case 1: Valid choice 1
    input << "1" << std::endl;
    handleMenuChoice();
    EXPECT_TRUE(output.str().find("handleClassChoice") != std::string::npos);

    // Test case 2: Valid choice 2
    input << "2" << std::endl;
    handleMenuChoice();
    EXPECT_TRUE(output.str().find("Starting the game...") != std::string::npos);

    // Test case 3: Valid choice 3
    input << "3" << std::endl;
    handleMenuChoice();
    EXPECT_TRUE(output.str().find("Exiting game. Goodbye!") != std::string::npos);

    // Test case 4: Invalid choice
    input << "4" << std::endl;
    handleMenuChoice();
    EXPECT_TRUE(output.str().find("Invalid choice. Please try again.") != std::string::npos);
    EXPECT_TRUE(output.str().find("1. View Character Classes") != std::string::npos);

    // Restore the original stdin and stdout
    std::cin.rdbuf(old);
    std::cout.rdbuf(oldOut);
 }

// Testing displayCharacterClasses()
TEST(DungeonDreamsTest, TestHandleClassChoice) {
    // Redirect stdout to a stringstream to capture output
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    handleClassChoice();

    std::string output = buffer.str();
    EXPECT_NE(output.find("Character Classes in Dungeon Dreams"), std::string::npos);
    EXPECT_NE(output.find("1. Knight"), std::string::npos);
    EXPECT_NE(output.find("2. Mage"), std::string::npos);
    EXPECT_NE(output.find("3. Thief"), std::string::npos);
    EXPECT_NE(output.find("4. Tank"), std::string::npos);
    EXPECT_NE(output.find("5. Cleric"), std::string::npos);
    EXPECT_NE(output.find("Press any key to return to the main menu..."), std::string::npos);

    // Restore the original stdout
    std::cout.rdbuf(old);
}

// Testing startingStory()
TEST(DungeonDreamsTest, TestStartingStory) {
    // Expect the function to run without errors
    EXPECT_NO_THROW(startingStory());
}

TEST(DungeonDreamsTest, TestPressAnyKeyToContinue2) {
    // Redirect stdout to a stringstream to capture output
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    pressAnyKeyToContinue2();

    std::string output = buffer.str();
    EXPECT_NE(output.find("Press enter to continue..."), std::string::npos);

    // Restore the original stdout
    std::cout.rdbuf(old);
}
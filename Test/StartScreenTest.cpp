#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <cstdlib>  
#include "MockAsciiArt.h"
#include <StartScreen.h>
#include "TestUtils.h"
#include "utils.h"


// // Testing displayWelcome()
// TEST(StartScreenTest, TestDisplayWelcome) {
//     // Expect the function to run without errors
//     EXPECT_NO_THROW(displayWelcome());
// }

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

// Testing handleMenuChoice()
// TEST(DungeonDreamsTest, TestHandleMenuChoice) {
//     std::istringstream input("3\n");
//     std::cin.rdbuf(input.rdbuf());

//     EXPECT_NO_THROW(handleMenuChoice());
// }

/** Testing displayCharacterClasses()
TEST(StartScreenTest, TestDisplayCharacterClasses) {
    // Expect the function to run without errors
    EXPECT_NO_THROW(displayCharacterClasses());
}

// Testing startingStory()
TEST(StartScreenTest, TestStartingStory) {
    // Expect the function to run without errors
    EXPECT_NO_THROW(startingStory());
}
*/

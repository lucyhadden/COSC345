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
    IntroductionToStore(playerStats);  // Second call - should print second-time messages

    // Capture the output
    std::string outputStr = output.str();

    // Restore cout to its original state
    std::cout.rdbuf(oldCout);

    // Check for the second call output
    EXPECT_NE(outputStr.find("Hello again friend! Welcome back to my store."), std::string::npos);
    EXPECT_NE(outputStr.find("Please buy something."), std::string::npos);
}

TEST(StoreTest, DisplayStoreMenuShowsCorrectItems) {
    // Redirect output to a stringstream
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    // Create a dummy player stats
    CharacterStats playerStats(KNIGHT);  // Adjust depending on your setup

    // Simulate user input for option 1 (View Stock) and pressing enter
    std::stringstream input("1\n\n");
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());

    // Call the function
    DisplayStoreMenu(playerStats);

    // Capture the output
    std::string outputStr = output.str();

    // Restore cout and cin to their original state
    std::cout.rdbuf(oldCout);
    std::cin.rdbuf(oldCin);

    // Assertions to check if "Sword of Valor" is printed
    EXPECT_NE(outputStr.find("Sword of Valor"), std::string::npos);  // Check for the real item
    EXPECT_NE(outputStr.find("Steel Shield"), std::string::npos); // Check for another real item

    // Assertions to check if a made-up item is not printed
    EXPECT_EQ(outputStr.find("Made-Up Item"), std::string::npos);  // Check that a fake item is NOT present
}

TEST(StoreTest, DisplayStoreMenuDialogueOption) {
    // Redirect output to a stringstream
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    // Create a dummy player stats
    CharacterStats playerStats(KNIGHT);  // Adjust depending on your setup

    // Simulate user input for option 3 (Talk)
    std::stringstream input("3\n"); // Input to select option 3
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());

    // Call the function
    DisplayStoreMenu(playerStats);

    // Capture the output
    std::string outputStr = output.str();

    // Restore cout and cin to their original state
    std::cout.rdbuf(oldCout);
    std::cin.rdbuf(oldCin);

    // Assertion to check if the dialogue message is printed
    EXPECT_NE(outputStr.find("I don't have any dialogue options for this right now."), std::string::npos);
}

TEST(StoreTest, DisplayStoreMenuShowsInventory) {
    // Redirect output to a stringstream
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    // Create a dummy player stats
    CharacterStats playerStats(KNIGHT);

    // Simulate user input for option 4 (My Inventory)
    std::stringstream input("4\n\n"); // Input to select option 4 and press enter
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());

    // Call the function
    DisplayStoreMenu(playerStats);

    // Capture the output
    std::string outputStr = output.str();

    // Restore cout and cin to their original state
    std::cout.rdbuf(oldCout);
    std::cin.rdbuf(oldCin);

    // Assertions to check if the inventory is printed correctly
    EXPECT_NE(outputStr.find("--- Inventory ---"), std::string::npos); // Check for inventory header
    // Check for the full output line of the Sword of Valor
    EXPECT_NE(outputStr.find("Item: Sword of Valor | Attack Boost: 10 | Defense Boost: 5"), std::string::npos);
    // Check for the full output line of the Staff of Wisdom with correct values
    EXPECT_NE(outputStr.find("Item: Staff of Wisdom | Attack Boost: 15 | Defense Boost: 3"), std::string::npos);

    // Assertions for "Press enter to continue..." message
    EXPECT_NE(outputStr.find("Press enter to continue..."), std::string::npos);  // Check if the message is printed
}

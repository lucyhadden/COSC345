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
    setIsFirstTime();
    IntroductionToStore(playerStats);

    // Capture the output
    std::string outputStr = output.str();

    // Restore cout
    std::cout.rdbuf(oldCout);

    // Assertions for first time visit
    EXPECT_NE(outputStr.find("Oh a new face? Hello friend, my name is Sive. I am a skeleton"), std::string::npos);
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

    // Assertions to check if "Wooden Spatula" is printed
    EXPECT_NE(outputStr.find("Wooden Spatula"), std::string::npos);  // Check for the real item
    EXPECT_NE(outputStr.find("Shinguards"), std::string::npos); // Check for another real item

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
extern Inventory playerInventory;

TEST(StoreTest, DisplayStoreMenuShowsInventory) {
    // Redirect output to a stringstream
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    // Create a dummy player stats
    CharacterStats playerStats(KNIGHT);

    // Simulate user input for option 4 (My Inventory)
    std::stringstream input("4\n\n"); // Input to select option 4 and press enter
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());

    CharacterClass playerClass = KNIGHT; 
    initializeInventory(playerInventory, playerClass);

    // Call the function
    DisplayStoreMenu(playerStats);

    // Capture the output
    std::string outputStr = output.str();

    // Restore cout and cin to their original state
    std::cout.rdbuf(oldCout);
    std::cin.rdbuf(oldCin);

    // Debugging: print captured output
    std::cout << "Captured Output:\n" << outputStr << std::endl;
    
    // Assertions to check if the inventory is printed correctly
    EXPECT_NE(outputStr.find("--- Inventory ---"), std::string::npos); // Check for inventory header
    // Check for the full output line of the Wooden Spatula

    EXPECT_NE(outputStr.find("Sword of Valor"), std::string::npos);
    EXPECT_EQ(outputStr.find("Item: Staff of Wisdom"), std::string::npos); 

    // Assertions for "Press enter to continue..." message
    EXPECT_NE(outputStr.find("Press enter to continue..."), std::string::npos);  // Check if the message is printed
}


TEST(StoreTest, DisplayWholeInventory) {
    // Redirect output to a stringstream
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    // Create a dummy player stats
    CharacterStats playerStats(KNIGHT);

    // Simulate user input for option 4 (My Inventory)
    std::stringstream input("4\n\n"); // Input to select option 4 and press enter
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());

    CharacterClass playerClass = KNIGHT; 
    initializeInventory(playerInventory, playerClass);
    playerClass = MAGE; 
    initializeInventory(playerInventory, playerClass);
    playerClass = THIEF; 
    initializeInventory(playerInventory, playerClass);
    playerClass = CLERIC; 
    initializeInventory(playerInventory, playerClass);
    playerClass = TANK; 
    initializeInventory(playerInventory, playerClass);

    // Call the function
    DisplayStoreMenu(playerStats);

    // Capture the output
    std::string outputStr = output.str();

    // Restore cout and cin to their original state
    std::cout.rdbuf(oldCout);
    std::cin.rdbuf(oldCin);

    // Debugging: print captured output
    std::cout << "Captured Output:\n" << outputStr << std::endl;
    
    // Assertions to check if the inventory is printed correctly
    EXPECT_NE(outputStr.find("--- Inventory ---"), std::string::npos); // Check for inventory header
    // Check for the full output line of the Wooden Spatula
    EXPECT_NE(outputStr.find("Sword of Valor"), std::string::npos);
    EXPECT_NE(outputStr.find("Staff of Wisdom"), std::string::npos); 
    EXPECT_NE(outputStr.find("Dagger of Speed"), std::string::npos); 
    EXPECT_NE(outputStr.find("Holy Mace"), std::string::npos); 

    // Assertions for "Press enter to continue..." message
    EXPECT_NE(outputStr.find("Press enter to continue..."), std::string::npos);  // Check if the message is printed
}

// Test to check if a player can successfully purchase an item when they have enough gold
TEST(ShopTest, PurchaseItemWithEnoughGold) {
    // Redirect output to a stringstream to capture console output
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    // Mock player stats with enough gold
    CharacterStats playerStats(KNIGHT);
    playerStats.gold = 50;  // Give enough gold to buy an item

    // Simulate user input for option 4 (My Inventory)
    std::stringstream input("2\n1\n"); // Input to select option 4 and press enter
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());

    DisplayStoreMenu(playerStats);

    // Restore cout to its original state
    std::cout.rdbuf(oldCout);

    // Capture output
    std::string outputStr = output.str();

    // Assertions:
    // Check if the item was successfully purchased and the gold was deducted
    EXPECT_EQ(playerStats.gold, 15);  // Gold should be reduced by the item's cost (100 - 50)
    

    // Check the output to confirm the purchase message
    EXPECT_NE(outputStr.find("Thank you for your purchase."), std::string::npos);
}

// Test to check if the player can not purchase when not enough gold
TEST(ShopTest, PurchaseItemWhenNotFound) {
    // Redirect output to a stringstream to capture console output
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    // Mock player stats with enough gold
    CharacterStats playerStats(KNIGHT);
    playerStats.gold = 10;  // Give enough gold to buy an item

    // Simulate user input for option 4 (My Inventory)
    std::stringstream input("2\n1\n"); // Input to select option 2 and purchase option 1
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());

    DisplayStoreMenu(playerStats);

    // Restore cout to its original state
    std::cout.rdbuf(oldCout);

    // Capture output
    std::string outputStr = output.str();

     // Debugging: print captured output
    // std::cout << "Captured Output:\n" << outputStr << std::endl;
    
    // Assertions:
    // Check if no gold was deducted
    EXPECT_EQ(playerStats.gold, 10);
    

    // Check the output to confirm the purchase message
    EXPECT_NE(outputStr.find("Item ID not found."), std::string::npos);
}


// Test to check if the player can not purchase when not enough gold
TEST(ShopTest, PurchaseItemWithNotEnoughGold) {
    // Redirect output to a stringstream to capture console output
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    // Mock player stats with enough gold
    CharacterStats playerStats(KNIGHT);
    playerStats.gold = 10;  // Give enough gold to buy an item

    // Simulate user input for option 4 (My Inventory)
    std::stringstream input("2\n2\n"); // Input to select option 2 and purchase option 1
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());

    DisplayStoreMenu(playerStats);

    // Restore cout to its original state
    std::cout.rdbuf(oldCout);

    // Capture output
    std::string outputStr = output.str();

     // Debugging: print captured output
    // std::cout << "Captured Output:\n" << outputStr << std::endl;
    
    // Assertions:
    // Check if no gold was deducted
    EXPECT_EQ(playerStats.gold, 10);
    

    // Check the output to confirm the purchase message
    EXPECT_NE(outputStr.find("You don't have enough gold to purchase this item."), std::string::npos);
}

// Test to check if the player can not purchase when not enough gold
TEST(ShopTest, PurchaseHealingPotionsA) {
    // Redirect output to a stringstream to capture console output
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    // Mock player stats with enough gold
    CharacterStats playerStats(KNIGHT);
    playerStats.gold = 100;  // Give enough gold to buy an item

    // Simulate user input for option 4 (My Inventory)
    std::stringstream input("2\n4\n"); // Input to select option 2 and purchase option 1
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());

    DisplayStoreMenu(playerStats);

    // Restore cout to its original state
    std::cout.rdbuf(oldCout);

    // Capture output
    std::string outputStr = output.str();

     // Debugging: print captured output
    // std::cout << "Captured Output:\n" << outputStr << std::endl;
    
    // Assertions:
    // Check if no gold was deducted
    EXPECT_EQ(playerStats.gold, 95);
    EXPECT_EQ(playerStats.health, 160);
    

    // Check the output to confirm the purchase message
    // EXPECT_NE(outputStr.find("You don't have enough gold to purchase this item."), std::string::npos);
}


// Test to check if the player can not purchase when not enough gold
TEST(ShopTest, PurchaseHealingPotionsB) {
    // Redirect output to a stringstream to capture console output
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    // Mock player stats with enough gold
    CharacterStats playerStats(KNIGHT);
    playerStats.gold = 100;  // Give enough gold to buy an item

    // Simulate user input for option 4 (My Inventory)
    std::stringstream input("2\n5\n"); // Input to select option 2 and purchase option 1
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());

    DisplayStoreMenu(playerStats);

    // Restore cout to its original state
    std::cout.rdbuf(oldCout);

    // Capture output
    std::string outputStr = output.str();

     // Debugging: print captured output
    // std::cout << "Captured Output:\n" << outputStr << std::endl;
    
    // Assertions:
    // Check if no gold was deducted
    EXPECT_EQ(playerStats.gold, 80);
    EXPECT_EQ(playerStats.health, 180);
    

    // Check the output to confirm the purchase message
    // EXPECT_NE(outputStr.find("You don't have enough gold to purchase this item."), std::string::npos);
}


// Test to check if the player can not purchase when not enough gold
TEST(ShopTest, PurchaseHealingPotionsC) {
    // Redirect output to a stringstream to capture console output
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    // Mock player stats with enough gold
    CharacterStats playerStats(KNIGHT);
    playerStats.gold = 100;  // Give enough gold to buy an item

    // Simulate user input for option 4 (My Inventory)
    std::stringstream input("2\n6\n"); // Input to select option 2 and purchase option 1
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());

    DisplayStoreMenu(playerStats);

    // Restore cout to its original state
    std::cout.rdbuf(oldCout);

    // Capture output
    std::string outputStr = output.str();

    // Assertions:
    // Check if no gold was deducted
    EXPECT_EQ(playerStats.gold, 50);
    EXPECT_EQ(playerStats.health, 230);
    
}

TEST(ShopTest, TestInvalidChoice) {

    std::ostringstream outputBuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputBuffer.rdbuf()); 

    std::istringstream inputBuffer("6\n"); 
    std::streambuf* oldCin = std::cin.rdbuf(inputBuffer.rdbuf());

    // Set up player stats
    CharacterStats playerStats(KNIGHT);

    // Call the function
    DisplayStoreMenu(playerStats);

    // Capture the output
    std::string outputStr = outputBuffer.str();
    
        // Debugging: print captured output
    std::cout << "Captured Output:\n" << outputStr << std::endl;

    // Expect the correct message for invalid choice (4)
    EXPECT_NE(outputStr.find("Invalid choice. Please try again."), std::string::npos);

    // Restore cin and cout to their original state
    std::cout.rdbuf(oldCout);
    std::cin.rdbuf(oldCin);
}
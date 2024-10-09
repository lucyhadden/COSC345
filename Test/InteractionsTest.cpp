#include "gtest/gtest.h"
#include "interactions.h" 
#include "Status.h" 

/** 
TEST(InteractionsTest, DummyTest) {
    EXPECT_TRUE(true);  
}
*/

//test pressAnyKeyToContinue
TEST(InteractionsTest, PressAnyKeyToContinue){
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());  // Redirect std::cout

    // Call the function that prints the message
    pressAnyKeyToContinue();

    // Restore std::cout to its original state
    std::cout.rdbuf(old);

    // Define expected output
    std::string expected_output = "Press enter to continue...";

    // Compare the captured output with the expected output
    EXPECT_EQ(buffer.str(), expected_output);
}

//test resetPlayerStats
TEST(InteractionsTest, ResetPlayerStatKnight){
    // Redirect cout to capture output
    std::ostringstream outputBuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputBuffer.rdbuf()); 

    // Simulate cin for user input
    std::istringstream inputBuffer("1\n"); // Simulate choosing the Knight class
    std::streambuf* oldCin = std::cin.rdbuf(inputBuffer.rdbuf());

    CharacterClass playerClass = KNIGHT; 
    CharacterStats playerStats(playerClass);

    resetPlayerStats(playerStats, playerClass); 

    // Capture the output
    std::string outputStr = outputBuffer.str();

    // Validate that the welcome message appeared
    EXPECT_NE(outputStr.find("Welcome to the Adventurer's Guild!"), std::string::npos);
    EXPECT_NE(outputStr.find("Select Class: "), std::string::npos);

    // Validate the character class options appeared
    EXPECT_NE(outputStr.find("1. Knight"), std::string::npos);
    EXPECT_NE(outputStr.find("2. Mage"), std::string::npos);
    EXPECT_NE(outputStr.find("3. Thief"), std::string::npos);
    EXPECT_NE(outputStr.find("4. Tank"), std::string::npos);
    EXPECT_NE(outputStr.find("5. Cleric"), std::string::npos);

    // Verify that class selection was successful
    EXPECT_EQ(playerClass, KNIGHT);
    EXPECT_EQ(playerStats.health, 150);
    EXPECT_EQ(playerStats.attack, 20);
    EXPECT_EQ(playerStats.defense, 15);
    EXPECT_EQ(playerStats.agility, 10);
    EXPECT_EQ(playerStats.intelligence, 5);
    EXPECT_EQ(playerStats.gold, 0);

    // Validate the message indicating class selection
    EXPECT_NE(outputStr.find("You have chosen the noble Knight class!"), std::string::npos);

    // Validate additional output after class selection
    EXPECT_NE(outputStr.find("It is time to accept your first quest as an adventurer!"), std::string::npos);
    EXPECT_NE(outputStr.find("Ah here's a simple one, an escort job through a low class dungeon."), std::string::npos);
    EXPECT_NE(outputStr.find("Good Luck!"), std::string::npos);
    EXPECT_NE(outputStr.find("Ah, there you are! Name’s Grizzle. Heard you're the new adventurer everyone’s talking about!"), std::string::npos);
    EXPECT_NE(outputStr.find("I need a bit of help, see? This dungeon just popped up recently — real simple stuff, nothing to worry about."), std::string::npos);

    // Restore cout and cin
    std::cout.rdbuf(oldCout);
    std::cin.rdbuf(oldCin);
}

TEST(InteractionsTest, ResetPlayerStatMage){
    // Redirect cout to capture output
    std::ostringstream outputBuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputBuffer.rdbuf()); 

    // Simulate cin for user input
    std::istringstream inputBuffer("2\n"); // Simulate choosing the Knight class
    std::streambuf* oldCin = std::cin.rdbuf(inputBuffer.rdbuf());

    CharacterClass playerClass = MAGE;
    CharacterStats playerStats(playerClass);

    resetPlayerStats(playerStats, playerClass); 

    // Capture the output
    std::string outputStr = outputBuffer.str();

    // Verify that class selection was successful
    EXPECT_EQ(playerClass, MAGE);
    EXPECT_EQ(playerStats.health, 80);
    EXPECT_EQ(playerStats.attack, 25);
    EXPECT_EQ(playerStats.defense, 5);
    EXPECT_EQ(playerStats.agility, 15);
    EXPECT_EQ(playerStats.intelligence, 30);
    EXPECT_EQ(playerStats.gold, 0);

    // Validate the message indicating class selection
    EXPECT_NE(outputStr.find("You have chosen the mystical Mage class!"), std::string::npos);

    // Restore cout and cin
    std::cout.rdbuf(oldCout);
    std::cin.rdbuf(oldCin);
}

//test levelPlay
//TEST(InteractionsTest, LevelPlay){}

//test setUpLevel
TEST(InteractionsTest, SetUpLevel){
// Test level 1
    setupLevel(1);
    EXPECT_EQ(enemyType, "Slime");
    EXPECT_EQ(enemyHealth, 10);
    EXPECT_EQ(enemyDamage, 10);
    EXPECT_EQ(trapType, "Pitfall");
    EXPECT_EQ(trapDamage, 10);

    // Test level 2
    setupLevel(2);
    EXPECT_EQ(enemyType, "Skeleton");
    EXPECT_EQ(enemyHealth, 15);
    EXPECT_EQ(enemyDamage, 15);
    EXPECT_EQ(trapType, "Falling rock");
    EXPECT_EQ(trapDamage, 15);

    // Test level 3
    setupLevel(3);
    EXPECT_EQ(enemyType, "Cave Spider");
    EXPECT_EQ(enemyHealth, 15);
    EXPECT_EQ(enemyDamage, 15);
    EXPECT_EQ(trapType, "Swinging blade");
    EXPECT_EQ(trapDamage, 15);

    // Test level 4
    setupLevel(4);
    EXPECT_EQ(enemyType, "Ghostly knight");
    EXPECT_EQ(enemyHealth, 20);
    EXPECT_EQ(enemyDamage, 20);
    EXPECT_EQ(trapType, "Spiked floor");
    EXPECT_EQ(trapDamage, 20);

    // Test level 5
    setupLevel(5);
    EXPECT_EQ(enemyType, "Banshee");
    EXPECT_EQ(enemyHealth, 20);
    EXPECT_EQ(enemyDamage, 20);
    EXPECT_EQ(trapType, "Phantom chain");
    EXPECT_EQ(trapDamage, 20);

    // Test level 6
    setupLevel(6);
    EXPECT_EQ(enemyType, "Fire Golem");
    EXPECT_EQ(enemyHealth, 30);
    EXPECT_EQ(enemyDamage, 30);
    EXPECT_EQ(trapType, "Boulder");
    EXPECT_EQ(trapDamage, 30);

    // Test level 7
    setupLevel(7);
    EXPECT_EQ(enemyType, "Liche");
    EXPECT_EQ(enemyHealth, 30);
    EXPECT_EQ(enemyDamage, 30);
    EXPECT_EQ(trapType, "Magical rune");
    EXPECT_EQ(trapDamage, 30);

    // Test level 8
    setupLevel(8);
    EXPECT_EQ(enemyType, "Wyvern");
    EXPECT_EQ(enemyHealth, 40);
    EXPECT_EQ(enemyDamage, 40);
    EXPECT_EQ(trapType, "Fire trap");
    EXPECT_EQ(trapDamage, 40);

    // Test default case (unknown level)
    std::ostringstream buffer; // Create a string stream to capture output
    std::streambuf *oldCout = std::cout.rdbuf(buffer.rdbuf()); // Redirect std::cout to the string stream

    setupLevel(9);  // Passing an invalid level number

    std::cout.rdbuf(oldCout); // Restore std::cout

    EXPECT_EQ(buffer.str(), "Unknown level\n"); // Check that the output matches expected message
}

//test processTileInteraction
//TEST(InteractionsTest, ProcessTileInteraction){}
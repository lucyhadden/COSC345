#include "gtest/gtest.h"
#include "interactions.h"  

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
//TEST(InteractionsTest, ResetPlayerStats){}

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
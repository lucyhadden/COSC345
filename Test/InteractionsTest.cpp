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

//test tiles
//TEST(InteractionsTest, Tiles){}

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
}

//test processTileInteraction
//TEST(InteractionsTest, ProcessTileInteraction){}
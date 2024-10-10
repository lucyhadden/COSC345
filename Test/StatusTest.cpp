#include <gtest/gtest.h>
#include <Status.h>


// Test Suite for upgradeStats
TEST(StatusTest, UpgradeKnight) {
    std::ostringstream outputBuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputBuffer.rdbuf()); 

    CharacterClass playerClass = KNIGHT; 
    CharacterStats playerStats(playerClass);
    upgradeStats(playerStats, playerClass);

    // Expected stats after upgrade
    EXPECT_EQ(playerStats.health, 160); 
    EXPECT_EQ(playerStats.attack, 25);      
    EXPECT_EQ(playerStats.defense, 18);     
    EXPECT_EQ(playerStats.agility, 10);     
    EXPECT_EQ(playerStats.intelligence, 5); 
    EXPECT_EQ(playerStats.gold, 5);         

    std::cout.rdbuf(oldCout);
}
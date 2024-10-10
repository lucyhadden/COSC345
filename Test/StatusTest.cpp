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

TEST(StatusTest, UpgradeMage) {
    std::ostringstream outputBuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputBuffer.rdbuf()); 

    CharacterClass playerClass = MAGE; 
    CharacterStats playerStats(playerClass);
    upgradeStats(playerStats, playerClass);

    // Expected stats after upgrade
    EXPECT_EQ(playerStats.health, 85); 
    EXPECT_EQ(playerStats.attack, 32);      
    EXPECT_EQ(playerStats.defense, 5);     
    EXPECT_EQ(playerStats.agility, 15);     
    EXPECT_EQ(playerStats.intelligence, 35); 
    EXPECT_EQ(playerStats.gold, 5);         

    std::cout.rdbuf(oldCout);
}

TEST(StatusTest, UpgradeThief) {
    std::ostringstream outputBuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputBuffer.rdbuf()); 

    CharacterClass playerClass = THIEF; 
    CharacterStats playerStats(playerClass);
    upgradeStats(playerStats, playerClass);

    // Expected stats after upgrade
    EXPECT_EQ(playerStats.health, 107);      // Health +7
    EXPECT_EQ(playerStats.attack, 19);       // Attack +4
    EXPECT_EQ(playerStats.defense, 10);      // Defense unchanged
    EXPECT_EQ(playerStats.agility, 30);      // Agility +5
    EXPECT_EQ(playerStats.intelligence, 10); // Intelligence unchanged
    EXPECT_EQ(playerStats.gold, 5);         // Gold +5

    std::cout.rdbuf(oldCout);
}

TEST(StatusTest, UpgradeCleric) {
    std::ostringstream outputBuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputBuffer.rdbuf()); 

    CharacterClass playerClass = CLERIC; 
    CharacterStats playerStats(playerClass);
    upgradeStats(playerStats, playerClass);

    // Expected stats after upgrade
    EXPECT_EQ(playerStats.health, 118);      // Health +8
    EXPECT_EQ(playerStats.attack, 10);       // Attack unchanged
    EXPECT_EQ(playerStats.defense, 24);      // Defense +4
    EXPECT_EQ(playerStats.agility, 8);       // Agility unchanged
    EXPECT_EQ(playerStats.intelligence, 29); // Intelligence +4
    EXPECT_EQ(playerStats.gold, 5);         // Gold +5

    std::cout.rdbuf(oldCout);
}

TEST(StatusTest, UpgradeTank) {
    std::ostringstream outputBuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputBuffer.rdbuf()); 

    CharacterClass playerClass = TANK; 
    CharacterStats playerStats(playerClass);
    upgradeStats(playerStats, playerClass);

    // Expected stats after upgrade
    EXPECT_EQ(playerStats.health, 212);      // Health +12
    EXPECT_EQ(playerStats.attack, 18);       // Attack unchanged
    EXPECT_EQ(playerStats.defense, 36);      // Defense +6
    EXPECT_EQ(playerStats.agility, 5);       // Agility unchanged
    EXPECT_EQ(playerStats.intelligence, 8);  // Intelligence unchanged
    EXPECT_EQ(playerStats.gold, 5);         // Gold +5

    std::cout.rdbuf(oldCout);
}
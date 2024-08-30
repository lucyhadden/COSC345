#include "gtest/gtest.h"
#include <iostream> 
#include <string> 
#include "player.h" 

TEST(PlayerTest, PlayerGetterTest) {
    
    Player player("Player", 100, 10, 5, 10, 5);
    
    ASSERT_TRUE(player.getName() == "Player");
    ASSERT_TRUE(player.getHealth() == 100);
    ASSERT_TRUE(player.getAttack() == 10);
    ASSERT_TRUE(player.getDefense() == 5);
    ASSERT_TRUE(player.getStealth() == 10);
    ASSERT_TRUE(player.getLuck() == 5);

    //EXPECT_TRUE(true);  
}

TEST(PlayerTest, PlayerSetterTest) {
    
    Player player("Player", 100, 10, 5, 10, 5);

    player.setName("Grizzle");
    player.setHealth(1);
    player.setAttack(0);
    player.setDefense(0);
    player.setStealth(0); 
    player.setLuck(100);

    ASSERT_TRUE(player.getHealth() == 1);
    ASSERT_TRUE(player.getAttack() == 0);
    ASSERT_TRUE(player.getDefense() == 0);
    ASSERT_TRUE(player.getStealth() == 0);
    ASSERT_TRUE(player.getLuck() == 100);

    //EXPECT_TRUE(true);  
}

TEST(PlayerTest, PlayerInventoryTest){
    Player player("Player", 100, 10, 5, 10, 5);
    player.addToInventory("Rusty dagger", 1);

    const string expected_output = "Player's Inventory:\n   1x Rusty dagger\n\n"

    ASSERT_TRUE(player.displayInventory() == expected_output);

    //EXPECT_TRUE(true);  
}

TEST(PlayerTest, PlayerFindInventoryTest){
    Player player("Player", 100, 10, 5, 10, 5);
    player.addToInventory("Rusty dagger", 1);
    player.addToInventory("Minor healing potion", 3);

    ASSERT_TRUE(player.findItem("Rusty dagger"));

    //EXPECT_TRUE(true);  
}

TEST(PlayerTest, PlayerRemoveInventoryTest){
    Player player("Player", 100, 10, 5, 10, 5);
    player.addToInventory("Minor healing potion", 3);

    player.removeFromInventory("Minor healing potion", 1);

    const string expected_output = "Player's Inventory:\n   2x Minor healing potion\n\n"

    ASSERT_TRUE(player.displayInventory() == expected_output);

    //EXPECT_TRUE(true);  
}

TEST(PlayerTest, PlayerAlive){
    Player player("Corpse", 0, 10, 5, 10, 5);

    ASSERT_FALSE(player.isAlive());

    //EXPECT_TRUE(true);  
}

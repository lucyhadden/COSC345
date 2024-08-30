#include "gtest/gtest.h"
#include "item.h"  

TEST(ItemTest, ItemGetterTest) {
    
    Item item("Rusty dagger", "equippable", "A rusty dagger with a worn out handle", "▬|═══");
    
    ASSERT_TRUE(item.getName() == "Player");
    ASSERT_TRUE(item.getType() == "equippable");
    ASSERT_TRUE(item.getDescription() == "A rusty dagger with a worn out handle");
    ASSERT_TRUE(item.getIcon() == "▬|═══");

    //EXPECT_TRUE(true);  
}
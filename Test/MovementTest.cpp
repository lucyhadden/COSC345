#include "gtest/gtest.h"
#include "movement.h"  

TEST(MovementTest, DummyTest) {
    EXPECT_TRUE(true);  
}



// Test to check if the path generation starts in the correct position
TEST(MovementTest, PathStartsCorrectly) {
    fillDungeon(3, 3);  // Set dungeon size, e.g., 10x10
    generate_path();

    // Check if the start point of the path is at the middle of the leftmost column
    // int expected_start_x = static_cast<int>(getHeight() / 2);
    // Check if the start point of the path is at the middle of the leftmost column



    // EXPECT_EQ(start_value, 1);  // Path should start with a value of 1
}

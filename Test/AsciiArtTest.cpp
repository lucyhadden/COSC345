#include "gtest/gtest.h"
#include "AsciiArt.h"

TEST(AsciiArtTest, DummyTest) {
    EXPECT_TRUE(true);  
}


// Test for getGuildMaster
TEST(AsciiArtTest, GetGuildMasterTest) {
    std::string expectedArt = R"(

           .=(((=.       
          i;'   `:i      
          !__   __!      
         (~(_)-(_)~)     
          !   n   !      
           \  -  /       
           !`---'!       
          /`-._.-'\      
     _.-~'\_/ |o\_/`~-._       _+_     
    '         |o        `     /   \
===========================================


===========================================
)";
    EXPECT_EQ(AsciiArt::getGuildMaster(), expectedArt);
}

// Test for Grizzle normal expression
TEST(AsciiArtTest, GetGrizzleNormalExpressionTest) {
    std::string expectedArt = R"(
              ———————————
           /               \
    ____ -     –       –     - ____
  /          ( o )   ( o )          \
  \ ____                       ____ /
        |          ^          |
         \      -v———v-      /
           \                /
              ———————————   
)";
    EXPECT_EQ(AsciiArt::getGrizzleNormalExpression(), expectedArt);
}

// Test for Grizzle angry expression
TEST(AsciiArtTest, GetGrizzleAngryExpressionTest) {
    std::string expectedArt = R"(
              ———————————
           /               \
    ____ -      \     /       - ____
  /          ( o )   ( o )          \
  \ ____                       ____ /
        |          ^          |
         \      -v———v-      /
          \                 /
              ———————————  
)";
    EXPECT_EQ(AsciiArt::getGrizzleAngryExpression(), expectedArt);
}

// Test for Grizzle happy expression
TEST(AsciiArtTest, GetGrizzleHappyExpressionTest) {
    std::string expectedArt = R"(
              ———————————
           /               \
    ____ -     -       –     - ____
  /          ( o )   ( o )          \
  \ ____      \\\      \\\     ____ /
        |          ^          |
         \      'v———v'      /
          \                 /
              ———————————   
)";
    EXPECT_EQ(AsciiArt::getGrizzleHappyExpression(), expectedArt);
}

// Test for Grizzle scared expression
TEST(AsciiArtTest, GetGrizzleScaredExpressionTest) {
    std::string expectedArt = R"(
              ———————————
           /               \
    ____ -     –       –     - ____
  /          ( o )   ( o )          \
  \ ____           ^           ____ /
        |      _________      |
         \    | -v———v- |    /
          \    —————————    /
              ———————————   
)";
    EXPECT_EQ(AsciiArt::getGrizzleScaredExpression(), expectedArt);
}

// Test for WinArt 4
TEST(AsciiArtTest, GetWinArt4Test) {
    std::string expectedArt = R"(
  _ ___ _
 '-|   |-'
   |___|
  / / \ \
 ' |___| '
   || ||   
)";
    EXPECT_EQ(AsciiArt::getWinArt4(), expectedArt);
}

// Test for WinArt 5
TEST(AsciiArtTest, GetWinArt5Test) {
    std::string expectedArt = R"(
  _ ___ _
 '-|   |-'
   |___|
  \ / \ /
   |___| 
   // \\   
)";
    EXPECT_EQ(AsciiArt::getWinArt5(), expectedArt);
}

// Test for WinArt 6
TEST(AsciiArtTest, GetWinArt6Test) {
    std::string expectedArt = R"(
    _ ___ 
   '__  o|
     |___|
      /|\
     |_|_|
      |_|_
)";
    EXPECT_EQ(AsciiArt::getWinArt6(), expectedArt);
}

// Test for WinArt 7
TEST(AsciiArtTest, GetWinArt7Test) {
    std::string expectedArt = R"(
    _ ___ 
   '__  o|
     |___|
   ,- / \ \,
     |___|
     '/ \,
)";
    EXPECT_EQ(AsciiArt::getWinArt7(), expectedArt);
}

// Test for WinArt 8
TEST(AsciiArtTest, GetWinArt8Test) {
    std::string expectedArt = R"(
    _ ___ 
   '__  o|
     |___|
   ,- / \ \,
     |___|
     '/ \,
)";
    EXPECT_EQ(AsciiArt::getWinArt8(), expectedArt);
}

// Test for WinArt 9
TEST(AsciiArtTest, GetWinArt9Test) {
    std::string expectedArt = R"(
    ___
   |  o| 
   |___|
   /   \
   | | |
   |_| |
   |  |
   |__|
)";
    EXPECT_EQ(AsciiArt::getWinArt9(), expectedArt);
}

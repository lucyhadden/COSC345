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
              -----------
           /               \
    ____ -     -       -     - ____
  /          ( o )   ( o )          \
  \ ____                       ____ /
        |          ^          |
         \      -v---v-      /
           \                /
              -----------   
)";
    EXPECT_EQ(AsciiArt::getGrizzleNormalExpression(), expectedArt);
}

// Test for Grizzle angry expression
TEST(AsciiArtTest, GetGrizzleAngryExpressionTest) {
    std::string expectedArt = R"(
              -----------
           /               \
    ____ -      \     /       - ____
  /          ( o )   ( o )          \
  \ ____                       ____ /
        |          ^          |
         \      -v---v-      /
          \                 /
              -----------  
)";
    EXPECT_EQ(AsciiArt::getGrizzleAngryExpression(), expectedArt);
}

// Test for Grizzle happy expression
TEST(AsciiArtTest, GetGrizzleHappyExpressionTest) {
    std::string expectedArt = R"(
              -----------
           /               \
    ____ -     -       -     - ____
  /          ( o )   ( o )          \
  \ ____      \\\      \\\     ____ /
        |          ^          |
         \      'v---v'      /
          \                 /
              -----------   
)";
    EXPECT_EQ(AsciiArt::getGrizzleHappyExpression(), expectedArt);
}

// Test for Grizzle scared expression
TEST(AsciiArtTest, GetGrizzleScaredExpressionTest) {
    std::string expectedArt = R"(
              -----------
           /               \
    ____ -     -       -     - ____
  /          ( o )   ( o )          \
  \ ____           ^           ____ /
        |      _________      |
         \    | -v---v- |    /
          \    ---------    /
              -----------   
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

// Test for getShopkeeper
TEST(AsciiArtTest, GetShopkeeperTest) {
    std::string expectedArt = R"(       
                    .                             
                   .$r                            
                  z$$$b                                   
                z$$$$$$$e                                 
             .d$$$$$$$$$$$b.                              
          zd$$$$$$$$$$$$$$$$$$e.                          
      z*************$*************4                       
      F         .*"   "%c.         L                      
     d     .z*"    .-.    "*e.     4                      
     F .z*"       (o.o)       "*e.  L                     
    dP"            |U|            ^*$                     
    F$            __|__            .PL                    
   d *          //.=|=.\\          4 3                    
  .F 4.        // .=|=. \\  _____  $  L                   
  d   F        \\ .=|=. // /Sive/\ F  3                   
  P   $'========================='4%   L                  
 d    3        Sive's Wares       d    *                  
 P    4r                          $    ^L                 
'%=====%============*=============%=====*      
)";
    EXPECT_EQ(AsciiArt::getShopkeeper(), expectedArt);
}

// Test for getShrugShopkeeper
TEST(AsciiArtTest, GetShrugShopkeeperTest) {
    std::string expectedArt = R"(       
                    .                             
                   .$r                            
                  z$$$b                                   
                z$$$$$$$e                                 
             .d$$$$$$$$$$$b.                              
          zd$$$$$$$$$$$$$$$$$$e.                          
      z*************$*************4                       
      F         .*"   "%c.         L                      
     d     .z*"    .-.    "*e.     4                      
     F .z*"       (0.0)       "*e.  L                     
    dP"            |w|            ^*$                     
    F$      __    __|__    __      .PL                    
   d *        \\//.=|=.\\//        4 3                    
  .F 4.        \/ .=|=. \/  _____  $  L                   
  d   F           .=|=.    /Sive/\ F  3                   
  P   $'========================='4%   L                  
 d    3        Sive's Wares       d    *                  
 P    4r                          $    ^L                 
'%=====%============*=============%=====*      
)";
    EXPECT_EQ(AsciiArt::getShrugShopkeeper(), expectedArt);
}

// Test for getRightTalkShopkeeper
TEST(AsciiArtTest, GetRightTalkShopkeeperTest) {
    std::string expectedArt = R"(       
                    .                             
                   .$r                            
                  z$$$b                                   
                z$$$$$$$e                                 
             .d$$$$$$$$$$$b.                              
          zd$$$$$$$$$$$$$$$$$$e.                          
      z*************$*************4                       
      F         .*"   "%c.         L                      
     d     .z*"    .-.    "*e.     4                      
     F .z*"       (>.o)       "*e.  L                     
    dP"            |<|            ^*$                     
    F$            __|__   />       .PL                    
   d *          //.=|=.\\//        4 3                    
  .F 4.        // .=|=. \/  _____  $  L                   
  d   F        \\ .=|=.    /Sive/\ F  3                   
  P   $'========================='4%   L                  
 d    3        Sive's Wares       d    *                  
 P    4r                          $    ^L                 
'%=====%============*=============%=====*      
)";
    EXPECT_EQ(AsciiArt::getRightTalkShopkeeper(), expectedArt);
}

// Test for getLeftTalkShopkeeper
TEST(AsciiArtTest, GetLeftTalkShopkeeperTest) {
    std::string expectedArt = R"(       
                    .                             
                   .$r                            
                  z$$$b                                   
                z$$$$$$$e                                 
             .d$$$$$$$$$$$b.                              
          zd$$$$$$$$$$$$$$$$$$e.                          
      z*************$*************4                       
      F         .*"   "%c.         L                      
     d     .z*"    .-.    "*e.     4                      
     F .z*"       (o.<)       "*e.  L                     
    dP"            |>|            ^*$                     
    F$       <\   __|__            .PL                    
   d *        \\//.=|=.\\          4 3                    
  .F 4.        \/ .=|=. \\  _____  $  L                   
  d   F           .=|=. // /Sive/\ F  3                   
  P   $'========================='4%   L                  
 d    3        Sive's Wares       d    *                  
 P    4r                          $    ^L                 
'%=====%============*=============%=====*      
)";
    EXPECT_EQ(AsciiArt::getLeftTalkShopkeeper(), expectedArt);
}

// Test for getDragonWelcomeArt
TEST(AsciiArtTest, GetDragonWelcomeArtTest) {
    std::string expectedArt = R"(
                         _                    _
                  ,/                        \,
        _________{(                          })_________
       /.-------./\\                        //\.-------.\
      //@@@@@@@//@@\\  )                (  //@@\\@@@@@@@\\
     //@@@@@@@//@@@@>>/                  \<<@@@@\\@@@@@@@\\
    //O@O@O@O//@O@O//                      \\O@O@\\O@O@O@O\\
  //OOOOOOOO//OOOO||          \  /          ||OOOO\\OOOOOOOO\\
 //O%O%O%O%//O%O%O%\\         ))((         //%O%O%O\\%O%O%O%O\\
||%%%%%%%%//'  `%%%%\\       //  \\       //%%%%'   `\\%%%%%%%||
((%%%%%%%((      %%%%%\\    ((    ))    //%%%%%       ))%%%%%%))
 \:::' `::\\      `:::::\\   \)~~(/    //:::::'      //::' `:::/
  )'     `;)'      (`  ` \\ `<@  @>' / / '  ')      `(;'     `(
          (               \`\ )^^( /  /               )
        _                  ) \\oo/   (
       (@)                  \  `'   /                      _
       |-|\__________________\__^__<________oOo__________ (@)
       |-|                                  VVV           |-|
       |-|   __          __  _                            |-|
       |-|  \ \        / / | |                            |-|
       |-|   \ \  /\  / /__| | ___ ___  _ __ ___   ___    |-|
       |-|    \ \/  \/ / _ \ |/ __/ _ \| '_ ` _ \ / _ \   |-|
       |-|     \  /\  /  __/ | (_| (_) | | | | | |  __/   |-|
       |-|      \/  \/ \___|_|\___\___/|_| |_| |_|\___|   |-|
       |-|                                                |-|
       |_|\_____________________________________________  | |
       (@)                 / ,/ \_____/ \\ ~\/~         `\|-|
        ~             ___//^~      \____/\\               (@)
                     <<<  \     __  <____/||               ~
                               <   \ <___/||
                                  || <___//
                                  \ \/__//
                                   ~----~
)";
    EXPECT_EQ(AsciiArt::getDragonWelcomeArt(), expectedArt);
}

#include "gtest/gtest.h"
#include "EndScreen.h"  

//TEST for winScreen
TEST(EndScreenTest, WinScreenTest) {

    std::string expectedWinArt1 = R"(
         ,.,",','=.
      ,'.''         '=. 
     ','                `"=.
    |o`"=._                 `"=.     
    | ;`-.o`"=._             . ' "., 
    |o;    `"-.o`"=._     ,'    ,,:-o;   
    | ;     (#) `-.o `"=.`_.--"_o.-; ;
    |o;._    "      `".o|o_.--"    ;o;
     "=._o--._        ; | ;        ; ;
          "=._o--._   ;o|o;     _._;o;
              "=._o._; | ;_.--"o.--"
                    "=.o|o_.--""
)";
    
    std::string expectedWinArt2 = R"(
           .=""_;=._
       ,-"_,=""     `"=.                  
      "=._o`"-._        `"=.
         `"=._o`"=._      _`"=._             
              :=._o "=._."_.-="'"=._
      __.--" , ; `"=._o." ,-"""-._ ".   
    ._"  ,. .` ` `` ,  `"-._"-._   ". .
    |o`"=._` , "` `; .". ,  "-._"-._; ;              
    | ;`-.o`"=._; ." ` '`."\` . "-._ /
    |o;    `"-.o`"=._``  '` " ,__.--o;   
    | ;     (#) `-.o `"=.`_.--"_o.-; ;
    |o;._    "      `".o|o_.--"    ;o;
     "=._o--._        ; | ;        ; ;
          "=._o--._   ;o|o;     _._;o;
              "=._o._; | ;_.--"o.--"
                    "=.o|o_.--""
)";
    std::string expectedWinArt3 = R"(
   ____                            _         _       _   _                      _       _                 _                       _  
  / ___|___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_(_) ___  _ __  ___     / \   __| |_   _____ _ __ | |_ _   _ _ __ ___ _ __| | 
 | |   / _ \| '_ \ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \| '_ \/ __|   / _ \ / _` \ \ / / _ \ '_ \| __| | | | '__/ _ \ '__| | 
 | |__| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | \__ \  / ___ \ (_| |\ V /  __/ | | | |_| |_| | | |  __/ |  |_| 
  \____\___/|_| |_|\__, |_|  \__,_|\__|\__,_|_|\__,_|\__|_|\___/|_| |_|___/ /_/   \_\__,_| \_/ \___|_| |_|\__|\__,_|_|  \___|_|  (_) 
                   |___/                                                                                                             
)";

    std::ostringstream outputBuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputBuffer.rdbuf()); 

    winScreen(true);

    // Capture the output
    std::string outputStr = outputBuffer.str();

    // Validate parts of the output
    EXPECT_NE(outputStr.find("You enter a dark room"), std::string::npos);
    EXPECT_NE(outputStr.find("In the middle, you see a treasure chest"), std::string::npos);
    EXPECT_NE(outputStr.find("Grizzle rushes forward"), std::string::npos);
    EXPECT_NE(outputStr.find("He eagerly opens the chest..."), std::string::npos);
    EXPECT_NE(outputStr.find(expectedWinArt1), std::string::npos);  
    EXPECT_NE(outputStr.find(expectedWinArt2), std::string::npos); 
    EXPECT_NE(outputStr.find("Inside, something glimmers - a crown of dark emeralds and gold"), std::string::npos);
    EXPECT_NE(outputStr.find("Grizzle looks at you with gratitude in his eyes"), std::string::npos);
    EXPECT_NE(outputStr.find("Ever grateful, he pledges his loyalty to you"), std::string::npos);
    EXPECT_NE(outputStr.find(expectedWinArt3), std::string::npos);
    EXPECT_NE(outputStr.find("You completed the game"), std::string::npos);
    
    std::cout.rdbuf(oldCout);
}

//TEST for loseScreen
TEST(EndScreenTest, LoseScreenTestA) {

    std::string expectedLoseArt1 = R"(
                                             ('-. .-.   ('-.          (`-.      ('-.         _ .-') _              ('-.  _ .-') _   
                                            ( OO )  /  ( OO ).-.    _(OO  )_  _(  OO)       ( (  OO) )           _(  OO)( (  OO) )  
  ,--.   ,--..-'),-----.  ,--. ,--.         ,--. ,--.  / . --. /,--(_/   ,. \(,------.       \     .'_   ,-.-') (,------.\     .'_  
   \  `.'  /( OO'  .-.  ' |  | |  |         |  | |  |  | \-.  \ \   \   /(__/ |  .---'       ,`'--..._)  |  |OO) |  .---',`'--..._) 
 .-')     / /   |  | |  | |  | | .-')       |   .|  |.-'-'  |  | \   \ /   /  |  |           |  |  \  '  |  |  \ |  |    |  |  \  ' 
(OO  \   /  \_) |  |\|  | |  |_|( OO )      |       | \| |_.'  |  \   '   /, (|  '--.        |  |   ' |  |  |(_/(|  '--. |  |   ' | 
 |   /  /\_   \ |  | |  | |  | | `-' /      |  .-.  |  |  .-.  |   \     /__) |  .--'        |  |   / : ,|  |_.' |  .--' |  |   / : 
 `-./  /.__)   `'  '-'  '('  '-'(_.-'       |  | |  |  |  | |  |    \   /     |  `---.       |  '--'  /(_|  |    |  `---.|  '--'  / 
   `--'          `-----'   `-----'          `--' `--'  `--' `--'     `-'      `------'       `-------'   `--'    `------'`-------' 
)";

    std::ostringstream outputBuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputBuffer.rdbuf()); 

    std::istringstream inputBuffer("1\n"); 
    std::streambuf* oldCin = std::cin.rdbuf(inputBuffer.rdbuf());

    loseScreen();

    // Capture the output
    std::string outputStr = outputBuffer.str();

    EXPECT_NE(outputStr.find("Oh no"), std::string::npos);
    EXPECT_NE(outputStr.find("..."), std::string::npos);
    EXPECT_NE(outputStr.find(expectedLoseArt1), std::string::npos);
    EXPECT_NE(outputStr.find("You failed to protect Grizzle and clear the dungeon"), std::string::npos);
    EXPECT_NE(outputStr.find("What would you like to do?"), std::string::npos);
    EXPECT_NE(outputStr.find("1. Restart"), std::string::npos);
    EXPECT_NE(outputStr.find("2. Go to main menu"), std::string::npos);
    EXPECT_NE(outputStr.find("3. Exit"), std::string::npos);
    EXPECT_NE(outputStr.find("Please enter your choice (1-3): "), std::string::npos);

    std::cout.rdbuf(oldCout);
    std::cin.rdbuf(oldCin);
}

TEST(EndScreenTest, LoseScreenTestD) {
    std::ostringstream outputBuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputBuffer.rdbuf()); 

    std::istringstream inputBuffer("99\n"); 
    std::streambuf* oldCin = std::cin.rdbuf(inputBuffer.rdbuf());

    loseScreen();

    // Capture the output
    std::string outputStr = outputBuffer.str();

    EXPECT_NE(outputStr.find("Invalid choice. Please try again."), std::string::npos);

    std::cout.rdbuf(oldCout);
    std::cin.rdbuf(oldCin);
}
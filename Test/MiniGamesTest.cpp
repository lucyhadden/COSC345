#include "gtest/gtest.h"
#include "miniGames.h"  
#include "BlackJack.h"

//WRITING TESTS FOR MINIGAMES
TEST(MiniGamesTest, SpinWheelTest){
    std::ostringstream outputBuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputBuffer.rdbuf()); 

    // Call the spinWheel function
    int result = spinWheel();

    // Capture the output
    std::string outputStr = outputBuffer.str();

    // Check if the result is in the expected range (1 to 4)
    EXPECT_GE(result, 1);
    EXPECT_LE(result, 4);

    // Check if the output contains the expected text
    EXPECT_NE(outputStr.find("Spinning the wheel..."), std::string::npos);
    EXPECT_NE(outputStr.find("The wheel stops at: "), std::string::npos);

    // Check that the spinner characters were displayed (you can refine this further if needed)
    EXPECT_NE(outputStr.find("|"), std::string::npos);
    EXPECT_NE(outputStr.find("/"), std::string::npos);
    EXPECT_NE(outputStr.find("-"), std::string::npos);
    EXPECT_NE(outputStr.find("\\"), std::string::npos);

    // Restore cout
    std::cout.rdbuf(oldCout);
}

//TEST for game 1
TEST(MiniGamesTest, Game1){

    std::ostringstream outputBuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputBuffer.rdbuf());

    std::istringstream inputBuffer("\n"); 
    std::streambuf* oldCin = std::cin.rdbuf(inputBuffer.rdbuf());

    // Call the game1 function
    int score = game1(true);

    // Capture the output
    std::string outputStr = outputBuffer.str();

    // Check output contains expected phrases
    EXPECT_NE(outputStr.find("Welcome to the Word Unscramble Game!"), std::string::npos);
    EXPECT_NE(outputStr.find("You will be given a series of scrambled words, and you must unscramble them within 15 seconds."), std::string::npos);
    EXPECT_NE(outputStr.find("For each correct unscrambled word, you will earn 1 gold."), std::string::npos);
    EXPECT_NE(outputStr.find("Let's start the adventure!"), std::string::npos);
    EXPECT_NE(outputStr.find("Press enter to continue..."), std::string::npos);
    EXPECT_NE(outputStr.find("Game over! Your final score is"), std::string::npos);

    EXPECT_EQ(score, 0);  

    // Restore cin and cout to their original state
    std::cout.rdbuf(oldCout);
    std::cin.rdbuf(oldCin);
}

//TEST for game 2
TEST(MiniGamesTest, Game2) {
    // Redirect cout to capture the output
    std::ostringstream outputBuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputBuffer.rdbuf());

    std::istringstream inputBuffer("0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n"); 
    std::streambuf* oldCin = std::cin.rdbuf(inputBuffer.rdbuf());

    // Call the game2 function
    int score = game2();

    // Capture the output
    std::string outputStr = outputBuffer.str();

    // Check if the expected phrases are present in the output
    EXPECT_NE(outputStr.find("Welcome to the Memory Test Game!"), std::string::npos);
    EXPECT_NE(outputStr.find("In this game, you need to memorize a sequence of numbers."), std::string::npos);
    EXPECT_NE(outputStr.find("Let's start the game!"), std::string::npos);
    EXPECT_NE(outputStr.find("Level 1: Memorize this sequence:"), std::string::npos);
    EXPECT_NE(outputStr.find("Now, enter the sequence: "), std::string::npos);
    EXPECT_NE(outputStr.find("Incorrect! Game over."), std::string::npos);
    EXPECT_NE(outputStr.find("You earned "), std::string::npos);

    // Restore cin and cout to their original state
    std::cout.rdbuf(oldCout);
    std::cin.rdbuf(oldCin);
}

//TEST game 3
TEST(MiniGamesTest, Game3) {
    // Redirect cout to capture the output
    std::ostringstream outputBuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputBuffer.rdbuf());

    std::istringstream inputBuffer("0\n1\n"); 
    std::streambuf* oldCin = std::cin.rdbuf(inputBuffer.rdbuf());

    // Call the game3 function
    int gold = game3(true);

    // Capture the output
    std::string outputStr = outputBuffer.str();

    // Check if the expected phrases are present in the output
    EXPECT_NE(outputStr.find("Welcome to the Tic Tac Toe!"), std::string::npos);
    EXPECT_NE(outputStr.find("In this game, you need to beat the computer at tic tac toe."), std::string::npos);
    EXPECT_NE(outputStr.find("Let's start the game!"), std::string::npos);
    EXPECT_NE(outputStr.find("Your turn (X). Enter your slot:"), std::string::npos);
    EXPECT_NE(outputStr.find("Invalid slot! Try again."), std::string::npos);
    EXPECT_NE(outputStr.find("Computer's turn (O)."), std::string::npos);
    EXPECT_NE(outputStr.find("It's a tie!"), std::string::npos);

    // Restore cin and cout to their original state
    std::cout.rdbuf(oldCout);
    std::cin.rdbuf(oldCin);
}

// TEST(MiniGamesTest, BlackJackInitialSetup) {
//     // Check if the game starts with the correct player and house account balances
//     EXPECT_EQ(player_account, 4);
//     EXPECT_EQ(house_account, 8);
// }

// // Test player's turn where the player hits and busts
// TEST(MiniGamesTest, BlackJackPlayerHitsAndBusts) {
//     players_value = 22; // Simulate a bust
//     EXPECT_FALSE(PlayerHasAce());
//     EXPECT_GT(players_value, 21);
// }

// // Test dealer's turn logic
// TEST(MiniGamesTest, BlackJackDealerTurnLogic) {
//     players_value = 18;
//     dealers_value = 17;
//     aces_in_play = 0;
//     EXPECT_TRUE(DealersPlayLogic());
// }

// // Test end conditions of the Blackjack game
// TEST(MiniGamesTest, BlackJackGameEndConditions) {
//     // Case 1: Player has no money left
//     player_account = 0;
//     EXPECT_FALSE(ContinueGame());

//     // Case 2: House has no money left
//     player_account = 4;
//     house_account = 0;
//     EXPECT_FALSE(ContinueGame());
// }

// // Test Blackjack gameplay including hit and stand scenarios
// TEST(MiniGamesTest, BlackJackGameplay) {
//     // Redirect cout to capture the output
//     std::ostringstream outputBuffer;
//     std::streambuf* oldCout = std::cout.rdbuf(outputBuffer.rdbuf());

//     std::istringstream inputBuffer("H\nS\n"); 
//     std::streambuf* oldCin = std::cin.rdbuf(inputBuffer.rdbuf());

//     // Reset the game state
//     ResetGame();

//     // Simulate player actions
//     PlayersTurn();
//     DealersTurn();
//     DisplayResults();

//     // Capture the output
//     std::string outputStr = outputBuffer.str();

//     // Verify key outputs
//     EXPECT_NE(outputStr.find("Hit or Stand (H/S)?"), std::string::npos);
//     EXPECT_NE(outputStr.find("Dealer's Turn"), std::string::npos);

//     // Restore cin and cout to their original state
//     std::cout.rdbuf(oldCout);
//     std::cin.rdbuf(oldCin);
// }
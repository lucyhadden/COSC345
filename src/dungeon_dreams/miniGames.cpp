#include <iostream>
#include <string>
#include <ctime>
#include <cctype>
#include <algorithm>
#include <random>
#include <vector>
#include <cstdlib>

#include "utils.h"
#include "miniGames.h"
#include "BlackJack.h"
#include <Status.h>
/**
 * @file
 * @brief Holds minigames
 * @author Elizabeth Stewart
 * 
 */
using namespace std; // Use the standard namespace

/**
 * @brief boolean variable to control whether being called from test to select which game
 */
bool isTesting = false;

/**
 * @brief int variable that can be set when testing minigame to select a game
 */
int gameNo = 0;

/**
 * @brief Setter for the is testing Boolean variable used in testing.
 */
void setIsTesting(bool value) {
    isTesting = value;
}

/**
 * @brief Setter used to select which game to test.
 */
void SelectGame(int value) {
    gameNo = value;
}
// Mini-game functions


//Word Scrabble - unscrabble as many words as you can in a set time
int game1(bool isTesting) {
    // Game 1 logic here

    vector<string> original_words = {"win", "lose", "game", "dungeon", "dream", "goblin", "guild", "adventure", "quest", "treasure", "reward", "monster", "ghost", "slime", "dragon", "troll", "knight", "mage", "tank", "theif", "cleric"};
    vector<string> scrambled_words = original_words;

    //Scramble words
    for(auto& word : scrambled_words){
        shuffle(word.begin(), word.end(), mt19937{random_device{}()});
    }

    srand(time(0)); // Seed the random number generator
    int score = 0; // Initialize score to 0
    
    cout << "Welcome to the Word Unscramble Game!" << endl;
    CustomSleep(1);
    cout << "You will be given a series of scrambled words, and you must unscramble them within 15 seconds." << endl;
    CustomSleep(1);
    cout << "For each correct unscrambled word, you will earn 1 gold." << endl;
    CustomSleep(1);
    cout << "Let's start the adventure!" << endl;
    CustomSleep(1);
    cout << "Press enter to continue...";
    cin.ignore();  // Ignore any leftover characters in the input buffer
    cin.get();     // Wait for user input

    // Create a random number generator
    mt19937 rng{random_device{}()};
    uniform_int_distribution<int> dist(0, scrambled_words.size() - 1);


    // Start the timer
    time_t start_time = time(0);
    time_t end_time = start_time + 1; // for testing
    if(!isTesting){
        time_t end_time =+ 29; // 30 seconds
    }

    while (time(0) < end_time) {
        // Clear the screen and print the remaining time
        Clear();
        cout << "Time remaining: " << end_time - time(0) << " seconds" << endl;
        cout << "Score: " << score << " gold" << endl;

        // Randomly select an index from the vector
        int selectedIndex = dist(rng);

        // Print the scrambled word and prompt the user to unscramble it
        cout << "Unscramble the word: " << scrambled_words[selectedIndex] << endl;


        string userInput;
        bool correct = false;
        while (!correct) {
            cout << "Enter your answer: ";
            cin >> userInput;

            // Check if the user's answer is correct
            if (userInput == original_words[selectedIndex]) {
                cout << "Correct! The unscrambled word is indeed " << original_words[selectedIndex] << "." << endl;
                correct = true;
                score++;
            } else {
                cout << "Sorry, that's incorrect. Try again!" << endl;
            }
        }
    }

    cout << "Game over! Your final score is " << score << " gold." << endl;
    return score;
}

// Memory Test Game - Lucy 
int game2() {
srand(time(0));
    int level = 1;
    int gold = 0;

    cout << "Welcome to the Memory Test Game!" << endl;
    CustomSleep(1);
    cout << "In this game, you need to memorize a sequence of numbers. Each level adds one more number to the sequence." << endl;
    CustomSleep(1);
    cout << "Let's start the game!" << endl;
    CustomSleep(1);

    bool playing = true;
    vector<int> sequence;
    while (playing) {
        sequence.push_back(rand() % 10);

        cout << "Level " << level << ": Memorize this sequence:" << endl;
        for (int num : sequence) {
            cout << num << " ";
        }
        cout << endl;
        CustomSleep(2);

        Clear();

        cout << "Now, enter the sequence: ";
        vector<int> playerInput;
        for (size_t i = 0; i < sequence.size(); ++i) {
            int input;
            cin >> input;
            playerInput.push_back(input);
        }

        if (playerInput == sequence) {
            cout << "Correct! Moving to the next level." << endl;
            gold += level; 
            level++;
        } else {
            cout << "Incorrect! Game over." << endl;
            playing = false;
        }
    }

    cout << "You earned " << gold << " gold." << endl;
    return gold;
}

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char current_marker;
char computer_marker = 'O';
int current_player;

void drawBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " \n";
}

bool placeMarker(int slot, char marker) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = marker;
        return true;
    }
    return false;
}
int winner() {
    // Rows
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return (board[i][0] == 'X') ? 1 : 2;

    // Columns
    for (int i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return (board[0][i] == 'X') ? 1 : 2;

    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return (board[0][0] == 'X') ? 1 : 2;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return (board[0][2] == 'X') ? 1 : 2;

    return 0;
}

void computerMove() {
    int slot;
    do {
        slot = std::rand() % 9 + 1; // Random slot between 1 and 9
    } while (!placeMarker(slot, computer_marker));
}

int game3() {
    int gold = 0; // Variable to keep track of gold
    cout << "Welcome to the Tic Tac Toe!" << endl;
    CustomSleep(1);
    cout << "In this game, you need to beat the computer at tic tac toe." << endl;
    CustomSleep(1);
    cout << "Let's start the game!" << endl;
    CustomSleep(1);
    srand(time(0));
    current_marker = 'X';
    drawBoard();

    int player_won;
    for (int i = 0; i < 9; i++) {
        // Player's turn
        cout << "Your turn (X). Enter your slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Try again.\n";
            i--;
            continue;
        }

        if (!placeMarker(slot, current_marker)) {
            cout << "Slot already taken! Try again.\n";
            i--;
            continue;
        }

        drawBoard();

        player_won = winner();
        if (player_won == 1) { cout << "You win!\n"; break; gold += 10; }
        if (player_won == 2) { cout << "Computer wins!\n"; break; gold +=1;}

        // Computer's turn
        cout << "Computer's turn (O).\n";
        computerMove();
        drawBoard();

        player_won = winner();
        if (player_won == 1) { cout << "You win!\n"; break; gold += 10; }
        if (player_won == 2) { cout << "Computer wins!\n"; break; gold +=1; }
    }

    if (player_won == 0) {cout << "It's a tie!\n"; gold +=3;}
    // cout << "You're playing Game 3!" << endl;
    return gold;
}

int game4() {
    // Game 4 logic here
    BlackJack();
    return 0;
}

// Wheel spinning 
int spinWheel() { 
    srand(time(0));

    int gameSelection = (rand() % 4) + 1;  // Generate a random number between 1 and 4
    int spins = (rand() % 8) + 8;        // Random number of spins between 8 and 16

    cout << "Spinning the wheel..." << endl;

    char spinner[4] = {'|', '/', '-', '\\'}; // Spinner characters
    for (int i = 0; i < spins; ++i) {
        cout << "\r" << spinner[i % 4] << " Number: " << ((i % 4) + 1) << flush; // Visual effect
        CustomSleep(1); //usleep(100000);  // Delay for 100 milliseconds
    }

    // Display the final result stored in gameSelection
    cout << "\rThe wheel stops at: " << gameSelection << "     " << endl;

    return gameSelection;  // Return the randomly selected number
}

int miniGames(CharacterStats& playerStats) {
    int goldEarned = 0;
    cout << "\033[2J\033[1;1H"; // ANSI escape code to clear the console
    cout << "You Have Entered The MiniGames!" << endl;
    CustomSleep(1);
    int gameSelection = spinWheel();
    if(isTesting){
        gameSelection = gameNo;
    }
    // int gameSelection = 3;
    switch (gameSelection) {
        case 1:
            playerStats.gold += game1(false);
            break;
        case 2:
            playerStats.gold += game2();
            break;
        case 3:
            playerStats.gold += game3();
            break;
        case 4:
            playerStats.gold += game4();
            break;
        default:
            cout << "Error: Invalid game selection." << endl;
            break;
    }
    return goldEarned;
}

// void SelectGame(int game)
// {
//     switch(game)
//     {
//         case 1:
//             game1();
//             break;
//         case 2:
//             game2();
//             break;
//         case 3:
//             game3();
//             break;
//         case 4:
//             game4();
//             break;
//         default:
//             break;
//     }
// }
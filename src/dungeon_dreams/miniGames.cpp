#include <iostream>
#include <string>
#include <ctime>
#include <cctype>
#include <algorithm>
#include <random>
#include <vector>

#include "utils.h"

using namespace std; // Use the standard namespace

// Mini-game functions

//Word Scrabble - unscrabble as many words as you can in a set time
int game1() {
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
    time_t end_time = start_time + 30; // 30 seconds

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

int game3() {
    // Game 3 logic here
    cout << "You're playing Game 3!" << endl;
    return 0;
}

int game4() {
    // Game 4 logic here
    cout << "You're playing Game 4!" << endl;
    return 0;
}

// Wheel spinning 
int spinWheel() { 
    srand(time(0));

    int gameSelection = (rand() % 4) + 1;  // Generate a random number between 1 and 4
    int spins = (rand() % 10) + 10;        // Random number of spins between 10 and 20

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

int miniGames() {
    int goldEarned = 0;
    cout << "\033[2J\033[1;1H"; // ANSI escape code to clear the console
    cout << "You Have Entered The MiniGames!" << endl;
    CustomSleep(1);
    int gameSelection = spinWheel();
    switch (gameSelection) {
        case 1:
            goldEarned = game1();
            break;
        case 2:
            goldEarned = game2();
            break;
        case 3:
            goldEarned = game3();
            break;
        case 4:
            goldEarned = game4();
            break;
        default:
            cout << "Error: Invalid game selection." << endl;
            break;
    }
    return goldEarned;
}

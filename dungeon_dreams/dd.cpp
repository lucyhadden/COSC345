#include <iostream>
#include <string>
#include <cstdlib> // for system("clear")

using namespace std;

// Function prototypes
void displayWelcome();
void displayMenu();
void displayCharacterClasses();
void handleMenuChoice();
void handleClassChoice();

// ASCII Art for Welcome Screen
const string welcomeArt = R"(
      __          __  _                            _   
     \ \        / / | |                          | |  
      \ \  /\  / /__| | ___ ___  _ __ ___   ___  | |_ 
       \ \/  \/ / _ \ |/ __/ _ \| '_ ` _ \ / _ \ | __|
        \  /\  /  __/ | (_| (_) | | | | | |  __/ | |_ 
         \/  \/ \___|_|\___\___/|_| |_| |_|\___|  \__|
  ______________________________________________________
  |                                                    |
  |  In a dense forest, a lone adventurer wanders...     |
  |                                                    |
  |              ____   ____    _  _                   |
  |            /     \ /    \  | || |                  |
  |           |  O   O |  O   | | || |                  |
  |            \_____/ \____/   \__/                  |
  |                                                    |
  |   The adventurer finds a hidden path leading to     |
  |   a dark dungeon. The quest is about to begin!      |
  |                                                    |
  |____________________________________________________|
)";

// ASCII Art for the Dungeon Entrance
const string dungeonEntranceArt = R"(
  ___
 /   \
|     |
|     |
 \___/
  | |
  | |
 /   \
|     |
|     |
 \___/
)";

// ASCII Art for Character Classes
const string knightArt = R"(
     ,    ,
    /(    )\
    \ \__/ /
    /- _ -\
   /_/\/\_\  
)";
const string mageArt = R"(
    *
  /   \
 |     |
 |  O  |
 |     |
  \   /
    *  
)";
const string thiefArt = R"(
   __o__
 /      \
|   O    o)
 \______/
)";
const string tankArt = R"(
   __|__    
  |  o  o|   
 (    ^   )
  |  \|/  |
  \ ___  /
    |   |  
)";
const string clericArt = R"(
    /|\
  /  |  \
  |  |  |
  |  |  |
  |  |  |
  |__|__|
)";

// Function to display the welcome screen
void displayWelcome() {
    system("clear"); // Clear the console (cross-platform, use "CLS" on Windows)
    cout << welcomeArt << endl;
    cout << "You find yourself lost in the forest, searching for adventure..." << endl;
    cout << "You stumble upon an old path leading to a dark dungeon." << endl;
    cout << "Are you ready to face the challenges ahead?" << endl;
    cout << "Press any key to enter the dungeon..." << endl;
    cin.ignore();
    cin.get(); // Wait for user input
    cout << dungeonEntranceArt << endl;
    system("clear"); // Clear the console before showing the main menu
}

// Function to display the main menu
void displayMenu() {
    cout << "Welcome to Dungeon Dreams: The Goblin Guide!" << endl;
    cout << "1. View Character Classes" << endl;
    cout << "2. Start Game" << endl;
    cout << "3. Exit" << endl;
    cout << "Please enter your choice (1-3): ";
}

// Function to handle the menu choice
void handleMenuChoice() {
    int choice;
    cin >> choice;
    switch(choice) {
        case 1:
            handleClassChoice();
            break;
        case 2:
            cout << "Starting the game..." << endl;
            // Add game start logic here
            break;
        case 3:
            cout << "Exiting game. Goodbye!" << endl;
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
}

// Function to display character classes
void displayCharacterClasses() {
    system("clear"); // Clear the console (cross-platform, use "CLS" on Windows)
    cout << "Character Classes in Dungeon Dreams: The Goblin Guide" << endl;
    cout << "1. Knight" << endl;
    cout << knightArt << endl;
    cout << "2. Mage" << endl;
    cout << mageArt << endl;
    cout << "3. Thief" << endl;
    cout << thiefArt << endl;
    cout << "4. Tank" << endl;
    cout << tankArt << endl;
    cout << "5. Cleric" << endl;
    cout << clericArt << endl;
    cout << "Press any key to return to the main menu..." << endl;
    cin.ignore();
    cin.get(); // Wait for user input
}

// Function to handle the character class choice
void handleClassChoice() {
    displayCharacterClasses();
    displayMenu();
    handleMenuChoice();
}

int main() {
    displayWelcome();
    displayMenu();
    handleMenuChoice();
    return 0;
}

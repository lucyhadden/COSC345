#include <iostream>
#include <string>
#include <cstdlib>  
#include <unistd.h>
#include "AsciiArt.h"

using namespace std;

// Function prototypes
void displayWelcome();
void displayMenu();
void displayCharacterClasses();
void handleMenuChoice();
void handleClassChoice();

// Function to display the welcome screen
void displayWelcome() {
    system("clear"); 
    cout << AsciiArt::dragonWelcomeArt << endl;
    cout << "You find yourself lost in the forest, searching for adventure..." << endl;
    cout << "You stumble upon an old path leading to a dark dungeon." << endl;
    cout << "Are you ready to face the challenges ahead?" << endl;
    cout << "Press any key to enter the dungeon..." << endl;
    cin.ignore();
    cin.get(); 

    int countdown = 5;
    int position = 0;

    while (countdown > 0) {
        system("clear");
        for (int i = 0; i < position; i++) {
            cout << endl;
        }
        cout << AsciiArt::dungeonEntranceArt << endl;
        cout << "You are entering the dungeon in " << countdown << endl;
        sleep(1);
        position++;
        countdown--;
    }

    system("clear");
    cout << "You have entered the dungeon..." << endl;
    sleep(1);
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
    system("clear"); 
    cout << "Character Classes in Dungeon Dreams: The Goblin Guide" << endl;
    cout << "1. Knight" << endl;
    cout << AsciiArt::knightArt << endl;
    cout << "2. Mage" << endl;
    cout << AsciiArt::mageArt << endl;
    cout << "3. Thief" << endl;
    cout << AsciiArt::thiefArt << endl;
    cout << "4. Tank" << endl;
    cout << AsciiArt::tankArt << endl;
    cout << "5. Cleric" << endl;
    cout << AsciiArt::clericArt << endl;
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

int function() {
    displayWelcome();
    displayMenu();
    handleMenuChoice();
    return 0;
}

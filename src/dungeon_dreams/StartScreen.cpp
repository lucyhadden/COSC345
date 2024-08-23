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
void startingStory();
void pressAnyKeyToContinue2();

// Function to display the welcome screen
void displayWelcome() {
    system("clear"); 
    cout << AsciiArt::dragonWelcomeArt << endl;
    sleep(1);
    displayMenu();
    handleMenuChoice();
    system("clear"); 

    startingStory();
    system("clear"); 
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
    bool validChoice = false;

    while (!validChoice) {
        cin >> choice;
        switch(choice) {
            case 1:
                handleClassChoice();
                validChoice = true;
                break;
            case 2:
                cout << "Starting the game..." << endl;
                validChoice = true;
                break;
            case 3:
                cout << "Exiting game. Goodbye!" << endl;
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
                displayMenu(); // Re-display the menu after an invalid choice
                break;
        }
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

void startingStory(){
    sleep(1);
    cout << AsciiArt::storyStartArt << endl;
    cout << "In a world filled with dungeons and monsters, adventure awaits at every corner. You are an aspiring adventurer, whose dreams have always been filled with epic quests and heroic deeds. " << endl;
    sleep(3);
    cout << "One fateful morning, you set off for the capital, leaving behind your village and mundane life. The grand walls of the capital greet you with an air of opportunity and excitement."  << endl;
    sleep(3);
    cout << "Are you ready to face the challenges ahead?" << endl;
    sleep(3);
    cout << "With a heart full of hope and a spirit ready for adventure, you march straight to the Adventurers' Guild..." << endl;
    sleep(3);
    pressAnyKeyToContinue2();

}

// Function to wait for user input before continuing
void pressAnyKeyToContinue2() {
    cout << "Press enter to continue...";
    cin.ignore();  // Ignore any leftover characters in the input buffer
    cin.get();     // Wait for user input
}

int function() {
    displayWelcome();
    displayMenu();
    handleMenuChoice();
    startingStory();
    pressAnyKeyToContinue2();
    return 0;
}
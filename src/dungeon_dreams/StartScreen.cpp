#include <iostream>
#include <string>
#include <cstdlib>  
#include <unistd.h>
#include "AsciiArt.h"

/**
 * @file
 * @brief Displays start screeen and handles relevant events
 * @author Lucy Hadden
 * 
 */
using namespace std;

/**
 * Displays the welcome screen and initiates the game.
 */
void displayWelcome();

/**
 * Displays the main menu.
 */
void displayMenu();

/**
 * Displays the available character classes.
 */
void displayCharacterClasses();

/**
 * Handles the user's choice from the main menu.
 */
void handleMenuChoice();

/**
 * Handles the user's choice of character class.
 */
void handleClassChoice();

/**
 * Displays the starting story.
 */
void startingStory();

/**
 * Waits for the user to press any key to continue.
 */
void pressAnyKeyToContinue2();

/**
 * Main function that starts the game.
 * 
 * @return int Returns 0 upon successful completion.
 */
int function() {
    displayWelcome();
    displayMenu();
    handleMenuChoice();
    startingStory();
    pressAnyKeyToContinue2();
    return 0;
}


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

void displayMenu() {
    cout << "Welcome to Dungeon Dreams: The Goblin Guide!" << endl;
    cout << "1. View Character Classes" << endl;
    cout << "2. Start Game" << endl;
    cout << "3. Exit" << endl;
    cout << "Please enter your choice (1-3): ";
}

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

void pressAnyKeyToContinue2() {
    cout << "Press enter to continue...";
    cin.ignore();  
    cin.get();    
}


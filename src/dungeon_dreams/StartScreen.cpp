#include <iostream>
#include <string>
#include <cstdlib>  
#include "AsciiArt.h"
// #include "Utils.h"
#include "utils.h"

/**
 * @file
 * @brief Displays start screeen and handles relevant events
 * @author Lucy Hadden
 * 
 */
using namespace std;

/**
 * @brief Displays the welcome screen and initiates the game.
 */
void displayWelcome();

/**
 * @brief Displays the main menu.
 */
void displayMenu();

/**
 * @brief Displays the available character classes.
 */
void displayCharacterClasses();

/**
 * @brief Handles the user's choice from the main menu.
 */
void handleMenuChoice();

/**
 * @brief Handles the user's choice of character class.
 */
void handleClassChoice();

/**
 * @brief Displays the starting story.
 */
void startingStory();

/**
 * @brief Waits for the user to press any key to continue.
 */
void pressAnyKeyToContinue2();

/**
 * Main function that starts the game.
 * 
 * @return int Returns 0 upon successful completion.
 */
int function() {
    displayMenu();
    handleMenuChoice();
    startingStory();
    pressAnyKeyToContinue2();
    return 0;
}


void displayWelcome() {
    Clear();
    cout << AsciiArt::getDragonWelcomeArt() << endl;
    CustomSleep(1);
    displayMenu();
    handleMenuChoice();
    Clear();

    startingStory();
    Clear();
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
    Clear();
    cout << "Character Classes in Dungeon Dreams: The Goblin Guide" << endl;
    cout << "1. Knight" << endl;
    cout << AsciiArt::getKnightArt() << endl;
    cout << "2. Mage" << endl;
    cout << AsciiArt::getMageArt() << endl;
    cout << "3. Thief" << endl;
    cout << AsciiArt::getThiefArt() << endl;
    cout << "4. Tank" << endl;
    cout << AsciiArt::getTankArt() << endl;
    cout << "5. Cleric" << endl;
    cout << AsciiArt::getClericArt() << endl;
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
    CustomSleep(1);
    cout << AsciiArt::getStoryStartArt() << endl;
    cout << "In a world filled with dungeons and monsters, adventure awaits at every corner. You are an aspiring adventurer, whose dreams have always been filled with epic quests and heroic deeds. " << endl;
    CustomSleep(3);
    cout << "One fateful morning, you set off for the capital, leaving behind your village and mundane life. The grand walls of the capital greet you with an air of opportunity and excitement."  << endl;
    CustomSleep(3);
    cout << "Are you ready to face the challenges ahead?" << endl;
    CustomSleep(3);
    cout << "With a heart full of hope and a spirit ready for adventure, you march straight to the Adventurers' Guild..." << endl;
    CustomSleep(3);
    pressAnyKeyToContinue2();

}

void pressAnyKeyToContinue2() {
    cout << "Press enter to continue...";
    cin.ignore();  
    cin.get();    
}


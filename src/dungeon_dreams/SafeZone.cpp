#include <iostream>
#include <string>
#include <cstdlib>
#include "Utils.h"

using namespace std;

/**
 * @brief Displays the safe zone dialogue.
 */
void displaySafeZone();

/**
 * @brief Displays the options in the safe zone.
 */
void displayOptions();

/**
 * @brief Displays the options in the safe zone.
 */
void handleChoice();

void displaySafeZone()
{
    displayOptions();
    handleChoice();
    cout << "Press enter to continue..." <<endl;
    cin.ignore(); // Ignore any leftover characters in the input buffer
    cin.get();    // Wait for user input
}

void displayOptions()
{
    cout << "Welcome to the safe zone" << endl;
    cout << "1. Play a minigame" << endl;
    cout << "2. Visit the store" << endl;
    cout << "3. Upgrade your stats" << endl;
    cout << "4. Continue to next level" << endl;
    cout << "Please enter your choice (1-4): ";
}

void handleChoice()
{
    int choice;
    bool validChoice = false;
    while (!validChoice)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "handle minigame" << endl;
            validChoice = true;
            break;
        case 2:
            cout << "Handle the store" << endl;
            validChoice = true;
            break;
        case 3:
            cout << "Handle stat upgrades" << endl;
            validChoice = true;
            break;
        case 4: 
            validChoice = true;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            displayOptions(); // Re-display the menu after an invalid choice
            break;
        }
    }
}
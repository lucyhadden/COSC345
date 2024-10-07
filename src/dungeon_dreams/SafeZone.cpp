#include <iostream>
#include <string>
#include <cstdlib>

#include "utils.h"
#include "Store.h"
#include "miniGames.h"
#include "BlackJack.h"

using namespace std;


bool doneMinigame = false;
bool doneStats = false;

// /**
//  * @brief Displays the safe zone dialogue.
//  */
// void displaySafeZone();

/**
 * @brief Displays the options in the safe zone.
 */
void displayOptions();

void IntroductionToStore();

/**
 * @brief Displays the options in the safe zone.
 */
void handleChoice(CharacterStats& playerStats);

void displaySafeZone(CharacterStats& playerStats)
{
    displayOptions();
    handleChoice(playerStats);
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

void handleChoice(CharacterStats& playerStats)
{
    int choice;

    cin >> choice;
    switch (choice)
    {
    case 1:
        if (doneMinigame){
            cout << "handle minigame" << endl;
            miniGames();
            doneMinigame = true;
        }
        else{
            cout << "You have already played a minigame" << endl;
        }
        displayOptions();
    case 2:
        StoreActivated(playerStats);
        displayOptions();
    case 3:
        if (doneStats){
            cout << "Handle stat upgrades" << endl;
            //ADD STATS UPGRADE
            doneStats = true;
        }
        else{
            cout << "You have already upgraded your stats" << endl;
        }
        displayOptions();
    case 4: 
        doneMinigame = false;
        doneStats = false;
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        displayOptions(); // Re-display the menu after an invalid choice
        break;
    }
}
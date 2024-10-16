#include <iostream>
#include <string>
#include <cstdlib>
#include "SafeZone.h"
#include "utils.h"
#include "Store.h"
#include "miniGames.h"
#include <Status.h>
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
 * @brief Setter for the minigame Boolean variable used in testing.
 */
void setDoneMinigame(bool value) {
    doneMinigame = value;
}


/**
 * @brief Displays the options in the safe zone.
 */
void handleChoice(CharacterStats& playerStats);

void displaySafeZone(CharacterStats& playerStats)
{
    // displayOptions();
    handleChoice(playerStats);
}

void displayOptions()
{
    cout << "Welcome to the safe zone" << endl;
    cout << "1. Play a minigame to earn more gold!" << endl;
    cout << "2. Visit the store" << endl;
    cout << "3. Continue to next level" << endl;
    cout << "Please enter your choice (1-3): ";
}

void handleChoice(CharacterStats& playerStats)
{
    bool inSafeZone = true;
    
    while (inSafeZone) {
        displayOptions();  // Display the menu
        
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (!doneMinigame) {
                // cout << "handle minigame" << endl;
                miniGames(playerStats);
                doneMinigame = true;
            } else {
                cout << "You have already played a minigame" << endl;
                CustomSleep(1);
                Clear();
            }
            break;
        case 2:
            StoreActivated(playerStats);
            break;
        case 3: 
            doneMinigame = false;
            inSafeZone = false;  // Exit the loop and safe zone
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
}
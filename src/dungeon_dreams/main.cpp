#include <iostream>
#include <cstdlib>
#include "StartScreen.h"
#include "movement.h"
#include "EndScreen.h"
#include "AsciiArt.h"
#include "interactions.h"
#include "miniGames.h"
#include "SafeZone.h"
#include "Store.h"
#include "Status.h"
#include "Equipment.h"  
#include "utils.h"
#include "InputUtils.h"

#include <string>
#include <limits>
#include <thread>
#include <chrono>

using namespace std;
//Comment test
/**
 * @file
 * @brief main class for our game. contains the game loop
 * @author Elizabeth Stewart
 * @author Lucy Hadden
 * 
 */


/** 
 * @brief Sizes of each dungeon level, where each pair represents the width and height of the dungeon.
 * 
 * int dungeon_sizes[8][2] = {{3, 3}, {5, 6}, {6, 3}, {6, 5}, {10, 5}, {8, 7}, {8, 7}, {10, 9}}; 
 */
int dungeon_sizes[8][2] = {{3, 3}, {3, 3}, {5, 5}, {5, 5}, {7, 7}, {7, 7}, {9, 9}, {9, 9}}; 


/** 
 * @brief The total number of levels in the dungeon.
 */
const int levels = 8;

extern CharacterStats playerStats;
extern Inventory playerInventory;

/**
 * @brief Main function that runs the game loop.
 * 
 * @return int Returns 0 upon successful completion.
 */
int main()
{
    bool gameRunning = true;
    bool gameCompleted = false;
    bool playerWon = false;      

    CharacterClass playerClass = KNIGHT; 
    CharacterStats playerStats(playerClass);
    
    Clear();

    displayWelcome();
    
    resetPlayerStats(playerStats, playerClass);

    initializeInventory(playerInventory, playerClass);

    applyInventoryStats(playerStats, playerInventory);


    while (gameRunning)
    {

        int countdown = 5;
        int position = 0;

        while (countdown > 0)
        {
            Clear();
            for (int i = 0; i < position; i++)
            {
                cout << endl;
            }
            cout << AsciiArt::getDungeonEntranceArt() << endl;
            cout << "You are entering the dungeon in " << countdown << endl;
            CustomSleep(1);

            position++;
            countdown--;
        }

        Clear();
        std::cout << "You have entered the dungeon..." << std::endl;
        CustomSleep(2);
        cout << "The treasure lies at the other end of this dungeon, but beware - it's filled with enemies, traps, and walls that will block your path." << std::endl;
        CustomSleep(3);
        cout << ""<< endl;
        cout << "How to move:"<< endl; 
        cout << "Use W to move up"<< endl;
        cout << "Use A to move left"<< endl;
        cout << "Use S to move down"<< endl;
        cout << "Use D to move right"<< endl;
        CustomSleep(3);
        cout << ""<< endl;
        cout << "Find the safe path and avoid the dangers hidden within the tiles." << endl;
        CustomSleep(3);
        cout << ""<< endl;
        cout << "Not all tiles are safe. Some hide dangerous enemies or traps. Others are blocked by walls." << endl;
        CustomSleep(3);
        cout << ""<< endl;
        cout << "Your goal is to navigate through each room safely to get the the treasure." << endl;
        CustomSleep(3);
        cout << ""<< endl;
        cout << "But remember, each step could be your last." << endl;
        CustomSleep(3);
        cout << ""<< endl;
        cout << "Good luck, adventurer! The dungeon awaits." << endl;
        CustomSleep(3);
        cout << "Press enter to continue...";
        cin.ignore();  // Ignore any leftover characters in the input buffer
        cin.get();     // Wait for user input

        Clear();    
        applyInventoryStats(playerStats, playerInventory);
        cout << "Level 1" << endl;
        cout << "\n--- Player Stats ---\n";
        cout << "Health: " << playerStats.health << "\n";
        cout << "Attack: " << playerStats.attack << "\n";
        cout << "Defense: " << playerStats.defense << "\n";
        cout << "\n--- Inventory ---\n";
        playerInventory.printInventory();

        for (int level = 1; level <= levels; level++)
        {
            fillDungeon(dungeon_sizes[level - 1][0], dungeon_sizes[level - 1][1]);
            generateDynamicLevels();
            updateBoard();

            while (true)
            {   
                if (enterUserInput())
                {
                    Clear();
                    setupLevel(level);
                    cout << "Level " << level << "\n"<< endl;
                    updateBoard();
                    short tyle = startEvent();
                    // cout << tyle << endl;

                    short result = processTileInteraction(tyle, playerStats, playerInventory);

                    if(tyle ==5){
                        break;
                    }
                    levelPlay(tyle, playerStats);

                    cout << "\n--- Updated Player Stats (with Inventory Bonuses) ---\n";
                    cout << "Health: " << playerStats.health << "\n";
                    cout << "Attack: " << playerStats.attack << "\n";
                    cout << "Defense: " << playerStats.defense << "\n";
                    cout << "\n--- Inventory ---\n";
                    playerInventory.printInventory();
                    cout << "\n";

                    // count++;
                }
            }
            // }
            std::this_thread::sleep_for(std::chrono::seconds(1));
            cout << "You have completed level " << level << ". Leveling up...\n";
            upgradeStats(playerStats, playerClass);
            cout << "Press enter to continue..." << endl;
            clearInputBuffer();
            cin.get();  // Wait for user input

            displaySafeZone(playerStats);
        }

        playerWon = true;
        clearInputBuffer(); 
        showEndScreen(playerWon);
        gameRunning = false;
    }
}

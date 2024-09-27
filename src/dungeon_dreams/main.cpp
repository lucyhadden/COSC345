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

#include <string>
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
int dungeon_sizes[8][2] = {{3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}, {9, 9}, {10, 10}}; 


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
        CustomSleep(1);

        applyInventoryStats(playerStats, playerInventory);

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
                    setupLevel(level);
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

                    // count++;
                }
            }
            // }
            std::this_thread::sleep_for(std::chrono::seconds(1));
            cout << "You have completed level " << level << ". Leveling up...\n";
            upgradeStats(playerStats, playerClass);
            cout << "Press enter to continue..." << endl;
            cin.ignore(); // Ignore any leftover characters in the input buffer
            cin.get();    // Wait for user input

            displaySafeZone(playerStats);
        }

        playerWon = true;

        showEndScreen(playerWon);
        gameRunning = false;
    }
}

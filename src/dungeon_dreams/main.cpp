#include <iostream>
#include <cstdlib>
#include "StartScreen.h"
#include "movement.h"
#include "EndScreen.h"
#include "AsciiArt.h"
#include "player.h"
#include "item.h"
#include "interactions.h"
#include "Utils.h"
#include <string>
#include <iostream>
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
 */
short dungeon_sizes[8][2] = {{3, 3}, {6, 5}, {6, 3}, {6, 5}, {10, 5}, {8, 7}, {8, 7}, {10, 9}}; 

/** 
 * @brief The total number of levels in the dungeon.
 */
const int levels = 8;

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

    displayWelcome();

    while (gameRunning)
    {
        resetPlayerStats();

        int countdown = 5;
        int position = 0;

        while (countdown > 0)
        {
            Clear();
            for (int i = 0; i < position; i++)
            {
                cout << endl;
            }
            cout << AsciiArt::dungeonEntranceArt << endl;
            cout << "You are entering the dungeon in " << countdown << endl;
            CustomSleep(1);
            position++;
            countdown--;
        }

        Clear();
        std::cout << "You have entered the dungeon..." << std::endl;
        CustomSleep(1);

        for (int level = 1; level <= levels; level++)
        {

            // for (int i = 0; i < levels; i++)
            // {
            fillDungeon(dungeon_sizes[level - 1][0], dungeon_sizes[level - 1][1]);
            generateDynamicLevels();
            updateBoard();
            // int count = 0;

            while (true)
            {
                if (enterUserInput())
                {
                    setupLevel(level);
                    updateBoard();
                    short tyle = startEvent();
                    // cout << tyle << endl;
                    if(tyle ==5){
                        break;
                    }
                    levelPlay(tyle);
                    // count++;
                }
            }
            // }
            CustomSleep(1);
            cout << "You have completed level " << level << ". Press enter for next level..." << endl;
            cin.ignore(); // Ignore any leftover characters in the input buffer
            cin.get();    // Wait for user input
        }

        playerWon = true;

        showEndScreen(playerWon);
        gameRunning = false;
    }
}

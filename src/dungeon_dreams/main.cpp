#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "StartScreen.h"
#include "movement.h"
#include "EndScreen.h"
#include "AsciiArt.h"
#include "player.h"
#include "item.h"
#include "interactions.h"
#include "utils.h"
#include <string>
#include <iostream>
using namespace std;

short dungeon_sizes[8][2] = {{3, 3}, {6, 5}, {6, 3}, {6, 5}, {10, 5}, {8, 7}, {8, 7}, {10, 9}}; // sizes of each dungeon level
const int levels = 8;

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
            system("clear");
            for (int i = 0; i < position; i++)
            {
                cout << endl;
            }
            cout << AsciiArt::dungeonEntranceArt << endl;
            cout << "You are entering the dungeon in " << countdown << endl;
            ::sleep(1);
            position++;
            countdown--;
        }

        system("clear");
        cout << "You have entered the dungeon..." << endl;
        ::sleep(1);

        for (int level = 1; level <= levels; level++)
        {
            setupLevel(level);

            // for (int i = 0; i < levels; i++)
            // {
            fillDungeon(dungeon_sizes[level - 1][0], dungeon_sizes[level - 1][1]);
            generateDynamicLevels();
            updateBoard();
            int count = 0;

            while (count < 5)
            {
                if (enterUserInput())
                {
                    updateBoard();
                    short tyle = startEvent();
                    // cout << tyle << endl;
                    levelPlay(tyle);
                    count++;
                }
            }
            // }
            sleep(1);
            cout << "You have completed level " << level << ". Press enter for next level..." << endl;
            cin.ignore(); // Ignore any leftover characters in the input buffer
            cin.get();    // Wait for user input
        }

        playerWon = true;

        showEndScreen(playerWon);
        gameRunning = false;
    }
}

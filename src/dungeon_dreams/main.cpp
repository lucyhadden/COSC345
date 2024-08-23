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


using namespace std;

int main()
{
    bool gameRunning = true;
    bool gameCompleted = false;
    bool playerWon = false;

    displayWelcome();


    while (gameRunning) {
        resetPlayerStats();  
        
        int countdown = 5;
        int position = 0;

        while (countdown > 0) {
            system("clear");
            for (int i = 0; i < position; i++) {
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

        for (int level = 1; level <= 8; level++) { 
            setupLevel(level);  

            //gameCompleted = runMovement();  

            if (gameCompleted) {
                int tileMovedTo = rand() % 5;  
                levelPlay(tileMovedTo);  
                if (getPlayerHealth() <= 0) {
                    playerWon = false;
                    break;
                }
            } else {
                playerWon = false;
                break;
            }
        }

        
        if (gameCompleted && getPlayerHealth() > 0) {
            playerWon = true;
        }

        
        showEndScreen(playerWon);
        gameRunning = false;  
    }
    return 0;
}

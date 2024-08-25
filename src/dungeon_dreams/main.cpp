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

            for(int move = 1; move <= 10; move++){
                //gameCompleted = runMovement();  

                cout << "Move: " << move << endl;

                int tileMovedTo = rand() % 4;  
                if (tileMovedTo == 3){
                    tileMovedTo = 0;
                }
                levelPlay(tileMovedTo); 
                sleep(1);
            }
            sleep(1);
            cout << "You have completed level " << level << ". Press enter for next level...";
            cin.ignore();  // Ignore any leftover characters in the input buffer
            cin.get();     // Wait for user input
        }
            
        playerWon = true;
        
        showEndScreen(playerWon);
        gameRunning = false;  
    }
}

#include "StartScreen.h"
#include "movement.h"
#include "EndScreen.h"
#include "AsciiArt.h"
#include "player.h"
#include "item.h"
#include "interactions.h"
#include "utils.h"

int main()
{
    bool gameRunning = true;
    bool gameCompleted = false;
    bool playerWon = false;

    displayWelcome();
    displayMenu();
    handleMenuChoice();

    while (gameRunning) {
        resetPlayerStats();  

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

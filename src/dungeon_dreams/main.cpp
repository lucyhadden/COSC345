#include "/Users/lucyhadden/COSC345/include/StartScreen.h"
//#include "StartScreen.h"
#include "/Users/lucyhadden/COSC345/include/movement.h"
#include "/Users/lucyhadden/COSC345/include/EndScreen.h"
#include "/Users/lucyhadden/COSC345/include/AsciiArt.h"
#include "/Users/lucyhadden/COSC345/include/player.h"
#include "/Users/lucyhadden/COSC345/include/item.h"
#include "/Users/lucyhadden/COSC345/include/interactions.h"
#include "/Users/lucyhadden/COSC345/include/utils.h"

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

            gameCompleted = runMovement();  

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

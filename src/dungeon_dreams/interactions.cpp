/** Making the tile interactions for each level 
 * 
 * Elizabeth Stewart
 * 
*/

#include <string>
#include <iostream>
#include <unistd.h>
#include "player.h"

#include <cstdlib>
#include <ctime>

using namespace std;

//STARTING VARIABLES
string enemyType;
int enemyHealth;
int enemyDamage;
string trapType;
int trapDamage; 
int randomNumber;

/** CLASS OPTIONS
 * Knight: medium health, damage, defence. But low luck and stealth
 * Mage: high damage and medium defence. But low health, luck and stealth
 * Tank: high health and defence. But low damage, luck and stealth
 * Thief: high luck and stealth, and medium damage. But low health and defence
 * Clerk: high health and luck. But low damage, defence, stealth - BUT HAS HEALING ABILITY 
*/

void resetPlayerStats() {
    sleep(2);
    cout << "Welcome to the Adventurer's Guild!" << endl;
    sleep(2);
    cout << "Select Class: " << endl;
    cout << "1. Knight" << endl;
    cout << "2. Mage" << endl;
    cout << "3. Thief" << endl;
    cout << "4. Tank" << endl;
    cout << "5. Cleric" << endl;

    int classChoice;
    cin >> classChoice;

    switch (classChoice) {
        case 1:
            cout << "You have chosen the noble Knight class!" << endl;
            Player("Player", 100, 10, 5, 0, 0);
            break;
        case 2:
            cout << "You have chosen the mystical Mage class!" << endl;
            Player("Player", 80, 15, 0, 0, 0);
            break;
        case 3:
            cout << "You have chosen the sneaky Thief class!" << endl;
            Player("Player", 50, 5, 0, 10, 10);
            break;
        case 4:
            cout << "You have chosen the stoic Tank class!" << endl;
            Player("Player", 120, 5, 15, 0, 0);
            break;
        case 5:
            cout << "You have chosen the devout Cleric class!" << endl;
            Player("Player", 110, 5, 0, 0, 10);
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            resetPlayerStats(); // recursive call to ask again
    }
    //cout << Player.toString() << endl;
    pressAnyKeyToContinue();
}

int getPlayerHealth() {
    return playerHealth;
}

int safeTile = 0;
int emenyTile = 1;
int trapTile = 2;
int wallTile = 4;

int tileMovedTo;


void levelPlay(int tileMovedTo) {
    if(tileMovedTo == 0) {
        cout << "You are safe" << endl;
    } else if(tileMovedTo == 1) {
        cout << "Oh no! You have encountered a " << enemyType << ". Attack it!" << endl;
        sleep(2);
        enemyHealth = enemyHealth - playerDamage;
        if(enemyHealth <= 0) {
            cout << "You have defeated the " << enemyType << "." << endl;
        } else {
            while (enemyHealth > 0) {
                cout << "The " << enemyType << " is still alive! It's going to attack" << endl;
                sleep(2);
                if(playerDefence > enemyDamage) {
                    cout << "Your defensive stat is higher than the enemy's damage! You take no damage" << endl;
                } else {
                    cout << "The " << enemyType << "'s damage is higher than your defensive stat! You took "<< (enemyDamage - playerDefence) << " damage" << endl;
                    playerHealth -= (enemyDamage - playerDefence);
                }
                sleep(2);
                if (playerHealth <= 0) {
                    cout << "You have died" << endl;
                    exit(0);
                }
                cout << "You have " << playerHealth << " health left" << endl;
                enemyHealth -= playerDamage;
            }
            cout << "You have defeated the " << enemyType << "." << endl;
        }
    } else if(tileMovedTo == 2) {
        cout << "Oh no! A " << trapType << endl;
        sleep(2);
        playerHealth -= trapDamage;
        if (playerHealth <= 0) {
            cout << "You have died" << endl;
            exit(0);
        }
        cout << "You have taken " << trapDamage << " damage" << endl; 
    } else if(tileMovedTo == 4) {
        cout << "It's a wall! You cannot move here" << endl;
    } else {
        cout << "Invalid tile" << endl;
    }
}

//just changed to one function which is called and adjusted based ont he level we input for it
void setupLevel(int levelNumber) {
    switch(levelNumber) {
        case 1:
            enemyType = "Slime";
            enemyHealth = 10;
            enemyDamage = 10;
            trapType = "Pitfall";
            trapDamage = 10;
            break;
        case 2:
            enemyType = "Skeleton";
            enemyHealth = 15;
            enemyDamage = 15;
            trapType = "Falling rock";
            trapDamage = 15;
            break;
        case 3:
            enemyType = "Cave Spider";
            enemyHealth = 15;
            enemyDamage = 15;
            trapType = "Swinging blade";
            trapDamage = 15;
            break;
        case 4:
            enemyType = "Ghostly knight";
            enemyHealth = 20;
            enemyDamage = 20;
            trapType = "Spiked floor";
            trapDamage = 20;
            break;
        case 5:
            enemyType = "Banshee";
            enemyHealth = 20;
            enemyDamage = 20;
            trapType = "Phantom chain";
            trapDamage = 20;
            break;
        case 6:
            enemyType = "Fire Golem";
            enemyHealth = 30;
            enemyDamage = 30;
            trapType = "Boulder";
            trapDamage = 30;
            break;
        case 7:
            enemyType = "Liche";
            enemyHealth = 30;
            enemyDamage = 30;
            trapType = "Magical rune";
            trapDamage = 30;
            break;
        case 8:
            enemyType = "Wyvern";
            enemyHealth = 40;
            enemyDamage = 40;
            trapType = "Fire trap";
            trapDamage = 40;
            break;
        default:
            cout << "Unknown level" << endl;
            break;
    }
}

// Function to wait for user input before continuing
void pressAnyKeyToContinue() {
    cout << "Press enter to continue...";
    cin.ignore();  // Ignore any leftover characters in the input buffer
    cin.get();     // Wait for user input
}

//MAIN METHOD (temporary - for testing)
// int main() {
//     srand(time(0));

//     //LEVEL 1
//     cout << "LEVEL 1" << endl;
//     sleep(2);

//     //loop through level play for all moves
//     for(int moveCount = 1; moveCount <= 5; moveCount++){
//         level1(); 
//         randomNumber = rand() % 5;
//         if (randomNumber == 3){
//             randomNumber = 0;
//         }
//         tileMovedTo = randomNumber; //generate a random number for tile to interact with 
//         cout << "Move: " << moveCount << endl; //move number
//         sleep(2);
//         levelPlay(); //call level play
//         sleep(2);
//         cout << endl;
//     }
//     cout << "Your current health is " << playerHealth << endl;
//     cout << endl;



//     //LEVEL 2
//     cout << "LEVEL 2" << endl;
//     sleep(2);

//     //loop through level play for all moves
//     for(int moveCount = 1; moveCount <= 5; moveCount++){
//         level2();
//         randomNumber = rand() % 5;
//         if (randomNumber == 3){
//             randomNumber = 0;
//         }
//         tileMovedTo = randomNumber; //generate a random number for tile to interact with 
//         cout << "Move: " << moveCount << endl; //move number
//         sleep(2);
//         levelPlay(); //call level play
//         sleep(2);
//         cout << endl;
//     }
//     cout << "Your current health is " << playerHealth << endl;
//     cout << endl;


//     //LEVEL 3
//     cout << "LEVEL 3" << endl;
//     sleep(2);

//     //loop through level play for all moves
//     for(int moveCount = 1; moveCount <= 5; moveCount++){
//         level3();
//         randomNumber = rand() % 5;
//         if (randomNumber == 3){
//             randomNumber = 0;
//         }
//         tileMovedTo = randomNumber; //generate a random number for tile to interact with 
//         cout << "Move: " << moveCount << endl; //move number
//         sleep(2);
//         levelPlay(); //call level play
//         sleep(2);
//         cout << endl;
//     }
//     cout << "Your current health is " << playerHealth << endl;
//     cout << endl;


//     //LEVEL 4
//     cout << "LEVEL 4" << endl;
//     sleep(2);

//     //loop through level play for all moves
//     for(int moveCount = 1; moveCount <= 5; moveCount++){
//         level4();
//         randomNumber = rand() % 5;
//         if (randomNumber == 3){
//             randomNumber = 0;
//         }
//         tileMovedTo = randomNumber; //generate a random number for tile to interact with 
//         cout << "Move: " << moveCount << endl; //move number
//         sleep(2);
//         levelPlay(); //call level play
//         sleep(2);
//         cout << endl;
//     }
//     cout << "Your current health is " << playerHealth << endl;
//     cout << endl;


//     //LEVEL 5
//     cout << "LEVEL 5" << endl;
//     sleep(2);

//     //loop through level play for all moves
//     for(int moveCount = 1; moveCount <= 5; moveCount++){
//         level5();
//         randomNumber = rand() % 5;
//         if (randomNumber == 3){
//             randomNumber = 0;
//         }
//         tileMovedTo = randomNumber; //generate a random number for tile to interact with 
//         cout << "Move: " << moveCount << endl; //move number
//         sleep(2);
//         levelPlay(); //call level play
//         sleep(2);
//         cout << endl;
//     }
//     cout << "Your current health is " << playerHealth << endl;
//     cout << endl;


//     //LEVEL 6
//     cout << "LEVEL 6" << endl;
//     sleep(2);

//     //loop through level play for all moves
//     for(int moveCount = 1; moveCount <= 5; moveCount++){
//         level6();
//         randomNumber = rand() % 5;
//         if (randomNumber == 3){
//             randomNumber = 0;
//         }
//         tileMovedTo = randomNumber; //generate a random number for tile to interact with 
//         cout << "Move: " << moveCount << endl; //move number
//         sleep(2);
//         levelPlay(); //call level play
//         sleep(2);
//         cout << endl;
//     }
//     cout << "Your current health is " << playerHealth << endl;
//     cout << endl;


//     //LEVEL 7
//     cout << "LEVEL 7" << endl;
//     sleep(2);

//     //loop through level play for all moves
//     for(int moveCount = 1; moveCount <= 5; moveCount++){
//         level7();
//         randomNumber = rand() % 5;
//         if (randomNumber == 3){
//             randomNumber = 0;
//         }
//         tileMovedTo = randomNumber; //generate a random number for tile to interact with 
//         cout << "Move: " << moveCount << endl; //move number
//         sleep(2);
//         levelPlay(); //call level play
//         sleep(2);
//         cout << endl;
//     }
//     cout << "Your current health is " << playerHealth << endl;
//     cout << endl;


//     //LEVEL 8
//     cout << "LEVEL 8" << endl;
//     sleep(2);

//     //loop through level play for all moves
//     for(int moveCount = 1; moveCount <= 5; moveCount++){
//         level8();
//         randomNumber = rand() % 5;
//         if (randomNumber == 3){
//             randomNumber = 0;
//         }
//         tileMovedTo = randomNumber; //generate a random number for tile to interact with 
//         cout << "Move: " << moveCount << endl; //move number
//         sleep(2);
//         levelPlay(); //call level play
//         sleep(2);
//         cout << endl;
//     }
//     cout << "Your current health is " << playerHealth << endl;
//     cout << endl;

// }
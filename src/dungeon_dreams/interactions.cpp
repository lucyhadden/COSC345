/** Making the tile interactions for each level 
 * 
 * Elizabeth Stewart
 * 
*/

/**
 * @file
 * @brief Tile interactions for each level
 * @author Elizabeth Stewart
 * 
 */

#include <string>
#include <iostream>
#include "player.h"
#include "StartScreen.h"
#include "EndScreen.h"
#include "Utils.h"

#include <cstdlib>
#include <ctime>

using namespace std;

//STARTING VARIABLES
/**
 * Type of the enemy the player encounters.
 */
string enemyType;

/**
 * Health points of the enemy.
 */
short enemyHealth;

/**
 * Damage the enemy can inflict on the player.
 */
short enemyDamage;

/**
 * Type of trap that the player may encounter.
 */

string trapType;

/**
 * Amount of damage a trap can inflict on the player.
 */
short trapDamage; 
// short randomNumber;

/**
 * The player character with initial stats: health, attack, defense, luck, and stealth.
 * 
 * This creates a player with the name "Player", 0 health points, 0 attack, 
 * 0 defense, 0 luck, and 0 stealth.
 */
Player player("Player", 0, 0, 0, 0, 0);


// Function to wait for user input before continuing
/**
 * Waits for the user to press any key to continue.
 */
void pressAnyKeyToContinue() {
    cout << "Press enter to continue...";
    cin.ignore();  // Ignore any leftover characters in the input buffer
    cin.get();     // Wait for user input
}

/* CLASS OPTIONS
 * Knight: medium health, damage, defence. But low luck and stealth
 * Mage: high damage and medium defence. But low health, luck and stealth
 * Tank: high health and defence. But low damage, luck and stealth
 * Thief: high luck and stealth, and medium damage. But low health and defence
 * Clerk: high health and luck. But low damage, defence, stealth - BUT HAS HEALING ABILITY 
*/
/**
 * Method that that sets player stats once choosen.
 */
void resetPlayerStats() {
    CustomSleep(2);
    cout << "Welcome to the Adventurer's Guild!" << endl;
    CustomSleep(2);
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
            player.setHealth(100);
            player.setAttack(10);
            player.setDefense(5);
            player.setLuck(0);
            player.setStealth(0);
            break;
        case 2:
            cout << "You have chosen the mystical Mage class!" << endl;
            player.setHealth(80);
            player.setAttack(15);
            player.setDefense(5);
            player.setLuck(0);
            player.setStealth(0);
            break;
        case 3:
            cout << "You have chosen the sneaky Thief class!" << endl;
            player.setHealth(50);
            player.setAttack(5);
            player.setDefense(0);
            player.setLuck(10);
            player.setStealth(10);
            break;
        case 4:
            cout << "You have chosen the stoic Tank class!" << endl;
            player.setHealth(120);
            player.setAttack(5);
            player.setDefense(15);
            player.setLuck(0);
            player.setStealth(0);
            break;
        case 5:
            cout << "You have chosen the devout Cleric class!" << endl;
            player.setHealth(110);
            player.setAttack(5);
            player.setDefense(0);
            player.setLuck(0);
            player.setStealth(10);
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            resetPlayerStats(); // recursive call to ask again
    }
    //cout << player.toString() << endl;
    cout << "Press enter to continue...";
    cin.ignore();  // Ignore any leftover characters in the input buffer
    cin.get();     // Wait for user input
}

/**
 * The tile that a player is safe on
 */
int safeTile = 1;

/**
 * The tile that the player encounters an enemy on
 */
int emenyTile = 2;

/**
 * The tile that the player encounters a trap on
 */
int trapTile = 3;

/**
 * The tile that the player encounters a wall
 */
int wallTile = 4;

/**
 * The tile that the player just moved on to
 */
int tileMovedTo;


/**
 * Method that handles what each tile does to the player.
 * @param tileMovedTo The type of tile that player just moved on
 */
void levelPlay(int tileMovedTo) {
    if(tileMovedTo == 1) {
        cout << "You are safe" << endl;
    } else if(tileMovedTo == 2) {
        cout << "Oh no! You have encountered a " << enemyType << ". Attack it!" << endl;
        CustomSleep(2);
        enemyHealth = enemyHealth - player.getAttack();
        if(enemyHealth <= 0) {
            cout << "You have defeated the " << enemyType << "." << endl;
        } else {
            while (enemyHealth > 0) {
                cout << "The " << enemyType << " is still alive! It's going to attack" << endl;
                CustomSleep(2);
                if(player.getDefense() >= enemyDamage) {
                    cout << "Your defensive stat is higher than the enemy's damage! You take no damage" << endl;
                } else {
                    cout << "The " << enemyType << "'s damage is higher than your defensive stat! You took "<< (enemyDamage - player.getDefense()) << " damage" << endl;
                    player.setHealth(player.getHealth()- (enemyDamage - player.getDefense()));
                }
                CustomSleep(2);
                if (player.getHealth() <= 0) {
                    cout << "You have died" << endl;
                    showEndScreen(false);
                }
                cout << "You have " << player.getHealth() << " health left" << endl;
                enemyHealth -= player.getAttack();
            }
            cout << "You have defeated the " << enemyType << "." << endl;
        }
    } else if(tileMovedTo == 3) {
        cout << "Oh no! A " << trapType << endl;
        CustomSleep(2);
        player.setHealth(player.getHealth() - trapDamage);
        if (player.getHealth() <= 0) {
            showEndScreen(false);
        }
        cout << "You have taken " << trapDamage << " damage" << endl; 
        cout << "You have " << player.getHealth() << " health left" << endl;
    } else if(tileMovedTo == 4) {
        cout << "It's a wall! You cannot move here" << endl;
    } else {
        cout << "Invalid tile" << endl;
    }
}

//just changed to one function which is called and adjusted based ont he level we input for it
/**
 * Method that handles setting the enemy stats up depneding on the level.
 * @param levelNumber controls what values are being set for the level
 */
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

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
#include <optional>
#include "interactions.h"
#include "StartScreen.h"
#include "EndScreen.h"
#include "utils.h"
#include "Status.h" 
#include "AsciiArt.h"
// #include "Utils.h"

#include <cstdlib>
#include <ctime>
#include <Status.h>
#include "Equipment.h"

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

// Function to wait for user input before continuing
/**
 * Waits for the user to press any key to continue.
 */
void pressAnyKeyToContinue() {
    cout << "Press enter to continue...";
    cin.ignore();  // Ignore any leftover characters in the input buffer
    cin.get();     // Wait for user input
}

/**
 * @brief Resets and initializes player stats based on chosen character class.
 * 
 * @param playerStats Reference to the player's current stats.
 * @param playerClass Reference to the player's chosen character class.
 */
void resetPlayerStats(CharacterStats& playerStats, CharacterClass& playerClass) {
    CustomSleep(2);
    cout << AsciiArt::getGuildMaster() << endl;
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
            playerClass = KNIGHT;
            playerStats = CharacterStats(playerClass);  // Initialize stats for Knight
            cout << "You have chosen the noble Knight class!" << endl;
            break;
        case 2:
            playerClass = MAGE;
            playerStats = CharacterStats(playerClass);  // Initialize stats for Mage
            cout << "You have chosen the mystical Mage class!" << endl;
            break;
        case 3:
            playerClass = THIEF;
            playerStats = CharacterStats(playerClass);  // Initialize stats for Thief
            cout << "You have chosen the sneaky Thief class!" << endl;
            break;
        case 4:
            playerClass = TANK;
            playerStats = CharacterStats(playerClass);  // Initialize stats for Tank
            cout << "You have chosen the stoic Tank class!" << endl;
            break;
        case 5:
            playerClass = CLERIC;
            playerStats = CharacterStats(playerClass);  // Initialize stats for Cleric
            cout << "You have chosen the devout Cleric class!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            resetPlayerStats(playerStats, playerClass);  // Recursive call if the choice is invalid
    }
    cout << "Press enter to continue...";
    cin.ignore();  // Ignore any leftover characters in the input buffer
    cin.get();     // Wait for user input

    Clear();
    cout << AsciiArt::getGuildMaster() << endl;
    CustomSleep(2);
    cout << "It is time to accept your first quest as an adventurer!" << endl;
    CustomSleep(2);
    cout << "Ah here's a simple one, an escort job through a low class dungeon." << endl;
    CustomSleep(2);
    cout << "Good Luck!" << endl;
    CustomSleep(2);
    cout << "Press enter to continue...";
    cin.ignore();  // Ignore any leftover characters in the input buffer
    cin.get();     // Wait for user input

    Clear();
    cout << AsciiArt::getGrizzleNormalExpression() << endl;
    cout << "Ah, there you are! Name's Grizzle. Heard you're the new adventurer everyone's talking about!" << endl;
    CustomSleep(4);
    Clear();
    cout << AsciiArt::getGrizzleScaredExpression() << endl;
    cout << "I need a bit of help, see? This dungeon just popped up recently - real simple stuff, nothing to worry about." << endl;
    CustomSleep(4);
    cout << "Just escort me through, and I'll make sure you get a little reward." << endl;
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
void levelPlay(int tileMovedTo, CharacterStats playerStats) {
    if(tileMovedTo == 1) {
        cout << "You are safe" << endl;
    } else if(tileMovedTo == 2) {
        cout << "Oh no! You have encountered a " << enemyType << ". Attack it!" << endl;
        CustomSleep(2);
        enemyHealth = enemyHealth - playerStats.attack;
        if(enemyHealth <= 0) {
            cout << "You have defeated the " << enemyType << "." << endl;
        } else {
            while (enemyHealth > 0) {
                cout << "The " << enemyType << " is still alive! It's going to attack" << endl;
                CustomSleep(2);
                if(playerStats.defense >= enemyDamage) {
                    cout << "Your defensive stat is higher than the enemy's damage! You take no damage" << endl;
                } else {
                    cout << "The " << enemyType << "'s damage is higher than your defensive stat! You took "<< (enemyDamage - playerStats.defense) << " damage" << endl;
                    playerStats.health -= (enemyDamage - playerStats.defense);
                }
                CustomSleep(2);
                if (playerStats.health <= 0) {
                    cout << "You have died" << endl;
                    showEndScreen(false);
                }
                cout << "You have " << playerStats.health << " health left" << endl;
                enemyHealth -= playerStats.attack;
            }
            cout << "You have defeated the " << enemyType << "." << endl;
        }
    } else if(tileMovedTo == 3) {
        cout << "Oh no! A " << trapType << endl;
        CustomSleep(2);
        playerStats.health -= trapDamage;
        if (playerStats.health <= 0) {
            showEndScreen(false);
        }
        cout << "You have taken " << trapDamage << " damage" << endl; 
        cout << "You have " << playerStats.health << " health left" << endl;
    } else if(tileMovedTo == 4) {
        cout << "It's a wall! You cannot move here" << endl;
    } else {
        cout << "This tile has already been explored. It has been cleared and is now safe." << endl;
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

/**
 * Process tile interactions based on the tile the player steps on.
 * 
 * @param tile The tile the player is on.
 * @param playerStats The player's stats.
 * @param playerInventory The player's inventory.
 * @return short The result of the interaction (e.g., 5 for level exit).
 */

short processTileInteraction(short tile, CharacterStats& playerStats, Inventory& playerInventory) {
    std::optional<Equipment> equipment;
    switch (tile) {
        case 1:  // Safe tile, no interaction
            cout << "Nothing happens on this tile.\n";
            return tile;

        case 2:  // Enemy encounter
            cout << "You encountered a " << enemyType << "!\n";
            playerStats.health -= enemyDamage;
            cout << "You lost " << enemyDamage << " health in the fight! Current health: " << playerStats.health << "\n";
            if (playerStats.health <= 0) {
                showEndScreen(false);  // Player died, show end screen
            }
            return tile;

        case 3:  // Item discovery
            cout << "You found a powerful item: Enchanted Rune Stone (+2 Attack, +2 Defense)\n";
            // int attack = (rand() % 5) + 1;
            // int defense = (rand() % 5) + 1;
            equipment = Equipment("Enchanted Rune Stone", 2, 2, 5);
            if (equipment.has_value()) {
                applyLastAddedItemToStats(playerStats, equipment.value()); 
                playerInventory.addEquipment(equipment.value());
            }
            return tile;

        case 4:  // Trap encounter
            cout << "Oh no! You stepped on a " << trapType << "!\n";
            playerStats.health -= trapDamage;
            cout << "You lost " << trapDamage << " health! Current health: " << playerStats.health << "\n";
            if (playerStats.health <= 0) {
                showEndScreen(false);  // Player died
            }
            return tile;

        case 5:  // Healing fountain
            cout << "You found a healing fountain! Restoring 20 health...\n";
            playerStats.health += 20;
            cout << "Current health: " << playerStats.health << "\n";
            return tile;

        case 6:  // Exit tile, level complete
            cout << "You found the exit! Moving to the next level...\n";
            return 5;  // Signal level completion

        default:
            cout << "You stepped on an unknown tile...\n";
            return tile;
    }
}




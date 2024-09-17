#ifndef INTERACTIONS_H
#define INTERACTIONS_H

#include <string>
#include "player.h"
#include "Status.h"     // Include for CharacterStats
#include "Equipment.h"  // Include for Inventory


/**
 * @file
 * @brief Header file for methods that relate to the interactions
 * @author Elizabeth Stewart
 * 
 */

/**
 * @brief Type of the enemy the player encounters.
 */
extern std::string enemyType;

/**
 * @brief Health points of the enemy.
 */
extern short enemyHealth;

/**
 * @brief Damage the enemy can inflict on the player.
 */
extern short enemyDamage;

/**
 * @brief Type of trap that the player may encounter.
 */
extern std::string trapType;

/**
 * @brief Amount of damage a trap can inflict on the player.
 */
extern short trapDamage;

/**
 * @brief The player character with initial stats: health, attack, defense, luck, and stealth.
 * 
 * This creates a player with the name "Player", 0 health points, 0 attack, 
 * 0 defense, 0 luck, and 0 stealth.
 */
extern Player player;

/**
 * @brief Handles what each tile does to the player.
 * 
 * @param tileMovedTo The type of tile that player just moved on.
 */
void levelPlay(int tileMovedTo);

/**
 * @brief Sets up the enemy stats depending on the level.
 * 
 * @param levelNumber Controls what values are being set for the level.
 */
void setupLevel(int levelNumber);

/**
 * @brief Sets player stats once chosen.
 */
void resetPlayerStats(CharacterStats& playerStats, CharacterClass& playerClass);

/**
 * @brief Waits for the user to press any key to continue.
 */
void pressAnyKeyToContinue(); 

/**
 * @brief Processes tile interactions based on the tile type.
 * 
 * @param tile The tile the player is currently on.
 * @param playerStats The player's stats that may be affected by the interaction.
 * @param playerInventory The player's inventory that may be affected by the interaction.
 * @return short The result of the interaction (e.g., 5 for level exit).
 */
short processTileInteraction(short tile, CharacterStats& playerStats, Inventory& playerInventory);

#endif

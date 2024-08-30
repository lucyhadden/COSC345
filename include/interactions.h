#ifndef INTERACTIONS_H
#define INTERACTIONS_H

#include <string>
#include "player.h"

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
void resetPlayerStats();

/**
 * @brief Waits for the user to press any key to continue.
 */
void pressAnyKeyToContinue(); 

#endif

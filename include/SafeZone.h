#ifndef SAFEZONE_H
#define SAFEZONE_H
#include "Status.h"

/**
 * @file
 * @brief Header file for safe zone related methods
 * @author Hayden Aish
 */

/**
 * @brief Displays the safe zone dialogue.
 */
void displaySafeZone(CharacterStats& playerStats);

/**
 * @brief Displays the options in the safe zone.
 */
void displayOptions();

/**
 * @brief Displays the options in the safe zone.
 */
void handleChoice(CharacterStats& playerStats);



#endif

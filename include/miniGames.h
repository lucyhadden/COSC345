#ifndef MINIGAMES_H
#define MINIGAMES_H

#include <Status.h>

/**
 * @file 
 * @brief Header file that holds the minigames
 */

/**
 * @brief Holds the first minigame option
 */
int game1();

/**
 * @brief Holds the second minigame option
 */
int game2();

/**
 * @brief Holds the third minigame option
 */
int game3();

/**
 * @brief Holds the fourth minigame option
 */
int game4();

/**
 * @brief randomly picks one of the games
 */
int spinWheel();

/**
 * @brief Method that contains logic for picking a game and returning gold
 * @param playerStats used to get the gold
 */
int miniGames(CharacterStats& playerStats);

/**
 * @brief Select game from game 1-4
 */
void SelectGame(int game);

/**
 * @brief Setter for the is testing Boolean variable used in testing.
 */
void setIsTesting(bool value);


#endif // MINIGAMES_H
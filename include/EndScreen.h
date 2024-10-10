#ifndef ENDSCREEN_H
#define ENDSCREEN_H

/**
 * @file
 * @brief Header file for methods that relate to the end screen
 * @author Elizabeth Stewart
 * 
 */


/**
 * @brief Displays the win screen animation.
 * 
 * @param isTest Boolean flag indicating if a test scenario. 
 */
void winScreen(bool isTest);

/**
 * @brief Displays the lose screen animation.
 */
void loseScreen();

/**
 * @brief Displays the end screen based on the game result.
 * 
 * @param won Boolean flag indicating if the game was won or lost. 
 */
void showEndScreen(bool won);

#endif

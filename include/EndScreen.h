#ifndef ENDSCREEN_H
#define ENDSCREEN_H

/**
 * @brief Displays the win screen animation.
 */
void winScreen();

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

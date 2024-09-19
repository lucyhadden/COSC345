#ifndef STARTSCREEN_H
#define STARTSCREEN_H

/**
 * @file
 * @brief Header file for start screeen and handles relevant events
 * @author Lucy Hadden
 * 
 */

/**
 * @brief Displays the welcome screen and initiates the game.
 */
void displayWelcome();

/**
 * @brief Displays the main menu.
 */
void displayMenu();

/**
 * @brief Handles the user's choice from the main menu.
 */
void handleMenuChoice();

/**
 * @brief Handles the user's choice of character class.
 */
void handleClassChoice();

/**
 * @brief Displays the available character classes.
 */
void displayCharacterClasses();

/**
 * @brief Displays the starting story.
 */
void startingStory();
void pressAnyKeyToContinue2();

#endif

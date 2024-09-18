/**
 * Header file for movement.cpp
 * 
 * Created by: Sen Macmaster 
 * Created on: 22/08/24
 * 
 * Last edited by: Sen Macmaster
 * Last edited on: 22/08/24
 */

/**
 * @file
 * @brief Header file for movement.cpp
 * @author Sen Macmaster
 * 
 */


#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <string>
#include <vector>

extern int length; /**< The length of the room. */
extern int height; /**< The height of the room. */

/**
 * @brief Gets the length of the room.
 * 
 * @return The length of the room.
 */
extern int getLength();

/**
 * @brief Gets the height of the room.
 * 
 * @return The height of the room.
 */
extern int getHeight();

/**
 * @brief Sets the length of the room.
 * 
 * @param l The new length of the room.
 */
extern void setLength(int l);

/**
 * @brief Sets the height of the room.
 * 
 * @param h The new height of the room.
 */
extern void setHeight(int h);

/**
 * @brief Checks if the player is against a wall based on the movement direction.
 * 
 * @param move A character indicating the direction of movement.
 * 
 * @return True if the player is against a wall in the specified direction, false otherwise.
 */
bool isAgainstWall(char move);

/**
 * @brief Clears the current board position of the player.
 */
void clearBoard();

/**
 * @brief Fills the dungeon with the specified dimensions and generates a path.
 * 
 * @param l The length of the dungeon.
 * @param h The height of the dungeon.
 */
void fillDungeon(int l, int h);

/**
 * @brief Generates dynamic levels for the dungeon.
 */
void generateDynamicLevels();

/**
 * @brief Handles user input for movement or help commands.
 * 
 * @return True if a valid move or help command is entered; false otherwise.
 */
bool enterUserInput();

/**
 * @brief Returns the type of tile the player is on.
 * 
 * @return Short representing the type of tile.
 */
short startEvent();

/**
 * @brief Updates the board to reflect the player's current position.
 */
void updateBoard();

#endif

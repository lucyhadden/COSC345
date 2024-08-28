/**
 * Header file for movement.cpp
 * 
 * Created by: Sen Macmaster 
 * Created on: 22/08/24
 * 
 * Last editted by: Sen Macmaster
 * Last editted on: 22/08/24
 */


#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <string>
#include <vector>

extern short length;
extern short height;

extern short getLength();
extern short getHeight();
extern void setLength(short l);
extern void setHeight(short h);

// Checks and displays
bool isAgainstWall(char move);
void clearBoard();

// Dungeon generation
void fillDungeon(short l, short h);
void generateDynamicLevels();

// Event functions after movement
bool enterUserInput();
short startEvent();

// Display functions
void updateBoard();

#endif
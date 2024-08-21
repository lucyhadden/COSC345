#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <string>

class movement
{
public:
    static const std::string input;

    void fillDungeon();
    void generateDynamicLevels(short length, short height);
    void updateBoard(bool remove);
    void clearBoard();
    bool isAgainstWall(char move);
    void startEvent();
    bool movementCheck(std::string input);
    bool enterUserInput();
    bool runMovement();
};

#endif
/*
    In this prototype, I haven't seen the new changes. But these are things I added (that we might have already):
    - Main (Mostly the same)
        - Dungeon sizes initialised in main from the A1 doc
        - A for loop that restarts a new level
        - Fill dungeon takes parameters of the size of the dungeon
    - Movement.cpp
        - Fixed the array into a vector because 2D arrays aren't as flexible to change its size after initialisation
        - Added getters and setters which link with the header. Now all height = getHeight() and same with length
        - Removed a few lines of redundant code in update & clear board methods
        - Start event method doesn't break if you clear a level. I think Hayden added that but idk
    - Movement.h
        - 'extern' = global, for getters & setters and length & height
    Pick and choose what's important. It should work but there's definitely a lot of redundancy
*/


#include <iostream>
#include "Movement.h"

using namespace std;

int main() {

    cout << "Testing" << endl; 
    const int levels = 8;
    short dungeon_sizes[8][2] = {{3,3},{6,5},{6,3},{6,5},{10,5},{8,7},{8,7},{10,9}}; // sizes of each dungeon level

    for(int i = 0; i < levels; i++){
        fillDungeon(dungeon_sizes[i][0], dungeon_sizes[i][1]); 
        generateDynamicLevels(); 
        updateBoard(); 

        //while(true) { 
            if(enterUserInput()) { 
                updateBoard(); 
                startEvent(); 
            } 
        //}
    }

    return 0; 
}
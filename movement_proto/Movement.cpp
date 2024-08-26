/**
 * Movement.cpp
 * 
 * Created by: Sen Macmaster 
 * Created on: 21/07/24
 * 
 * Last editted by: Sen Macmaster
 * Last editted on: 26/08/24
 */

#include <iostream> 
#include <cctype> 
#include <cmath>
#include <string>
#include <vector>
#include "Movement.h"

using namespace std; 

// Board config 
string level_board; 
 
const char player = 'X'; 
short y; 
short x; 

// Room config
const short length_of_room = 5; 
const short height_of_room = 1; 

vector<vector<short>> dynamic_dungeon; 

short height;
short length;

// Positions of player 
short movement; 
short pos[2];

short getLength() { return length; }
short getHeight() { return height; }
void setLength(short l) { length = l; }
void setHeight(short h) { height = h; }

void fillDungeon(short l, short h) { 
    setLength(l);
    setHeight(h);

    pos[0] = static_cast<short>(getHeight() / 2); 
    pos[1] = 0; 

    dynamic_dungeon.resize(getLength());
    for(int i = 0; i < getLength(); i++) {
        dynamic_dungeon[i].resize(getHeight(), 0);
    }
} 

void generateDynamicLevels() { 
    
    string board; 

    x = length_of_room + 1; 
    y = (x * getLength()) * 2; 

    for (int i = 0; i < getHeight(); i++) { 
        for (int j = 0; j < (height_of_room * getLength()); j++) { 
            board += string(length_of_room, ' '); 
            if(j < getLength() - 1){ 
                board += "|"; 
            } 
        }
        board += "\n"; 
        if (i < getHeight() - 1) { 
            for (int j = 0; j < getLength(); j++) { 
                board += string(length_of_room, '-'); 
                if(j < getLength() - 1){ 
                    board += "+"; 
                } 
            } 
            board += "\n"; 
        } 
    } 
    level_board = board; 
} 

void updateBoard(){ 
    movement = 2 + (pos[1] * x) + (pos[0] * y); 
    level_board.replace(movement, 1 , 1, player);  // update board 
    cout << level_board << endl; 
} 

void clearBoard(){ 
    movement = 2 + (pos[1] * x) + (pos[0] * y); 
    level_board.replace(movement, 1 , 1, ' ');  // update board 
} 


bool isAgainstWall(char move) { 
    // Vertical wall and horizontal wall checks 
    if((move == 'W' && pos[0] <= 0) || (move == 'S' && pos[0] >= getHeight() - 1)) { 
        cout << "TEST" << endl;
        return true; 
    } else if((move == 'A' && pos[1] <= 0) || (move == 'D' && pos[1] >= getLength() - 1)) { 
        cout << "TEST" << endl;
        return true; 
    } 
    return false; 
} 

void startEvent() { 
    short type_of_room = dynamic_dungeon[pos[0]][pos[1]];
    switch(type_of_room) { 
        case 0: 
            cout << "SAFE" << endl; 
            break; 
        default: 
            cout << "Descend the dungeon" << endl; 
    } 
} 

bool movementCheck(string input) { 
    char direction = toupper(input.at(0)); 
    clearBoard(); 
    if(direction == 'W' && !isAgainstWall('W')) { 
        pos[0] -= 1; 
    } else if(direction == 'A' && !isAgainstWall('A')) { 
        pos[1] -= 1; 
    } else if (direction == 'S' && !isAgainstWall('S')) { 
        pos[0] += 1; 
    } else if (direction == 'D' && !isAgainstWall('D')) { 
        pos[1] += 1; 
    } else { 
        cout << "Could not make move, try again" << endl; 
        return false; 
    } 
    return true; 
} 

bool enterUserInput() { 
    cout << "Enter movement WASD: "; 

    string input; 
    cin >> input; 

    if(input.length() == 1) { 
        return movementCheck(input); 
    } 
    if(input == "Help") { 
        cout << "--Help Menu--" << endl; 
        return true; 
    } 
    cout << "Could not make move, try again" << endl; 
    return false; 
}

// int main() { 
//     cout << "Testing" << endl; 

//     fillDungeon(); 
//     printVector();
//     generateDynamicLevels(length, height); 
//     updateBoard(); 

//     while(true) { 
//         if(enterUserInput()) { 
//             updateBoard(); 
//             startEvent(); 
//         } 
//     }
//     return 0; 
// }
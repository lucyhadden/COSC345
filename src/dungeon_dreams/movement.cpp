#include <iostream> 
#include <cctype> 
#include <cmath>
#include <string> 

using namespace std; 

// board config 
string level_board =     "     |     |     \n" 

                         "-----+-----+-----\n" 

                         "     |     |     \n" 

                         "-----+-----+-----\n" 

                         "     |     |     \n"; 

 
const char player = 'X'; 
short board_size = 0; 
short y; 
short x; 

 
// Room config
const short length_of_room = 5; 
const short height_of_room = 1; 
const short length = 10; 
const short height = 9; 

short dynamic_dungeon[length][height]; 
short level = 0; 

// Positions of player 
short movement; 
short pos[2] = {static_cast<short>(height / 2), 0}; 

// Console removal testing
short lines_to_be_removed = 0; 


void fillDungeon(){ 
    for(int i = 0; i < length; i++){ 
        for(int j = 0; j < height; j++){ 
            dynamic_dungeon[i][j] = 0; 
        } 
    } 
} 

void removeConsole(short remove){ 

    string move_cursor_up = "\033[A"; 
    string clear_line = "\033[2K"; 

    for(int i = 0; i < remove; i++){ 
        cout << move_cursor_up; 
        cout << clear_line; 
    } 
    cout.flush(); 
} 

void generateDynamicLevels(short length, short height){ 

    string board; 

    x = length_of_room + 1; 
    y = (x*length)*2; 

    board_size++; 
    for (int i = 0; i < height; i++) { 
        for (int j = 0; j < (height_of_room * length); j++) { 
            board += string(length_of_room, ' '); 
            if(j < length -1){ 
                board += "|"; 
            } 
        }
        board += "\n"; 
        board_size++;
        if (i < height - 1) { 
            for (int j = 0; j < length; j++) { 
                board += string(length_of_room, '-'); 
                if(j < length -1){ 
                    board += "+"; 
                } 
            } 
            board += "\n"; 
            board_size++; 
        } 
    } 
    level_board = board; 
} 

void updateBoard(bool remove){ 
    movement = 2 + (pos[1] * x) + (pos[0] * y); 
    level_board = level_board.replace(movement, 1 , 1, player);  // update board 
    if(remove){ 
        //removeConsole(board_size + lines_to_be_removed); 
        lines_to_be_removed = 0; 
    } 
    cout << level_board << endl; 
} 

void clearBoard(){ 
    movement = 2 + (pos[1] * x) + (pos[0] * y); 
    level_board = level_board.replace(movement, 1 , 1, ' ');  // update board 
} 

bool isAgainstWall(char move){ 
    // Vertical wall and horizontal wall checks 
    if((move == 'W' && pos[0] <= 0) || (move == 'S' && pos[0] >= height-1)){ 
        return true; 
    }else if((move == 'A' && pos[1] <= 0) || (move == 'D' && pos[1] >= length-1)){ 
        return true; 
    } 
    return false; 
} 

void startEvent(){ 
    short type_of_room; 
    type_of_room = dynamic_dungeon[pos[0]][pos[1]]; 
    switch(type_of_room){ 
        case 0: 
            cout << "SAFE" << endl; 
            break; 
        default: 
            cout << "Descend the dungeon" << endl; 
            level++; 
    } 
    //lines_to_be_removed++; 
} 

bool movementCheck(string input){ 
    char direction; 
    direction = toupper(input.at(0)); 
    clearBoard(); 
    if(direction == 'W' && !isAgainstWall('W')) { 
        pos[0] -= 1; 
    }else if(direction == 'A' && !isAgainstWall('A')) { 
        pos[1] -= 1; 
    }else if (direction == 'S' && !isAgainstWall('S')) { 
        pos[0] += 1; 
    }else if (direction == 'D' && !isAgainstWall('D')) { 
        pos[1] += 1; 
    }else{ 
        cout << "Could not make move,  try again" << endl; 
        return false; 
    } 
    return true; 
} 

bool enterUserInput(){ 
    cout << "Enter movement WASD: "; 
    lines_to_be_removed++; 

    string input; 
    cin >> input; 

    if(input.length() == 1){ 
        return movementCheck(input); 
    } 
    if(input == "Help"){ 
        cout << "--Help Menu--" << endl; 
        lines_to_be_removed++; 
        return true; 
    } 
    cout << "Could not make move,  try again" << endl; 
    lines_to_be_removed++; 
    return false; 
}

int main() { 
    cout << "Testing" << endl; 

    fillDungeon(); 
    generateDynamicLevels(length, height); 
    updateBoard(false); 

    while(true){ 
        if(enterUserInput()){ 
            updateBoard(true); 
            startEvent(); 
        } 
    }
    return 0; 
} 

 
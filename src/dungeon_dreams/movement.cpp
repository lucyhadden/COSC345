#include <iostream> 
#include <cctype> 
#include <cmath>
#include <string> 
#include <time.h> 
#include <vector>
#include <utility>

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
const short length = 8; 
const short height = 7; 

short dynamic_dungeon[height][length]; 
short level = 0; 

// Positions of player 
short movement; 
short pos[2] = {static_cast<short>(height / 2), 0}; 

// Console removal testing
short lines_to_be_removed = 0; 

// Check if a position is safe
bool is_safe(int x, int y) {
    return x >= 0 && x < height && y >= 0 && y < length && dynamic_dungeon[x][y] == 0;
}

// Check if placing a path at (x, y) would form a 2x2 block
bool forms_block(int x, int y) {
    int directions[3][2] = {{-1, -1}, {-1, 0}, {-1, 1}};
    for (int i = 0; i < 3; ++i) {
        int dx = directions[i][0], dy = directions[i][1];
        if (x + dx >= 0 && x + dx < height - 1 &&
            y + dy >= 0 && y + dy < length - 1 &&
            dynamic_dungeon[x + dx][y + dy] == 1 &&
            dynamic_dungeon[x + dx + 1][y + dy] == 1 &&
            dynamic_dungeon[x + dx][y + dy + 1] == 1 &&
            dynamic_dungeon[x + dx + 1][y + dy + 1] == 1) {
            return true;
        }
    }
    return false;
}

// Print the dungeon
void print_dungeon() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < length; j++) {
            cout << dynamic_dungeon[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n====================\n" << endl;
}

// Generate a random path through the dungeon
void generate_path() {
    int x = height / 2, y = 0;
    dynamic_dungeon[x][y] = 1;
    // print_dungeon();
    
    vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}};
    
    while (y < length - 1) {
        vector<pair<int, int>> possible_moves;
        
        for (const auto& dir : directions) {
            int new_x = x + dir.first, new_y = y + dir.second;
            if (is_safe(new_x, new_y) && !forms_block(new_x, new_y)) {
                possible_moves.push_back({new_x, new_y});
            }
        }
        
        if (!possible_moves.empty()) {
            int index = rand() % possible_moves.size();
            x = possible_moves[index].first;
            y = possible_moves[index].second;
            dynamic_dungeon[x][y] = 1;
            // print_dungeon();
        } else {
            break;
        }
    }
}

//method that randomly fills the rest of the dungeon with 1
void generate_rest() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < length; j++) {
            if( dynamic_dungeon[i][j] !=1){
                int index = rand() %3+2;
                dynamic_dungeon[i][j] = index;   
            }
        }
    }

}

// Fill the dungeon with the generated path
void fillDungeon() {
    // Initialize the dungeon to zeros
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < length; j++) {
            dynamic_dungeon[i][j] = 0;
        }
    }
    // Use current time as seed for random generator 
    srand(time(0)); 
    // Generate the path
    generate_path();
    print_dungeon();
    generate_rest();
    print_dungeon();
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
        case 1: 
            cout << "SAFE" << endl; 
            break; 
        case 2: 
            cout << "enemy" << endl; 
            break; 
        case 3: 
            cout << "enemy" << endl; 
            break; 
        case 4: 
            cout << "wall" << endl; 
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

bool runMovement() {
    fillDungeon();
    generateDynamicLevels(length, height);
    updateBoard(false);

    while(true) {
        if(enterUserInput()) {
            updateBoard(true);
            startEvent();
        }

        //this is where we will want to end the level, when the player reaches a certain positon on the board (i.e. gets through unharmed)
    }

    return true; 
}

 
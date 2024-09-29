/**
 * @file
 * @brief Handles the player movement and generation of tiles (Hayden)
 * @author Sen Macmaster
 * @author Hayden Aish
 */
#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include <time.h>
#include <vector>
#include <utility>
#include "movement.h"
#include "utils.h"

using namespace std;

// Board config
/**
 * String that holds the board
 */
string level_board;

/**
 * Char that represents the player
 */
const char player = 'X';
int yPOS;
int xPOS;

// Room config
/**
 * Variable that controls how many spaces long the room is
 */
const int length_of_room = 5;

/**
 * Variable that controls how many spaces high the room is
 */
const int height_of_room = 1;


/**
 * Vector of a vector that represents the dungeon
 */
vector<vector<int>> dynamic_dungeon;

/**
 * The number of tiles high in the room.
 */
int height;

/**
 * The number of tiles long in the room.
 */
int length;

// Positions of player
int movement;
int pos[2];

/**
 * Method that gets the length of the room.
 * @return The length of the room
 */
int getLength() { return length; }

/**
 * Method that gets the height of the room.
 * @return The height of the room
 */
int getHeight() { return height; }

/**
 * Method that sets the length of the room.
 * @param l The new length
 */
void setLength(int l) { length = l; }

/**
 * Method that sets the height of the room.
 * @param h The new height
 */
void setHeight(int h) { height = h; }

/**
 * Method that gets the height of the room.
 * @details used during debugging to see if valid room tiles were generated
 */
void print_dungeon()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cout << dynamic_dungeon[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n====================\n"
         << endl;

}

// Check if a position is safe
/**
 * Method that checks if the coordinates passed are within bounds of room.
 * @param x The new x coordinate
 * @param y The new y coordinate
 * @return True if the coordinate is valid
 */
bool is_safe(int x, int y)
{
    return x >= 0 && x < height && y >= 0 && y < length && dynamic_dungeon[x][y] == 0;
}

// Check if placing a path at (x, y) would form a 2x2 block
/**
 * Method that checks if the coordinates passed form a square.
 * @param x The new x coordinate
 * @param y The new y coordinate
 * @return True if the coordinate forms a square
 */
bool forms_block(int x, int y)
{
    int directions[3][2] = {{-1, -1}, {-1, 0}, {-1, 1}};
    for (int i = 0; i < 3; ++i)
    {
        int dx = directions[i][0], dy = directions[i][1];
        if (x + dx >= 0 && x + dx < height - 1 &&
            y + dy >= 0 && y + dy < length - 1 &&
            dynamic_dungeon[x + dx][y + dy] == 1 &&
            dynamic_dungeon[x + dx + 1][y + dy] == 1 &&
            dynamic_dungeon[x + dx][y + dy + 1] == 1 &&
            dynamic_dungeon[x + dx + 1][y + dy + 1] == 1)
        {
            return true;
        }
    }
    return false;
}

// Generate a random path through the dungeon
/**
 * Method that generates a path from one side of the dungeon to the other
 * @details Marks the final tile as 5 to indicate end of path/room
 */
void generate_path()
{
    int x = static_cast<int>(getHeight() / 2);
    int y = 0;

    dynamic_dungeon[x][y] = 1;
    // print_dungeon();

    vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}};
    pair<int, int> last_position = {x, y};

    while (y < getLength() - 1)
    {
        vector<pair<int, int>> possible_moves;

        for (const auto &dir : directions)
        {
            int new_x = x + dir.first, new_y = y + dir.second;
            if (is_safe(new_x, new_y) && !forms_block(new_x, new_y))
            {
                possible_moves.push_back({new_x, new_y});
            }
        }

        if (!possible_moves.empty())
        {
            int index = rand() % possible_moves.size();
            x = possible_moves[index].first;
            y = possible_moves[index].second;
            dynamic_dungeon[x][y] = 1;
            last_position = {x, y}; // Update last position
            //print_dungeon();
        }
        else
        {
            break;
        }
    }
    // print_dungeon();
    // cout << "first positon: " << last_position.first << " second postion: " << last_position.second << endl;
    // Mark the last tile in the path as 5
    dynamic_dungeon[last_position.first][last_position.second] = 5;
}

// method that randomly fills the rest of the dungeon with 1
/**
 * Method that fills every square apart from path or final tile with other tile type
 */
void generate_rest()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (dynamic_dungeon[i][j] != 1 && dynamic_dungeon[i][j] != 5)
            {
                int index = rand() % 3 + 2;
                dynamic_dungeon[i][j] = index;
            }
        }
    }
}

/**
 * Method that sets size of size of dungeon and fills it 
 * @details Used in game loop to change size of rooms and randomly fill it
 * @param l The new length
 * @param h The new height
 */
void fillDungeon(int l, int h)
{
    setLength(l);
    setHeight(h);

    pos[0] = static_cast<int>(getHeight() / 2);
    pos[1] = 0;

    dynamic_dungeon.clear();
    dynamic_dungeon.resize(getLength());
    for (int i = 0; i < getLength(); i++)
    {
        dynamic_dungeon[i].resize(getHeight(), 0);
    }

    // Use current time as seed for random generator
    
    /*  warning C4244: 
        'argument': conversion from 'time_t' to 'unsigned int', possible loss of data [D:\University\2024\COSC345\C 
        OSC345_Project\COSC345\build\COSC345.vcxproj]
    */
    srand(time(0)); 

    // print_dungeon();
    // Generate the path
    generate_path();
    // print_dungeon();
    generate_rest();
    // print_dungeon();
}

void generateDynamicLevels()
{

    string board;

    xPOS = length_of_room + 1;
    yPOS = (xPOS * getLength()) * 2;

    for (int i = 0; i < getHeight(); i++)
    {
        for (int j = 0; j < (height_of_room * getLength()); j++)
        {
            board += string(length_of_room, ' ');
            if (j < getLength() - 1)
            {
                board += "|";
            }
        }
        board += "\n";
        if (i < getHeight() - 1)
        {
            for (int j = 0; j < getLength(); j++)
            {
                board += string(length_of_room, '-');
                if (j < getLength() - 1)
                {
                    board += "+";
                }
            }
            board += "\n";
        }
    }
    level_board = board;
}

void updateBoard()
{
    movement = 2 + (pos[1] * xPOS) + (pos[0] * yPOS);
    level_board.replace(movement, 1, 1, player); // update board
    cout << level_board << endl;
}

void clearBoard()
{
    movement = 2 + (pos[1] * xPOS) + (pos[0] * yPOS);
    level_board.replace(movement, 1, 1, ' '); // update board
}

/**
 * Method that checks if the entered move is valid e.g. will keep the plyer with in the bounds of the dungeon
 * @param move A character indicating the direction of movement
 * Returns true if the player is against a wall in the specified direction, false otherwise.
 */
bool isAgainstWall(char move)
{
    // Vertical wall and horizontal wall checks
    if ((move == 'W' && pos[0] <= 0) || (move == 'S' && pos[0] >= getHeight() - 1))
    {
        cout << "TEST" << endl;
        return true;
    }
    else if ((move == 'A' && pos[1] <= 0) || (move == 'D' && pos[1] >= getLength() - 1))
    {
        cout << "TEST" << endl;
        return true;
    }
    return false;
}

/**
 * Method that returns the type of tile the player is on
 * @return Short representing the type of tile
 */
short startEvent()
{
    short type_of_room = dynamic_dungeon[pos[0]][pos[1]];
    return type_of_room;
    // switch(type_of_room) {
    //     case 0:
    //         cout << "SAFE" << endl;
    //         break;
    //     default:
    //         cout << "Descend the dungeon" << endl;
    // }
}

/**
 * Method that checks if the input string is a valid move 
 * @param input A string containing a single character direction ('W', 'A', 'S', 'D').
 * @return Returns true if the move was successful, false if the move was invalid.
 */
bool movementCheck(string input)
{
    char direction = toupper(input.at(0));
    clearBoard();
    if (direction == 'W' && !isAgainstWall('W'))
    {
        pos[0] -= 1;
    }
    else if (direction == 'A' && !isAgainstWall('A'))
    {
        pos[1] -= 1;
    }
    else if (direction == 'S' && !isAgainstWall('S'))
    {
        pos[0] += 1;
    }
    else if (direction == 'D' && !isAgainstWall('D'))
    {
        pos[1] += 1;
    }
    else
    {
        cout << "Could not make move, try again" << endl;
        return false;
    }
    return true;
}

/**
 * Method that controls user input for movement or help commands.
 * 
 * @returns True if a valid move or help command is entered; false otherwise.
 */
bool enterUserInput()
{
    cout << "Enter movement WASD: ";

    string input;
    cin >> input;

    if (input.length() == 1)
    {
        return movementCheck(input);
    }
    if (input == "Help")
    {
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
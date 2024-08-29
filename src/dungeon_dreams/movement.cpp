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
#include <time.h>
#include <vector>
#include <utility>
#include "movement.h"

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

/**
 * @brief Method that gets the length of the room.
 * @return The length of the room
 */
short getLength() { return length; }

/**
 * @brief Method that gets the height of the room.
 * @return The height of the room
 */
short getHeight() { return height; }

/**
 * @brief Method that sets the length of the room.
 * @param l The new length
 */
void setLength(short l) { length = l; }

/**
 * @brief Method that sets the height of the room.
 * @param h The new height
 */
void setHeight(short h) { height = h; }

/**
 * @brief Method that gets the height of the room.
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
 * @brief Method that checks if the coordinates passed are within bounds of room.
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
 * @brief Method that checks if the coordinates passed form a square.
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
 * @brief Method that generates a path from one side of the dungeon to the other
 * @details Marks the final tile as 5 to indicate end of path/room
 */
void generate_path()
{
    int x = height / 2, y = 0;
    dynamic_dungeon[x][y] = 1;
    // print_dungeon();

    vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}};
    pair<int, int> last_position = {x, y};

    while (y < length - 1)
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
            // print_dungeon();
        }
        else
        {
            break;
        }
    }
    // print_dungeon();
    cout << "first positon: " << last_position.first << " second postion: " << last_position.second << endl;
    // Mark the last tile in the path as 5
    dynamic_dungeon[last_position.first][last_position.second] = 5;
}

// method that randomly fills the rest of the dungeon with 1
/**
 * @brief Method that fills every square apart from path or final tile with other tile type
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
 * @brief Method that sets size of size of dungeon and fills it 
 * @details Used in game loop to change size of rooms and randomly fill it
 * @param l The new length
 * @param h The new height
 */
void fillDungeon(short l, short h)
{
    setLength(l);
    setHeight(h);

    pos[0] = static_cast<short>(getHeight() / 2);
    pos[1] = 0;

    dynamic_dungeon.clear();
    dynamic_dungeon.resize(getLength());
    for (int i = 0; i < getLength(); i++)
    {
        dynamic_dungeon[i].resize(getHeight(), 0);
    }

    // Use current time as seed for random generator
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

    x = length_of_room + 1;
    y = (x * getLength()) * 2;

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
    movement = 2 + (pos[1] * x) + (pos[0] * y);
    level_board.replace(movement, 1, 1, player); // update board
    cout << level_board << endl;
}

void clearBoard()
{
    movement = 2 + (pos[1] * x) + (pos[0] * y);
    level_board.replace(movement, 1, 1, ' '); // update board
}

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
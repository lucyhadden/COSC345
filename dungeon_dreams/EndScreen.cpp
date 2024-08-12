/** File for ending screen for win/lose scenarios */

#include <iostream>
#include <string>
#include <cstdlib>  
#include <unistd.h>
#include "AsciiArt.h"
using namespace std;

void winScreen();
void loseScreen();


// Function to display the win screen animation
void winScreen() {

    system("clear");
    cout << "You have completed the dungeon!" << endl;
    sleep(1);
    cout << AsciiArt::WinArt << endl;

}

// Function to display the lose screen animation
void loseScreen() {
    for (int i = 0; i < 6; i++) {
        switch (i) {
            case 0: 
                cout << "\033[2J\033[1;1H"; // Clear screen
                cout <<
                " "
                << endl;
                sleep(1); 
                break;
            case 1: 
                cout << "\033[2J\033[1;1H"; // Clear screen
                cout <<
                " "
                << endl;
                sleep(1); 
                break;
            case 2: 
                cout << "\033[2J\033[1;1H"; // Clear screen
                cout <<
                " "
                << endl;
                sleep(1); 
                break;
            case 3: 
                cout << "\033[2J\033[1;1H"; // Clear screen
                cout <<
                " "
                << endl;
                sleep(1); 
                break;
            case 4: 
                cout << "\033[2J\033[1;1H"; // Clear screen
                cout <<
                " "
                << endl;
                sleep(1); 
                break;
            case 5: 
                cout << "\033[2J\033[1;1H"; // Clear screen
                cout <<
                " "
                << endl;
                sleep(1); 
                break;
        }
    }
    cout << "You Lose!" << endl;
}

int main() {
    winScreen();
    return 0;
}

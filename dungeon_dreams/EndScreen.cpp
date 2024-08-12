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
    cout << "You and Grizzle have sucessfully cleared the dungeon!" << endl;
    sleep(1);

}

// Function to display the lose screen animation
void loseScreen() {
    system("clear");
    cout << AsciiArt::LoseArt << endl;
}

int main() {
    winScreen();
    //loseScreen();
    return 0;
}

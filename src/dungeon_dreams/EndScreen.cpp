/** File for ending screen for win/lose scenarios 
 * 
 * Elizabeth Stewart
 * 
*/

#include <iostream>
#include <string>
#include <cstdlib>  
#include <unistd.h>
#include "COSC345/include/AsciiArt.h"
using namespace std;

void winScreen();
void loseScreen();

// Function to display the win screen animation
void winScreen() {
    system("clear");
    //cout << AsciiArt::WinArt9 << AsciiArt::WinArt6  << endl;

    cout << "You enter a dark room" << endl;
    sleep(3);
    cout << "In the middle, you see a treasure chest" << endl;
    sleep(3);
    
    cout << "Grizzle rushes forward" << endl;
    sleep(3);
    
    cout << "He eagerly opens the chest..." << endl;
    sleep(2);

    cout << AsciiArt::WinArt2 << endl;
    sleep(2);
    cout << "\033[15A";
    cout << AsciiArt::WinArt3 << endl;
    sleep(2);
    
    cout << "\nInside, something glimmers — a crown of dark emeralds and gold" << endl;
    sleep(3);
    
    cout << "It's an ancient goblin crown, a relic of a long-lost dynasty" << endl;
    sleep(3);
    
    cout << "Grizzle looks at you with gratitude in his eyes" << endl;
    sleep(3);
    
    cout << "Ever grateful, he pledges his loyalty to you" << endl;
    sleep(3);
    
    cout << "He will follow you on all your future adventures" << endl;
    sleep(3);

    system("clear");
    cout << AsciiArt::WinArt1 << endl;
    cout << "You completed the game" << endl;
    cout << endl; 

    sleep(2);
    
    cout << "What would you like to do?" << endl;
    cout << "1. Restart" << endl;
    cout << "2. Go to main menu" << endl;
    cout << "3. Exit" << endl;
    cout << "Please enter your choice (1-3): ";

    int choice;
    cin >> choice;
    switch(choice) {
        case 1:
            //restart game
            cout << "Restarting game..." << endl;
            break;
        case 2:
            //go to main menu
            cout << "Going to main menu..." << endl;
            break;
        case 3:
            //exit game
            cout << "Exiting game..." << endl;
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
}

// Function to display the lose screen animation
void loseScreen() {
    system("clear");
    cout << "Oh no" << endl;
    sleep(1);
    system("clear");

    for(int count = 0; count < 3; count++){
        cout <<  ".";
        cout.flush();
        sleep(1);
    }

    system("clear");
    cout << AsciiArt::LoseArt1 << endl;
    sleep(2);
    cout << "You failed to protect Grizzle and clear the dungeon" << endl;
    sleep(2);

    cout << "What would you like to do?" << endl;
    sleep(2);
    cout << "1. Restart" << endl;
    sleep(1); 
    cout << "2. Go to main menu" << endl;
    sleep(1);
    cout << "3. Exit" << endl;
    sleep(1);
    cout << "Please enter your choice (1-3): ";

    int choice;
    cin >> choice;
    switch(choice) {
        case 1:
            //restart game
            cout << "Restarting game..." << endl;
            break;
        case 2:
            //go to main menu
            cout << "Going to main menu..." << endl;
            break;
        case 3:
            //exit game
            cout << "Exiting game..." << endl;
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
}

// int main() {
//     winScreen();
//     //loseScreen();
//     return 0;
// }

//this will show the end screen based on the game result
void showEndScreen(bool won) {
    if (won) {
        winScreen();
    } else {
        loseScreen();
    }
}

/** File for ending screen for win/lose scenarios 
 * 
 * Elizabeth Stewart
 * 
*/

#include <iostream>
#include <string>
#include <cstdlib>  
#include "Utils.h"
#include "AsciiArt.h"
using namespace std;

/**
 * @file
 * @brief Displays end screeen and handles relevant events
 * @author Elizabeth Stewart
 * 
 */

void winScreen();
void loseScreen();

// Function to display the win screen animation

/**
 * Method that displays the win screen animation
 */
void winScreen() {
    Clear();

    cout << "You enter a dark room" << endl;
    CustomSleep(3);
    cout << "In the middle, you see a treasure chest" << endl;
    CustomSleep(3);
    
    cout << "Grizzle rushes forward" << endl;
    CustomSleep(3);
    
    cout << "He eagerly opens the chest..." << endl;
    CustomSleep(2);

    cout << AsciiArt::WinArt2 << endl;
    CustomSleep(2);
    cout << "\033[15A";
    cout << AsciiArt::WinArt3 << endl;
    CustomSleep(2);
    
    cout << "\nInside, something glimmers — a crown of dark emeralds and gold" << endl;
    CustomSleep(3);
    
    cout << "It's an ancient goblin crown, a relic of a long-lost dynasty" << endl;
    CustomSleep(3);
    
    cout << "Grizzle looks at you with gratitude in his eyes" << endl;
    CustomSleep(3);
    
    cout << "Ever grateful, he pledges his loyalty to you" << endl;
    CustomSleep(3);
    
    cout << "He will follow you on all your future adventures" << endl;
    CustomSleep(3);

    Clear();
    cout << AsciiArt::WinArt1 << endl;
    cout << "You completed the game" << endl;
    cout << endl; 

    CustomSleep(3);
    
    cout << "What would you like to do?" << endl;
    cout << "1. Restart" << endl;
    cout << "2. Go to main menu" << endl;
    cout << "3. Exit" << endl;
    cout << "Please enter your choice (1-3): ";

    int choice;
    cin >> choice;
    switch(choice) {
        case 1:
            //restart game - not implemented
            cout << "Restarting game..." << endl;
            break;
        case 2:
            //go to main menu - not implemented
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
/**
 * Method that displays the lose screen animation
 */
void loseScreen() {
    Clear();
    cout << "Oh no" << endl;
    CustomSleep(1);
    Clear();

    for(int count = 0; count < 3; count++){
        cout <<  ".";
        cout.flush();
        CustomSleep(1);
    }

    Clear();
    cout << AsciiArt::LoseArt1 << endl;
    CustomSleep(2);
    cout << "You failed to protect Grizzle and clear the dungeon" << endl;
    CustomSleep(2);

    cout << "What would you like to do?" << endl;
    CustomSleep(2);
    cout << "1. Restart" << endl;
    CustomSleep(1);
    cout << "2. Go to main menu" << endl;
    CustomSleep(1);
    cout << "3. Exit" << endl;
    CustomSleep(1);
    cout << "Please enter your choice (1-3): ";

    int choice;
    cin >> choice;
    switch(choice) {
        case 1:
            //restart game (not implemented)
            cout << "Restarting game..." << endl;
            break;
        case 2:
            //go to main menu (not implemented)
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

//this will show the end screen based on the game result
/**
 * Method that handles which screen is displayed
 */
void showEndScreen(bool won) {
    if (won) {
        winScreen();
    } else {
        loseScreen();
    }
}

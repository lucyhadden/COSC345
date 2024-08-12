#include <iostream>
#include <unistd.h> // For sleep function on Unix systems
using namespace std;

// Function to display the win screen animation
void winScreen() {
    cout << "\033[2J\033[1;1H"; // Clear screen
    cout << "You Win!" << endl;

    for (int i = 0; i < 6; i++) {
        switch (i) {
            case 0: 
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
                break;
        }
    }
    cout << "You Win!" << endl;
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
    // Example condition for deciding which screen to show
    bool playerWon = true;

    if (playerWon) {
        winScreen();
    } else {
        loseScreen();
    }

    return 0;
}

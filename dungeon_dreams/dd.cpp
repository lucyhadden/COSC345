#include <iostream>
#include <string>
#include <cstdlib>  
#include <unistd.h>

using namespace std;

// Function prototypes
void displayWelcome();
void displayMenu();
void displayCharacterClasses();
void handleMenuChoice();
void handleClassChoice();


// ASCII Art for the Dungeon Entrance
const string dungeonEntranceArt = R"(
   _________________________________________________________
 /|     -_-                                             _-  |\
/ |_-_- _                                         -_- _-   -| \   
  |                            _-  _--                      | 
  |                            ,                            |
  |      .-'````````'.        '(`        .-'```````'-.      |
  |    .` |           `.      `)'      .` |           `.    |          
  |   /   |   ()        \      U      /   |    ()       \   |
  |  |    |    ;         | o   T   o |    |    ;         |  |
  |  |    |     ;        |  .  |  .  |    |    ;         |  |
  |  |    |     ;        |   . | .   |    |    ;         |  |
  |  |    |     ;        |    .|.    |    |    ;         |  |
  |  |    |____;_________|     |     |    |____;_________|  |  
  |  |   /  __ ;   -     |     !     |   /     `'() _ -  |  |
  |  |  / __  ()        -|        -  |  /  __--      -   |  |
  |  | /        __-- _   |   _- _ -  | /        __--_    |  |
  |__|/__________________|___________|/__________________|__|
 /                                             _ -        lc \
/   -_- _ -             _- _---                       -_-  -_ \
)";

// ASCII Art for Character Classes
const string knightArt = R"(
              /
       ,~~   /
   _  <=)  _/_
  /I\.="==.{>
  \I/-\T/-'
      /_\
     // \\_
    _I    /
)";
const string mageArt = R"(
            ,    _
           /|   | |
         _/_\_  >_<
        .-\-/.   |
       /  | | \_ |
       \ \| |\__(/
       /(`---')  |
      / /     \  |
   _.'  \'-'  /  |
   `----'`=-='   '
)";
const string thiefArt = R"(
   __o__
 /      \
|   O    o)
 \______/
)";
const string tankArt = R"(
    ___
 __(   )====::
/~~~~~~~~~\
\O.O.O.O.O/

)";
const string clericArt = R"(
    /|\
  /  |  \
  |  |  |
  |  |  |
  |  |  |
  |__|__|
)";

/**
 * Level - Entrance hall
 * Inventory - Weapon that fits style of class (TBD)
 * 
*/
const string enemySlimeArt = R"(
    /|\
  /  |  \
  |  |  |
  |  |  |
  |  |  |
  |__|__|
)";

/**
 * Level - Tomb of the Fallen
 * Inventory - Weapon that fits style of class (TBD)
*/
const string enemySkeletonArt = R"(
             _..---..__
           ,'          `-.
          .'` .          )
          |     `;.__.._.'
           \ .`--.(##)(#).
            `-->;--' pWq`>
              < <"v\,,,,]
               `\`^-''''7
                 `~"--^-'
)";

/**
 * Level - Treacherous Corridors
 * Inventory - Weapon that fits style of class (TBD)
*/
const string enemySpiderArt = R"(
          |
      /   |   \
     / /  |  \ \
     \ \_(*)_/ /
      \_(~:~)_/
       /-(:)-\
      / / * \ \
      \ \   / /
       \     /
)";

/**
 * Level - Haunted Gallery
 * Inventory - Weapon that fits style of class (TBD)
*/
const string enemyGhostArt = R"(
         ___
       _/ @@\
      ( \  O/__
       \    \__)
       /     \
      /      _\
     `"""""``
)";

/**
 * Level - Wailing Halls
 * Inventory - Weapon that fits style of class (TBD)
*/
const string enemyBansheeArt = R"(
    /|\
  /  |  \
  |  |  |
  |  |  |
  |  |  |
  |__|__|
)";

/**
 * Level - Crimson Forges
 * Inventory - Weapon that fits style of class (TBD)
*/
const string enemyFireGolemArt = R"(
    /|\
  /  |  \
  |  |  |
  |  |  |
  |  |  |
  |__|__|
)";

/**
 * Level - Mystic Chamber
 * Inventory - Weapon that fits style of class (TBD)
*/
const string enemyLicheArt = R"(
    /|\
  /  |  \
  |  |  |
  |  |  |
  |  |  |
  |__|__|
)";

/**
 * Level - Guardian's lair
 * Inventory - Weapon that fits style of class (TBD)
*/
const string enemyWyvernArt = R"(
    /|\
  /  |  \
  |  |  |
  |  |  |
  |  |  |
  |__|__|
)";

// ASCII Art for the welcome & prologue 
const string dragonWelcomeArt = R"(
                         _                    _
                  ,/                        \,
        _________{(                          })_________
       /.-------./\\                        //\.-------.\
      //@@@@@@@//@@\\  )                (  //@@\\@@@@@@@\\
     //@@@@@@@//@@@@>>/                  \<<@@@@\\@@@@@@@\\
    //O@O@O@O//@O@O//                      \\O@O@\\O@O@O@O\\
  //OOOOOOOO//OOOO||          \  /          ||OOOO\\OOOOOOOO\\
 //O%O%O%O%//O%O%O%\\         ))((         //%O%O%O\\%O%O%O%O\\
||%%%%%%%%//'  `%%%%\\       //  \\       //%%%%'   `\\%%%%%%%||
((%%%%%%%((      %%%%%\\    ((    ))    //%%%%%       ))%%%%%%))
 \:::' `::\\      `:::::\\   \)~~(/    //:::::'      //::' `:::/
  )'     `;)'      (`  ` \\ `<@  @>' / / '  ')      `(;'     `(
          (               \`\ )^^( /  /               )
        _                  ) \\oo/   (
       (@)                  \  `'   /                      _
       |-|\__________________\__^__<________oOo__________ (@)
       |-|                                  VVV           |-|
       |-|   __          __  _                            |-|
       |-|  \ \        / / | |                            |-|
       |-|   \ \  /\  / /__| | ___ ___  _ __ ___   ___    |-|
       |-|    \ \/  \/ / _ \ |/ __/ _ \| '_ ` _ \ / _ \   |-|
       |-|     \  /\  /  __/ | (_| (_) | | | | | |  __/   |-|
       |-|      \/  \/ \___|_|\___\___/|_| |_| |_|\___|   |-|
       |-|                                                |-|
       |_|\_____________________________________________  | |
       (@)                 / ,/ \_____/ \\ ~\/~         `\|-|
        ~             ___//^~      \____/\\               (@)
                     <<<  \     __  <____/||               ~
                               <   \ <___/||
                                  || <___//
                                  \ \/__//
                                   ~----~
    _________________________________________________________
    |                                                       |
    |  In a dense forest, a lone adventurer wanders...      |
    |                                                       |
    |   ^  ^  ^   ^      ___I_      ^  ^   ^  ^  ^   ^  ^   |
    |  /|\/|\/|\ /|\    /\-_--\    /|\/|\ /|\/|\/|\ /|\/|\  |
    |  /|\/|\/|\ /|\   /  \_-__\   /|\/|\ /|\/|\/|\ /|\/|\  |
    |  /|\/|\/|\ /|\   |[]| [] |   /|\/|\ /|\/|\/|\ /|\/|\  |   
    |                                                       |
    |   The adventurer finds a hidden path leading to       |
    |   a dark dungeon. The quest is about to begin!        |
    |                                                       |
    |_______________________________________________________|
)";

// Function to display the welcome screen
void displayWelcome() {
    system("clear"); 
    cout << dragonWelcomeArt << endl;
    cout << "You find yourself lost in the forest, searching for adventure..." << endl;
    cout << "You stumble upon an old path leading to a dark dungeon." << endl;
    cout << "Are you ready to face the challenges ahead?" << endl;
    cout << "Press any key to enter the dungeon..." << endl;
    cin.ignore();
    cin.get(); // Wait for user input
    system("clear");
    cout << dungeonEntranceArt << endl;
    cout << "You are entering the dungeon in 5" << endl;
    sleep(1);
    system("clear");
    cout << dungeonEntranceArt << endl;
    cout << "You are entering the dungeon in 4" << endl;
    sleep(1);
    system("clear");
    cout << dungeonEntranceArt << endl;
    cout << "You are entering the dungeon in 3" << endl;
    sleep(1);
    system("clear");
    cout << dungeonEntranceArt << endl;
    cout << "You are entering the dungeon in 2" << endl;
    sleep(1);
    system("clear");
    cout << dungeonEntranceArt << endl;
    cout << "You are entering the dungeon in 1" << endl;
    sleep(1);
    system("clear");

}

// Function to display the main menu
void displayMenu() {
    cout << "Welcome to Dungeon Dreams: The Goblin Guide!" << endl;
    cout << "1. View Character Classes" << endl;
    cout << "2. Start Game" << endl;
    cout << "3. Exit" << endl;
    cout << "Please enter your choice (1-3): ";
}

// Function to handle the menu choice
void handleMenuChoice() {
    int choice;
    cin >> choice;
    switch(choice) {
        case 1:
            handleClassChoice();
            break;
        case 2:
            cout << "Starting the game..." << endl;
            break;
        case 3:
            cout << "Exiting game. Goodbye!" << endl;
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
}

// Function to display character classes
void displayCharacterClasses() {
    system("clear"); 
    cout << "Character Classes in Dungeon Dreams: The Goblin Guide" << endl;
    cout << "1. Knight" << endl;
    cout << knightArt << endl;
    cout << "2. Mage" << endl;
    cout << mageArt << endl;
    cout << "3. Thief" << endl;
    cout << thiefArt << endl;
    cout << "4. Tank" << endl;
    cout << tankArt << endl;
    cout << "5. Cleric" << endl;
    cout << clericArt << endl;
    cout << "Press any key to return to the main menu..." << endl;
    cin.ignore();
    cin.get(); // Wait for user input
}

// Function to handle the character class choice
void handleClassChoice() {
    displayCharacterClasses();
    displayMenu();
    handleMenuChoice();
}

int main() {
    displayWelcome();
    displayMenu();
    handleMenuChoice();
    return 0;
}

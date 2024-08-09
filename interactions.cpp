/** Making the tile interactions for each level - to later be added to another game play */

#include <string>
#include <iostream>
using namespace std;

//STARTING VARIABLES
string enemyType;
int enemyHealth;
int enemyDamage;
string trapType;
int trapDamage; 

int playerHealth = 100;
int playerDamage = 10;
int playerDefence = 0;

/** CLASS OPTIONS
 * Knight: medium health, damage, defence. But low luck and stealth
 * Mage: high damage and medium defence. But low health, luck and stealth
 * Tank: high health and defence. But low damage, luck and stealth
 * Thief: high luck and stealth, and medium damage. But low health and defence
 * Clerk: high health and luck. But low damage, defence, stealth - BUT HAS HEALING ABILITY 
*/

int safeTile = 0;
int emenyTile = 1;
int trapTile = 2;
int wallTile = 4;

int tileMovedTo;


void levelPlay(){

    if(tileMovedTo == safeTile){
        cout << "You are safe" << endl;
    }
    else if(tileMovedTo == emenyTile){
        cout << "Oh no! You have encountered a " << enemyType << ". Attack it!"<<endl;
        enemyHealth = enemyHealth - playerDamage;
        if(enemyHealth <= playerDamage){
            cout << "You have defeated the " << enemyType << "." << endl;
        }
        else{
            while (enemyHealth > 0)
            {
                cout << "The " << enemyType << " is still alive! It's going to attack" << enemyDamage << endl;
                playerHealth = playerHealth - (playerDefence - enemyDamage);
                cout << "You have taken damage"<< endl;
            
                cout << "You have " << playerHealth << " health left. You need to attack till its dead!";
                cout << "The " << enemyType << " has " << enemyHealth << " health left";
                enemyHealth = enemyHealth - playerDamage;
            }
            cout << "You have defeated the " << enemyType << "." << endl;
        }

    }
    else if(tileMovedTo == trapTile){
        cout << "Oh no! A " << trapType << endl;
        playerHealth = playerHealth - trapDamage;
        cout << "You have taken " << trapDamage << " damage" << endl; 
    }
    else if(tileMovedTo == wallTile){
        cout << "It's a wall!" << endl;
    }
    else{
        cout << "Invalid tile" << endl;
    }
}

void level1(){
    //LEVEL 1
    string enemyType = "Slime";
    int enemyHealth = 10;
    int enemyDamage = 10;
    string trapType = "Pitfall";
    int trapDamage = 10;
}
void level2(){
    //LEVEL 2
    string enemyType = "Skeleton";
    int enemyHealth = 15;
    int enemyDamage = 15;
    string trapType = "Falling rock";
    int trapDamage = 15;
}
void level3(){
    //LEVEL 3
    string enemyType = "Cave Spider";
    int enemyHealth = 15;
    int enemyDamage = 15;
    string trapType = "Swinging blade";
    int trapDamage = 15;
}
void level4(){
    //LEVEL 4
    string enemyType = "Ghostly knight";
    int enemyHealth = 20;
    int enemyDamage = 20;
    string trapType = "Spiked floor";
    int trapDamage = 20;
}
void level5(){
    //LEVEL 5
    string enemyType = "Banshee";
    int enemyHealth = 20;
    int enemyDamage = 20;
    string trapType = "Phantom chain";
    int trapDamage = 20;
}
void level6(){
    //LEVEL 6
    string enemyType = "Fire Golem";
    int enemyHealth = 30;
    int enemyDamage = 30;
    string trapType = "Boulder";
    int trapDamage = 30;
}
void level7(){
    //LEVEL 7
    string enemyType = "Liche";
    int enemyHealth = 30;
    int enemyDamage = 30;
    string trapType = "Magical rune";
    int trapDamage = 30;
}
void level8(){
    //LEVEL 8
    string enemyType = "Wyvern";
    int enemyHealth = 40;
    int enemyDamage = 40;
    string trapType = "Fire trap";
    int trapDamage = 40;
}
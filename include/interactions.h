#ifndef INTERACTIONS_H
#define INTERACTIONS_H

#include <string>
#include "player.h"

// Declare the global variables as extern
extern std::string enemyType;
extern short enemyHealth;
extern short enemyDamage;
extern std::string trapType;
extern short trapDamage;

// Declare global player object
extern Player player;

void levelPlay(int tileMovedTo);
void setupLevel(int levelNumber);
void resetPlayerStats();
void pressAnyKeyToContinue(); 

#endif

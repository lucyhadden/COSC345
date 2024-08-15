/**
 * Header file for player.cpp
 * 
 * Created by: Sen Macmaster 
 * Created on: 11/08/24
 * 
 * Last editted by: Sen Macmaster
 * Last editted on: 11/08/24
 */


#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <map>

using namespace std;

class Player {
private:
    string name;
    short health;
    short attack;
    short defense;
    short stealth;
    short luck;
    map<string, short> inventory;

public:
    // Constructor
    Player(string name, short health, short attack, short defense, short stealth, short luck);

    // Getters
    string getName() const { return name; }
    short getHealth() const { return health; }
    short getAttack() const { return attack; }
    short getDefense() const { return defense; }
    short getStealth() const { return stealth; }
    short getLuck() const { return luck; }
    bool isAlive() const { return (health > 0); }

    // Setters
    void setName(const string& n) { name = n; }
    void setHealth(short h) { health = h; }
    void setAttack(short a) { attack = a; }
    void setDefense(short d) { defense = d; }
    void setStealth(short s) { stealth = s; }
    void setLuck(short l) { luck = l; }

    // Inventory-specific functions
    bool addToInventory(const string& itemName, short amount);
    bool removeFromInventory(const string& itemName, short amount);
    bool findItem(const string& itemName) const;

    // Display functions
    void displayInventory() const;
    void displayStats() const;
    void toString() const;
};

#endif
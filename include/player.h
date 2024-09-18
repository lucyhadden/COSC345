#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <map>

class Player {
private:
    std::string name;
    short health;
    short attack;
    short defense;
    short stealth;
    short luck;
    std::map<std::string, short> inventory;

public:
    // Constructor
    Player(std::string name, short health, short attack, short defense, short stealth, short luck);

    // Getters
    std::string getName() const { return name; }
    short getHealth() const { return health; }
    short getAttack() const { return attack; }
    short getDefense() const { return defense; }
    short getStealth() const { return stealth; }
    short getLuck() const { return luck; }
    bool isAlive() const { return (health > 0); }

    // Setters
    void setName(const std::string& n) { name = n; }
    void setHealth(short h) { health = h; }
    void setAttack(short a) { attack = a; }
    void setDefense(short d) { defense = d; }
    void setStealth(short s) { stealth = s; }
    void setLuck(short l) { luck = l; }

    // Inventory-specific functions
    bool addToInventory(const std::string& itemName, short amount);
    bool removeFromInventory(const std::string& itemName, short amount);
    bool findItem(const std::string& itemName) const;

    // Display functions
    void displayInventory() const;
    void displayStats() const;
    void toString() const;
};

#endif
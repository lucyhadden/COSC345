/**
 * @file
 * @brief Initialises a player objact and tracks related variables
 * @author Sen Macmaster
 */

#include "player.h"
#include <iostream>
#include <map>

using namespace std;

Player::Player(string name, short health, short attack, short defense, short stealth, short luck)
: name(name), health(health), attack(attack), defense(defense), stealth(stealth), luck(luck) { }

bool Player::addToInventory(const string& itemName, short amount) {
    if (amount <= 0) return false; 
    inventory[itemName] += amount; 
    return true;
}

bool Player::removeFromInventory(const string& itemName, short amount) {
    auto item = inventory.find(itemName);
    if (item == inventory.end() || amount <= 0) {
        return false;
    }   
    
    if (item->second <= amount) {
        inventory.erase(item);
    }else{
        item->second -= amount;
    }
    return true;
}

/**
 * @brief Checks if an item is in the player's inventory.
 * 
 * This method searches the player's inventory for the specified item name.
 * 
 * @param itemName The name of the item to search for.
 * @return `true` if the item is found in the inventory, `false` otherwise.
 */
bool Player::findItem(const string& itemName) const{
    return inventory.find(itemName) != inventory.end();
}

/**
 * @brief Method that prints player inventory
 */
void Player::displayInventory() const {
    cout << name << "'s Inventory:" << endl;
    if (!inventory.empty()) {
        for (const auto& item : inventory) {
            cout << "   " << item.second <<  "x " << item.first << endl;
        }
        cout << endl;
    }
}

/**
 * @brief Method that prints player stats
 */
void Player::displayStats() const {
    cout << "Player: " << name << endl
         << "   Health: " << health << endl
         << "   Attack: " << attack << endl
         << "   Defense: " << defense << endl
         << "   Stealth: " << stealth << endl
         << "   Luck: " << luck << endl << endl;
}

/**
 * @brief to String method that displays player stats and Inventory
 */
void Player::toString() const {
    Player::displayStats();
    Player::displayInventory();
}
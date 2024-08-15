/**
 * Header file for item.cpp
 * 
 * Created by: Sen Macmaster 
 * Created on: 11/08/24
 * 
 * Last editted by: Sen Macmaster
 * Last editted on: 11/08/24
 */


#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
private:
    string name;
    string type; // consumable/equippable/neither/something else entirely
    string description;
    string icon;
    //float weight; // fun concept
    //float value;    // fun concept
    //short durability // fun concept


public:
    // Constructor
    Item(string name, string type, string description, string icon);
    // Getters
    string getName() const { return name; }
    string getType() const { return type; }
    string getDescription() const { return description; }
    string getIcon() const { return icon; }
    // float getWeight() const { return weight; }
    // float getValue() const { return value; }
    // string getDurability() const { return durability; }

    void useItem(string type);

};

#endif
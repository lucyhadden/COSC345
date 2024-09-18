#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
private:
    std::string name;
    std::string type; // consumable/equippable/neither/something else entirely
    std::string description;
    std::string icon;
    //float weight; // fun concept
    //float value;    // fun concept
    //short durability // fun concept


public:
    // Constructor
    Item(std::string name, std::string type, std::string description, std::string icon);
    // Getters
    std::string getName() const { return name; }
    std::string getType() const { return type; }
    std::string getDescription() const { return description; }
    std::string getIcon() const { return icon; }
    // float getWeight() const { return weight; }
    // float getValue() const { return value; }
    // string getDurability() const { return durability; }

    void useItem(const std::string& type);

};

#endif
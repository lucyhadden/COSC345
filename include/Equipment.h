#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>
#include <vector>
#include <iostream>
#include "Status.h"  // Include for CharacterStats and CharacterClass
 

/**
 * @file
 * @brief Represents a piece of equipment that can provide bonuses to the player's stats.
 * @author Lucy Hadden
 */
class Equipment {
public:
    std::string name;
    int attackBoost;
    int defenseBoost;
    int cost;

    /**
     * @brief Constructor for Equipment.
     * @param n The name of the equipment.
     * @param atkBoost The attack boost this equipment provides.
     * @param defBoost The defense boost this equipment provides.
     * @param cost The cost of this equipment.
     */
    Equipment(std::string n, int atkBoost, int defBoost, int c);
};

/**
 * @brief Manages the player's inventory of equipment and provides methods to calculate total stat bonuses.
 */
class Inventory {
private:
    std::vector<Equipment> equipment;  // List of equipment

public:

    /**
     * @brief Get inventory
     * @return equipment
     */
    std::vector<Equipment> getInventory() { return equipment; }

    /**
     * @brief Adds a piece of equipment to the inventory.
     * @param equip The equipment to be added.
     */
    void addEquipment(const Equipment& equip);

    /**
     * @brief Calculates the total attack bonus from all equipment.
     * @return The total attack boost from the inventory.
     */
    int calculateTotalAttack() const;

    /**
     * @brief Calculates the total defense bonus from all equipment.
     * @return The total defense boost from the inventory.
     */
    int calculateTotalDefense() const;

    /**
     * @brief Prints the list of equipment in the inventory.
     */
    void printInventory() const;
};

/**
 * @brief Applies the inventory's stat bonuses to the player's stats.
 * @param stats Reference to the player's character stats.
 * @param inventory Reference to the player's inventory.
 */
void applyInventoryStats(CharacterStats& stats, Inventory& inventory);

/**
 * @brief Initializes the inventory based on the player's class.
 * @param inventory Reference to the player's inventory.
 * @param characterClass The player's chosen character class.
 */
void initializeInventory(Inventory& inventory, CharacterClass characterClass);

#endif // EQUIPMENT_H

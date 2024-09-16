#include "Equipment.h"

/**
 * @brief Constructor for Equipment.
 * @param n The name of the equipment.
 * @param atkBoost The attack boost this equipment provides.
 * @param defBoost The defense boost this equipment provides.
 */
Equipment::Equipment(std::string n, int atkBoost, int defBoost) 
    : name(n), attackBoost(atkBoost), defenseBoost(defBoost) {}

/**
 * @brief Adds equipment to the inventory.
 */
void Inventory::addEquipment(const Equipment& equip) {
    equipment.push_back(equip);
}

/**
 * @brief Calculates the total attack bonus from all equipment in the inventory.
 */
int Inventory::calculateTotalAttack() const {
    int totalAttack = 0;
    for (const auto& equip : equipment) {
        totalAttack += equip.attackBoost;
    }
    return totalAttack;
}

/**
 * @brief Calculates the total defense bonus from all equipment in the inventory.
 */
int Inventory::calculateTotalDefense() const {
    int totalDefense = 0;
    for (const auto& equip : equipment) {
        totalDefense += equip.defenseBoost;
    }
    return totalDefense;
}

/**
 * @brief Prints the inventory details.
 */
void Inventory::printInventory() const {
    for (const auto& equip : equipment) {
        std::cout << "Item: " << equip.name << " | Attack Boost: " 
                  << equip.attackBoost << " | Defense Boost: " 
                  << equip.defenseBoost << std::endl;
    }
}

/**
 * @brief Applies the inventory's total attack and defense bonuses to the player's stats.
 */
void applyInventoryStats(CharacterStats& stats, Inventory& inventory) {
    stats.attack += inventory.calculateTotalAttack();
    stats.defense += inventory.calculateTotalDefense();
}

/**
 * @brief Initializes the inventory based on the player's class.
 */
void initializeInventory(Inventory& inventory, CharacterClass characterClass) {
    switch (characterClass) {
        case KNIGHT:
            inventory.addEquipment(Equipment("Sword of Valor", 10, 5));
            inventory.addEquipment(Equipment("Steel Shield", 0, 15));
            break;
        case MAGE:
            inventory.addEquipment(Equipment("Staff of Wisdom", 15, 3));
            inventory.addEquipment(Equipment("Magic Robe", 0, 5));
            break;
        case THIEF:
            inventory.addEquipment(Equipment("Dagger of Speed", 7, 0));
            inventory.addEquipment(Equipment("Cloak of Shadows", 0, 8));
            break;
        case CLERIC:
            inventory.addEquipment(Equipment("Holy Mace", 8, 4));
            inventory.addEquipment(Equipment("Blessed Armor", 0, 10));
            break;
        case TANK:
            inventory.addEquipment(Equipment("Warhammer", 12, 0));
            inventory.addEquipment(Equipment("Tower Shield", 0, 20));
            break;
    }
}

#ifndef STORE_H
#define STORE_H


#include <unordered_map>
#include "Status.h"
#include "Equipment.h"

/**
 * @file
 * @brief Header for to represent the store and storekeeper
 */

/**
 * @brief Displays menu and inputs of shop
 */
void DisplayStoreMenu(CharacterStats& playerStats);

/**
 * @brief Manages all methods in one
 */
void IntroductionToStore(CharacterStats &playerStats);

/**
 * @brief Checks if a purchase can be made
 * @param playerStats a reference to the players stats
 * @param list is the equipment being bought
 * @param index the index of the equipment purchased
 */
void PurchaseEquipment(CharacterStats& playerStats, const std::unordered_map<int, Equipment>& list, int index);

/**
 * @brief Updates the ASCII ART for the shopkeeper
 */
void UpdateShopkeeper();

/**
 * @brief The main loop of store
 */
void StoreActivated(CharacterStats& playerStats);

/**
 * @brief The main loop of store
 * @param equipment the equipment selected
 * @param playerStats to add the attack and defense bonuses to the player
 */
void BuyItem(CharacterStats& playerStats, Equipment equipment);

/**
 * @brief Prints the shopkeeper's wares
 * @param list the vector containing all of the purchasable equipment
 */
void PrintStock(const std::unordered_map<int, Equipment>& list);

/**
 * @brief reset isFirstTime
 */
void setIsFirstTime();

#endif // STORE_H
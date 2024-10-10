#include <iostream>
#include <string>
#include <unordered_map>

#include "Equipment.h"
#include "AsciiArt.h"
#include "SafeZone.h"
#include "Status.h"
#include "Store.h"
#include "utils.h"

bool isFirstTime = true;
bool atStore = true;

Inventory playerInventory;

std::unordered_map<int, Equipment> stock = {
    {0, Equipment("Wooden Spatula", 15, 0, 20)},
    {1, Equipment("Shinguards", 0, 10, 35)}, 
    {2, Equipment("Plastic Shiv", 20, 0, 55)},   
    {3, Equipment("Metal Umberella", 0, 50, 100)},
    // Potion Items
    {4, Equipment("Minor Healing Potion - 10HP", 0, 0, 5)},
    {5, Equipment("Major Healing Potion - 30HP", 0, 0, 20)},
    {6, Equipment("Super Healing Potion - 80HP", 0, 0, 50)},

    {444343434, Equipment("God Killer", 9999, 9999, 0)}
};

const std::string shopkeeper1 = AsciiArt::getShopkeeper();
const std::string shopkeeper2 = AsciiArt::getLeftTalkShopkeeper();
const std::string shopkeeper3 = AsciiArt::getRightTalkShopkeeper();
const std::string shopkeeper4 = AsciiArt::getShrugShopkeeper();

std::vector<std::string> shopkeeperSprites = {shopkeeper1, shopkeeper2, shopkeeper3, shopkeeper4};

void setIsFirstTime(){
    isFirstTime = true;
}

void PressEnterToContinue()
{
    std::cout << "Press enter to continue...";
    std::cin.ignore();
    std::cin.get();
}

void UpdateShopkeeper()
{
    srand(time(0));
    int random = rand() % 4;
    Clear();
    std::cout << shopkeeperSprites[random] << std::endl;
}

void DisplayStoreMenu(CharacterStats &playerStats)
{
    UpdateShopkeeper();
    std::cout << "Welcome to Sive's Wares" << std::endl;
    std::cout << "You have " << playerStats.gold << " gold." << std::endl;
    std::cout << "1. View Stock" << std::endl;
    std::cout << "2. Purchase" << std::endl;
    std::cout << "3. Talk" << std::endl;
    std::cout << "4. My Inventory" << std::endl;
    std::cout << "5. Exit Shop" << std::endl;
    std::cout << "Please enter your choice (1-5): ";

    int choice;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        PrintStock(stock);
        PressEnterToContinue();
        break;
    case 2:
        std::cout << "Please enter the ID of the item you want to purchase: ";
        int index;
        std::cin >> index;
        PurchaseEquipment(playerStats, stock, index);
        break;
    case 3:
        std::cout << "I don't have any dialogue options for this right now." << std::endl;
        CustomSleep(2);
        break;
    case 4:
        std::cout << "--- Inventory ---" << std::endl;
        playerInventory.printInventory();
        PressEnterToContinue();
        break;
    case 5:
        atStore = false;
        break;
    default:
        std::cout << "Invalid choice. Please try again." << std::endl;
        CustomSleep(2);
        break;
    }
}

void IntroductionToStore(CharacterStats &playerStats)
{
    Clear();
    if (isFirstTime)
    {
        std::cout << shopkeeperSprites[0] << std::endl;
        CustomSleep(2);
        std::cout << "Oh a new face? Hello friend, my name is Sive. I am a skeleton" << std::endl;
        CustomSleep(2);
        std::cout << "This is my shop. Please buy something." << std::endl;
        CustomSleep(2);
        isFirstTime = false;
    }
    else
    {
        UpdateShopkeeper();
        CustomSleep(1);
        std::cout << "Hello again friend! Welcome back to my store." << std::endl;
        CustomSleep(1);
        std::cout << "Please buy something." << std::endl;
        CustomSleep(1);
    }
    // DisplayStoreMenu(playerStats);
}

void StoreActivated(CharacterStats &playerStats)
{
    IntroductionToStore(playerStats);
    atStore = true;
    while(atStore){
        DisplayStoreMenu(playerStats);
    }
    Clear();
    // displaySafeZone(playerStats);
}

void BuyItem(CharacterStats &playerStats, Equipment equipment)
{
    playerInventory.addEquipment(equipment);
    applyLastAddedItemToStats(playerStats, equipment);
}

void PurchaseEquipment(CharacterStats &playerStats, const std::unordered_map<int, Equipment> &list, int index)
{
    if (index < 0 || stock.find(index) == stock.end())
    {
        std::cout << "Item ID not found." << std::endl;
        CustomSleep(5);
    }
    else
    {
        auto it = list.find(index);
        const Equipment &equipment = it->second;
        int cost = equipment.cost;

        if (playerStats.gold >= cost && !(index == 4 || index == 5 || index == 6))
        {
            playerStats.gold -= cost;
            BuyItem(playerStats, equipment);
            stock.erase(index);
            std::cout << "Thank you for your purchase. Remaining gold: " << playerStats.gold << std::endl;
            CustomSleep(3);
        }
        else if (playerStats.gold >= cost && (index == 4 || index == 5 || index == 6))
        {
            playerStats.gold -= cost;
            if(index == 4) // minor
            {
                playerStats.health += 10;
            }else if(index == 5)
            {
                playerStats.health += 30;
            }else // super
            {
                playerStats.health += 80;
            }
            std::cout << "Thank you for your purchase. Remaining gold: " << playerStats.gold << " gold." << std::endl;
            std::cout << "We have many in stock." << std::endl;
            CustomSleep(3);
        }
        else
        {
            std::cout << "You don't have enough gold to purchase this item." << std::endl;
            CustomSleep(5);
        }
    }
}

void PrintStock(const std::unordered_map<int, Equipment> &list)
{
    Clear();
    UpdateShopkeeper();
    std::cout << " ~~~ Sive's Wares ~~~ " << std::endl;
    for (const auto &item : list)
    {
        const Equipment &equipment = item.second;
        if (item.first != 444343434)
        {
            std::cout << item.first << ": "
                      << equipment.name << " (+"
                      << equipment.attackBoost << " Attack, +"
                      << equipment.defenseBoost << " Defense): $"
                      << equipment.cost
                      << std::endl;
        }
    }
}
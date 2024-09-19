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
    {0, Equipment("Sword of Valor", 10, 5, 20)}, // base equip for KNIGHT
    {1, Equipment("Steel Shield", 0, 15, 20)},
    {2, Equipment("Staff of Wisdom", 15, 3, 20)}, // base equip for MAGE
    {3, Equipment("Magic Robe", 0, 5, 20)},
    {4, Equipment("Dagger of Speed", 7, 0, 20)}, // base equip for THIEF
    {5, Equipment("Cloak of Shadows", 0, 8, 20)},
    {6, Equipment("Holy Mace", 8, 4, 20)}, // base equip for CLERIC
    {7, Equipment("Blessed Armor", 0, 10, 20)},
    {8, Equipment("Warhammer", 12, 0, 20)}, // base equip for TANK
    {9, Equipment("Tower Shield", 0, 20, 20)},
    // Upgraded Items
    {10, Equipment("Amulet", 2, 2, 10)},
    {12, Equipment("Magic Amulet", 5, 3, 30)},
    {13, Equipment("God's Gift", 9999, 9999, 9999)}
};

const std::string shopkeeper1 = AsciiArt::getShopkeeper();
const std::string shopkeeper2 = AsciiArt::getLeftTalkShopkeeper();
const std::string shopkeeper3 = AsciiArt::getRightTalkShopkeeper();
const std::string shopkeeper4 = AsciiArt::getShrugShopkeeper();

std::vector<std::string> shopkeeperSprites = {shopkeeper1, shopkeeper2, shopkeeper3, shopkeeper4 };

void UpdateShopkeeper()
{
    srand(time(0));
    int random = rand() % 4;
    Clear();
    std::cout << shopkeeperSprites[random] << std::endl; 
}

void DisplayStoreMenu(CharacterStats& playerStats)
{
    UpdateShopkeeper();
    std::cout << "Welcome to [....]'s Wares" << std::endl;
    std::cout << "1. View Stock" << std::endl;
    std::cout << "2. Purchase" << std::endl;
    std::cout << "3. Talk" << std::endl;
    std::cout << "4. Exit Shop" << std::endl;
    std::cout << "Please enter your choice (1-4): ";
    
    int choice;
    std::cin >> choice;
    switch(choice) 
    {
        case 1:
            PrintStock(stock);   
            std::cout << "Press enter to continue...";
            std::cin.ignore();  
            std::cin.get(); 
            break;
        case 2:
            std::cout << "Please enter the ID of the item you want to purchase: ";
            int index;
            std::cin >> index;
            PurchaseEquipment(playerStats, stock, index);
            break;
        case 3:
            std::cout << "I don't have any dialogue options for this right now." << std::endl;
            std::cout << "Press enter to continue...";
            std::cin.ignore();  
            std::cin.get(); 
            break;
        case 4:
            atStore = false;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
    }
}

void IntroductionToStore(CharacterStats& playerStats)
{
    Clear();
    if(isFirstTime)
    {
        std::cout << shopkeeperSprites[0] << std::endl;
        CustomSleep(2);
        std::cout << "Oh a new face? Hello friend, my name is [...]. I am a skeleton" << std::endl;
        CustomSleep(2);
        std::cout << "This is my shop. Please buy something." << std::endl;
        CustomSleep(2);
        isFirstTime = false;
    }else
    {
        UpdateShopkeeper();
        CustomSleep(1);
        std::cout << "Hello again friend! Welcome back to my store." << std::endl;
        CustomSleep(1);
        std::cout << "Please buy something." << std::endl;
        CustomSleep(1);
    }
    DisplayStoreMenu(playerStats);
}

void StoreActivated(CharacterStats& playerStats)
{   
    IntroductionToStore(playerStats);
    while(atStore)
    {
        DisplayStoreMenu(playerStats);
    }
    atStore = true;
    Clear();
    displaySafeZone(playerStats);
}

void BuyItem(Equipment equipment)
{
    playerInventory.addEquipment(equipment);
}

void PurchaseEquipment(CharacterStats& playerStats, const std::unordered_map<int, Equipment>& list, int index)
{   
    if (index < 0 || stock.find(index) == stock.end())
    {
        std::cout << "Item ID not found." << std::endl;
    }else
    {   
        auto it = list.find(index);
        const Equipment& equipment = it->second;
        int cost = equipment.cost;

        if (playerStats.gold >= cost) 
        {   
            playerStats.gold -= cost;
            stock.erase(index);
            //BuyItem(equipment);
            std::cout << "Thank you for your purchase. Remaining gold: " << playerStats.gold << std::endl;
            //playerInventory.printInventory();
        } else 
        {
            std::cout << "You don't have enough gold to purchase this item." << std::endl;
        }
    }
}

void PrintStock(const std::unordered_map<int, Equipment>& list)
{
    Clear();
    UpdateShopkeeper();
    std::cout << " ~~~ [...]'s Wares ~~~ " << std::endl;
    for(const auto& item : list)
    {
        const Equipment& equipment = item.second;
        std::cout << item.first << ": " 
                  << equipment.name << " (ATK: " 
                  << equipment.attackBoost << ", DEF: " 
                  << equipment.defenseBoost << "): $"
                  << equipment.cost
                  << std::endl;
    }
}
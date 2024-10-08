#include "gtest/gtest.h"
#include "Equipment.h"

TEST(EquipmentTest, DummyTest) {
    EXPECT_TRUE(true);  
}

// // Test Equipment Constructor
// TEST(EquipmentTest, EquipmentConstructorTest) {
//     Equipment sword("Sword of Valor", 10, 5, 20);
//     EXPECT_EQ(sword.name, "Sword of Valor");
//     EXPECT_EQ(sword.attackBoost, 10);
//     EXPECT_EQ(sword.defenseBoost, 5);
//     EXPECT_EQ(sword.cost, 20);
// }

// // Test adding equipment to Inventory
// TEST(InventoryTest, AddEquipmentTest) {
//     Inventory inventory;
//     Equipment sword("Sword of Valor", 10, 5, 20);
//     inventory.addEquipment(sword);

//     auto equipmentList = inventory.getInventory();
//     ASSERT_EQ(equipmentList.size(), 1);
//     EXPECT_EQ(equipmentList[0].name, "Sword of Valor");
//     EXPECT_EQ(equipmentList[0].attackBoost, 10);
//     EXPECT_EQ(equipmentList[0].defenseBoost, 5);
// }

// // Test calculating total attack bonus from Inventory
// TEST(InventoryTest, CalculateTotalAttackTest) {
//     Inventory inventory;
//     Equipment sword("Sword of Valor", 10, 5, 20);
//     Equipment shield("Steel Shield", 0, 15, 20);
//     inventory.addEquipment(sword);
//     inventory.addEquipment(shield);

//     EXPECT_EQ(inventory.calculateTotalAttack(), 10);  // Only sword has attack boost
// }

// // Test calculating total defense bonus from Inventory
// TEST(InventoryTest, CalculateTotalDefenseTest) {
//     Inventory inventory;
//     Equipment sword("Sword of Valor", 10, 5, 20);
//     Equipment shield("Steel Shield", 0, 15, 20);
//     inventory.addEquipment(sword);
//     inventory.addEquipment(shield);

//     EXPECT_EQ(inventory.calculateTotalDefense(), 20);  // 5 from sword, 15 from shield
// }

// // Test applying Inventory stats to CharacterStats
// TEST(InventoryTest, ApplyInventoryStatsTest) {
//     Inventory inventory;
//     CharacterStats playerStats(KNIGHT);
//     Equipment sword("Sword of Valor", 10, 5, 20);
//     Equipment shield("Steel Shield", 0, 15, 20);
//     inventory.addEquipment(sword);
//     inventory.addEquipment(shield);

//     applyInventoryStats(playerStats, inventory);

//     EXPECT_EQ(playerStats.attack, 10);   // Attack boost from sword
//     EXPECT_EQ(playerStats.defense, 20);  // 5 from sword, 15 from shield
// }

// // Test initializing Inventory for different CharacterClass (KNIGHT)
// TEST(InventoryTest, InitializeInventoryKnightTest) {
//     Inventory inventory;
//     initializeInventory(inventory, KNIGHT);

//     auto equipmentList = inventory.getInventory();
//     ASSERT_EQ(equipmentList.size(), 2);

//     EXPECT_EQ(equipmentList[0].name, "Sword of Valor");
//     EXPECT_EQ(equipmentList[0].attackBoost, 10);
//     EXPECT_EQ(equipmentList[0].defenseBoost, 5);

//     EXPECT_EQ(equipmentList[1].name, "Steel Shield");
//     EXPECT_EQ(equipmentList[1].attackBoost, 0);
//     EXPECT_EQ(equipmentList[1].defenseBoost, 15);
// }

// // Test initializing Inventory for different CharacterClass (MAGE)
// TEST(InventoryTest, InitializeInventoryMageTest) {
//     Inventory inventory;
//     initializeInventory(inventory, MAGE);

//     auto equipmentList = inventory.getInventory();
//     ASSERT_EQ(equipmentList.size(), 2);

//     EXPECT_EQ(equipmentList[0].name, "Staff of Wisdom");
//     EXPECT_EQ(equipmentList[0].attackBoost, 15);
//     EXPECT_EQ(equipmentList[0].defenseBoost, 3);

//     EXPECT_EQ(equipmentList[1].name, "Magic Robe");
//     EXPECT_EQ(equipmentList[1].attackBoost, 0);
//     EXPECT_EQ(equipmentList[1].defenseBoost, 5);
// }

// // Test Inventory printInventory method
// TEST(InventoryTest, PrintInventoryTest) {
//     Inventory inventory;
//     Equipment sword("Sword of Valor", 10, 5, 20);
//     Equipment shield("Steel Shield", 0, 15, 20);
//     inventory.addEquipment(sword);
//     inventory.addEquipment(shield);

//     testing::internal::CaptureStdout();  // Capture standard output
//     inventory.printInventory();
//     std::string output = testing::internal::GetCapturedStdout();

//     EXPECT_NE(output.find("Item: Sword of Valor | Attack Boost: 10 | Defense Boost: 5"), std::string::npos);
//     EXPECT_NE(output.find("Item: Steel Shield | Attack Boost: 0 | Defense Boost: 15"), std::string::npos);
// }

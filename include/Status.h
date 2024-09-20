#ifndef STATUS_H
#define STATUS_H

/**
 * @file
 * @brief Header for to represent different classes and player stats
 */

/**
 * @brief Enum representing different character classes in the game.
 */
enum CharacterClass {
    KNIGHT,
    MAGE,
    THIEF,
    CLERIC,
    TANK
};

/**
 * @brief Manages the player's base stats such as health, attack, defense, etc.
 */
struct CharacterStats {
    int health;
    int attack;
    int defense;
    int agility;
    int intelligence;
    int gold;

    /**
     * @brief Initializes stats based on the selected character class.
     * @param characterClass The player's chosen character class.
     */
    CharacterStats(CharacterClass characterClass) {
        switch (characterClass) {
            case KNIGHT:
                health = 150;
                attack = 20;
                defense = 15;
                agility = 10;
                intelligence = 5;
                break;
            case MAGE:
                health = 80;
                attack = 25;
                defense = 5;
                agility = 15;
                intelligence = 30;
                break;
            case THIEF:
                health = 100;
                attack = 15;
                defense = 10;
                agility = 25;
                intelligence = 10;
                break;
            case CLERIC:
                health = 110;
                attack = 10;
                defense = 20;
                agility = 8;
                intelligence = 25;
                break;
            case TANK:
                health = 200;
                attack = 18;
                defense = 30;
                agility = 5;
                intelligence = 8;
                break;
        }
        gold = 0;
    }
};

/**
 * @brief Upgrades the player's stats when they level up.
 * @param stats Reference to the player's current stats.
 * @param characterClass The player's chosen character class.
 */
void upgradeStats(CharacterStats& stats, CharacterClass characterClass);

#endif // STATUS_H

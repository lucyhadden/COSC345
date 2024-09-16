enum CharacterClass {
    KNIGHT,
    MAGE,
    THIEF,
    CLERIC,
    TANK
};

struct CharacterStats {
    int health;
    int attack;
    int defense;
    int agility;
    int intelligence;

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
    }
};

void upgradeStats(CharacterStats& stats, CharacterClass characterClass) {
    switch (characterClass) {
        case KNIGHT:
            stats.health += 10;
            stats.attack += 5;
            stats.defense += 3;
            break;
        case MAGE:
            stats.health += 5;
            stats.attack += 7;
            stats.intelligence += 5;
            break;
        case THIEF:
            stats.health += 7;
            stats.agility += 5;
            stats.attack += 4;
            break;
        case CLERIC:
            stats.health += 8;
            stats.defense += 4;
            stats.intelligence += 4;
            break;
        case TANK:
            stats.health += 12;
            stats.defense += 6;
            break;
    }
}


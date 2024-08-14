// AsciiArt.h
#ifndef ASCIIART_H
#define ASCIIART_H

#include <string>

class AsciiArt {
public:
    /**
     * Start screen ASCII art
    */
    static const std::string dungeonEntranceArt;
    static const std::string knightArt;
    static const std::string mageArt;
    static const std::string thiefArt;
    static const std::string tankArt;
    static const std::string clericArt;

    //welcome screen display
    static const std::string dragonWelcomeArt;
    
    /**
     * Main game ASCII art
    */
    static const std::string enemySlimeArt;
    static const std::string enemySkeletonArt;
    static const std::string enemySpiderArt;
    static const std::string enemyGhostArt;
    static const std::string enemyBansheeArt;
    static const std::string enemyFireGolemArt;
    static const std::string enemyLicheArt;
    static const std::string enemyWyvernArt;

    /**
     * End screen ASCII art
    */
    static const std::string LoseArt1;
    static const std::string WinArt1;
    static const std::string WinArt2;
    static const std::string WinArt3;
};

#endif

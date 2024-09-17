// AsciiArt.h
#ifndef ASCIIART_H
#define ASCIIART_H

#include <string>

/**
 * @file
 * @brief Header file that holds strings ascii art
 * @author Elizabeth Stewart
 * 
 */


class AsciiArt {
public:
    /**
     * Start screen ASCII art
    */

   /**
     * @brief ASCII art for the dungeon entrance screen.
     */
    static const std::string dungeonEntranceArt;

     /**
     * @brief ASCII art for the knight character.
     */
    static const std::string knightArt;

    /**
     * @brief ASCII art for the mage character.
     */
    static const std::string mageArt;

    /**
     * @brief ASCII art for the thief character.
     */
    static const std::string thiefArt;


    /**
     * @brief ASCII art for the tank character.
     */
    static const std::string tankArt;

    /**
     * @brief ASCII art for the cleric character.
     */
    static const std::string clericArt;

    //welcome screen display

    /**
     * @brief ASCII art for the dragon welcome screen.
     */
    static const std::string dragonWelcomeArt; 
    
    /**
     * @brief ASCII art for the story start screen.
     */ 
    static const std::string storyStartArt;
    
    /**
     * Main game ASCII art
    */
   /**
     * @brief ASCII art for the slime enemy.
     */ 
    static const std::string enemySlimeArt;

    /**
     * @brief ASCII art for the skeleton enemy.
     */ 
    static const std::string enemySkeletonArt;

       /**
     * @brief ASCII art for the spider enemy.
     */ 
    static const std::string enemySpiderArt;

       /**
     * @brief ASCII art for the ghost enemy.
     */ 
    static const std::string enemyGhostArt;

       /**
     * @brief ASCII art for the banshee enemy.
     */ 
    static const std::string enemyBansheeArt;

       /**
     * @brief ASCII art for the fire golem enemy.
     */ 
    static const std::string enemyFireGolemArt;

       /**
     * @brief ASCII art for the liche enemy.
     */ 
    static const std::string enemyLicheArt;

       /**
     * @brief ASCII art for the wyvern enemy.
     */ 
    static const std::string enemyWyvernArt;

    /**
     * End screen ASCII art
    */

    /**
     * @brief ASCII art for the lose screen.
     */ 
    static const std::string LoseArt1;

    /**
     * @brief ASCII art for the first win screen.
     */ 
    static const std::string WinArt1;

    /**
     * @brief ASCII art for the second win screen.
     */ 
    static const std::string WinArt2;

    /**
     * @brief ASCII art for the third win screen.
     */ 
    static const std::string WinArt3;

    /**
     * @brief ASCII art for the fourth win screen.
     */ 
    static const std::string WinArt4;

    /**
     * @brief ASCII art for the fifth win screen.
     */ 
    static const std::string WinArt5;

    /**
     * @brief ASCII art for the sixth win screen.
     */ 
    static const std::string WinArt6;

    /**
     * @brief ASCII art for the seventh win screen.
     */ 
    static const std::string WinArt7;

    /**
     * @brief ASCII art for the eigth win screen.
     */ 
    static const std::string WinArt8;

    /**
     * @brief ASCII art for the ninth win screen.
     */ 
    static const std::string WinArt9;



    /**
     * @brief ASCII art for the grizzles normal face
     */ 
   static const std::string grizzleNormalExpression;

       /**
     * @brief ASCII art for the grizzles angry face
     */ 
   static const std::string grizzleAngryExpression;

       /**
     * @brief ASCII art for the grizzles happy face
     */ 
   static const std::string grizzleHappyExpression;

       /**
     * @brief ASCII art for the grizzles scared face
     */ 
   static const std::string grizzleScaredExpression;

};


#endif

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
    static const std::string& getDungeonEntranceArt();

     /**
     * @brief ASCII art for the knight character.
     */
    static const std::string& getKnightArt();

    /**
     * @brief ASCII art for the mage character.
     */
    static const std::string& getMageArt();

    /**
     * @brief ASCII art for the thief character.
     */
    static const std::string& getThiefArt();

    /**
     * @brief ASCII art for the tank character.
     */
    static const std::string& getTankArt();

    /**
     * @brief ASCII art for the cleric character.
     */
    static const std::string& getClericArt();

    //welcome screen display

    /**
     * @brief ASCII art for the dragon welcome screen.
     */
    static const std::string& getDragonWelcomeArt(); 
    
    /**
     * @brief ASCII art for the story start screen.
     */ 
    static const std::string& getStoryStartArt();
    
    /**
     * Main game ASCII art
    */
   /**
     * @brief ASCII art for the slime enemy.
     */ 
    static const std::string& getEnemySlimeArt();

    /**
     * @brief ASCII art for the skeleton enemy.
     */ 
    static const std::string& getEnemySkeletonArt();

       /**
     * @brief ASCII art for the spider enemy.
     */ 
    static const std::string& getEnemySpiderArt();

       /**
     * @brief ASCII art for the ghost enemy.
     */ 
    static const std::string& getEnemyGhostArt();

       /**
     * @brief ASCII art for the banshee enemy.
     */ 
    static const std::string& getEnemyBansheeArt();

       /**
     * @brief ASCII art for the fire golem enemy.
     */ 
    static const std::string& getEnemyFireGolemArt();

       /**
     * @brief ASCII art for the liche enemy.
     */ 
    static const std::string& getEnemyLicheArt();

       /**
     * @brief ASCII art for the wyvern enemy.
     */ 
    static const std::string& getEnemyWyvernArt();

    /**
     * End screen ASCII art
    */

    /**
     * @brief ASCII art for the lose screen.
     */ 
    static const std::string& getLoseArt1();

    /**
     * @brief ASCII art for the first win screen.
     */ 
    static const std::string& getWinArt1();

    /**
     * @brief ASCII art for the second win screen.
     */ 
    static const std::string& getWinArt2();

    /**
     * @brief ASCII art for the third win screen.
     */ 
    static const std::string& getWinArt3();

    /**
     * @brief ASCII art for the fourth win screen.
     */ 
    static const std::string& getWinArt4();

    /**
     * @brief ASCII art for the fifth win screen.
     */ 
    static const std::string& getWinArt5();

    /**
     * @brief ASCII art for the sixth win screen.
     */ 
    static const std::string& getWinArt6();

    /**
     * @brief ASCII art for the seventh win screen.
     */ 
    static const std::string& getWinArt7();

    /**
     * @brief ASCII art for the eigth win screen.
     */ 
    static const std::string& getWinArt8();

    /**
     * @brief ASCII art for the ninth win screen.
     */ 
    static const std::string& getWinArt9();



    /**
     * @brief ASCII art for the grizzles normal face
     */ 
   static const std::string& getGrizzleNormalExpression();

       /**
     * @brief ASCII art for the grizzles angry face
     */ 
   static const std::string& getGrizzleAngryExpression();

       /**
     * @brief ASCII art for the grizzles happy face
     */ 
   static const std::string& getGrizzleHappyExpression();

       /**
     * @brief ASCII art for the grizzles scared face
     */ 
   static const std::string& getGrizzleScaredExpression();

};


#endif

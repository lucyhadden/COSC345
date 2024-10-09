#include "AsciiArt.h"

// Dungeon entrance art
const std::string& AsciiArt::getDungeonEntranceArt() {
    static const std::string dungeonEntranceArt = R"(
   _________________________________________________________
 /|     -_-                                             _-  |\
/ |_-_- _                                         -_- _-   -| \   
  |                            _-  _--                      | 
  |                            ,                            |
  |      .-'````````'.        '(`        .-'```````'-.      |
  |    .` |           `.      `)'      .` |           `.    |          
  |   /   |   ()        \      U      /   |    ()       \   |
  |  |    |    ;         | o   T   o |    |    ;         |  |
  |  |    |     ;        |  .  |  .  |    |    ;         |  |
  |  |    |     ;        |   . | .   |    |    ;         |  |
  |  |    |     ;        |    .|.    |    |    ;         |  |
  |  |    |____;_________|     |     |    |____;_________|  |  
  |  |   /  __ ;   -     |     !     |   /     `'() _ -  |  |
  |  |  / __  ()        -|        -  |  /  __--      -   |  |
  |  | /        __-- _   |   _- _ -  | /        __--_    |  |
  |__|/__________________|___________|/__________________|__|
 /                                             _ -        lc \
/   -_- _ -             _- _---                       -_-  -_ \
)";
  return dungeonEntranceArt;
}

// Knight art
const std::string& AsciiArt::getKnightArt() {
    static const std::string knightArt = R"(
              /
       ,~~   /
   _  <=)  _/_
  /I\.="==.{>
  \I/-\T/-'
      /_\
     // \\_
    _I    /
)";
  return knightArt;
}

// Mage art
const std::string& AsciiArt::getMageArt() {
    static const std::string mageArt = R"(
            ,    _
           /|   | |
         _/_\_  >_<
        .-\-/.   |
       /  | | \_ |
       \ \| |\__(/
       /(`---')  |
      / /     \  |
   _.'  \'-'  /  |
   `----'`=-='   '
)";
  return mageArt;
}

// Thief art
const std::string& AsciiArt::getThiefArt() {
    static const std::string thiefArt = R"(
   .-.
  (o o) 
   | O \
  /  .  \
 /_'---'_\
  |     |
 /       \
)";
  return thiefArt;
}

// Tank art
const std::string& AsciiArt::getTankArt() {
    static const std::string tankArt = R"(
    ___
 __(   )====::
/~~~~~~~~~\
\O.O.O.O.O/
)";
  return tankArt;
}

// Cleric art
const std::string& AsciiArt::getClericArt() {
    static const std::string clericArt = R"(
  /\_/\ 
 / o o \
(   "   )
 \~(*)~/
  \~_~/
   | |
  /   \
 /_____\)";
  return clericArt;
}

/** NOT USED
// Enemy slime art
const std::string& AsciiArt::getEnemySlimeArt() {
    static const std::string enemySlimeArt = R"(
    .------.  
   /        \ 
  / .-"""-.  \
 | |  .-.  | |
  \ \_| |_/ / 
   '.\   /.'  
     '|_|'    
      |_|     
    _/   \_   
   /_______\
)";
  return enemySlimeArt;
}

// Enemy skeleton art
const std::string& AsciiArt::getEnemySkeletonArt() {
    static const std::string enemySkeletonArt = R"(
             _..---..__
           ,'          `-.
          .'` .          )
          |     `;.__.._.'
           \ .`--.(##)(#).
            `-->;--' pWq`>
              < <"v\,,,,]
               `\`^-''''7
                 `~"--^-'
)";
  return enemySkeletonArt;
}

// Enemy spider art
const std::string& AsciiArt::getEnemySpiderArt() {
    static const std::string enemySpiderArt = R"(
          |
      /   |   \
     / /  |  \ \
     \ \_(*)_/ /
      \_(~:~)_/
       /-(:)-\
      / / * \ \
      \ \   / /
       \     /
)";
  return enemySpiderArt;
}

// Enemy ghost art
const std::string& AsciiArt::getEnemyGhostArt() {
    static const std::string enemyGhostArt = R"(
         ___
       _/ @@\
      ( \  O/__
       \    \__)
       /     \
      /      _\
     `"""""``
)";
  return enemyGhostArt;
}

// Enemy banshee art
const std::string& AsciiArt::getEnemyBansheeArt() {
    static const std::string enemyBansheeArt = R"(
   .-""""-.  
  /        \ 
 | .-.  .-. | 
 |/_o | o_\| 
 |  (_)   (_)
 |  \ '---'/
 /    '---' \ 
/`'-       -'\ 
\   '-...-'   /
 '.___ .___.'
     |_|_|
)";
  return enemyBansheeArt;
}

// Enemy fire golem art
const std::string& AsciiArt::getEnemyFireGolemArt() {
    static const std::string enemyFireGolemArt = R"(
   .   _    .  
  /.\ | |  /.\ 
 /@@|_|_|_/@@\ 
 | @@@@|@@@@ | 
 \  @@'|`@@  / 
  \  '@|@'  /  
   '-- | --'   
       |       
   .   |   .   
 /@\  / \  /@\ 
)";
  return enemyFireGolemArt;
}

// Enemy liche art
const std::string& AsciiArt::getEnemyLicheArt() {
    static const std::string enemyLicheArt = R"(
  .-"""-.  
 /       \ 
| .-"""-. |
| |  X  | |
| | /^\ | |
| |(   )| |
|  \'-'/  |
 \_______/ 
  _|_|_|_  
)";
  return enemyLicheArt;
}

// Enemy wyvern art
const std::string& AsciiArt::getEnemyWyvernArt() {
    static const std::string enemyWyvernArt = R"(
    / \__/ \
   /        \
  |  .-""-.  |
 /`-'  oo  '-'\
|           >  |
 \   '--'   / /
  '.___ __.'_/ 
     |_||_|    
)";
  return enemyWyvernArt;
}
**/

// Shopkeeper art
const std::string& AsciiArt::getShopkeeper() {
    static const std::string shopkeeperArt = R"(       
                    .                             
                   .$r                            
                  z$$$b                                   
                z$$$$$$$e                                 
             .d$$$$$$$$$$$b.                              
          zd$$$$$$$$$$$$$$$$$$e.                          
      z*************$*************4                       
      F         .*"   "%c.         L                      
     d     .z*"    .-.    "*e.     4                      
     F .z*"       (o.o)       "*e.  L                     
    dP"            |U|            ^*$                     
    F$            __|__            .PL                    
   d *          //.=|=.\\          4 3                    
  .F 4.        // .=|=. \\  _____  $  L                   
  d   F        \\ .=|=. // /Sive/\ F  3                   
  P   $'========================='4%   L                  
 d    3        Sive's Wares       d    *                  
 P    4r                          $    ^L                 
'%=====%============*=============%=====*      
)";
  return shopkeeperArt;
}

// Shopkeeper art
const std::string& AsciiArt::getShrugShopkeeper() {
    static const std::string shrugShopkeeper = R"(       
                    .                             
                   .$r                            
                  z$$$b                                   
                z$$$$$$$e                                 
             .d$$$$$$$$$$$b.                              
          zd$$$$$$$$$$$$$$$$$$e.                          
      z*************$*************4                       
      F         .*"   "%c.         L                      
     d     .z*"    .-.    "*e.     4                      
     F .z*"       (0.0)       "*e.  L                     
    dP"            |w|            ^*$                     
    F$      __    __|__    __      .PL                    
   d *        \\//.=|=.\\//        4 3                    
  .F 4.        \/ .=|=. \/  _____  $  L                   
  d   F           .=|=.    /Sive/\ F  3                   
  P   $'========================='4%   L                  
 d    3        Sive's Wares       d    *                  
 P    4r                          $    ^L                 
'%=====%============*=============%=====*      
)";
  return shrugShopkeeper;
}

// Shopkeeper art
const std::string& AsciiArt::getRightTalkShopkeeper() {
    static const std::string rightTalkShopkeeper = R"(       
                    .                             
                   .$r                            
                  z$$$b                                   
                z$$$$$$$e                                 
             .d$$$$$$$$$$$b.                              
          zd$$$$$$$$$$$$$$$$$$e.                          
      z*************$*************4                       
      F         .*"   "%c.         L                      
     d     .z*"    .-.    "*e.     4                      
     F .z*"       (>.o)       "*e.  L                     
    dP"            |<|            ^*$                     
    F$            __|__   />       .PL                    
   d *          //.=|=.\\//        4 3                    
  .F 4.        // .=|=. \/  _____  $  L                   
  d   F        \\ .=|=.    /Sive/\ F  3                   
  P   $'========================='4%   L                  
 d    3        Sive's Wares       d    *                  
 P    4r                          $    ^L                 
'%=====%============*=============%=====*      
)";
  return rightTalkShopkeeper;
}

// Shopkeeper art
const std::string& AsciiArt::getLeftTalkShopkeeper() {
    static const std::string leftTalkShopkeeperArt = R"(       
                    .                             
                   .$r                            
                  z$$$b                                   
                z$$$$$$$e                                 
             .d$$$$$$$$$$$b.                              
          zd$$$$$$$$$$$$$$$$$$e.                          
      z*************$*************4                       
      F         .*"   "%c.         L                      
     d     .z*"    .-.    "*e.     4                      
     F .z*"       (o.<)       "*e.  L                     
    dP"            |>|            ^*$                     
    F$       <\   __|__            .PL                    
   d *        \\//.=|=.\\          4 3                    
  .F 4.        \/ .=|=. \\  _____  $  L                   
  d   F           .=|=. // /Sive/\ F  3                   
  P   $'========================='4%   L                  
 d    3        Sive's Wares       d    *                  
 P    4r                          $    ^L                 
'%=====%============*=============%=====*      
)";
  return leftTalkShopkeeperArt;
}



const std::string& AsciiArt::getDragonWelcomeArt() {
    static const std::string dragonWelcomeArt = R"(
                         _                    _
                  ,/                        \,
        _________{(                          })_________
       /.-------./\\                        //\.-------.\
      //@@@@@@@//@@\\  )                (  //@@\\@@@@@@@\\
     //@@@@@@@//@@@@>>/                  \<<@@@@\\@@@@@@@\\
    //O@O@O@O//@O@O//                      \\O@O@\\O@O@O@O\\
  //OOOOOOOO//OOOO||          \  /          ||OOOO\\OOOOOOOO\\
 //O%O%O%O%//O%O%O%\\         ))((         //%O%O%O\\%O%O%O%O\\
||%%%%%%%%//'  `%%%%\\       //  \\       //%%%%'   `\\%%%%%%%||
((%%%%%%%((      %%%%%\\    ((    ))    //%%%%%       ))%%%%%%))
 \:::' `::\\      `:::::\\   \)~~(/    //:::::'      //::' `:::/
  )'     `;)'      (`  ` \\ `<@  @>' / / '  ')      `(;'     `(
          (               \`\ )^^( /  /               )
        _                  ) \\oo/   (
       (@)                  \  `'   /                      _
       |-|\__________________\__^__<________oOo__________ (@)
       |-|                                  VVV           |-|
       |-|   __          __  _                            |-|
       |-|  \ \        / / | |                            |-|
       |-|   \ \  /\  / /__| | ___ ___  _ __ ___   ___    |-|
       |-|    \ \/  \/ / _ \ |/ __/ _ \| '_ ` _ \ / _ \   |-|
       |-|     \  /\  /  __/ | (_| (_) | | | | | |  __/   |-|
       |-|      \/  \/ \___|_|\___\___/|_| |_| |_|\___|   |-|
       |-|                                                |-|
       |_|\_____________________________________________  | |
       (@)                 / ,/ \_____/ \\ ~\/~         `\|-|
        ~             ___//^~      \____/\\               (@)
                     <<<  \     __  <____/||               ~
                               <   \ <___/||
                                  || <___//
                                  \ \/__//
                                   ~----~
)";
  return dragonWelcomeArt;
}

const std::string& AsciiArt::getStoryStartArt() {
    static const std::string storyStartArt = R"(
    _________________________________________________________
    |                                                       |
    |                                                       |
    |   ^  ^  ^   ^      ___I_      ^  ^   ^  ^  ^   ^  ^   |
    |  /|\/|\/|\ /|\    /\-_--\    /|\/|\ /|\/|\/|\ /|\/|\  |
    |  /|\/|\/|\ /|\   /  \_-__\   /|\/|\ /|\/|\/|\ /|\/|\  |
    |  /|\/|\/|\ /|\   |[]| [] |   /|\/|\ /|\/|\/|\ /|\/|\  |   
    |                                                       |
    |_______________________________________________________|
)";
  return storyStartArt;
}


/**
 * ENDSCREEN ART
 */
const std::string& AsciiArt::getLoseArt1() {
    static const std::string loseArt1 =  R"(
                                             ('-. .-.   ('-.          (`-.      ('-.         _ .-') _              ('-.  _ .-') _   
                                            ( OO )  /  ( OO ).-.    _(OO  )_  _(  OO)       ( (  OO) )           _(  OO)( (  OO) )  
  ,--.   ,--..-'),-----.  ,--. ,--.         ,--. ,--.  / . --. /,--(_/   ,. \(,------.       \     .'_   ,-.-') (,------.\     .'_  
   \  `.'  /( OO'  .-.  ' |  | |  |         |  | |  |  | \-.  \ \   \   /(__/ |  .---'       ,`'--..._)  |  |OO) |  .---',`'--..._) 
 .-')     / /   |  | |  | |  | | .-')       |   .|  |.-'-'  |  | \   \ /   /  |  |           |  |  \  '  |  |  \ |  |    |  |  \  ' 
(OO  \   /  \_) |  |\|  | |  |_|( OO )      |       | \| |_.'  |  \   '   /, (|  '--.        |  |   ' |  |  |(_/(|  '--. |  |   ' | 
 |   /  /\_   \ |  | |  | |  | | `-' /      |  .-.  |  |  .-.  |   \     /__) |  .--'        |  |   / : ,|  |_.' |  .--' |  |   / : 
 `-./  /.__)   `'  '-'  '('  '-'(_.-'       |  | |  |  |  | |  |    \   /     |  `---.       |  '--'  /(_|  |    |  `---.|  '--'  / 
   `--'          `-----'   `-----'          `--' `--'  `--' `--'     `-'      `------'       `-------'   `--'    `------'`-------' 
)";
  return loseArt1;
}

const std::string& AsciiArt::getWinArt1() {
    static const std::string winArt1 = R"(
   ____                            _         _       _   _                      _       _                 _                       _  
  / ___|___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_(_) ___  _ __  ___     / \   __| |_   _____ _ __ | |_ _   _ _ __ ___ _ __| | 
 | |   / _ \| '_ \ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \| '_ \/ __|   / _ \ / _` \ \ / / _ \ '_ \| __| | | | '__/ _ \ '__| | 
 | |__| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | \__ \  / ___ \ (_| |\ V /  __/ | | | |_| |_| | | |  __/ |  |_| 
  \____\___/|_| |_|\__, |_|  \__,_|\__|\__,_|_|\__,_|\__|_|\___/|_| |_|___/ /_/   \_\__,_| \_/ \___|_| |_|\__|\__,_|_|  \___|_|  (_) 
                   |___/                                                                                                             
)";
    return winArt1;
}


// Win art 2
const std::string& AsciiArt::getWinArt2() {
    static const std::string winArt2 = R"(
         ,.,",','=.
      ,'.''         '=. 
     ','                `"=.
    |o`"=._                 `"=.     
    | ;`-.o`"=._             . ' "., 
    |o;    `"-.o`"=._     ,'    ,,:-o;   
    | ;     (#) `-.o `"=.`_.--"_o.-; ;
    |o;._    "      `".o|o_.--"    ;o;
     "=._o--._        ; | ;        ; ;
          "=._o--._   ;o|o;     _._;o;
              "=._o._; | ;_.--"o.--"
                    "=.o|o_.--""
)";
    return winArt2;
}

// Win art 3
const std::string& AsciiArt::getWinArt3() {
    static const std::string winArt3 = R"(
           .=""_;=._
       ,-"_,=""     `"=.                  
      "=._o`"-._        `"=.
         `"=._o`"=._      _`"=._             
              :=._o "=._."_.-="'"=._
      __.--" , ; `"=._o." ,-"""-._ ".   
    ._"  ,. .` ` `` ,  `"-._"-._   ". .
    |o`"=._` , "` `; .". ,  "-._"-._; ;              
    | ;`-.o`"=._; ." ` '`."\` . "-._ /
    |o;    `"-.o`"=._``  '` " ,__.--o;   
    | ;     (#) `-.o `"=.`_.--"_o.-; ;
    |o;._    "      `".o|o_.--"    ;o;
     "=._o--._        ; | ;        ; ;
          "=._o--._   ;o|o;     _._;o;
              "=._o._; | ;_.--"o.--"
                    "=.o|o_.--""
)";
    return winArt3;
}

// Win art 3
const std::string& AsciiArt::getGuildMaster() {
    static const std::string guildMaster = R"(

           .=(((=.       
          i;'   `:i      
          !__   __!      
         (~(_)-(_)~)     
          !   n   !      
           \  -  /       
           !`---'!       
          /`-._.-'\      
     _.-~'\_/ |o\_/`~-._       _+_     
    '         |o        `     /   \
===========================================


===========================================
)";
    return guildMaster;
}

// Grizzle normal expression
const std::string& AsciiArt::getGrizzleNormalExpression() {
    static const std::string grizzleNormalExpression = R"(
              -----------
           /               \
    ____ -     -       -     - ____
  /          ( o )   ( o )          \
  \ ____                       ____ /
        |          ^          |
         \      -v---v-      /
           \                /
              -----------   
)";
    return grizzleNormalExpression;
}

// Grizzle angry expression
const std::string& AsciiArt::getGrizzleAngryExpression() {
    static const std::string grizzleAngryExpression = R"(
              -----------
           /               \
    ____ -      \     /       - ____
  /          ( o )   ( o )          \
  \ ____                       ____ /
        |          ^          |
         \      -v---v-      /
          \                 /
              -----------  
)";
    return grizzleAngryExpression;
}

// Grizzle happy expression
const std::string& AsciiArt::getGrizzleHappyExpression() {
    static const std::string grizzleHappyExpression = R"(
              -----------
           /               \
    ____ -     -       -     - ____
  /          ( o )   ( o )          \
  \ ____      \\\      \\\     ____ /
        |          ^          |
         \      'v---v'      /
          \                 /
              -----------   
)";
    return grizzleHappyExpression;
}

// Grizzle scared expression
const std::string& AsciiArt::getGrizzleScaredExpression() {
    static const std::string grizzleScaredExpression = R"(
              -----------
           /               \
    ____ -     -       -     - ____
  /          ( o )   ( o )          \
  \ ____           ^           ____ /
        |      _________      |
         \    | -v---v- |    /
          \    ---------    /
              -----------   
)";
    return grizzleScaredExpression;
}


// Additional Win arts (4-9) follow the same pattern.
const std::string& AsciiArt::getWinArt4() {
    static const std::string winArt4 = R"(
  _ ___ _
 '-|   |-'
   |___|
  / / \ \
 ' |___| '
   || ||   
)";
    return winArt4;
}

const std::string& AsciiArt::getWinArt5() {
    static const std::string winArt5 = R"(
  _ ___ _
 '-|   |-'
   |___|
  \ / \ /
   |___| 
   // \\   
)";
    return winArt5;
}

const std::string& AsciiArt::getWinArt6() {
    static const std::string winArt6 = R"(
    _ ___ 
   '__  o|
     |___|
      /|\
     |_|_|
      |_|_
)";
    return winArt6;
}

const std::string& AsciiArt::getWinArt7() {
    static const std::string winArt7 = R"(
    _ ___ 
   '__  o|
     |___|
   ,- / \ \,
     |___|
     '/ \,
)";
    return winArt7;
}

const std::string& AsciiArt::getWinArt8() {
    static const std::string winArt8 = R"(
    _ ___ 
   '__  o|
     |___|
   ,- / \ \,
     |___|
     '/ \,
)";
    return winArt8;
}

const std::string& AsciiArt::getWinArt9() {
    static const std::string winArt9 = R"(
    ___
   |  o| 
   |___|
   /   \
   | | |
   |_| |
   |  |
   |__|
)";
    return winArt9;
}



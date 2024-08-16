// AsciiArt.cpp
#include "AsciiArt.h"

const std::string AsciiArt::dungeonEntranceArt = R"(
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

const std::string AsciiArt::knightArt = R"(
              /
       ,~~   /
   _  <=)  _/_
  /I\.="==.{>
  \I/-\T/-'
      /_\
     // \\_
    _I    /
)";

const std::string AsciiArt::mageArt = R"(
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

const std::string AsciiArt::thiefArt = R"(
   .-.
  (o o) 
   | O \
  /  .  \
 /_'---'_\
  |     |
 /       \
)";

const std::string AsciiArt::tankArt = R"(
    ___
 __(   )====::
/~~~~~~~~~\
\O.O.O.O.O/
)";

const std::string AsciiArt::clericArt = R"(
  /\_/\ 
 / o o \
(   "   )
 \~(*)~/
  \~_~/
   | |
  /   \
 /_____\)";

const std::string AsciiArt::enemySlimeArt = R"(
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

const std::string AsciiArt::enemySkeletonArt = R"(
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

const std::string AsciiArt::enemySpiderArt = R"(
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

const std::string AsciiArt::enemyGhostArt = R"(
         ___
       _/ @@\
      ( \  O/__
       \    \__)
       /     \
      /      _\
     `"""""``
)";

const std::string AsciiArt::enemyBansheeArt = R"(
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

const std::string AsciiArt::enemyFireGolemArt = R"(
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

const std::string AsciiArt::enemyLicheArt = R"(
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

const std::string AsciiArt::enemyWyvernArt = R"(
    / \__/ \
   /        \
  |  .-""-.  |
 /`-'  oo  '-'\
|           >  |
 \   '--'   / /
  '.___ __.'_/ 
     |_||_|    
)";

const std::string AsciiArt::dragonWelcomeArt = R"(
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
    _________________________________________________________
    |                                                       |
    |  In a dense forest, a lone adventurer wanders...      |
    |                                                       |
    |   ^  ^  ^   ^      ___I_      ^  ^   ^  ^  ^   ^  ^   |
    |  /|\/|\/|\ /|\    /\-_--\    /|\/|\ /|\/|\/|\ /|\/|\  |
    |  /|\/|\/|\ /|\   /  \_-__\   /|\/|\ /|\/|\/|\ /|\/|\  |
    |  /|\/|\/|\ /|\   |[]| [] |   /|\/|\ /|\/|\/|\ /|\/|\  |   
    |                                                       |
    |   The adventurer finds a hidden path leading to       |
    |   a dark dungeon. The quest is about to begin!        |
    |                                                       |
    |_______________________________________________________|
)";



/**
 * ENDSCREEN ART
 */
const std::string AsciiArt::LoseArt1 = R"(
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
const std::string AsciiArt::WinArt1 = R"(
   ____                            _         _       _   _                      _       _                 _                       _  
  / ___|___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_(_) ___  _ __  ___     / \   __| |_   _____ _ __ | |_ _   _ _ __ ___ _ __| | 
 | |   / _ \| '_ \ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \| '_ \/ __|   / _ \ / _` \ \ / / _ \ '_ \| __| | | | '__/ _ \ '__| | 
 | |__| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | \__ \  / ___ \ (_| |\ V /  __/ | | | |_| |_| | | |  __/ |  |_| 
  \____\___/|_| |_|\__, |_|  \__,_|\__|\__,_|_|\__,_|\__|_|\___/|_| |_|___/ /_/   \_\__,_| \_/ \___|_| |_|\__|\__,_|_|  \___|_|  (_) 
                   |___/                                                                                                             
)";

const std::string AsciiArt::WinArt2 = R"(
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

const std::string AsciiArt::WinArt3 = R"(
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


/**
 * Grizzle Art
 */

const std::string AsciiArt::grizzleNormalExpression = R"(
	            ———————————
		       /  	           \
	  ____ -     –      –      - ____
  / 	       ( o )  ( o )          \
  \ ____  	                   ____ /
	      |		       ^          |
	       \	    -v———v-      /
	        \	                /
		          ———————————    
)";

const std::string AsciiArt::grizzleAngryExpression = R"(
	            ———————————
		       /  	           \
	  ____ -      \    /       - ____
  / 	       ( o )  ( o )           \
  \ ____  	                   ____ /
	      |		       ^          |
	       \	    -v———v-      /
	        \	                /
		          ———————————  
)";

const std::string AsciiArt::grizzleHappyExpression = R"(
	            ———————————
		       /  	           \
	  ____ -     -      –      - ____
  / 	       ( o )  ( o )           \
  \ ____  	\\\        \\\     ____ /
	      |		       ^          |
	       \	    'v———v'      /
	        \	                /
		          ———————————  
)";

const std::string AsciiArt::grizzleScaredExpression = R"(
	            ———————————
		       /  	           \
	  ____ -     –       –     - ____
  / 	       ( o )   ( o )          \
  \ ____  	       ^           ____ /
	      |		   _________      |
	       \	  | -v———v- |    /
	        \	   —————————    /
		          ———————————   
)";
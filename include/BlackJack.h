#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <string>

/**
 * @file
 * @brief Header file for game4(), BlackJack
 * @author Sen Macmaster
 */
extern std::string title;
extern int card_values[];
extern std::string card_strings[];
extern std::string player_hand;
extern std::string played_hand;
extern int players_value;
extern int dealers_value;
extern int aces_in_play;
extern bool playing;
extern int player_account;
extern int house_account;
extern int bet;

/**
* @brief Main method for the BlackJack minigame
*/
void ResetGame();
int DrawFromDeck();
bool PlayerHasAce();
bool DealerHasAce();
void PlayersInput();
bool ContinueGame();
void PlayersTurn();
bool DealersPlayLogic();
void DealersTurn();
void DisplayResults();
void Instructions();
void BlackJack();

#endif
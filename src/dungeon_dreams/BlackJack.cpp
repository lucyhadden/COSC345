#include <iostream>
#include <string>
#include <thread>
#include <cstdlib>  
#include <ctime>

#include "BlackJack.h"
#include "miniGames.h"
#include "utils.h"

std::string title = "--- BlackJack ---\n";

int card_values[] = {11,2,3,4,5,6,7,8,9,10,10,10,10};
std::string card_strings[] = {"[A]","[2]","[3]","[4]","[5]","[6]","[7]","[8]","[9]","[10]","[J]","[Q]","[K]"};
std::string player_hand;
std::string played_hand;

int players_value = 0;
int dealers_value = 0;
int aces_in_play = 0;
bool playing = true;

int player_account = 4;
int house_account = 8;
int bet;

void ResetGame()
{
    playing = true;
    played_hand = "";
    player_hand = "";
    players_value = 0;
    dealers_value = 0;
    aces_in_play = 0;
}

int DrawFromDeck() 
{
    int random = rand() % 13;
    played_hand += card_strings[random];
    if(random == 0) aces_in_play++;
    return card_values[random];
}

bool PlayerHasAce()
{
    if(aces_in_play > 0)
    {
        players_value -= 10;
        aces_in_play--;
        PlayerHasAce();
    }
    return players_value < 21;
}

bool DealerHasAce()
{
    if(aces_in_play > 0)
    {
        dealers_value -= 10;
        aces_in_play--;
        DealerHasAce();
    }
    return dealers_value < 21;
}

void PlayersInput()
{
    std::string input;
    std::cout << "Hit or Stand (H/S)?" << std::endl;
    std::cin >> input;
    if(input == "Hit" || input == "H")
    {
        playing = true; 
    }else if(input == "Stand" || input == "S")
    {
        playing = false; 
        aces_in_play = 0;
        std::cout << "Dealer's Turn" << std::endl;
    }else
    {
        std::cout << "Incorrect Input" << std::endl;
        PlayersInput();
    }
}

bool ContinueGame()
{
    if(player_account == 0)
    {
        std::cout << "Oh you have no more money?" << std::endl;
        std::cout << "Pleasure doing business with you." << std::endl;
        std::cout << "Now get out of my sight..." << std::endl;
        return false;
    }else if(house_account == 0)
    {
        std::cout << "Yea yea, you got lucky" << std::endl;
        std::cout << "Take your money and..." << std::endl;
        std::cout << "Get out of my sight..."<< std::endl;
        return false;
    }

    std::string input;
    std::cout << "Continue or Leave (C/L)?" << std::endl;
    std::cin >> input;
    if(input == "Continue" || input == "C")
    {
        std::cout << "Okay, let's play then. How much?" << std::endl;
        std::cin >> bet;
        while (std::cin.fail() || bet <= 0 || bet > player_account) 
        {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cout << "Invalid amount. Please enter a positive number less than or equal to your account balance: " << std::endl;
            std::cin >> bet;
        }
        player_account -= bet; 
        return true;
    }else if(input == "Leave" || input == "L")
    {
        std::cout << "Get out of my sight..." << std::endl;
        return false;
    }else
    {
        ContinueGame();
    }
    return false;
}

void PlayersTurn()
{
    players_value += DrawFromDeck(); 
    while(playing)
    {
        std::cout << "\033c" << title << std::endl;
        players_value += DrawFromDeck(); 
        std::cout << "Hand: " << players_value << " - " <<  played_hand <<std::endl;
        if(players_value < 21 && PlayerHasAce())
        {
            PlayersInput();
        }else if(players_value > 21 && !PlayerHasAce())
        {
            std::cout << "BUST!" << std::endl;
            playing = !playing;
        }else
        {
            std::cout << "BlackJack!" << std::endl;
            playing = !playing;
        }
        std::cout << "\033c" << title << std::endl;
    }
    player_hand = played_hand;
    played_hand = "";
}

bool DealersPlayLogic()
{
    if((players_value <= 21) && (players_value > dealers_value) && (dealers_value < 21) && DealerHasAce())
    {
        return true;
    }else if((dealers_value > 21) && !DealerHasAce())
    {
        return false;
    }
    return false;
}

void DealersTurn()
{
    dealers_value += DrawFromDeck(); 
    dealers_value += DrawFromDeck(); 

    while(DealersPlayLogic())
    {
        dealers_value += DrawFromDeck(); 
        std::cout << "Card drawn: " << dealers_value << std::endl;
    }
    std::cout << "\033c" << title << std::endl;
    aces_in_play = 0;
}

void DisplayResults()
{
    std::cout << "\033c" << title << std::endl;

    if(players_value > 21 || (players_value <= dealers_value && dealers_value <= 21))
    {
        house_account += bet;
        std::cout << "Lost: $" << bet << std::endl;
    }else
    {
        house_account -= bet;
        player_account += (bet * 2);
        std::cout << "Won: $" << bet << std::endl;
    }

    std::cout << "Player Account: " << player_account << std::endl;
    std::cout << "House: " << house_account << std::endl << std::endl;

    std::cout << "Player: " << players_value << " - " <<  player_hand << std::endl;
    std::cout << "Dealer: " << dealers_value << " - " <<  played_hand << std::endl;

    ResetGame();
}

void Instructions()
{   
    std::cout << "Welcome to BlackJack" << std::endl;
    CustomSleep(1);
    std::cout << "Try to get a hand total as close to 21 as possible without going over." << std::endl;
    CustomSleep(1);
    std::cout << "Each card has a value: cards 2-10 are worth their face value, face cards are worth 10, and Aces can be worth 1 or 11." << std::endl;
    CustomSleep(1);
    std::cout << "You can 'Hit' to draw another card or 'Stand' to keep your current total. The highest hand without busting wins." << std::endl;
    CustomSleep(1);
    std::cout << "Eh...you'll get the hang of it. Here's some coins, on the house. Now..." << std::endl << std::endl;
    CustomSleep(1);
    std::cout << "Press enter to continue...";
    std::cin.ignore();  
    std::cin.get(); 
}

void BlackJack() 
{
    srand(time(0));

    std::cout << "\033c" << title << std::endl;
    std::cout << "Player Account: " << player_account << std::endl;
    std::cout << "House: " << house_account << std::endl << std::endl;

    Instructions();

    while(ContinueGame())
    {
        PlayersTurn();   
        DealersTurn();
        DisplayResults();
    }
    std::cout << "You made " << player_account <<  " gold." << std::endl;
}
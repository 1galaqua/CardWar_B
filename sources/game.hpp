#pragma once
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "player.hpp"
#include <vector>
namespace ariel{
    
class Game {

   private:
    Player &player1;
    Player &player2;
    vector<string> log;
    string winner="draw";
    vector<Card> deck;
public:

    
    Game(Player& player01, Player& player02);
   
    vector<Card> mydeck(){return this->deck;}

    void shuffleDeck(vector<Card>& deck);

    void deal_cards();
    
    void playTurn();

    void printLastTurn();
    
    void playAll();
    
    void printWiner(){cout<<"the winner is: "+this->winner<<endl;}

    void playTurnafterdraw(int draw_num); 

    void printLog();
    
    void printStats();



    
        

};
}

#endif

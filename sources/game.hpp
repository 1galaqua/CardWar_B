#pragma once
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "player.hpp"

namespace ariel{
    
class Game {

   private:
    Player player1;
    Player player2;

public:

    Game(Player& player01, Player& player02);

    void playTurn();

    void printLastTurn();
    
    void playAll();
    
    void printWiner();

    void printLog();
    
    void printStats();



    
        

};
}

#endif

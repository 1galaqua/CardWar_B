#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "card.hpp"
#include <vector>
using namespace std;

namespace ariel{
    
class Player {
    string myname;
    int num_won;

    vector<Card> mycards;
    
        public:
            Player();
            Player (string name);


            int stacksize();

            int cardesTaken();

            void won(Player& palyer);       

        };

}


#endif
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "card.hpp"
#include <vector>
using namespace std;

namespace ariel{
    
class Player {
    string myname;
    int num_won=0;
    int num_draw=0;
    vector<Card> mycards;
    vector<string> cardswon;
    vector<string> cardsdraw;
    
        public:
            Player();
            Player (string name);


            string name(){return this->myname;} 

            int stacksize();

            int cardesTaken();

            void won(int draw=0){this->num_won=this->num_won+2+draw*2;} 
            void lastdraw(){this->num_won=this->num_won-2;}
            int won_amount()const{return this->num_won;}

            void draw(int num=0){this->num_draw=this->num_won+num;}
            
            int draw_amount()const{return this->num_draw;}

            Card throw_card();

            void push_card(Card& card){this->mycards.push_back(card);}

            void stat_won(string const &turn){this->cardswon.push_back(turn);}

            void stat_draw(string const &turn){this->cardsdraw.push_back(turn);}

            vector<string> getstate_draw(){return this->cardsdraw;}

            vector<string> getstate_win(){return this->cardswon;}
            
        }; 

}


#endif
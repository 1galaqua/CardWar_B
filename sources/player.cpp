#include "player.hpp"
#include "card.hpp"
#include "string"
using namespace std;
using namespace ariel;
// #include <algorithm>
// #include <random>
// auto rng = std::default_random_engine {};
//     shuffle(std::begin(this->mycards), std::end(this->mycards), rng);
Player::Player(){};
 Player::Player (string name){
    this->myname=name;
    
    
 }

    



   int Player::stacksize(){
       return this->mycards.size();
   }

   int Player::cardesTaken(){
       
       return this->num_won;
   }

   
    Card Player::throw_card(){
        
        if(!this->mycards.empty()){
            
            Card temp=this->mycards.back();
            
            this->mycards.pop_back();
            return temp;
        }else {
            
            throw std::invalid_argument("empty stack");}

        return Card();
    }

    

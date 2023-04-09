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
    cout<< name <<endl;
    
 }



   int Player::stacksize(){
       return this->mycards.size();
   }

   int Player::cardesTaken(){
       
       return this->num_won;
   }

   void Player::won(Player& player){
      player.num_won = player.cardesTaken()+1;
   }

#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
#include <algorithm>
#include <random>
#include <chrono>
using namespace ariel;

Game::Game(Player& player01, Player& player02): player1(player01), player2(player02)
{
      string ranks[13] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13"};
      string suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
      for (int i = 0; i < 13; i++) {
          for (int j = 0; j < 4; j++) {
              Card newCard(ranks[i], suits[j]);
              this->deck.push_back(newCard);
          }
      }
      this->shuffleDeck(this->deck);
  
  
      for (size_t i = 0; i < this->deck.size(); i++){
         
         if( i%2 == 0 ){
            
            this->player1.push_card(this->deck[i]);

         }else{
            this->player2.push_card(this->deck[i]);
         }

         
      
   
  }
      

   };
   
void Game::shuffleDeck(vector<Card>& deck) {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(deck.begin(), deck.end(), default_random_engine(seed));
}
   
   
void Game::playTurn(){
   
   if(this->player1.stacksize()!=0 && this->player2.stacksize()!=0 && &(this->player1) != &(this->player2)){
      Card pl1_card=this->player1.throw_card();
      Card pl2_card=this->player2.throw_card();
   
      if(pl1_card.getvalue()==2 && pl2_card.getvalue()!=2){
         this->player1.won();
         this->log.push_back(this->player1.name() + " played Ace of " + pl1_card.card_name() + ", " + this->player2.name() + " played " + pl2_card.print_card()+". "+ this->player1.name()+" win.");
         this->player1.stat_won("Ace of " + pl1_card.card_name());

      }else if(pl1_card.getvalue()!=2 && pl2_card.getvalue()==2){
         this->player2.won();
         this->log.push_back(this->player2.name() + " played Ace of " + pl2_card.card_name()+", " + this->player1.name() + " played " + pl1_card.print_card()+". " + this->player2.name()+ " win." );
         this->player2.stat_won("Ace of " + pl2_card.card_name());

      }else if(pl1_card.getvalue()> pl2_card.getvalue()){
         this->player1.won();
         this->log.push_back(this->player1.name() + " played " + pl1_card.print_card() + ", " + this->player2.name() + " played " + pl2_card.print_card() +". "+ this->player1.name() + " win." );
         this->player1.stat_won(pl1_card.print_card());

      }else if(pl1_card.getvalue() < pl2_card.getvalue()){
         this->player2.won();
         this->log.push_back(this->player2.name() + " played " + pl2_card.print_card() + ", " + this->player1.name() + " played " + pl1_card.print_card() +". "+ this->player2.name() + " win." );
         this->player2.stat_won(pl2_card.print_card());

      }else if (pl1_card.getvalue() == pl2_card.getvalue()){
         
         this->log.push_back(this->player1.name() + " played " + pl1_card.print_card() + ", "+ this->player2.name() + " played " + pl2_card.print_card()+ ". draw." );
         this->player1.stat_draw( pl1_card.print_card());
         this->player2.stat_draw( pl2_card.print_card());
         Game::playTurnafterdraw(1);

      }
      if(this->player1.won_amount()>this->player2.won_amount()){
         this->winner=this->player1.name();
      }else if(this->player1.won_amount()<this->player2.won_amount()){
         this->winner=this->player2.name();
      }else{
         this->winner="draw";
      }
   }else if(this->player1.stacksize()==0 && this->player2.stacksize()==0){
      throw std:: __throw_out_of_range;
   }
   
   else {throw std::__throw_logic_error;}
  
};

void Game::playTurnafterdraw(int draw_num=0){
   if(this->player1.stacksize()!=0 && this->player2.stacksize()!=0){
      Card pl1_card=this->player1.throw_card();
      Card pl2_card=this->player2.throw_card();

      if(pl1_card.getvalue()==2 && pl2_card.getvalue()!=2){
         this->player1.won(draw_num);
         this->log.push_back(this->player1.name() + " played Ace of " + pl1_card.card_name() + ", " + this->player2.name() + " played " + pl2_card.print_card()+". "+ this->player1.name()+" win.");
         this->player1.stat_won("Ace of " + pl1_card.card_name());

      }else if(pl1_card.getvalue()!=2 && pl2_card.getvalue()==2){
         this->player2.won(draw_num);
         this->log.push_back(this->player2.name() + " played Ace of " + pl2_card.card_name()+", " + this->player1.name() + " played " + pl1_card.print_card()+". " + this->player2.name()+ " win." );
         this->player2.stat_won("Ace of " + pl2_card.card_name());

      }else if(pl1_card.getvalue()> pl2_card.getvalue()){
         this->player1.won(draw_num);
         this->log.push_back(this->player1.name() + " played " + pl1_card.print_card() + ", " + this->player2.name() + " played " + pl2_card.print_card() +". "+ this->player1.name() + " win." );
         this->player1.stat_won(pl1_card.print_card());

      }else if(pl1_card.getvalue() < pl2_card.getvalue()){
         this->player2.won(draw_num);
         this->log.push_back(this->player2.name() + " played " + pl2_card.print_card() + ", " + this->player1.name() + " played " + pl1_card.print_card() +". "+ this->player2.name() + " win." );
         this->player2.stat_won(pl2_card.print_card());

      }else if (pl1_card.getvalue() == pl2_card.getvalue()){
         
         this->log.push_back(this->player1.name() + " played " + pl1_card.print_card() + ", "+ this->player2.name() + " played " + pl2_card.print_card()+ ". draw." );
         this->player1.stat_draw( pl1_card.print_card());
         this->player2.stat_draw( pl2_card.print_card());
         Game::playTurnafterdraw(draw_num+1);

      }
      
   }else if(this->player1.stacksize()==0 && this->player2.stacksize()==0){
      this->player1.won(((draw_num)/2));
      this->player1.lastdraw();
      this->player2.won(((draw_num)/2));
      this->player2.lastdraw();
        
   }
   
   
   else {
      
      throw std::__throw_logic_error;}

   if(this->player1.won_amount()>this->player2.won_amount()){
         this->winner=this->player1.name();
      }else if(this->player1.won_amount()<this->player2.won_amount()){
         this->winner=this->player2.name();
      }else{
         this->winner="draw";
      }

}
void Game::printLastTurn(){
   if(!this->log.empty()){
      cout<< log.back()<< endl;
   }else {
      cout << "game dont start yet..."<< endl;}

};

void Game::playAll(){
   while(this->player1.stacksize()!=0 && this->player2.stacksize()!=0){
      Game::playTurn();
   }
   
};

void Game::printLog(){
   for(string i:this->log){ 
      cout<< i <<endl;
   }
   
};

void Game::printStats(){
      cout<< "Statistic of "<<this->player1.name()+ ": "<<endl;
      cout<< "amount of draw: "<<this->player1.getstate_draw().size()<<endl;
      cout<< "amount of win:" << this->player1.getstate_win().size()<<endl;
      int draw_precent=(this->player1.getstate_draw().size()/(this->player1.getstate_draw().size()+this->player1.getstate_win().size()+this->player2.getstate_win().size())) * 100;
      cout<< "precent of draw :" << draw_precent<<endl;
      double win_precent=(this->player1.getstate_win().size()/(this->player1.getstate_draw().size()+this->player1.getstate_win().size()+this->player2.getstate_win().size())) * 100;
      cout<< "precent of win :" << win_precent<<endl;

      cout<< "Statistic of "<<this->player2.name()+ ": "<<endl;
      cout<< "amount of draw: "<<this->player2.getstate_draw().size()<<endl;
      cout<< "amount of win:" << this->player2.getstate_win().size()<<endl;
      double draw_precent2=(this->player2.getstate_draw().size()/(this->player2.getstate_draw().size()+this->player2.getstate_win().size()+ this->player1.getstate_win().size())) * 100;
      cout<< "precent of draw :" << draw_precent2<<endl;
      double win_precent2=(this->player2.getstate_win().size()/(this->player2.getstate_draw().size()+this->player2.getstate_win().size()+ this->player1.getstate_win().size())) * 100;
      cout<< "precent of win :" << win_precent2<<endl;
   
};
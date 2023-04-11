#include "card.hpp"
using namespace ariel;
using namespace std;




Card::Card(string num, string name_shape){

    this->name_shape=name_shape;
    int value;
    if(num != "Ace"){
    this->number=stoi(num);
    
    }
}

string Card::print_card(){
    if(this->getvalue()<11){
        return (to_string(this->getvalue()) + " of "+ this->card_name()); 
    }else if(this->getvalue()==11){
        return "jack of "+this->card_name();
    }else if(this->getvalue()==12){
        return "queen of "+this->card_name();
    }else if(this->getvalue()==13){
        return "king of "+this->card_name();
    }

    return "problem in print card function!";
}


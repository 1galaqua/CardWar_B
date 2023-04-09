#include "card.hpp"
using namespace ariel;





Card::Card(int num, string name_shape){

    this->name_shape=name_shape;
    this->number=num;
}


string Card::card_name(Card& card){
 return card.name_shape;
}

int Card::value(Card& card){
    return card.number;
}
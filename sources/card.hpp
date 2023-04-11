#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;

namespace ariel {
class Card {

    string name_shape;
    int number;

public:

    Card();

    Card(string num , string name_shape);

    int getvalue ()const{return this->number;}

    string card_name(){return this->name_shape;}

    string print_card();

    };
}

#endif
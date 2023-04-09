#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;
namespace ariel {
class Card {

    string name_shape;
    int number;

public:


    Card(int num , string name_shape);

    int value (Card& card);

    string card_name(Card& card);


};
}

#endif
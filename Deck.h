#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <stack>


using namespace std;

class Deck
{

public:
Deck();
void drawCard();
void shuffle();

private:


string colors[2] = {"Black", "Red"};
string suits[4] = {"Clubs", "Spades", "Diamonds", "Hearts"};
string faces[4] = {"King", "Queen", "Jack", "Ace"};


struct Card{

string color;
string suit;
string face;
int val;

} card;

stack<Card> Cards;

};

#endif

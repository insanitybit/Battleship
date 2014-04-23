#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string>

#include <stack>
#include "Deck.h"


using namespace std;


Deck::Deck(){

int z; //full size of deck
int i; //card numbers
int j; //card suits
int n; //card colors
int p; //card face


i = 0;
n = 0;
j = 0;
for(z = 0; z < 208; z++){
Cards.push(card);

if(i > 12){i = 0;}

Cards.top().val = i + 2;

if(i == 9){Cards.top().face = "King";}
if(i == 10){Cards.top().face = "Queen";}
if(i == 11){Cards.top().face = "Jack";}
if(i == 12){Cards.top().face = "Ace";}

if(n > 3){n = 0;}

if(n == 0){Cards.top().suit = "Clubs";}
if(n == 1){Cards.top().suit = "Spades";}
if(n == 2){Cards.top().suit = "Diamonds";}
if(n == 3){Cards.top().suit = "Hearts";}


if(j > 1){j = 0;}

if(j == 0){Cards.top().color = "Black";}
if(j == 1){Cards.top().color = "Red";}


j++;
n++;
i++;

}

//Deck filled

for(i = 0; i < 20; i++)
shuffle();


for(i = 2; i < 210; i++){

if(Cards.top().val < 9)
cout << Cards.top().color << " " << Cards.top().val << " of " << Cards.top().suit << endl;

else
cout << Cards.top().color << " " << Cards.top().face << " of " << Cards.top().suit << endl;

Cards.pop();
}
}

void Deck::shuffle(){

int i;

for(i = 0; i < 208; i++){
shuffle_card[i] = Cards.top();

if(!Cards.empty())
Cards.pop();

}

int location1, location2;

Card temp;

  srand(time(NULL));
  for(i = 0; i < 208; i++)
	{
        
        
        location1 = rand() % 208;
        location2 = (1 + rand()) % 208; 
        //Swap
        temp = shuffle_card[location1];
        shuffle_card[location1] = shuffle_card[location2];
        shuffle_card[location2] = temp;  
  }


for(i = 0; i < 208; i++){

Cards.push(shuffle_card[i]);

}

}












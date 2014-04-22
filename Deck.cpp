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


for(z = 0; z < 52; z++){

Cards.push(card);

    
    for(i = 0; i < 8; i++){
    
    Cards.top().val = i;
    
        
        for(j = 0; j < 4; j++){
        
        if(j == 0)        
        Cards.top().suit = "Clubs";
        
        if(j == 1)        
        Cards.top().suit = "Spades";
        
        if(j == 2)        
        Cards.top().suit = "Diamonds";
        
        if(j == 3)        
        Cards.top().suit = "Hearts";
        
        
        
            for(n = 0; n < 2; n++){
            
            if(n == 0)
            Cards.top().color = "Black";
            
            if(n == 1)
            Cards.top().color = "Red";
            
            }
        
        
        }
    
    
        
    }



}



for(i = 0; i < 52; i++){
    cout << Cards.top().val << endl;
    cout << Cards.top().suit << endl;
    cout << Cards.top().color << endl;
    cout << Cards.top().face << endl;
    Cards.pop();

}
 
}




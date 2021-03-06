//Some of these libraries are not necessary yet but will be for future features.

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <vector>
#include <thread>         
#include <chrono>         


#include "Players.h"
#include "Deck.h"

using namespace std;
using namespace this_thread;
using namespace chrono;



int fillPlayerCount();
bool checkLoser(int x, vector <Players>& Playerx);
void roll();
void roll(string hold_string);

//Battleship only ever has 17 pieces. This value may change in the future though, I'm interested in creating a smaller and larger board 'mode'
const int piece_count = 17;

int main(){
int i = 0;
int j = 0;

int x;
int y;
int z;
int player_count = 0;
string player_name;
char decision;
bool did_hit;
bool did_sink;

//Deck deck;


player_count = fillPlayerCount();

while(player_count < 2){
    cout << "You must have at least 2 players." << endl;
    player_count = fillPlayerCount();
}


vector <Players> Player (player_count);

for(i = 0; i < player_count; i++){
    cout << "What is player " << i+1 << "'s name?" << endl;
    cin >> player_name;
    Player[i].setName(player_name);
    cout << "Setting player " << i+1 << "'s name to " << player_name << endl;
    
}

//Let players put down their pieces

for(i = 0; i < player_count; i++){
    
    cout << Player[i].getName() << "'s turn to place their pieces..." << endl;
    
    Player[i].setPieces();
    for(z = 0; z < 1500; z++){
                    
    cout << ".\n..\n...\n...." << endl; //replace with 'clear' later? - probably not. This + sleep works well.
                    
    }
}

//Begin turn 
while (Player.size() != 1){
for(i = 0; i < player_count; i++){
cout << "New turn " << endl;

    for(j = 0; j < player_count; j++){
    
            if(i == j){
            continue;
            }
            cout << Player[i].getName() << "'s turn against " << Player[j].getName() << endl;
            cout << Player[i].getName() << ": What would you like to do?" << endl;
            cout << "Enter 'a' to attack. Enter 'd' to display " << Player[j].getName() << "'s board.";
            cout << " Enter 'm' to display your own board." << endl;
        
            cin >> decision;
            if(decision == 'a' || decision == 'd' || decision == 'm'){
            
                if(decision == 'a'){
                    cout << "If you're reading this you're a cheater! :( " << endl;
                    for(z = 0; z < 1500; z++){
                    
                    cout << ".\n..\n...\n...." << endl; //replace with 'clear' later? - probably not. This + sleep works well.
                    
                    }
                    


                    
                    cout << "Displaying " << Player[j].getName() << "'s board." << endl;
                    Player[j].displayLess();
                    cout << Player[i].getName() << ": Enter in coordinates to attack." << endl;
                    
                    cout << "Enter X coordinate: " << endl;
                    cin >> x;
                    cout << "Enter Y coordinate: " << endl;
                    cin >> y;


                    did_hit = Player[j].actionAttacked(x,y);
                    Player[j].displayLess();
                    
                    if (did_hit == true){
                        roll();
                        did_sink = Player[j].getSunk(x,y);
                        if(did_sink){
                        
                        roll(Player[j].getName());
                        
                        }
                        j--; //POSSIBLE SEGFAULT - CAREFUL
                        continue;
                    }
                    
                    else if(!did_hit){
                    //sleep_for (seconds(10)); NOT NEEDED RIGHT NOW
                    }
                    
                }
                
                else if(decision == 'd'){
                    cout << "Displaying " << Player[j].getName() << "'s board." << endl;
                    Player[j].displayLess();
                    j--;
                }
                else if(decision == 'm'){
                    cout << "Displaying " << Player[i].getName() << "'s board." << endl;
                    Player[i].displayAll();
                    j--;
                }
            
            }
        
            else{
                cout << "Invalid decision. Restarting turn..." << endl;
                j--;
            }
        
        
            if(checkLoser(j, Player)){//returns TRUE if 'j' has lost
            cout << Player[j].getName() << " loses!" << endl;
            Player.erase(Player.begin() + (j-1)); //remove the item at the first element + j - 1. Remove j.
       }
       
        
    }//End of j loop


}//end outer for loop/ turn loop



}//end while loop that checks player size to see if it's one

cout << "The winner is: " << Player[0].getName() << "!! Congratulations." << endl;
    
} //end main


bool checkLoser(int x, vector <Players>& Playerx){
    
    
    if (Playerx[x].getHits() == 17) //17 is number of pieces
    return true;
    
    else
    return false;
}


int fillPlayerCount(){
    int count = 0;
    
    cout << "How many players are there?" << endl;
    cin >> count;
    
    return count;
    
}


void roll(){
int hold;


srand(time(NULL));

hold = rand() % 2;

if(hold <= 1){
    cout << "Drink!" << endl;
}

else{
    cout << "Strip!" << endl;
}


}

void roll(string hold_string){
int hold;

srand(time(NULL));

hold = rand() % 4;

if(hold <= 1){
    cout << "Everyone else Drink!" << endl;
}

else if(hold == 2){
    cout << "Everyone else Strip!" << endl;
}

else{
    cout <<"Time to draw a card!" << endl;

}



}











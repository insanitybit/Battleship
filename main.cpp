//Some of these libraries are not necessary yet but will be for future features.

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <vector>
#include "Player.cpp"

using namespace std;

int fillPlayerCount();
bool checkLoser(int x);


int main(){
int i = 0;
int j = 0;

int x;
int y;
int player_count = 0;
string player_name;
char decision;
bool did_hit;


player_count = fillPlayerCount();
 
vector <Player> Player (player_count);

//Set player names
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
    
}

//Begin turn 
while (Player.size() != 1){
for(i = 0; i < player_count; i++){
cout << "New turn " << endl;


    for(j = 0; j < player_count; j++){
    
            if(i == j){ //Don't let a player attack themselves.
            j++;
            }
            cout << Player[i].getName() << "'s turn against " << Player[j].getName() << endl;
            cout << Player[i].getName() << ": What would you like to do?" << endl;
            cout << "Enter 'a' to attack. Enter 'd' to display " << Player[j].getName() << "'s board.";
            cout << " Enter 'm' to display your own board." << endl;
        
            cin >> decision;
            if(decision == 'a' || decision == 'd' || decision == 'm'){
            
                if(decision == 'a'){
                    cout << Player[i].getName() << ": Enter in coordinates to attack." << endl;
                    cout << "Enter X coordinate: " << endl;
                    cin >> x;
                    cout << "Enter Y coordinate: " << endl;
                    cin >> y;
                    
                    did_hit = Player[j].actionAttacked(x,y);
                    //TODO - get return value for success, if success roll for drinking/ stripping
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
        
        
        if(checkLoser(j)){//returns TRUE if 'j' has lost
            cout << Player[j].getName() << " loses!" << endl;
            Player.erase(Player.begin() + (j-1)); //remove the item at the first element + j - 1. Remove j.
        }
        
        
    }//End of j loop

}//end outer for loop/ turn loop

}//end while loop that checks player size to see if it's one

cout << "The winner is: " << Player[0].getName() << "!! Congratulations." << endl;
    
}


bool checkLoser(int x){
    
    return false;
}


int fillPlayerCount(){
    int count = 0;
    
    cout << "How many players are there?" << endl;
    cin >> count;
    
    return count;
    
}




#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <vector>
#include <map>
#include "Players.h"


using namespace std;




Players::Players(){
    cout << "\n\n\nTHIS IS THE CONSTRUCTOR\n\n\n" << endl;
}


//There are 17 'pieces' and 5 ships. Players will place the pieces one at a time.
void Players::setPieces(){
    int x_coord = 0;
    int y_coord = 0;
    bool first_turn = true;
    int pieces = 17;
    const int ships = 5;
    int i = 0;
    string direction_v;
    
    //First turn has no checks or rules
    
    
    displayAll();
    
    
    for(i = 0; i < ships; i++){
    cout << "Time to put the first piece of your " << ship_types[i] << " down." << endl;
    
    cout << "Enter in X coordinate: " << endl;
    cin >> x_coord;
    cout << "Enter in Y coordinate: " << endl;
    cin >> y_coord;
    cout << "Which direction should your ship continue in?" << endl;
    cout << "Enter up, down, left, right." << endl;
    cin >> direction_v;


    makeMove(y_coord, x_coord, direction_v, ship_types[i]);
    
    }
    
}


void Players::setName(string new_name){
    name = new_name;

}

string Players::getName(){
    
    return name;
}

int Players::getHits(){

return hit_tiles;
}

bool Players::actionAttacked(int x, int y){
    
    if(board[y][x].ship_tile && board[y][x].hit == false){
    
    board[y][x].hit = true;
    
    hit_tiles++;
    
    return true;
    }
    
    else if(board[y][x].hit == true){
    cout << "You've already gone here...'" << endl;
    
    makeMove(300, 300, "no_ship", "invalid"); //SEND MAKEMOVE() INVALID INFORMATION TO ALWAYS REDO MOVE
    
    
    }
    
    else{
        board[y][x].miss = true;
    }

return false;

}


void Players::displayLess(){//For when the ships should not be displayed, only hits/ misses
    int row = 0;
    int col = 0;
    
    for(row = 9; row >= 0; row--){

        cout << "[" << row << "]";
        
        for(col = 0; col < 10; col++){

            
            if(board[row][col].hit){
            cout << "[H]";
            }
            
            else if(board[row][col].miss){
            cout << "[M]";
            }
            else{
            cout << "[_]";
            }
        }
        cout << "\n";

    }
    cout << "[_][0][1][2][3][4][5][6][7][8][9]" << endl;
  
  
    
}




void Players::displayAll(){//For when a player wants to see their own board
    int row = 0;
    int col = 0;
    
    for(row = 9; row >= 0; row--){

        cout << "[" << row << "]";
        
        for(col = 0; col < 10; col++){

            
            if(board[row][col].ship_tile && !board[row][col].hit){
            cout << "[S]";
            }
            
            else if(board[row][col].hit){
            cout << "[H]";
            }
            
            else if(board[row][col].miss){
            cout << "[M]";
            }
                        
            else{
            cout << "[_]";
            }
        }
        cout << "\n";

    }
    cout << "[_][0][1][2][3][4][5][6][7][8][9]" << endl;
}

void Players::makeMove(int yC, int xC, string direction, string ship_t){


    Ships["Patrol Boat"]         = 2; //0
    Ships["Cruiser"]             = 3; //1
    Ships["Submarine"]           = 3; //2
    Ships["Battleship"]          = 4; //3
    Ships["Aircraft Carrier"]    = 5; //4

    int i = 0;

    while (!(validMove(xC, yC, direction, Ships[ship_t]))){
    
    cout << "Invalid move." << endl;
    cout << "Try again. Only positive integers between 0 and 9!!" << endl;
    cout << "Enter in X coordinate: " << endl;
    cin >> xC;
    cout << "Enter in Y coordinate: " << endl;
    cin >> yC;
    cout << "Which direction should your ship continue in?" << endl;
    cout << "Enter up, down, left, right." << endl;
    cin >> direction;
    
    
    
    }
    
    
    if (validMove(xC, yC, direction, Ships[ship_t])){
        board[yC][xC].ship_tile = true;
        board[yC][xC].hit = false;
        board[yC][xC].miss = false;
        board[yC][xC].type_of_ship = ship_t;
        cout << "first piece set " << endl;
    
        while(i < Ships[ship_t]){
            
        if(direction == "up"){
        
        board[yC+i][xC].ship_tile = true;
        board[yC+i][xC].hit = false;
        board[yC+i][xC].miss = false;
        board[yC+i][xC].type_of_ship = ship_t;    
        i++;
        }
        
        else if(direction == "down"){
        
        board[yC-i][xC].ship_tile = true;
        board[yC-i][xC].hit = false;
        board[yC-i][xC].miss = false;
        board[yC-i][xC].type_of_ship = ship_t;    
        i++;
        }
        
        else if(direction == "left"){
        
        board[yC][xC-i].ship_tile = true;
        board[yC][xC-i].hit = false;
        board[yC][xC-i].miss = false;
        board[yC][xC-i].type_of_ship = ship_t;    
        i++;
        }
        
        else if(direction == "right"){
        
        board[yC][xC+i].ship_tile = true;
        board[yC][xC+i].hit = false;
        board[yC][xC+i].miss = false;
        board[yC][xC+i].type_of_ship = ship_t;    
        i++;
        }
            
        }
        
    }
    

    displayAll();


}

bool Players::validMove(int x, int y, string direction, int ship_size){
    bool is_valid = true;
    int i = 0;
    
    if(x < 0 || x > 9 || y < 0 || y > 9){
        return false;
    }
    
    
    while(i < ship_size){
            
        if(direction == "up" || direction == "u"){
        
            if(board[y+i][x].ship_tile == true){
                return false;
                }
        }
        
        else if(direction == "down" || direction == "d" && y - ship_size >= 0){
        
            if(board[y-i][x].ship_tile == true){
                return false;
                }
        }
        
        else if(direction == "left" || direction == "l" && x - ship_size >= 0){
        
            if(board[y][x-i].ship_tile == true){
                return false;
                }
        }
        
        else if(direction == "right" || direction == "r" && x + ship_size <= 10){
        
            if(board[y][x+i].ship_tile == true){
                return false;
                }
        }
        
        else if(direction != "up" || direction != "down" || direction != "left" || direction != "right"){
        
        return false;
        }
        i++;
        
        }

    
    
    
    
    
    return is_valid;
    
}






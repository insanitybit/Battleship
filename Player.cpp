#ifndef PLAYERCLASS_CPP
#define PLAYERCLASS_CPP

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

class Player
{

public:
Player();
void setPieces();
void setName(string new_name);
string getName();
bool actionAttacked(int x, int y);
void displayLess();
void displayAll();

private:
string name;
bool validMove(int x, int y, string direction, int ship_size);
int hit_tiles;

struct Tile{
    bool ship_tile = false; //True if tile is holding a ship piece
    bool hit = false; //set to false by default - sinks are not hit by default
    bool miss = false; //set to false by default - set to miss if it's not a ship tile and a player attacks it
    string type_of_ship;
    
};

Tile board[10][10]; // create a board with 100 elements of type Tile


struct Inventory{
    
    int radar;
    int aircraft_sweep;
    int move_ship;  
    
};

Inventory Inventory;


};

Player::Player(){
    cout << "\n\n\nTHIS IS THE CONSTRUCTOR\n\n\n" << endl;
}


//There are 17 'pieces' and 5 ships. Players will place the pieces one at a time.
void Player::setPieces(){
    int x_coord = 0;
    int y_coord = 0;
    bool first_turn = true;
    int pieces = 17;
    int ships = 5;
    int i = 0;
    int ship_size;
    string ship_type;
    string direction;
    
    //First turn has no checks or rules
    
    
    displayAll();
    
    ship_type = "patrol boat";
    ship_size = 2;
    
    cout << "Time to put the first piece of your " << ship_type << " down." << endl;
    
    cout << "Enter in X coordinate: " << endl;
    cin >> x_coord;
    cout << "Enter in Y coordinate: " << endl;
    cin >> y_coord;
    cout << "Which direction should your ship continue in?" << endl;
    cout << "Enter up, down, left, right." << endl;
    cin >> direction;
    
    if (validMove(x_coord, y_coord, direction, ship_size)){
        board[y_coord][x_coord].ship_tile = true;
        board[y_coord][x_coord].hit = false;
        board[y_coord][x_coord].miss = false;
        board[y_coord][x_coord].type_of_ship = ship_type;
        cout << "first piece set " << endl;
        while(i < ship_size){
            
        if(direction == "up"){
        
        board[y_coord+i][x_coord].ship_tile = true;
        board[y_coord+i][x_coord].hit = false;
        board[y_coord+i][x_coord].miss = false;
        board[y_coord+i][x_coord].type_of_ship = ship_type;    
        i++;
        }
        
        else if(direction == "down"){
        
        board[y_coord-i][x_coord].ship_tile = true;
        board[y_coord-i][x_coord].hit = false;
        board[y_coord-i][x_coord].miss = false;
        board[y_coord-i][x_coord].type_of_ship = ship_type;    
        i++;
        }
        
        else if(direction == "left"){
        
        board[y_coord][x_coord-i].ship_tile = true;
        board[y_coord][x_coord-i].hit = false;
        board[y_coord][x_coord-i].miss = false;
        board[y_coord][x_coord-i].type_of_ship = ship_type;    
        i++;
        }
        
        else if(direction == "right"){
        
        board[y_coord][x_coord+i].ship_tile = true;
        board[y_coord][x_coord+i].hit = false;
        board[y_coord][x_coord+i].miss = false;
        board[y_coord][x_coord+i].type_of_ship = ship_type;    
        i++;
        }
            
        }
        
    }
    
    displayAll();
    
    first_turn = false;
    ship_size = 3;
    ship_type = "cruiser";
    
    i = 0;
    
    cout << "Time to put the first piece of your " << ship_type << " down." << endl;
    
    cout << "Enter in X coordinate: " << endl;
    cin >> x_coord;
    cout << "Enter in Y coordinate: " << endl;
    cin >> y_coord;
    cout << "Which direction should your ship continue in?" << endl;
    cout << "Enter up, down, left, right." << endl;
    cin >> direction;
    
    if (validMove(x_coord, y_coord, direction, ship_size)){
        board[y_coord][x_coord].ship_tile = true;
        board[y_coord][x_coord].hit = false;
        board[y_coord][x_coord].miss = false;
        board[y_coord][x_coord].type_of_ship = ship_type;
        cout << "first piece set " << endl;
        while(i < ship_size){
            
        if(direction == "up"){
        
        board[y_coord+i][x_coord].ship_tile = true;
        board[y_coord+i][x_coord].hit = false;
        board[y_coord+i][x_coord].miss = false;
        board[y_coord+i][x_coord].type_of_ship = ship_type;    
        i++;
        }
        
        else if(direction == "down"){
        
        board[y_coord-i][x_coord].ship_tile = true;
        board[y_coord-i][x_coord].hit = false;
        board[y_coord-i][x_coord].miss = false;
        board[y_coord-i][x_coord].type_of_ship = ship_type;    
        i++;
        }
        
        else if(direction == "left"){
        
        board[y_coord][x_coord-i].ship_tile = true;
        board[y_coord][x_coord-i].hit = false;
        board[y_coord][x_coord-i].miss = false;
        board[y_coord][x_coord-i].type_of_ship = ship_type;    
        i++;
        }
        
        else if(direction == "right"){
        
        board[y_coord][x_coord+i].ship_tile = true;
        board[y_coord][x_coord+i].hit = false;
        board[y_coord][x_coord+i].miss = false;
        board[y_coord][x_coord+i].type_of_ship = ship_type;    
        i++;
        }
            
        }
        
    }
    
    displayAll();

    
    i = 0;
    
    ship_type = "submarine";
    ship_size = 3;

    cout << "Time to put the first piece of your " << ship_type << " down." << endl;
    
    cout << "Enter in X coordinate: " << endl;
    cin >> x_coord;
    cout << "Enter in Y coordinate: " << endl;
    cin >> y_coord;
    cout << "Which direction should your ship continue in?" << endl;
    cout << "Enter up, down, left, right." << endl;
    cin >> direction;
    
    if (validMove(x_coord, y_coord, direction, ship_size)){
        board[y_coord][x_coord].ship_tile = true;
        board[y_coord][x_coord].hit = false;
        board[y_coord][x_coord].miss = false;
        board[y_coord][x_coord].type_of_ship = ship_type;
        cout << "first piece set " << endl;
        while(i < ship_size){
            
        if(direction == "up"){
        
        board[y_coord+i][x_coord].ship_tile = true;
        board[y_coord+i][x_coord].hit = false;
        board[y_coord+i][x_coord].miss = false;
        board[y_coord+i][x_coord].type_of_ship = ship_type;    
        i++;
        }
        
        else if(direction == "down"){
        
        board[y_coord-i][x_coord].ship_tile = true;
        board[y_coord-i][x_coord].hit = false;
        board[y_coord-i][x_coord].miss = false;
        board[y_coord-i][x_coord].type_of_ship = ship_type;    
        i++;
        }
        
        else if(direction == "left"){
        
        board[y_coord][x_coord-i].ship_tile = true;
        board[y_coord][x_coord-i].hit = false;
        board[y_coord][x_coord-i].miss = false;
        board[y_coord][x_coord-i].type_of_ship = ship_type;    
        i++;
        }
        
        else if(direction == "right"){
        
        board[y_coord][x_coord+i].ship_tile = true;
        board[y_coord][x_coord+i].hit = false;
        board[y_coord][x_coord+i].miss = false;
        board[y_coord][x_coord+i].type_of_ship = ship_type;    
        i++;
        }
            
        }
        
    }
    
    displayAll();
    
    i = 0;
    
    ship_type = "battleship";
    ship_size = 4;
    
    cout << "Time to put the first piece of your " << ship_type << " down." << endl;
    
    cout << "Enter in X coordinate: " << endl;
    cin >> x_coord;
    cout << "Enter in Y coordinate: " << endl;
    cin >> y_coord;
    cout << "Which direction should your ship continue in?" << endl;
    cout << "Enter up, down, left, right." << endl;
    cin >> direction;
    
    if (validMove(x_coord, y_coord, direction, ship_size)){
        board[y_coord][x_coord].ship_tile = true;
        board[y_coord][x_coord].hit = false;
        board[y_coord][x_coord].miss = false;
        board[y_coord][x_coord].type_of_ship = ship_type;
        cout << "first piece set " << endl;
        while(i < ship_size){
            
        if(direction == "up"){
        
        board[y_coord+i][x_coord].ship_tile = true;
        board[y_coord+i][x_coord].hit = false;
        board[y_coord+i][x_coord].miss = false;
        board[y_coord+i][x_coord].type_of_ship = ship_type;    
        i++;
        }
        
        else if(direction == "down"){
        
        board[y_coord-i][x_coord].ship_tile = true;
        board[y_coord-i][x_coord].hit = false;
        board[y_coord-i][x_coord].miss = false;
        board[y_coord-i][x_coord].type_of_ship = ship_type;    
        i++;
        }
        
        else if(direction == "left"){
        
        board[y_coord][x_coord-i].ship_tile = true;
        board[y_coord][x_coord-i].hit = false;
        board[y_coord][x_coord-i].miss = false;
        board[y_coord][x_coord-i].type_of_ship = ship_type;    
        i++;
        }
        
        else if(direction == "right"){
        
        board[y_coord][x_coord+i].ship_tile = true;
        board[y_coord][x_coord+i].hit = false;
        board[y_coord][x_coord+i].miss = false;
        board[y_coord][x_coord+i].type_of_ship = ship_type;    
        i++;
        }
            
        }
        
    }
    
    displayAll();
    
    
    i = 0;
    
    ship_type = "aircraft carrier";
    ship_size = 5;
    
    cout << "Time to put the first piece of your " << ship_type << " down." << endl;
    
    cout << "Enter in X coordinate: " << endl;
    cin >> x_coord;
    cout << "Enter in Y coordinate: " << endl;
    cin >> y_coord;
    cout << "Which direction should your ship continue in?" << endl;
    cout << "Enter up, down, left, right." << endl;
    cin >> direction;
    
    if (validMove(x_coord, y_coord, direction, ship_size)){
        board[y_coord][x_coord].ship_tile = true;
        board[y_coord][x_coord].hit = false;
        board[y_coord][x_coord].miss = false;
        board[y_coord][x_coord].type_of_ship = ship_type;
        cout << "first piece set " << endl;
        while(i < ship_size){
            
        if(direction == "up"){
        
        board[y_coord+i][x_coord].ship_tile = true;
        board[y_coord+i][x_coord].hit = false;
        board[y_coord+i][x_coord].miss = false;
        board[y_coord+i][x_coord].type_of_ship = ship_type;    
        i++;
        }
        
        else if(direction == "down"){
        
        board[y_coord-i][x_coord].ship_tile = true;
        board[y_coord-i][x_coord].hit = false;
        board[y_coord-i][x_coord].miss = false;
        board[y_coord-i][x_coord].type_of_ship = ship_type;    
        i++;
        }
        
        else if(direction == "left"){
        
        board[y_coord][x_coord-i].ship_tile = true;
        board[y_coord][x_coord-i].hit = false;
        board[y_coord][x_coord-i].miss = false;
        board[y_coord][x_coord-i].type_of_ship = ship_type;    
        i++;
        }
        
        else if(direction == "right"){
        
        board[y_coord][x_coord+i].ship_tile = true;
        board[y_coord][x_coord+i].hit = false;
        board[y_coord][x_coord+i].miss = false;
        board[y_coord][x_coord+i].type_of_ship = ship_type;    
        i++;
        }
            
        }
        
    }
    
    displayAll();
    
    
    
    
}


void Player::setName(string new_name){
    name = new_name;

}

string Player::getName(){
    
    return name;
}

bool Player::actionAttacked(int x, int y){
    
    if(board[y][x].ship_tile){
    
    board[y][x].hit == true;
    
    hit_tiles++;
    
    return true;
    }

return false;

}


void Player::displayLess(){//For when the ships should not be displayed, only hits/ misses
    
}

void Player::displayAll(){//For when a player wants to see their own board
    int row = 0;
    int col = 0;
    
    for(row = 9; row >= 0; row--){

        cout << "[" << row << "]";
        
        for(col = 0; col < 10; col++){

            
            if(board[row][col].ship_tile){
            cout << "[S]";
            }
            
            else{
            cout << "[_]";
            }
        }
        cout << "\n";

    }
    cout << "[_][0][1][2][3][4][5][6][7][8][9]" << endl;
}

bool Player::validMove(int x, int y, string direction, int ship_size){
    bool is_valid = true;
    int i = 0;
    
    if(x < 0 || x > 9 || y < 0 || y > 9){
        return false;
    }
    
    
    while(i < ship_size){
            
        if(direction == "up"){
        
            if(board[y+i][x].ship_tile == true){
                return false;
                }
        }
        
        if(direction == "down" && y - ship_size >= 0){
        
            if(board[y-i][x].ship_tile == true){
                return false;
                }
        }
        
        if(direction == "left" && x - ship_size >= 0){
        
            if(board[y][x-i].ship_tile == true){
                return false;
                }
        }
        
        if(direction == "right" && x + ship_size <= 10){
        
            if(board[y][x+i].ship_tile == true){
                return false;
                }
        }
        i++;
        
        }

    
    
    
    
    
    return is_valid;
    
}

#endif






#ifndef PLAYERS_H
#define PLAYERS_H

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <vector>
#include <map>


using namespace std;

class Players
{

public:
Players();
void setPieces();
void setName(string new_name);
string getName();
bool actionAttacked(int x, int y);
void displayLess();
void displayAll();
int getHits();
bool getSunk(int x, int y);


private:
void makeMove(int yC, int xC, string direction, string ship_t);
string name;
bool validMove(int x, int y, string direction, int ship_size);
int hit_tiles;
bool pieces_set = false;
void decrementShip(int x, int y);

map<string, int> Ship_sunk_counter;
map<string, int> Ships;

string ship_types[5] = {"Patrol Boat", "Cruiser", "Submarine", "Battleship", "Aircraft Carrier"};


struct Tile{
    bool ship_tile = false; //True if tile is holding a ship piece
    bool hit = false; //set to false by default - sinks are not hit by default
    bool miss = false; //set to false by default - set to miss if it's not a ship tile and a player attacks it
    string type_of_ship;
    
};


Tile board[10][10]; // create a board with 100 elements of type Tile


};

#endif

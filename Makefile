## file Makefile

# The -O2 is fairly important. The rest are really just there because this will be networked at some point.
CXXOBJECTS= %.o
CXX= g++ 
CXXSOURCES= main.cpp Players.cpp Deck.cpp
CXXFLAGS= -march=native -std=c++11 -Os -fstack-protector-all -fPIC -pie


Battleship : main.o Players.o Deck.o
	g++  -Wl,-z,relro,-z,now,-z,noexecstack -fPIC -pie main.o Players.o Deck.o -o Battleship


main.o : main.cpp 
Players.o : Players.cpp Players.h
Deck.o : Deck.cpp Deck.h
 
clean:

	rm main.o Players.o Deck.o
	
cleaner:

	rm main.o Players.o Deck.o Battleship

## eof Makefile
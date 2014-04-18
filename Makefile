## file Makefile

# The -O2 is fairly important. The rest are really just there because this will be networked at some point.
CXXOBJECTS= %.o
CXX= g++ 
CXXSOURCES= main.cpp Players.cpp
CXXFLAGS= -march=native -std=c++11 -O2 -fstack-protector-all -fPIC -pie


Battleship : main.o Players.o
	g++ -Wl,-z,relro,-z,now,-z,noexecstack -fPIC -pie main.o Players.o -o Battleship


main.o : main.cpp 
Players.o : Players.cpp Players.h
 
clean:

	rm main.o Players.o
	
cleaner:

    rm main.o Players.o Battleship

## eof Makefile

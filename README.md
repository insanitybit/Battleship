Battleship
==========

This is a game that allows multiple people to play Battleship with each other. As they play the game will instruct them to do various things, such as taking a shot, etc. Turns out Battleship makes a really good drinking game.

I'm making this for fun. It's not a particularly impressive or interesting program, but I'll get to use it once in a while, and that's all that I care about in this case.

The most pratice I'll get out of this is with GITHub.

Right now a base full game is playable with multiple players (currently I have tested 2 player games).

Building
========

1) Download the source.
2) Run 'make'
3) ./Battleship

Features
========
* Multiple players, variable number
* Basic game mechanics - attack, view maps, etc.
* TODO - inventory / abilities. Certain ships will allow you to use more complex moves.
* TODO - the game will determine who drinks and when. There will be a 'Kings' element with a virtual deck of cars as          well, which will lead to minigames.
* TODO - networked. Ideally two people could play this remotely, or on their own systems. While the best party would          involve everyone being together, in person, the game involves secrecy and sharing a screen is a bottleneck.
* TODO - AI component. Algorithmically there's a lot you can do with a battleship AI. 

Notes
=====


A bit about the mechanics and abilities: 

A basic game of battleship is going to basically come down to finding the first tile of a ship and then trying to sink that ship, and repeating the process.

There are 5 ships of size: 2, 3, 3, 4, 5.

The '2' is going to be the most strategically valuable ship as it's the smallest and therefor hardest to find.

Because no ship is ever smaller than 2 spaces you can eliminate half of the board, only ever attacking every other space. 

An attacker who takes down the size 2 ship will gain significant information about the board, much more than an attacker who takes down a ship of any other size.

Things like this mean that some boats are simply weighted way more than others. My approach to this "problem" (though it certainly isn't a problem, I just want to change things up) is to give boats 'powers'. A typical move involves attacking a single space. A 'power' move could involve many different things - viewing 4 spaces at once, attacking a full line, moving your boat around, etc.

The larger boats would get more significant abilities and therefor each boat would, ideally, be equivelant in their value.

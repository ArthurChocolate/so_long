# so_long
Status: Completed </br>
Score: 125/125 </br>
Retries: 0

The goal of the project is to learn how windows, sprites, textures, and events work, and to work with game logic</br>

In the project we use the school graphical library: MiniLibX </br> 
This library was developed internally and includes basic necessary tools to open a window, create images and deal with keyboard and mouse events. <br>

In the project it was necessary to create a 2D game. </br>

The game must conform to the following rules: </br>
1) The map is read from a file, must be completely covered by walls, must have a square or rectangular shape and contain only appropriate symbols: "0" for an empty space, "1" for a wall, "C" for a collectible, "E" for a map exit, "P" for the player's starting position. If it's not, the program must return an error. </br>
2) Only one player may be present on the map. </br>
3) The map must be at least one exit.</br>
4) Collectibles do not necessarily have to be on the map.</br>
5) When the player stepped on the collectible, the collectible disappears.</br>
6) The player can not go through walls.</br>
7) When parsing it is not necessary to check whether the player can get to the exit.</br>
8) The player can use the exit only after all collectibles are collected.</br>
9) The console must have a counter that will count the number of player moves.</br>
10) Pressing the ESC button must close the game.</br>
11) Clicking on the cross should close the game.</br>
12) The map must be stored in a file with the extension ".ber".</br>

In the bonus part it is necessary to implement the following: </br>
1) Add enemies to the map, which will have the symbol "K". </br>
2) Add the death of the player on contact with the enemy. </br>
3) Add any sprite animation. </br>

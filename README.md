# FILLER

Filler is a game which consists in filling a board with pieces of random size and shapes, without the pieces being stacked more than one square above each other and without them exceeding the grid.
Each successfully placed piece yields a number of points, the goal of the game could be to get the best score possible. Each player has for the purpose of placing as many pieces as possible while attempting to prevent his opponent from doing the same.


![screenshot](screenshot/filler1.gif)


## Rules

- two players fight each other, they play one after the other
- goal is to collect as many points as possible by placing the highest number of pieces on the the game board
- to be able to place a piece on the board, it is mandatory that one, and only one cell of the shape (in your piece) covers the cell of a shape placed previously (your territory)
- shape must not exceed the dimensions of the board
- game stops at the first error: either when a game piece cannot be placed anymore or it has been wrongly placed

## Install

```
git clone https://github.com/gitEllE-if/filler_game.git filler
cd filler
make
```
The program was tested and run on MacOS (Mojave, HighSierra, Catalina)


## Usage

```
./run.sh
```

- run the game with another bot
```
./run.sh -b {path_to_another_bot}
```
example: `./run.sh -b ./players/jupiter.filler`

- run the game with another map
```
./run.sh -m {path_to_another_map}
```
example: `./run.sh -m ./maps/map01`

- run the game with another images
```
./run.sh -i {path_to_another_image1} -j {path_to_another_image2}
```
example: `./run.sh -i ./visualizer/resources/img/mario1.jpg`

- it is possible to run game "bot vs bot"
```
./filler_vm -f maps/map01 -p1 players/jupiter.filler -p2 players/superjeannot.filler|./filler_visu_vm
```

![screenshot](screenshot/filler1.gif)


## Control

`[arrows]`	- move
`[SPACE]`	- set
`[Q]`		- autoplace
`[X]`		- autoplace once
`[M]`		- music
`[S]`		- sound

### Authors 

- bot				- [Phill](https://github.com/PhilippNox)
- visualizer 		- me
- virtual_machine	- Ecole42

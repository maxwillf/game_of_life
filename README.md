# Conway's Game of Life

C++ object oriented implementation of Conway's Game of Life for Basic Data Structure classes.

Conway's Game of Life is a cellular automaton that is actually a simulator. The evolution is determined only by its initial state and no other input is required.

# Rules 

The board of the Game of Life is an infinite two-dimensional grid of square "cells", that each one has two possibles states, dead or alive. Every cell must interact with its neighbours, the cells that are horizontally, vertically or diagonally adjacent. At each turn, these rules are applied.
1. Any live cell with **fewer than two live neighbours dies**, as if caused by underpopulation.
2. Any live cell with **two of three live neighbours lives** on to the next generation.
3. Any live cell with **more than three live neighbours dies** as if by overpopulation.
4. Any dead cell with **exactly three live neighbours becomes a live cell**, as if by reproduction.
5. All the births and deaths must happen at the same time. Therefore, cells that are dying can help others to born, but can't previne other cells death by overpopulation; using the same logic, cells that are borning won't preserve or kill living cells at past generation.

##### Authors: Max William Souto Filgueira and Emanuel Costa Betcel 
		

## Usage

If you want to simply play Conway's game of life then do:

```
make project && ./game
```

Otherwise if you want to compile the game with all its documentation do:

```
make 
```

If you are only interested in the documentation you can generate it with :

```
make docs
```

or simply:
```
doxygen Doxyfile
```



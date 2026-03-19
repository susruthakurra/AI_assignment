# Part 2: A* Algorithm (Grid-Based Pathfinding with Static Obstacles)

## Objective

This program implements the **A* (A-star) algorithm** to find the shortest path for an Unmanned Ground Vehicle (UGV) in a grid environment.

The system:

* Represents the environment as a 2D grid
* Places obstacles randomly
* Computes the shortest path from a start point to a goal point
* Avoids all obstacles

---

## What is A* Algorithm?

A* is a pathfinding algorithm used to find the shortest path between two points.

It improves upon Dijkstra’s algorithm by using a **heuristic function** to guide the search.

### Formula used:

f(n) = g(n) + h(n)

Where:

* g(n): cost from start to current node
* h(n): estimated cost from current node to goal
* f(n): total estimated cost

The algorithm always selects the node with the lowest f(n).

---

## Problem Representation

* The environment is a grid of size 10 × 10
* Each cell can be:

  * 0 → free space
  * 1 → obstacle
* Movement is allowed in four directions:

  * up, down, left, right

---

## File Structure

```
part2_static_path/
│
├── astar_main.c      → Main program and A* implementation
├── grid.c            → Grid initialization and printing
├── grid.h            → Structure definitions and function declarations
├── obstacles.c       → Random obstacle generation
└── README.md         → Documentation
```

---

## Input Description

There is no external input file. The grid is generated internally.

### Configuration inside code:

* Grid size: 10 × 10
* Start position: (0, 0)
* Goal position: (9, 9)
* Obstacles: randomly placed using a density value

Example:

```
addObstacles(grid, 20);
```

This places 20 random obstacles in the grid.

---

## Output

The program prints:

1. The grid (with obstacles)
2. Start and goal positions
3. The shortest path (if found)

---

### Sample Output

```
Grid:
0 0 1 0 0 ...
...

Start: (0, 0)
Goal: (9, 9)

Path:
-> (0,0) -> (1,0) -> (2,0) -> ... -> (9,9)
```

If no valid path exists:

```
No path found
```

---

## Code Explanation

### grid.h

Defines core structures:

* Point:
  Stores coordinates (x, y)

* Cell:
  Stores A* values:

  * f (total cost)
  * g (distance from start)
  * h (heuristic value)
  * parent coordinates

---

### grid.c

Contains:

* initializeGrid():
  Sets all cells to 0 (free)

* printGrid():
  Displays the grid

---

### obstacles.c

Contains:

* addObstacles():
  Randomly places obstacles (value = 1) in the grid

---

### astar_main.c

Contains the main A* logic.

#### Important functions:

* isValid():
  Checks if a cell is inside grid boundaries

* isUnBlocked():
  Checks if a cell is not an obstacle

* calculateH():
  Computes heuristic using Manhattan distance

* aStar():
  Core algorithm:

  * Selects node with lowest f value
  * Explores neighbors
  * Updates costs
  * Stops when destination is reached

* tracePath():
  Reconstructs path using parent pointers

---

## Heuristic Used

Manhattan Distance:

|x1 - x2| + |y1 - y2|

This is suitable because movement is restricted to four directions.

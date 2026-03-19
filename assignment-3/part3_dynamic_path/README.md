# Part 3: Dynamic Obstacles in Grid Environment

## Objective

This program simulates a grid-based environment where **obstacles appear dynamically over time**.

The goal is to demonstrate how an environment can change during execution, which is an important aspect of real-world navigation systems such as Unmanned Ground Vehicles (UGVs).

---

## Concept of Dynamic Obstacles

In many real-world scenarios, the environment is not static.

* New obstacles may appear unexpectedly
* Previously free paths may become blocked
* The system must adapt to changes in real time

This program focuses on **simulating such dynamic changes** in a simple grid environment.

---

## Problem Representation

* The environment is represented as a **10 × 10 grid**
* Each cell can be:

  * 0 → free space
  * 1 → obstacle

Initially, the grid contains no obstacles.
Over time, new obstacles are added randomly.

---

## File Structure

```
part3_dynamic_path/
│
├── dynamic.c        → Main program (simulation logic)
├── environment.c    → Grid operations and obstacle updates
├── environment.h    → Function declarations and constants
└── README.md        → Documentation
```

---

## How the Program Works

1. The grid is initialized with all cells set to 0 (free space)
2. The initial grid is displayed
3. A loop runs for a fixed number of steps
4. At each step:

   * A new obstacle is added at a random position
   * The updated grid is printed

---

## Input

There is no external input file.

All parameters are defined inside the program:

* Grid size: 10 × 10
* Number of steps: 5
* Obstacles are added randomly using a random number generator

---

## Output

The program prints:

* Initial empty grid
* Updated grid after each step

---

### Sample Output

```
Initial Grid:
0 0 0 0 0 ...
...

After step 1:
0 0 1 0 0 ...
...

After step 2:
0 1 1 0 0 ...
...
```

Each step shows how the environment changes over time.

---

## Code Explanation

### environment.h

Defines:

* Grid dimensions (ROW, COL)
* Function declarations for grid operations

---

### environment.c

Contains:

* initializeGrid():
  Sets all grid cells to 0

* printGrid():
  Displays the grid

* addDynamicObstacle():
  Randomly selects a cell and marks it as an obstacle (value = 1)

---

### dynamic.c

Main program logic:

* Initializes grid
* Seeds random number generator
* Runs a loop to simulate time steps
* Adds a new obstacle at each step
* Prints updated grid

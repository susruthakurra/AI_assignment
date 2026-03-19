#ifndef GRID_H
#define GRID_H

#define ROW 10
#define COL 10

typedef struct {
    int x, y;
} Point;

typedef struct {
    int parent_x, parent_y;
    int f, g, h;
} Cell;

void initializeGrid(int grid[ROW][COL]);
void printGrid(int grid[ROW][COL]);

#endif

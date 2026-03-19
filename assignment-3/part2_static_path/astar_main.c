#include <stdio.h>
#include "grid.h"

// Function declaration
void addObstacles(int grid[ROW][COL], int density);

int main() {
    int grid[ROW][COL];

    initializeGrid(grid);
    addObstacles(grid, 15);

    printf("Grid with obstacles:\n");
    printGrid(grid);

    return 0;
}

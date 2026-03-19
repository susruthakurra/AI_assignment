#include <stdlib.h>
#include <time.h>
#include "grid.h"

void addObstacles(int grid[ROW][COL], int density) {
    srand(time(0));

    for(int i = 0; i < density; i++) {
        int x = rand() % ROW;
        int y = rand() % COL;
        grid[x][y] = 1; // 1 = obstacle
    }
}

#include <stdio.h>
#include "grid.h"

void initializeGrid(int grid[ROW][COL]) {
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            grid[i][j] = 0; // 0 = free cell
        }
    }
}

void printGrid(int grid[ROW][COL]) {
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

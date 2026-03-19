#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "environment.h"

void initializeGrid(int grid[ROW][COL]) {
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            grid[i][j] = 0;
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

void updateObstacles(int grid[ROW][COL]) {
    int x = rand() % ROW;
    int y = rand() % COL;
    grid[x][y] = 1;
}

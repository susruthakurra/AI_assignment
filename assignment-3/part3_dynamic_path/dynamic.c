#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "environment.h"

int main() {
    int grid[ROW][COL];

    srand(time(0));

    initializeGrid(grid);

    printf("Initial Grid:\n");
    printGrid(grid);

    for(int step = 1; step <= 5; step++) {
        addDynamicObstacle(grid);

        printf("\nAfter step %d (new obstacle added):\n", step);
        printGrid(grid);
    }

    return 0;
}

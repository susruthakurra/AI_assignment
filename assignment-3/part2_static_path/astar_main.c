#include <stdio.h>
#include <limits.h>
#include <math.h>
#include "grid.h"

void addObstacles(int grid[ROW][COL], int density);

int isValid(int x, int y) {
    return (x >= 0 && x < ROW && y >= 0 && y < COL);
}

int isUnBlocked(int grid[ROW][COL], int x, int y) {
    return grid[x][y] == 0;
}

int isDestination(int x, int y, Point dest) {
    return (x == dest.x && y == dest.y);
}

int calculateH(int x, int y, Point dest) {
    return abs(x - dest.x) + abs(y - dest.y);
}

void tracePath(Cell cellDetails[ROW][COL], Point dest) {
    int x = dest.x;
    int y = dest.y;

    int path[ROW * COL][2];
    int index = 0;

    while (!(cellDetails[x][y].parent_x == x && cellDetails[x][y].parent_y == y)) {
        path[index][0] = x;
        path[index][1] = y;
        index++;

        int temp_x = cellDetails[x][y].parent_x;
        int temp_y = cellDetails[x][y].parent_y;
        x = temp_x;
        y = temp_y;
    }

    path[index][0] = x;
    path[index][1] = y;

    for (int i = index; i >= 0; i--) {
        printf("-> (%d,%d) ", path[i][0], path[i][1]);
    }
    printf("\n");
}

void aStar(int grid[ROW][COL], Point start, Point dest) {
    Cell cellDetails[ROW][COL];
    int closedList[ROW][COL] = {0};

    int i, j;

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            cellDetails[i][j].f = INT_MAX;
            cellDetails[i][j].g = INT_MAX;
            cellDetails[i][j].h = INT_MAX;
            cellDetails[i][j].parent_x = -1;
            cellDetails[i][j].parent_y = -1;
        }
    }

    int x = start.x, y = start.y;
    cellDetails[x][y].f = 0;
    cellDetails[x][y].g = 0;
    cellDetails[x][y].h = 0;
    cellDetails[x][y].parent_x = x;
    cellDetails[x][y].parent_y = y;

    for (int step = 0; step < ROW * COL; step++) {

        int min_f = INT_MAX;
        int cur_x = -1, cur_y = -1;

        for (i = 0; i < ROW; i++) {
            for (j = 0; j < COL; j++) {
                if (!closedList[i][j] && cellDetails[i][j].f < min_f) {
                    min_f = cellDetails[i][j].f;
                    cur_x = i;
                    cur_y = j;
                }
            }
        }

        if (cur_x == -1) break;

        closedList[cur_x][cur_y] = 1;

        if (isDestination(cur_x, cur_y, dest)) {
            printf("\nPath:\n");
            tracePath(cellDetails, dest);
            return;
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int dir = 0; dir < 4; dir++) {
            int new_x = cur_x + dx[dir];
            int new_y = cur_y + dy[dir];

            if (isValid(new_x, new_y) && isUnBlocked(grid, new_x, new_y)) {

                int gNew = cellDetails[cur_x][cur_y].g + 1;
                int hNew = calculateH(new_x, new_y, dest);
                int fNew = gNew + hNew;

                if (cellDetails[new_x][new_y].f == INT_MAX ||
                    cellDetails[new_x][new_y].f > fNew) {

                    cellDetails[new_x][new_y].f = fNew;
                    cellDetails[new_x][new_y].g = gNew;
                    cellDetails[new_x][new_y].h = hNew;
                    cellDetails[new_x][new_y].parent_x = cur_x;
                    cellDetails[new_x][new_y].parent_y = cur_y;
                }
            }
        }
    }

    printf("No path found\n");
}

int main() {
    int grid[ROW][COL];

    Point start = {0, 0};
    Point goal = {9, 9};

    initializeGrid(grid);
    addObstacles(grid, 20);

    grid[start.x][start.y] = 0;
    grid[goal.x][goal.y] = 0;

    printf("Grid:\n");
    printGrid(grid);

    printf("\nStart: (%d, %d)\n", start.x, start.y);
    printf("Goal: (%d, %d)\n", goal.x, goal.y);

    aStar(grid, start, goal);

    return 0;
}

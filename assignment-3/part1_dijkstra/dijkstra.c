#include <stdio.h>
#include "utils.h"

int main() {
    int graph[MAX][MAX] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    int n = 5;
    int start = 0;

    dijkstra(graph, n, start);

    return 0;
}

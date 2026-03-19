#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "utils.h"

int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void printPath(int parent[], int j, char cities[MAX][50]) {
    if (parent[j] == -1) {
        printf("%s ", cities[j]);
        return;
    }
    printPath(parent, parent[j], cities);
    printf("-> %s ", cities[j]);
}

void dijkstra(int graph[MAX][MAX], int n, int start, char cities[MAX][50]) {
    int dist[MAX], visited[MAX], parent[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("\nShortest Paths:\n");
    for (int i = 0; i < n; i++) {
        printf("\n%s → %s\nDistance: %d\nPath: ",
               cities[start], cities[i], dist[i]);
        printPath(parent, i, cities);
        printf("\n");
    }
}

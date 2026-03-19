#include <stdio.h>
#include "utils.h"

int main() {
    int graph[MAX][MAX], n;
    char cities[MAX][50];

    FILE *file = fopen("graph_data.txt", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fscanf(file, "%d", &n);

    for (int i = 0; i < n; i++) {
        fscanf(file, "%s", cities[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &graph[i][j]);
        }
    }

    fclose(file);

    int start = 0; // Hyderabad

    dijkstra(graph, n, start, cities);

    return 0;
}

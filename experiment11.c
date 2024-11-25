#include <stdio.h>
#include <limits.h>

#define MAX_NODES 10
#define INF INT_MAX

void dijkstra(int graph[MAX_NODES][MAX_NODES], int source, int num_nodes) {
    int dist[MAX_NODES], visited[MAX_NODES] = {0};

    for (int i = 0; i < num_nodes; i++)
        dist[i] = INF;
    dist[source] = 0;

    for (int i = 0; i < num_nodes - 1; i++) {
        int min = INF, minIndex;
        for (int j = 0; j < num_nodes; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                minIndex = j;
            }
        }

        visited[minIndex] = 1;

        for (int j = 0; j < num_nodes; j++) {
            if (!visited[j] && graph[minIndex][j] && dist[minIndex] != INF &&
                dist[minIndex] + graph[minIndex][j] < dist[j]) {
                dist[j] = dist[minIndex] + graph[minIndex][j];
            }
        }
    }

    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %d\n", i, dist[i]);
    }
}

int main() {
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 7, 9, 0, 0, 0},
        {7, 0, 10, 15, 0, 0},
        {9, 10, 0, 11, 0, 0},
        {0, 15, 11, 0, 6, 0},
        {0, 0, 0, 6, 0, 9},
        {0, 0, 0, 0, 9, 0}
    };

    dijkstra(graph, 0, 6);

    return 0;
}

#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 10

void bfs(int graph[MAX_NODES][MAX_NODES], int start, int num_nodes) {
    bool visited[MAX_NODES] = {false};
    int queue[MAX_NODES], front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < num_nodes; i++) {
            if (graph[node][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

void dfsHelper(int graph[MAX_NODES][MAX_NODES], int node, int num_nodes, bool visited[]) {
    visited[node] = true;
    printf("%d ", node);

    for (int i = 0; i < num_nodes; i++) {
        if (graph[node][i] && !visited[i]) {
            dfsHelper(graph, i, num_nodes, visited);
        }
    }
}

void dfs(int graph[MAX_NODES][MAX_NODES], int start, int num_nodes) {
    bool visited[MAX_NODES] = {false};
    dfsHelper(graph, start, num_nodes, visited);
}

int main() {
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0}
    };

    printf("BFS: ");
    bfs(graph, 0, 5);
    printf("\nDFS: ");
    dfs(graph, 0, 5);

    return 0;
}

#include <stdio.h>
#define INFINITY 9999
#define MAX 8

void Dijkstra(int Graph[MAX][MAX], int n, int start);

void Dijkstra(int Graph[MAX][MAX], int n, int start) {
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;

    // Creating cost matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (Graph[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = Graph[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    while (count < n - 1) {
        mindistance = INFINITY;

        for (i = 0; i < n; i++) {
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;
        for (i = 0; i < n; i++) {
            if (!visited[i]) {
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }
        count++;
    }

    // Printing the distance and paths
    for (i = 0; i < n; i++) {
        if (i != start) {
            printf("\nDistance from source to %d: %d", i, distance[i]);

            printf("\nPath: %d", i);
            j = i;
            do {
                j = pred[j];
                printf(" <- %d", j);
            } while (j != start);
        }
    }
}

int main() {
    int Graph[MAX][MAX], i, j, n, u;

    // Creating the graph
    Graph[0][0] = 0;
    Graph[0][1] = 50;
    Graph[0][2] = 50;
    Graph[0][3] = 100;
    Graph[0][4] = 0;
    Graph[0][5] = 0;

    Graph[1][0] = 0;
    Graph[1][1] = 0;
    Graph[1][2] = 0;
    Graph[1][3] = 40;
    Graph[1][4] = 0;
    Graph[1][5] = 0;

    Graph[2][0] = 0;
    Graph[2][1] = 0;
    Graph[2][2] = 0;
    Graph[2][3] = 40;
    Graph[2][4] = 80;
    Graph[2][5] = 0;

    Graph[3][0] = 0;
    Graph[3][1] = 0;
    Graph[3][2] = 0;
    Graph[3][3] = 0;
    Graph[3][4] = 30;
    Graph[3][5] = 80;

    Graph[4][0] = 0;
    Graph[4][1] = 0;
    Graph[4][2] = 0;
    Graph[4][3] = 0;
    Graph[4][4] = 0;
    Graph[4][5] = 40;

    Graph[5][0] = 0;
    Graph[5][1] = 0;
    Graph[5][2] = 0;
    Graph[5][3] = 0;
    Graph[5][4] = 0;
    Graph[5][5] = 0;


    n = 6ㅈ;
    u = 0;
    Dijkstra(Graph, n, u);

    return 0;
}

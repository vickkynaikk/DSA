#include <stdio.h>

#define MAX_NODES 100

int adjacencyMatrix[MAX_NODES][MAX_NODES];

void initializeMatrix() {
    int i, j;
    for (i = 0; i < MAX_NODES; i++) {
        for (j = 0; j < MAX_NODES; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(int source, int destination) {
    adjacencyMatrix[source][destination] = 1;
    adjacencyMatrix[destination][source] = 1; // For an undirected graph
}

void printMatrix(int numNodes) {
    int i, j;
    printf("Adjacency Matrix:\n");
    for (i = 0; i < numNodes; i++) {
        for (j = 0; j < numNodes; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numNodes, numEdges, i;
    int source, destination;

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);

    initializeMatrix();

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (source destination):\n");
    for (i = 0; i < numEdges; i++) {
        scanf("%d %d", &source, &destination);
        addEdge(source, destination);
    }

    printMatrix(numNodes);

    return 0;
}

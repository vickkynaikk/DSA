#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Function to read inputs from a file and generate adjacency matrix and list
void generateGraph(const char* filename, int adjacencyMatrix[][MAX_NODES], int adjacencyList[][MAX_NODES], int* numNodes) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    // Read the number of nodes
    fscanf(file, "%d", numNodes);

    // Initialize the adjacency matrix and list
    for (int i = 0; i < *numNodes; i++) {
        for (int j = 0; j < *numNodes; j++) {
            adjacencyMatrix[i][j] = 0;
            adjacencyList[i][j] = -1;
        }
    }

    // Read the edges and populate the adjacency matrix and list
    int source, destination;
    while (fscanf(file, "%d %d", &source, &destination) == 2) {
        adjacencyMatrix[source][destination] = 1;
        adjacencyList[source][destination] = destination;
    }

    fclose(file);
}

// Function to print the adjacency matrix
void printAdjacencyMatrix(const int adjacencyMatrix[][MAX_NODES], int numNodes) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to print the adjacency list
void printAdjacencyList(const int adjacencyList[][MAX_NODES], int numNodes) {
    printf("Adjacency List:\n");
    for (int i = 0; i < numNodes; i++) {
        printf("%d: ", i);
        for (int j = 0; j < numNodes; j++) {
            if (adjacencyList[i][j] != -1) {
                printf("%d ", adjacencyList[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    const char* filename = "graph.txt"; // Replace with the actual input file name

    int adjacencyMatrix[MAX_NODES][MAX_NODES];
    int adjacencyList[MAX_NODES][MAX_NODES];
    int numNodes = 0;

    generateGraph(filename, adjacencyMatrix, adjacencyList, &numNodes);
    printAdjacencyMatrix(adjacencyMatrix, numNodes);
    printAdjacencyList(adjacencyList, numNodes);

    return 0;
}

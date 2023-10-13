#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_VERTICES 5
#define MAX_EDGES 10

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E;
    struct Edge edges[MAX_EDGES];
};

// Function to create a new graph
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    return graph;
}

// Function to find the MST using Prim's algorithm
void randomMST(struct Graph* graph) {
    int numVertices = graph->V;
    int numEdges = graph->E;
    int included[MAX_EDGES] = {0};

    // Initialize a subgraph
    struct Graph* subgraph = createGraph(numVertices, 0);

    // Seed for random number generator
    srand(time(NULL));

    while (subgraph->E < numVertices - 1) {
        // Randomly select an edge
        int randomEdge = rand() % numEdges;

        // Check if including this edge doesn't form a cycle
        if (!included[randomEdge]) {
            included[randomEdge] = 1;
            subgraph->edges[subgraph->E++] = graph->edges[randomEdge];
        }
    }

    // Calculate and print the MST of the subgraph
    int totalWeight = 0;
    printf("Edges in the MST:\n");
    for (int i = 0; i < subgraph->E; i++) {
        printf("%d -- %d : %d\n", subgraph->edges[i].src, subgraph->edges[i].dest, subgraph->edges[i].weight);
        totalWeight += subgraph->edges[i].weight;
    }

    printf("Total Weight of MST: %d\n");

    // Clean up
    free(subgraph);
}

int main() {
    int V = 5;
    int E = 7;

    struct Graph* graph = createGraph(V, E);

    // Example edges with weights
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = 2;

    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].weight = 4;

    graph->edges[2].src = 1;
    graph->edges[2].dest = 2;
    graph->edges[2].weight = 3;

    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].weight = 1;

    graph->edges[4].src = 2;
    graph->edges[4].dest = 3;
    graph->edges[4].weight = 5;

    graph->edges[5].src = 2;
    graph->edges[5].dest = 4;
    graph->edges[5].weight = 6;

    graph->edges[6].src = 3;
    graph->edges[6].dest = 4;
    graph->edges[6].weight = 7;

    randomMST(graph);

    return 0;
}
